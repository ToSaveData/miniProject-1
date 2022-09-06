#ifndef _UI_H_
#define _UI_H_

extern int getNumber();
#include "OrderInfoHandler.h"
#include "ClientHandler.h"
#include "ProductHandler.h"
#include "Client.h"
#include "Product.h"
#include "OrderInfo.h"
#include <iostream>
using namespace std;

void start()
{
	cout << endl;
	cout << "****************************************************************" << endl;
	cout << "*                      상품 관리 프로그램" << "                      *" << endl;
	cout << "*                      1. 고객 정보 관리" << "                       *" << endl;
	cout << "*                      2. 상품 정보 관리" << "                       *" << endl;
	cout << "*                      3. 주문 정보 관리" << "                       *" << endl;
	cout << "*                      4. 프로그램 종료" << "                        *" << endl;
	cout << "****************************************************************" << endl;
	cout << endl;
}

void firstQuestion(int &n)
{
	cout << "번호를 입력하세요." << endl;
	n = getNumber();
}

void ClientQ(ClientHandler& CH)
{
	int m = 0 , n = 0;
	int flag = 0;
	string s="";	
	
	do {
		cout << "───────────────────────────────────────────────────────────────" << endl;
		cout << "1. 고객 정보 등록 / 2. 고객 목록 조회 / 3. 고객 정보 검색 " << endl;
		cout << "4. 고객 정보 삭제 / 5. 고객 정보 변경 / 6. 뒤로 가기" << endl;
		cout << "───────────────────────────────────────────────────────────────" << endl;
		m = getNumber();
		if (m < 1 || m > 6)
			cout << "잘못된 번호입니다. 다시 입력하세요." << endl;
		else
		{
			flag = 1;
			switch (m)
			{
			case 1:
				{
					CH.ClientEnroll();
				}break;
			case 2:
				{
					CH.ClientShowlist();
					cout << "───────────────────────────────────────────────────────────────" << endl;
					cout << "계속 하시려면 아무 숫자값이나 입력하세요.";
					n = getNumber();
					system("cls");
				}break;
			case 3:
				{
					CH.ClientSearch();
				}break;
			case 4:
				{
					CH.ClientRemove();
				}break;
			case 5:
				{
					CH.ClientEdit();
				}break;
			case 6: 
				{
					system("cls");
				}break;
			}
		}
	} while (flag == 0);
}

void ProductQ(ProductHandler& PH)
{
	int x = 0,m = 0, flag = 0;
	string s = "";
	cout << "───────────────────────────────────────────────────────────────" << endl;
	cout << "1. 제품 정보 등록 / 2. 제품 목록 조회 / 3. 제품 정보 검색 " << endl;
	cout << "4. 제품 정보 삭제 / 5. 제품 정보 변경 / 6. 뒤로 가기" << endl;
	cout << "───────────────────────────────────────────────────────────────" << endl;
	do{
		m = getNumber();
	if(m < 1 || m > 6)
		cout << "잘못된 번호입니다. 다시 입력하세요." << endl;
	else{
		flag = 1;
		switch (m)
		{
		case 1:
			{
				PH.productEnroll();
			}break;
		case 2:
			{
				PH.productShowlist();
				cout << "───────────────────────────────────────────────────────────────" << endl;
				cout << "계속 하시려면 아무 숫자값이나 입력하세요.";
				x = getNumber();
				system("cls");
			}break;
		case 3:
			{
				PH.productSearch();
			}break;
		case 4:
			{
				PH.productRemove();
			}break;
		case 5:
			{
				PH.productEdit();
			}break;
		case 6:		
			{
				system("cls"); 
			}break;	
		}
	}
	} while (flag == 0);
}

void OrderInfoQ(ClientHandler& CH, ProductHandler& PH, OrderInfoHandler& OH1)
{
	int x = 0, m = 0, flag = 0;
	string s = "";
	cout << endl;
	cout << "───────────────────────────────────────────────────────────────" << endl;
	cout << "1. 주문 정보 등록 / 2. 주문 목록 조회 / 3. 주문 정보 검색 " << endl;
	cout << "4. 주문 정보 삭제 / 5. 주문 정보 변경 / 6. 뒤로 가기" << endl;
	cout << "───────────────────────────────────────────────────────────────" << endl;
	do {
		m = getNumber();
		if (m < 1 || m > 6)
			cout << "잘못된 번호입니다. 다시 입력하세요." << endl;
		else {
			flag = 1;
			switch (m)
			{
			case 1:
			{
				OH1.OrderInfoEnroll();
			}break;
			case 2:
			{
				OH1.OrderInfoShowlist(CH, PH);
				cout << "───────────────────────────────────────────────────────────────" << endl;
				cout << "계속 하시려면 아무 숫자값이나 입력하세요.";
				x = getNumber();
				system("cls");
			}break;
			case 3:
			{
				OH1.OrderInfoSearchShow(CH, PH);
			}break;
			case 4:
			{
				OH1.OrderInfoRemove(CH, PH);
			}break;
			case 5:
			{
				OH1.OrderInfoEdit(CH, PH);
			}break;
			case 6:		
			{
				system("cls");
			}break;
			}
		}
	} while (flag == 0);
}

#endif // !_UI_H_