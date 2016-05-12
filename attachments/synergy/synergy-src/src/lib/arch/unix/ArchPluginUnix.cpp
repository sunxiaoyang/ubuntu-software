/*
 * synergy -- mouse and keyboard sharing utility
 * Copyright (C) 2012 Synergy Si Ltd.
 * Copyright (C) 2012 Nick Bolton
 * 
 * This package is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * found in the file LICENSE that should have accompanied this file.
 * 
 * This package is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "arch/unix/ArchPluginUnix.h"

#include "arch/unix/XArchUnix.h"
#include "common/PluginVersion.h"
#include "base/IEventQueue.h"
#include "base/Event.h"
#include "base/Log.h"

#include <vector>
#include <sys/types.h>
#include <dirent.h>
#include <dlfcn.h>

typedef void (*initFunc)(void*, void*);
typedef int (*initEventFunc)(void (*sendEvent)(const char*, void*));
typedef void* (*invokeFunc)(const char*, void*);
typedef void (*cleanupFunc)();

void* g_eventTarget = NULL;
IEventQueue* g_events = NULL;

ArchPluginUnix::ArchPluginUnix()
{
}

ArchPluginUnix::~ArchPluginUnix()
{
}

void
ArchPluginUnix::load()
{
	String pluginsDir = getPluginsDir();
	LOG((CLOG_DEBUG "plugins dir: %s", pluginsDir.c_str()));

	struct dirent* de = NULL;
	DIR* dir = NULL;

	dir = opendir(pluginsDir.c_str());
	if (dir == NULL) {
		LOG((CLOG_DEBUG "can't open plugins dir: %s",
		     pluginsDir.c_str()));
		return;
	}

	std::vector<String> plugins;
	while ((de = readdir(dir)) != NULL) {
		// ignore hidden files and diretories like .. and .
		if (de->d_name[0] != '.') {
			plugins.push_back(de->d_name);
		}
	}
	closedir(dir);

	std::vector<String>::iterator it;
	for (it = plugins.begin(); it != plugins.end(); ++it) {
		String filename = *it;
		String path = synergy::string::sprintf(
			"%s/%s", pluginsDir.c_str(), filename.c_str());
		String name = synergy::string::removeFileExt(filename.substr(3));

		LOG((CLOG_DEBUG "loading plugin: %s", filename.c_str()));
		void* handle = dlopen(path.c_str(), RTLD_LAZY);

		if (handle == NULL) {
			LOG((CLOG_ERR "failed to load plugin '%s', error: %s",
				filename.c_str(), dlerror()));
			continue;
		}


		String expectedVersion = getExpectedPluginVersion(name.c_str());
		String currentVersion =  getCurrentVersion(name, handle);

		if (currentVersion.empty() || (expectedVersion != currentVersion)) {
			LOG((CLOG_ERR
				"failed to load plugin '%s', "
				"expected version %s but was %s",
				filename.c_str(),
				expectedVersion.c_str(),
				currentVersion.empty() ? "unknown" : currentVersion.c_str()));

			dlclose(handle);
			continue;
		}

		LOG((CLOG_DEBUG "plugin loaded: %s (version %s)",
			filename.c_str(),
			currentVersion.c_str()));

		m_pluginTable.insert(std::make_pair(name, handle));
	}
}

void
ArchPluginUnix::unload()
{
	PluginTable::iterator it;
	for (it = m_pluginTable.begin(); it != m_pluginTable.end(); it++) {
		cleanupFunc cleanup = (cleanupFunc)dlsym(it->second, "cleanup");
		if (cleanup != NULL) {
			cleanup();
		}
		else {
			LOG((CLOG_DEBUG "no cleanup function in %s", it->first.c_str()));
		}

		LOG((CLOG_DEBUG "unloading plugin: %s", it->first.c_str()));
		dlclose(it->second);
	}
}

void
ArchPluginUnix::init(void* log, void* arch)
{
	PluginTable::iterator it;
	for (it = m_pluginTable.begin(); it != m_pluginTable.end(); it++) {
		initFunc initPlugin = (initFunc)dlsym(it->second, "init");
		if (initPlugin != NULL) {
			initPlugin(log, arch);
		}
		else {
			LOG((CLOG_DEBUG "no init function in %s", it->first.c_str()));
		}
	}
}

void
ArchPluginUnix::initEvent(void* eventTarget, IEventQueue* events)
{
	g_eventTarget = eventTarget;
	g_events = events;

	PluginTable::iterator it;
	for (it = m_pluginTable.begin(); it != m_pluginTable.end(); it++) {
		initEventFunc initEventPlugin = (initEventFunc)dlsym(it->second, "initEvent");
		if (initEventPlugin != NULL) {
			initEventPlugin(&sendEvent);
		}
		else {
			LOG((CLOG_DEBUG "no init event function in %s", it->first.c_str()));
		}
	}
}

bool
ArchPluginUnix::exists(const char* name)
{
	PluginTable::iterator it;
	it = m_pluginTable.find(name);
	return it != m_pluginTable.end() ? true : false;
}

void*
ArchPluginUnix::invoke(
	const char* plugin,
	const char* command,
	void** args,
	void* library)
{
	void* lib = NULL;

	if (library == NULL) {
		PluginTable::iterator it;
		it = m_pluginTable.find(plugin);
		if (it != m_pluginTable.end()) {
			lib = it->second;
		}
		else {
			LOG((CLOG_DEBUG "invoke command failed, plugin: %s command: %s",
					plugin, command));
			return NULL;
		}
	}
	else {
		lib = library;
	}
	
	invokeFunc invokePlugin = (invokeFunc)dlsym(lib, "invoke");
	void* result = NULL;
	if (invokePlugin != NULL) {
		result = invokePlugin(command, args);
	}
	else {
		LOG((CLOG_DEBUG "no invoke function in %s", plugin));
	}

	return result;
}

String
ArchPluginUnix::getPluginsDir()
{
	return ARCH->getPluginDirectory();
}

String
ArchPluginUnix::getCurrentVersion(const String& name, void* handle)
{
	char* version = (char*)invoke(name.c_str(), "version", NULL, handle);
	if (version == NULL) {
		return "";
	}

	return version;
}

void
sendEvent(const char* eventName, void* data)
{
	LOG((CLOG_DEBUG5 "plugin sending event"));
	Event::Type type = g_events->getRegisteredType(eventName);
	g_events->addEvent(Event(type, g_eventTarget, data));
}

void
log(const char* text)
{
	LOG((CLOG_DEBUG "plugin: %s", text));
}

