/*
 * EpollManager.h
 *
 *  Created on: 2015年6月14日
 *      Author: yjlong
 */

#ifndef EPOLLMANAGER_H_
#define EPOLLMANAGER_H_

#include <iostream>

class EpollManager
{
public:
	EpollManager();								//构造函数初始化 Epoll ，得到句柄
	~EpollManager();

public:
	//注册 Socket 句柄
	int registHandle(int handle);
	//注销句柄
	int unregistHandle(int handle);

private:
	int m_eHandle;											//epool 句柄
	int m_tasknum;											//维护抓取的最大任务数
};

#endif /* EPOLLMANAGER_H_ */
