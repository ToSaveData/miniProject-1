#pragma once
#ifndef _ORDERINFOHANDLER_H_
#define _ORDERINFOHANDLER_H_

#include <vector>
#include "OrderInfo.h"
#include "ClientHandler.h"
#include "ProductHandler.h"

class OrderInfoHandler
{
public:
	OrderInfoHandler(ClientHandler& CH, ProductHandler& PH);
	~OrderInfoHandler();
	void OrderInfoEnroll();
	void OrderInfoSearchShow(ClientHandler&, ProductHandler&);
	void OrderInfoShowlist(ClientHandler&, ProductHandler&);
	void OrderInfoRemove(ClientHandler&, ProductHandler&);
	void OrderInfoEdit(ClientHandler&, ProductHandler&);
	string getCName(string, ClientHandler&);
	string getCAddress(string, ClientHandler&);
	string getPName(int, ProductHandler&);
	int getPPrice(int, ProductHandler&);
	int MakeOrderCode();
	vector<string> parseOCSV(istream& file, char delimiter);
	
private:
	vector<OrderInfo*> OrderInfoInfo;
	ClientHandler &CInfo;
	ProductHandler &PInfo;
};

#endif // !_ORDERINFOHANDLER_H_
