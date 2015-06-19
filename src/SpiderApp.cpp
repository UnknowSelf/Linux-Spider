/*
 * SpiderApp.cpp
 *
 *  Created on: 2015年6月13日
 *      Author: yjlong
 */

#include "SpiderApp.h"
#include "confparser.h"

SpiderApp::SpiderApp()
{
	// TODO Auto-generated constructor stub
	isDeamon = false;
	
}

SpiderApp::~SpiderApp()
{
	// TODO Auto-generated destructor stub
}

int SpiderApp::initArgc(int argc, char *argv[])
{

}

int SpiderApp::initApp(int argc, char *argv[])
{
	/*处理参数*/
	if (initArgc(argc, argv) == 0)
	{
		//
			return 0;
	}

	/*读取配置文件*/
	ConfigParser::GetInstance()->loader(CONF_PATH);

	/*处理是否以守护进程运行*/
	if (isDeamon)
	{
		deamon();
	}

	/*载入所有模块*/
	//待完成
	//


}

int SpiderApp::run()
{

}

int SpiderApp::deamon()
{

}
