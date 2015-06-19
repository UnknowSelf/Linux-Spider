/*
 * SpiderApp.h
 *
 *  Created on: 2015年6月13日
 *      Author: yjlong
 */

#ifndef SPIDERAPP_H_
#define SPIDERAPP_H_

#define CONF_PATH "spider.conf"

class SpiderApp
{
public:
	SpiderApp();
	~SpiderApp();

public:						//业务成员函数
	//初始化环境
	//返回值：    1.成功       0.失败			与C语言相反
	int initApp(int argc, char *argv[]);
	//主处理流程
	//返回值：    1.成功       0.失败
	int run();
	int deamon();							//守护进程

private:					//内部接口
	//处理参数
	int initArgc(int argc, char *argv[]);

private:					//类私有成员变量
	bool isDeamon;						//是否以守护进程运行



};

#endif /* SPIDERAPP_H_ */
