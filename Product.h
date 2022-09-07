#ifndef _PRODUCT_H_
#define _PRODUCT_H_

#include <iostream>
using namespace std;

class Product //제품 정보의 요소를 소유하는 클래스
{
public: // 주소만 복사함으로써 메모리 사용을 줄이고 속도를 빠르게 하기 위해 레퍼런스 변수를 인자로 사용
	Product(int ID= 0000, string productName= "", int productPrice= 0, string productSort= ""): 
		m_productID(ID), m_productName(productName), m_productPrice(productPrice), m_productSort(productSort){ }
	//생성자
	void setProductID(int&); //제품 ID 입력
	int getProductID() const; //제품 ID 반환
	void setProductName(string&); //제품명 입력
	string getProductName() const; //제품명 반환
	void setProductPrice(int&); //제품 가격 입력
	int getProductPrice() const; //제품 가격 반환
	void setProductSort(string&); //제품 종류 입력
	string getProductSort() const; //제품 종류 반환

private:
	int m_productID; //제품ID, PK
	string m_productName; //제품명
	int m_productPrice; //제품 가격
	string m_productSort; //제품 종류
};

#endif // !_PRODUCT_H_
