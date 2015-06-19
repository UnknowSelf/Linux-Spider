/**************************************************************************
   * File Name:    confparser.h
   * Author:	   yanjinlong
   * Mail:		   yjlxaut@126.com 
   * Created Time: 2015年06月07日 星期日 21时17分17秒
 ************************************************************************/

#ifndef CONFPARSER_H
#define CONFPARSER_H

#include <iostream>
#include <string>
#include <list>

class ConfigParser
{
public:
	//~ConfigParser();
	//单例模式 : 保证一个类只有一个实例，并提供一个访问他的全局访问点
	//1.构造函数私有 2.静态成员变量 3.静态成员函数获取实例
	static ConfigParser *GetInstance();

	//操作
	int loader(const char *conf_filepath);	//加载配置文件
	int getJobNum();				//任务数
	char * getUrlSeed();				//URL 种子
	int getLogLevel();				//日志等级
	int getDepth();					//深度
	char * getModulePath();			//模块路径
	std::list<std::string> getModules();		//模块
	std::list<std::string> getFileTypes();	//文件类型

private:
	ConfigParser();
	static ConfigParser *self;

private:
	int job_num;
	char *seed;
	int depth;
	int log_level;
	char *module_path;
	std::list<std::string> module_name;
	std::list<std::string> file_type;
};
#endif	//
