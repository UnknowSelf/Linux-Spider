/**************************************************************************
   * File Name:    confparser.cpp
   * Author:	   yanjinlong
   * Mail:		   yjlxaut@126.com 
   * Created Time: 2015年06月07日 星期日 22时44分04秒
 ************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "confparser.h"

ConfigParser *ConfigParser::self = NULL;		//静态成员变量类外初始化

//构造函数
ConfigParser::ConfigParser()
{
	job_num = 0;
	seed = new char[40];
	memset(seed, 0, 40);
	depth = 1;
	log_level = 0;
	//module_path = (char *)malloc(20 * sizeof(char));
	module_path = new char[40];
	memset(module_path, 0, 20);
}

/*
ConfigParser::~ConfigParser()
{

	if (seed != nullptr)
	{
		delete seed;
		seed = nullptr;
	}
	if (module_path != nullptr)
	{
		delete module_path;
		module_path = nullptr;
	}
}	*/

ConfigParser * ConfigParser::GetInstance()
{
	if (self == NULL)
	{
		self = new ConfigParser();
	}

	return self;
}

int ConfigParser::loader(const char *conf_filepath)
{
	const int MAX_LEN = 200;
	char buf[MAX_LEN] = {0};
	char *res = NULL;
	char left[20] = {0};
	char right[40] = {0};
	FILE *fp;
	fp = fopen(conf_filepath, "r");
	if (fp == NULL)
	{
		return -1;
	}

	//逐行解析
	while (fgets(buf, MAX_LEN, fp) != NULL)
	{
		if (buf[0]=='#' || buf[0]=='\0' || buf[0]==' ')		//忽略注释和空行
			continue;

		//分割字符串
		res = strtok(buf, "=");				// = 左边
		memset(left, 0, sizeof(left));
		strcpy(left, res);
		while (res != NULL)
		{
			memset(right, 0, sizeof(right));
			strcpy(right, res);
			res = strtok(NULL, "=");		// = 右边
		}

		//解析字符串
		if (strcmp(left, "max_job_num") == 0)
		{
			job_num = atoi(right);
		}else if (strcmp(left, "seeds") == 0)
		{
			strcpy(seed, right);
		}else if (strcmp(left, "log_level") == 0)
		{
			log_level = atoi(right);
		}else if (strcmp(left, "module_path") == 0)
		{
			strcpy(module_path, right);
		}else if (strcmp(left, "max_depth") == 0)
		{
			depth = atoi(right);
		}else if (strcmp(left, "load_module") == 0)
		{
			module_name.push_back(right);
		}else if (strcmp(left, "accept_types") == 0)
		{
			file_type.push_back(right);
		}
		else
			continue;
	}
	return 0;
}

int ConfigParser::getJobNum()				//任务数
{
	printf("job_num = %d\n", job_num);
	return job_num;
}

char *ConfigParser::getUrlSeed()				//URL 种子
{
	printf("seed = %s\n", seed);
	return seed;
}

int ConfigParser::getLogLevel()				//日志等级
{
	printf("log_level = %d\n", log_level);
	return log_level;
}

int ConfigParser::getDepth()					//深度
{
	printf("depth = %d\n", depth);
	return depth;
}

char * ConfigParser::getModulePath()			//模块路径
{
	printf("module_path = %s\n",  module_path);
	return module_path;
}

std::list<std::string> ConfigParser::getModules()		//模块
{
	std::list<std::string>::iterator ibegin, iend;
	ibegin = module_name.begin();
	iend = module_name.end();
	for(; ibegin!=iend; ibegin++)
		std::cout << "module_name = " <<*ibegin << std::endl;
	return module_name;
}

std::list<std::string> ConfigParser::getFileTypes()	//文件类型
{
	std::list<std::string>::iterator ibegin, iend;
	ibegin = file_type.begin();
	iend = file_type.end();
	for(; ibegin!=iend; ibegin++)
		std::cout << "file_type = " <<*ibegin << std::endl;
	return file_type;
}

/*
int main()
{
	ConfigParser *conf = ConfigParser::GetInstance();
	if (conf->loader("./spider.conf") < 0)
	{
		printf("Load Config File Failed!\n");
		return -1;
	}
	conf->getJobNum();
	conf->getLogLevel();
	conf->getUrlSeed();
	conf->getDepth();
	conf->getModulePath();
	conf->getModules();
	conf->getFileTypes();

	std::cout << "Module Test Success!" << std::endl;
	return 0;
}
*/
