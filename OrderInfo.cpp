#include "OrderInfo.h"

void OrderInfo::setOrderCode(int& ordercode)
{
	m_orderCode = ordercode;
}
int OrderInfo::getOrderCode() { return m_orderCode; }

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

void OrderInfo::setCID(string& phoneNumber)
{
	m_CID = phoneNumber;
}
string OrderInfo::getCID() { return m_CID; }

void OrderInfo::setPID(int& productID)
{
	m_PID = productID;
}
int OrderInfo::getPID() { return m_PID; }

