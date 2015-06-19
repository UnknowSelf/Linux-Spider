/*
 * SaveBase.h
 *
 *  Created on: 2015年6月14日
 *      Author: yjlong
 */

#ifndef SAVEBASE_H_
#define SAVEBASE_H_

class SaveBase
{
public:
	SaveBase();
	virtual ~SaveBase();

public:
	int setFilePath();
	virtual int save() = 0;												//子类重写
	int setFileData();
};

#endif /* SAVEBASE_H_ */
