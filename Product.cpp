#include "Product.h"

void Product::setID(int& ID)
{
	m_ID = ID;
}
int Product::getID() const { return m_ID; }

void Product::setProductName(string& ProductName)
{
	m_productName = ProductName;
}
string Product::getProductName() const { return m_productName; }

void Product::setProductPrice(int& productPrice)
{
	m_productPrice = productPrice;
}
int Product::getProductPrice() const { return m_productPrice; }

void Product::setProductSort(string& productSort)
{
	m_productSort = productSort;
}
string Product::getProductSort() const { return m_productSort; }