#pragma once
#ifndef _ORDERINFO_H_
#include <iostream>
using namespace std;

class OrderInfo
{
public:
	OrderInfo(string orderCode = "", int orderDate = 00000000, int orderNumber = 0) :
		m_orderCode(orderCode), m_orderDate(orderDate), m_orderNumber(orderNumber) {}
	void setOrderCode(string&);
	string getOrderCode();
	void setOrderDate(int&);
	int getOrderDate();
	void setOrderNumber(int&);
	int getOrderNumber();

private:
	string m_orderCode;
	int m_orderDate;
	int m_orderNumber;
};

#endif // !1