/*
 * HtmlParserMod.cpp
 *
 *  Created on: 2015年6月16日
 *      Author: yjlong
 */

#include "HtmlParserMod.h"
#include "HtmlParser.h"

void init(Module *module)
{
	
}

int handle(void *data)
{
	htmlParserParam *lparam = (htmlParserParam *)data;
	HtmlParser parser;
	lparam->urls  = parser.getUrls(lparam->url);
	if (lparam->urls.size() == 0)
		return MODULE_ERR;
	return MODULE_OK;
}
