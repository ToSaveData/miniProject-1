#include "Product.h"

void Product::setProductID(int& productID) //제품ID 입력
{
	m_productID = productID;
}
int Product::getProductID() const { return m_productID; } //제품ID 반환

void Product::setProductName(string& ProductName) //제품명 입력
{
	m_productName = ProductName;
}
string Product::getProductName() const { return m_productName; } //제품명 반환

void Product::setProductPrice(int& productPrice) //제품 가격 입력
{
	m_productPrice = productPrice;
}
int Product::getProductPrice() const { return m_productPrice; } //제품 가격 반환

void Product::setProductSort(string& productSort) //제품 종류 입력
{
	m_productSort = productSort;
}
string Product::getProductSort() const { return m_productSort; } //제품 종류 반환
