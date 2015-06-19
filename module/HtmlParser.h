/*
 * HtmlParser.h
 *
 *  Created on: 2015年6月14日
 *      Author: yjlong
 */

#ifndef HTMLPARSER_H_
#define HTMLPARSER_H_

#include <list>
#include <string>

class HtmlParser
{
public:
	HtmlParser();
	~HtmlParser();

public:			//公有接口
	std::list<std::string> getUrls(std::string page);

private:		//私有接口
};

#endif /* HTMLPARSER_H_ */
