#include "Product.h"

void Product::setProductID(int& productID) //��ǰID �Է�
{
	m_productID = productID;
}
int Product::getProductID() const { return m_productID; } //��ǰID ��ȯ

void Product::setProductName(string& ProductName) //��ǰ�� �Է�
{
	m_productName = ProductName;
}
string Product::getProductName() const { return m_productName; } //��ǰ�� ��ȯ

void Product::setProductPrice(int& productPrice) //��ǰ ���� �Է�
{
	m_productPrice = productPrice;
}
int Product::getProductPrice() const { return m_productPrice; } //��ǰ ���� ��ȯ

void Product::setProductSort(string& productSort) //��ǰ ���� �Է�
{
	m_productSort = productSort;
}
string Product::getProductSort() const { return m_productSort; } //��ǰ ���� ��ȯ
