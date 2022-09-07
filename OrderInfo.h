#ifndef _ORDERINFO_H_
#define _ORDERINFO_H_

#include <iostream>
#include "Client.h"
#include "Product.h"

using namespace std;

class OrderInfo //�ֹ� ������ ��Ҹ� �����ϴ� Ŭ����
{
public: // �ּҸ� ���������ν� �޸� ����� ���̰� �ӵ��� ������ �ϱ� ���� ���۷��� ������ ���ڷ� ���
	OrderInfo(int orderCode = 0, int orderDate = 00000000, int orderNumber = 0,	string cid = "", 
		int pid = 0): m_orderCode(orderCode), m_orderDate(orderDate), m_orderNumber(orderNumber), 
		m_CID(cid), m_PID(pid) {} //������
	
	void setOrderCode(int&); //�ֹ��ڵ� �Է�
	int getOrderCode(); //�ֹ��ڵ� ��ȯ
	void setOrderDate(int&); //�ֹ����� �Է�
	int getOrderDate(); //�ֹ����� ��ȯ
	void setOrderNumber(int&); //�ֹ����� �Է�
	int getOrderNumber(); //�ֹ����� ��ȯ
	void setCID(string&); //�� ��ȭ��ȣ(ClientŬ���� PK) �Է�
	string getCID(); //�� ��ȭ��ȣ(ClientŬ���� PK) ��ȯ
	void setPID(int&); //��ǰID(ProductŬ���� PK) �Է�
	int getPID(); //��ǰID(ProductŬ���� PK) ��ȯ

private:
	int m_orderCode; //�ֹ��ڵ�, PK
	int m_orderDate; //�ֹ�����
	int m_orderNumber; //�ֹ�����
	string m_CID; //�� ��ȭ��ȣ(ClientŬ���� PK)
	int m_PID; // ��ǰID(ProductŬ���� PK)
};

#endif // !1
