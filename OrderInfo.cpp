#include "OrderInfo.h"

void OrderInfo::setOrderCode(int& ordercode) //�ֹ��ڵ� �Է�
{
	m_orderCode = ordercode;
}
int OrderInfo::getOrderCode() { return m_orderCode; } //�ֹ��ڵ� ��ȯ

void OrderInfo::setOrderDate(int& orderdate) //�ֹ����� �Է�
{
	m_orderDate = orderdate;
}
int OrderInfo::getOrderDate() { return m_orderDate; } //�ֹ����� ��ȯ

void OrderInfo::setOrderNumber(int& ordernumber) //�ֹ����� �Է�
{
	m_orderNumber = ordernumber;
}
int OrderInfo::getOrderNumber() { return m_orderNumber; } //�ֹ����� ��ȯ

void OrderInfo::setCID(string& phoneNumber) //�� ��ȭ��ȣ(Client Ŭ���� PK) �Է�
{
	m_CID = phoneNumber;
}
string OrderInfo::getCID() { return m_CID; } //�� ��ȭ��ȣ(Client Ŭ���� PK) ��ȯ

void OrderInfo::setPID(int& productID) //��ǰID(ProductŬ���� PK) �Է�
{
	m_PID = productID;
}
int OrderInfo::getPID() { return m_PID; } //��ǰID(ProductŬ���� PK) ��ȯ

