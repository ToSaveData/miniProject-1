#pragma once
#ifndef _PRODUCT_H_
#include <iostream>
using namespace std;

class Product
{
public:
	Product(int ID= 0000, string productName= "", int productPrice= 0, string productSort= ""): 
		m_ID(ID), m_productName(productName), m_productPrice(productPrice), m_productSort(productSort){ }
	void setProductID(int&);
	int getProductID() const;
	void setProductName(string&);
	string getProductName() const;
	void setProductPrice(int&);
	int getProductPrice() const;
	void setProductSort(string&);
	string getProductSort() const;

private:
	int m_ID; //PK
	string m_productName; //T1, T2 (CT ��ǰ), N1 (���ͺ� X-ray), SNAP(���� ī�޶�), Scanner(��ĳ��)
	int m_productPrice;
	string m_productSort; //CT, X-ray, DentalCam, DentalScanner
};

#endif // !_PRODUCT_H_
