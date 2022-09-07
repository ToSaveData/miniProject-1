#include "OrderInfo.h"

void OrderInfo::setOrderCode(int& ordercode) //주문코드 입력
{
	m_orderCode = ordercode;
}
int OrderInfo::getOrderCode() { return m_orderCode; } //주문코드 반환

void OrderInfo::setOrderDate(int& orderdate) //주문일자 입력
{
	m_orderDate = orderdate;
}
int OrderInfo::getOrderDate() { return m_orderDate; } //주문일자 반환

void OrderInfo::setOrderNumber(int& ordernumber) //주문수량 입력
{
	m_orderNumber = ordernumber;
}
int OrderInfo::getOrderNumber() { return m_orderNumber; } //주문수량 반환

void OrderInfo::setCID(string& phoneNumber) //고객 전화번호(Client 클래스 PK) 입력
{
	m_CID = phoneNumber;
}
string OrderInfo::getCID() { return m_CID; } //고객 전화번호(Client 클래스 PK) 반환

void OrderInfo::setPID(int& productID) //제품ID(Product클래스 PK) 입력
{
	m_PID = productID;
}
int OrderInfo::getPID() { return m_PID; } //제품ID(Product클래스 PK) 반환

