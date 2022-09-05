#include "Product.h"
#include "ProductHandler.h"

void Product::setProductID(int& productID)
{
	m_productID = productID;
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
