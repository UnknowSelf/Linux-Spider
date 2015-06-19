/*
 * Dso.h
 *
 *  Created on: 2015年6月9日
 *      Author: yjlong
 */

#ifndef DSOMANAGER_H_
#define DSOMANAGER_H_

#include <iostream>
#include <string>
#include <map>
#include <list>

#define MODULE_OK  0
#define MODULE_ERR 1

#define MODULE_MAIN_VERSION 1
#define 	MODULE_SUB_VERSION   0

//模块描述结构
class Module
{
public:
	int version;									//主版本号
	int subversion;							//次版本号
	std::string name;								//模块名
	void (*init)(Module *);			//初始化函数指针
	int (*handle)(void *);				//入口函数指针
};

class DsoManager
{
public:
	DsoManager();
	~DsoManager();

public:
	int load(const std::string &path, const std::string &name);			//动态加载编译好的模块
	Module * getModule(const std::string &name);							//从模块列表中获得需要的模块

private:
	std::map<std::string, Module *> m_modules;
};

class htmlParserParam
{
public:
	std::string url; 								//in
	std::list<std::string> urls;				//out
};

#endif /* DSOMANAGER_H_ */
