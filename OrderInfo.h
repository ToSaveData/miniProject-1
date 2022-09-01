#pragma once
#ifndef _ORDERINFO_H_
#define _ORDERINFO_H_
#include <iostream>
using namespace std;

class OrderInfo
{
public:
	OrderInfo(string orderCode = "", int orderDate = 00000000, int orderNumber = 0, int totalPrice = 0) :
		m_orderCode(orderCode), m_orderDate(orderDate), m_orderNumber(orderNumber), m_totalPrice(totalPrice) {}
	void setOrderCode(string&);
	string getOrderCode();
	void setOrderDate(int&);
	int getOrderDate();
	void setOrderNumber(int&);
	int getOrderNumber();
	void setTotalPrice(int&);
	int getTotalPrice();

private:
	string m_orderCode; //PK
	int m_orderDate;
	int m_orderNumber;
	int m_totalPrice;
};

#endif // !1
