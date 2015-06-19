/*
 * Url.h
 *
 *  Created on: 2015年6月8日
 *      Author: yjlong
 */

#ifndef URL_H_
#define URL_H_

#include <iostream>
#include <string>

typedef struct stru_url
{
	std::string url;
	std::string protocol;
	std::string siteName;
	std::string path;
	std::string fileName;
	bool state;
	int deep;
	std::string fileType;
}URL;

class Url
{
public:
	Url();
	Url(std::string url_str);
	 ~Url();

public:
	 int parseUrl();						//解析URL，并填充内部URL结构
	 struct stru_url * getUrlData();		//获得URL数据描述结构

private:
	 struct stru_url m_url;
};
#endif /* URL_H_ */
