#include "Product.h"

void Product::setProductID(int& ID)
{
	m_productID = ID;
}
int Product::getProductID() const { return m_productID; }

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

bool Product::operator==(int productID) const
{
	return (this->m_productID == productID);
}