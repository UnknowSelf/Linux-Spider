/*
 * DownLoader.h
 *
 *  Created on: 2015年6月14日
 *      Author: yjlong
 */

#ifndef DOWNLOADER_H_
#define DOWNLOADER_H_

#include <iostream>
#include <string>
#include "Url.h"
#include "Socket.h"
#include "HttpParser.h"

class DownLoader
{
public:
	DownLoader();
	~DownLoader();

public:
	int getResource(URL *urls);									//下载资源内容  动作
	void *getResContent();										//下载资源内容

	int init();																	//初始化
	int reinit();																//重新初始化

	int getSockHandle();												//得到Socket句柄

private:
	//socket 分装模块
	Socket m_sock;
	//http 协议处理模块
	HttpParser m_httpParser;

	URL *m_url;
};

#endif /* DOWNLOADER_H_ */
