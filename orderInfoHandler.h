#pragma once
#ifndef _ORDERINFOHANDLER_H_
#define _ORDERINFOHANDLER_H_
#include "OrderInfo.h"
#include "ClientHandler.h"
#include "ProductHandler.h"
#include <vector>


class OrderInfoHandler
{
public:
	OrderInfoHandler(ClientHandler& CH, ProductHandler& PH) :
		CInfo(CH), PInfo(PH) {}
	void OrderInfoEnroll();
	void OrderInfoSearchShow(string&, ClientHandler&, ProductHandler&);
	void OrderInfoShowlist(ProductHandler&);
	void OrderInfoRemove();
	void OrderInfoEdit();
	string getCName(string, ClientHandler&);
	string getCAddress(string, ClientHandler&);
	string getPName(int, ProductHandler&);
	int getPPrice(int, ProductHandler&);
	

private:
	vector<OrderInfo*> OrderInfoInfo;
	ClientHandler &CInfo;
	ProductHandler &PInfo;
};

#endif // !_ORDERINFOHANDLER_H_
