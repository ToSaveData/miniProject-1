#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <iostream>
using namespace std;

class Product //��ǰ ������ ��Ҹ� �����ϴ� Ŭ����
{
public: // �ּҸ� ���������ν� �޸� ����� ���̰� �ӵ��� ������ �ϱ� ���� ���۷��� ������ ���ڷ� ���
	Product(int ID= 0000, string productName= "", int productPrice= 0, string productSort= ""): 
		m_productID(ID), m_productName(productName), m_productPrice(productPrice), m_productSort(productSort){ }
	//������
	void setProductID(int&); //��ǰ ID �Է�
	int getProductID() const; //��ǰ ID ��ȯ
	void setProductName(string&); //��ǰ�� �Է�
	string getProductName() const; //��ǰ�� ��ȯ
	void setProductPrice(int&); //��ǰ ���� �Է�
	int getProductPrice() const; //��ǰ ���� ��ȯ
	void setProductSort(string&); //��ǰ ���� �Է�
	string getProductSort() const; //��ǰ ���� ��ȯ

private:
	int m_productID; //��ǰID, PK
	string m_productName; //��ǰ��
	int m_productPrice; //��ǰ ����
	string m_productSort; //��ǰ ����
};

#endif // !_PRODUCT_H_
