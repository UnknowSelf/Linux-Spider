/*
 * Socket.h
 *
 *  Created on: 2015年6月14日
 *      Author: yjlong
 */

#ifndef SOCKET_H_
#define SOCKET_H_

#include "Url.h"

class Socket
{
public:
	Socket();
	~Socket();

public:				//外部接口
	int Request(URL *urls);									//发送请求
	int Response();													//接收反馈
	int setSocket();													//设置Socket
	int connect();														//连接
	int disConnect();												//断开连接
	void getData();

private:			//内部接口

private:
	int m_sockHandle;					//socket 句柄
	char *buf;									//
};

#endif /* SOCKET_H_ */
