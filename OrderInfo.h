#pragma once
#ifndef _ORDERINFO_H_
#define _ORDERINFO_H_

#include "Client.h"
#include "Product.h"
#include <iostream>
using namespace std;

class OrderInfo
{
public:
	OrderInfo(string orderCode = "", int orderDate = 00000000, int orderNumber = 0,	string cid = "", 
		int pid = 0): m_orderCode(orderCode), m_orderDate(orderDate), m_orderNumber(orderNumber), 
		m_CID(cid), m_PID(pid) {}
	
	void setOrderCode(string&);
	string getOrderCode();
	void setOrderDate(int&);
	int getOrderDate();
	void setOrderNumber(int&);
	int getOrderNumber();
	void setCID(string&);
	string getCID();
	void setPID(int&);
	int getPID();
	bool operator==(string ordercode) const;

private:
	string m_orderCode; //PK
	int m_orderDate;
	int m_orderNumber;
	string m_CID; //Client PK
	int m_PID; // Product PK
};

#endif // !1
