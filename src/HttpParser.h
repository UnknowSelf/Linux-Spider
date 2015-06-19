/*
 * Http.h
 *
 *  Created on: 2015年6月14日
 *      Author: yjlong
 */

#ifndef HTTPPARSER_H_
#define HTTPPARSER_H_

#include "Url.h"

class HttpParser
{
public:
	HttpParser();
	~HttpParser();

public:		//公共接口
	int parserHeader();				//解析头
	int createHeader();

	int getContent(void *buf);				//得到下载的内容,传入缓冲区			动态分配内存
	int getUrl(URL *url);

	int init();
	int reinit();

	int updateUrl();									//把从 http 中获取的信息进行更新

private:
	URL m_url;
};

#endif /* HTTPPARSER_H_ */
