#pragma once
#ifndef _ORDERHANDLER_H_
#define _ORDERHANDLER_H_
#include "OrderInfo.h"
#include <vector>

class orderInfoHandler
{
public:
	void OrderInfoEnroll();
	void OrderInfoSearch(string&);
	void OrderInfoShowlist();
	void OrderInfoRemove();
	void OrderInfoEdit();
	

private:
	vector<OrderInfo*> OrderInfoInfo;
};

#endif // !_ORDERINFOHANDLER_H_
