#pragma once
#ifndef _ORDERHANDLER_H_
#define _ORDERHANDLER_H_
#include "OrderInfo.h"
#include <vector>

class orderInfoHandler
{
public:
	void OrderInfoEnroll(clientHandler, productHandler);
	void OrderInfoSearch(int&);
	void OrderInfoShowlist(clientHandler, productHandler);
	void OrderInfoRemove();
	void OrderInfoEdit();
	

private:
	vector<OrderInfo*> OrderInfoInfo;
};

#endif // !_ORDERINFOHANDLER_H_
