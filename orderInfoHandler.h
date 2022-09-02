#pragma once
#ifndef _ORDERINFOHANDLER_H_
#define _ORDERINFOHANDLER_H_
#include "OrderInfo.h"
#include "clientHandler.h"
#include "productHandler.h"
#include <vector>

class orderInfoHandler
{
public:
	orderInfoHandler(clientHandler& CH, productHandler& PH) :
		CInfo(CH), PInfo(PH) {}
	void OrderInfoEnroll();
	void OrderInfoSearchShow(string&, clientHandler&, productHandler&);
	void OrderInfoShowlist();
	void OrderInfoRemove();
	void OrderInfoEdit();
	string getCName(string, clientHandler&);
	string getCAddress(string, clientHandler&);
	string getPName(int, productHandler&);
	int getPPrice(int, productHandler&);
	

private:
	vector<OrderInfo*> OrderInfoInfo;
	clientHandler &CInfo;
	productHandler &PInfo;
};

#endif // !_ORDERINFOHANDLER_H_
