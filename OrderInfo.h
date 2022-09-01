#pragma once
#ifndef _ORDERINFO_H_
#define _ORDERINFO_H_

#include "clientHandler.h"
#include "productHandler.h"
#include <iostream>
using namespace std;

class OrderInfo
{
public:
	OrderInfo(string orderCode = "", int orderDate = 00000000, int orderNumber = 0, int totalPrice = 0, 
		string cid = "", int pid = 0): m_orderCode(orderCode), m_orderDate(orderDate),
		m_orderNumber(orderNumber), m_totalPrice(totalPrice), m_CID(cid), m_PID(pid) {}
	
	void setOrderCode(string&);
	string getOrderCode();
	void setOrderDate(int&);
	int getOrderDate();
	void setOrderNumber(int&);
	int getOrderNumber();
	void setTotalPrice(int&);
	int getTotalPrice();
	void getCID(clientHandler&, string&);
	void getPID(productHandler&, int&);

private:
	string m_orderCode; //PK
	int m_orderDate;
	int m_orderNumber;
	int m_totalPrice;
	string m_CID; //Client PK
	int m_PID; // Product PK
};

#endif // !1
