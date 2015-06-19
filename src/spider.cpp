/*
 * spider.cpp
 *
 *  Created on: 2015年6月13日
 *      Author: yjlong
 */

#include "spider.h"
#include "SpiderApp.h"
#include "EpollManager.h"

int main(int argc, char *argv[])
{

	//对程序初始化
	SpiderApp app;

	/*初始化*/
	if (app.initApp(argc, argv) == 0)		//失败
	{
		//写入日志
		SPIDER_LOG(SPIDER_LEVEL_ERROR, "App init failed!  app has exit!");
		return 0;
	}
	/*主流程*/
	if (app.run() == 0)
	{
		SPIDER_LOG(SPIDER_LEVEL_ERROR, "App Run Error!");
		return 0;
	}

	return 0;
}



