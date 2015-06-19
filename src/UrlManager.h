/*
 * UrlManager.h
 *
 *  Created on: 2015年6月8日
 *      Author: yjlong
 */

#ifndef URLMANAGER_H_
#define URLMANAGER_H_

#include <list>
#include <string>
#include <map>
#include <queue>
#include "Url.h"

class UrlManager
{
public:
	UrlManager();
	~UrlManager();
public:		//外部接口
	 bool addUrl(std::string urls);									//添加一个新的URL，加入 list 和 queue 中，并生成索引
	 int addUrlList(std::list<std::string> urls);				//批量添加
	 stru_url * getUrlForQueue();									//取一个未处理的对象指针
	 int setUrlState(stru_url *urls);								//设置url处理状态

private:		//内部借口
	stru_url *findurl(std::string urls);
	// removeUrlForQueue();


private:
	 std::list<Url *> m_urls;												//所有URL
	 std::map<std::string, Url *> m_urlMap;					//所有URL索引
	 std::queue<Url *> m_urlQue;									//等待抓取的URL
};
#endif /* URLMANAGER_H_ */
