#include "OrderInfo.h"


void OrderInfo::setOrderCode(string& ordercode)
{
	m_orderCode = ordercode;
}
string OrderInfo::getOrderCode() { return m_orderCode; }

void OrderInfo::setOrderDate(int& orderdate)
{
	m_orderDate = orderdate;
}
int OrderInfo::getOrderDate() { return m_orderDate; }

void OrderInfo::setOrderNumber(int& ordernumber)
{
	m_orderNumber = ordernumber;
}
int OrderInfo::getOrderNumber() { return m_orderNumber; }