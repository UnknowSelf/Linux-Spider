/*
 * Dso.cpp
 *
 *  Created on: 2015年6月9日
 *      Author: yjlong
 */

#include <dlfcn.h>
#include <stdio.h>
#include "DsoManager.h"

DsoManager::DsoManager()
{
	// TODO Auto-generated constructor stub
	
}

DsoManager::~DsoManager()
{
	// TODO Auto-generated destructor stub
}

//动态加载编译好的模块
int DsoManager::load(const std::string &path, const std::string &name)
{
	Module *module = new Module();
	void *handle = NULL;
	std::string  filepath = path + name +".so";
	handle = dlopen(filepath.c_str(), RTLD_GLOBAL| RTLD_NOW);
	if (handle == NULL)
		return MODULE_ERR;
	//module->handle = handle;
	//int (*phandle)(void *, const char *) = dlsym;
	//module->init = phandle;
	//module->handle = (int)(*handle)(dlsym(handle , "handle"));
	if (module->handle == NULL)
		return MODULE_ERR;
	dlclose(handle);

	m_modules.insert(std::pair<const std::string&, Module *>(name, module));
	//m_modules[name] = module;
	return 0;
}

//从模块列表中获得需要的模块
Module * DsoManager::getModule(const std::string &name)
{
	//std::map<const std::string&, Module *>::iterator it;
	auto it =  m_modules.find(name);
	//Module test;
	if (it != m_modules.end())
	{
		return   (*it).second;
	}
	else
	{
		return NULL;
	}
	//return &test;
	//return 0;
}
