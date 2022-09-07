#ifndef _ORDERINFO_H_
#define _ORDERINFO_H_

#include <iostream>
#include "Client.h"
#include "Product.h"

using namespace std;

class OrderInfo //주문 정보의 요소를 소유하는 클래스
{
public: // 주소만 복사함으로써 메모리 사용을 줄이고 속도를 빠르게 하기 위해 레퍼런스 변수를 인자로 사용
	OrderInfo(int orderCode = 0, int orderDate = 00000000, int orderNumber = 0,	string cid = "", 
		int pid = 0): m_orderCode(orderCode), m_orderDate(orderDate), m_orderNumber(orderNumber), 
		m_CID(cid), m_PID(pid) {} //생성자
	
	void setOrderCode(int&); //주문코드 입력
	int getOrderCode(); //주문코드 반환
	void setOrderDate(int&); //주문일자 입력
	int getOrderDate(); //주문일자 반환
	void setOrderNumber(int&); //주문수량 입력
	int getOrderNumber(); //주문수량 반환
	void setCID(string&); //고객 전화번호(Client클래스 PK) 입력
	string getCID(); //고객 전화번호(Client클래스 PK) 반환
	void setPID(int&); //제품ID(Product클래스 PK) 입력
	int getPID(); //제품ID(Product클래스 PK) 반환

private:
	int m_orderCode; //주문코드, PK
	int m_orderDate; //주문일자
	int m_orderNumber; //주문수량
	string m_CID; //고객 전화번호(Client클래스 PK)
	int m_PID; // 제품ID(Product클래스 PK)
};

#endif // !1
