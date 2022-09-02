#ifndef _UI_H_
#define _UI_H_

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
	cout << "****************************************************************" << endl;
	cout << "*                      상품 관리 프로그램" << "                      *" << endl;
	cout << "*                      1. 고객 정보 관리" << "                       *" << endl;
	cout << "*                      2. 상품 정보 관리" << "                       *" << endl;
	cout << "*                      3. 쇼핑 정보 관리" << "                       *" << endl;
	cout << "****************************************************************" << endl;
	cout << endl;
}

void firstQuestion(int &n)
{
	do 
	{
		
		cout << "번호를 입력하세요." << endl;
		cin >> n;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			throw 100;
		}
		
		if (n > 3 || n < 1 || n == 0)
		{
			cout << "잘못된 번호입니다. 다시 입력하세요." << endl;
		}
		else   break;
	} while (!(n ==- 1));
}

void ClientQ(ClientHandler& CH)
{
	int m = 0;
	string s="";	
	
	cout << "───────────────────────────────────────────────────────────────" << endl;
	cout << "1. 제품 정보 등록 / 2. 제품 목록 조회 / 3. 제품 정보 검색 " << endl;
	cout << "4. 제품 정보 삭제 / 5. 제품 정보 변경" << endl;
	cout << "───────────────────────────────────────────────────────────────" << endl;
	cin >> m;
	
	switch (m)
	{
	case 0:
	{}
	case 1: 
		{
		CH.ClientEnroll();
		}break;
	case 2:
		{
		CH.ClientShowlist();
		}break;
	case 3:
		{
		cout << "찾는 사람의 전화번호를 입력하세요(010-xxxx-xxxx). ";
		cin >> s;
		CH.ClientSearch(s);
		}break;
	case 4:
		{
		CH.ClientRemove();
		}break;
	case 5:
		{
		CH.ClientEdit();
		}break;
	}
}

void ProductQ(ProductHandler& PH)
{
	int x = 0,m = 0;
	string s = "";
	cout << "───────────────────────────────────────────────────────────────" << endl;
	cout << "1. 제품 정보 등록 / 2. 제품 목록 조회 / 3. 제품 정보 검색 " << endl;
	cout << "4. 제품 정보 삭제 / 5. 제품 정보 변경" << endl;
	cout << "───────────────────────────────────────────────────────────────" << endl;
	cin >> m;

	switch (m)
	{
	case 1:
		{
			PH.productEnroll();
		}break;
	case 2:
		{
			PH.productShowlist();
		}break;
	case 3:
		{
			cout << "찾는 제품의 ID를 입력하세요. ";
			cin >> x;
			PH.productSearch(x);
		}break;
	case 4:
		{
			PH.productRemove();
		}break;
	case 5:
		{
			PH.productEdit();
		}break;
	}
}

void OrderInfoQ(ClientHandler& CH, ProductHandler& PH, OrderInfoHandler& OH1)
{
	int x = 0, m = 0;
	string s = "";

	cout << "───────────────────────────────────────────────────────────────" << endl;
	cout << "1. 제품 정보 등록 / 2. 제품 목록 조회 / 3. 제품 정보 검색 " << endl;
	cout << "4. 제품 정보 삭제 / 5. 제품 정보 변경" << endl;
	cout << "───────────────────────────────────────────────────────────────" << endl;
	cin >> m;

	switch (m)
	{
	case 1:
	{
		OH1.OrderInfoEnroll();
	}break;
	case 2:
	{
		OH1.OrderInfoShowlist(PH);
	}break;
	case 3:
	{
		cout << "찾는 제품의 ID를 입력하세요. ";
		cin >> s;
		OH1.OrderInfoSearchShow(s, CH, PH);
	}break;
	case 4:
	{
		OH1.OrderInfoRemove();
	}break;
	case 5:
	{
		OH1.OrderInfoEdit();
	}break;
	}
}


//cout << "3) 1. 제품 정보 등록 / 2. 제품 목록 조회 / 3. 제품 정보 검색 / 4. 제품 정보 삭제 / 5. 제품 정보 변경" << endl;

#endif // !_UI_H_



