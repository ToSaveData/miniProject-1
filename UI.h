#ifndef _UI_H_
#define _UI_H_

#include <iostream>
#include "OrderInfoHandler.h"
#include "ClientHandler.h"
#include "ProductHandler.h"
#include "Client.h"
#include "Product.h"
#include "OrderInfo.h"

using namespace std;
extern int getNumber();                                                         //0~9까지의 숫자만 입력하는 함수

void start()																	//시작 화면의 인터페이스를 출력하는 함수
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

void firstQuestion(int &n)														//첫 입력을 요청하고 입력받는 함수
{
	cout << "번호를 입력하세요." << endl;
	n = getNumber();															//인자 i에 번호 입력
}

void ClientQ(ClientHandler& CH)													//고객 정보 관리 기능을 구현한 함수
{
	int m = 0 , n = 0;															//int형 입력을 받기 위한 변수
	int flag = 0;																//while문의 탈출을 위한 변수
	
	do {																		//메뉴에 있는 번호를 입력할 때까지 반복
		cout << "───────────────────────────────────────────────────────────────" << endl;
		cout << "1. 고객 정보 등록 / 2. 고객 목록 조회 / 3. 고객 정보 검색 " << endl;
		cout << "4. 고객 정보 삭제 / 5. 고객 정보 변경 / 6. 뒤로 가기" << endl;
		cout << "───────────────────────────────────────────────────────────────" << endl;
		m = getNumber();														//번호 입력
		if (m < 1 || m > 6)														//잘못된 번호 입력시
			cout << "잘못된 번호입니다. 다시 입력하세요." << endl;
		else		
		{
			flag = 1;															//do...while문 탈출조건으로 변경
			switch (m)															//번호 입력에 따른 메뉴 선택
			{
			case 1:																//고객 정보 등록 함수 호출
				{
					CH.ClientEnroll();
				}break;															// 메인메뉴로 복귀
			case 2:																//고객 정보 조회 함수 호출
				{
					CH.ClientShowlist();
					cout << "───────────────────────────────────────────────────────────────" << endl;
					cout << "계속 하시려면 아무 숫자값이나 입력하세요.";
					n = getNumber();											//아무 숫자 입력
					system("cls");												//화면 전환
				}break;															// 메인메뉴로 복귀
			case 3:																//고객 정보 검색 함수 호출
				{
					CH.ClientSearch();
				}break;															// 메인메뉴로 복귀
			case 4:																//고객 정보 삭제 함수 호출
				{
					CH.ClientRemove();
				}break;															// 메인메뉴로 복귀
			case 5:																//고객 정보 변경 함수 호출
				{
					CH.ClientEdit();
				}break;															// 메인메뉴로 복귀
			case 6: 
				{
					system("cls");												//화면 전환
				}break;															// 메인메뉴로 복귀
			}
		}
	} while (flag == 0);
}

void ProductQ(ProductHandler& PH)												//제품 정보 관리 기능을 구현한 함수
{
	int x = 0,m = 0, flag = 0;													//int형 입력 변수들과 while문 탈출용 변수 flag
	cout << "───────────────────────────────────────────────────────────────" << endl;
	cout << "1. 제품 정보 등록 / 2. 제품 목록 조회 / 3. 제품 정보 검색 " << endl;
	cout << "4. 제품 정보 삭제 / 5. 제품 정보 변경 / 6. 뒤로 가기" << endl;
	cout << "───────────────────────────────────────────────────────────────" << endl;
	do{																			//메뉴에 있는 번호를 입력할 때까지 반복
		m = getNumber();														//번호 입력
	if(m < 1 || m > 6)															//잘못된 번호 입력시
		cout << "잘못된 번호입니다. 다시 입력하세요." << endl;
	else{
		flag = 1;																//do...while문 탈출조건으로 변경
		switch (m)																//번호 입력에 따른 메뉴 선택
		{
		case 1:																	//제품 정보 등록 함수 호출
			{
				PH.productEnroll();
			}break;																// 메인메뉴로 복귀
		case 2:																	//제품 정보 조회 함수 호출
			{
				PH.productShowlist();
				cout << "───────────────────────────────────────────────────────────────" << endl;
				cout << "계속 하시려면 아무 숫자값이나 입력하세요.";
				x = getNumber();												//아무 숫자 입력
				system("cls");													//화면 전환
			}break;																// 메인메뉴로 복귀
		case 3:																	//제품 정보 검색 함수 호출
			{
				PH.productSearch();
			}break;																// 메인메뉴로 복귀
		case 4:																	//제품 정보 삭제 함수 호출
			{
				PH.productRemove();
			}break;																// 메인메뉴로 복귀
		case 5:																	//제품 정보 변경 함수 호출
			{
				PH.productEdit();
			}break;																// 메인메뉴로 복귀
		case 6:																	//제품 정보 등록 함수 호출		
			{
				system("cls");													//화면 전환
			}break;																// 메인메뉴로 복귀
		}
	}
	} while (flag == 0);
}

void OrderInfoQ(ClientHandler& CH, ProductHandler& PH, OrderInfoHandler& OH1)   //주문 정보 관리 기능을 구현한 함수
{
	int x = 0, m = 0, flag = 0;													//int형 입력 변수들과 while문 탈출용 변수 flag
	cout << endl;
	cout << "───────────────────────────────────────────────────────────────" << endl;
	cout << "1. 주문 정보 등록 / 2. 주문 목록 조회 / 3. 주문 정보 검색 " << endl;
	cout << "4. 주문 정보 삭제 / 5. 주문 정보 변경 / 6. 뒤로 가기" << endl;
	cout << "───────────────────────────────────────────────────────────────" << endl;
	do {																		//메뉴에 있는 번호를 입력할 때까지 반복
		m = getNumber();														//번호 입력
		if (m < 1 || m > 6)														//잘못된 번호 입력시
			cout << "잘못된 번호입니다. 다시 입력하세요." << endl;
		else {
			flag = 1;															//do...while문 탈출조건으로 변경
			switch (m)															//번호 입력에 따른 메뉴 선택
			{
			case 1:																//주문 정보 등록 함수 호출
			{
				OH1.OrderInfoEnroll();
			}break;																// 메인메뉴로 복귀
			case 2:																//주문 정보 조회 함수 호출
			{
				OH1.OrderInfoShowlist(CH, PH);
				cout << "───────────────────────────────────────────────────────────────" << endl;
				cout << "계속 하시려면 아무 숫자값이나 입력하세요.";
				x = getNumber();												//아무 숫자 입력
				system("cls");													//화면 전환
			}break;																// 메인메뉴로 복귀
			case 3:																//주문 정보 검색 함수 호출
			{
				OH1.OrderInfoSearchShow(CH, PH);
			}break;																// 메인메뉴로 복귀
			case 4:																//주문 정보 삭제 함수 호출
			{
				OH1.OrderInfoRemove(CH, PH);
			}break;																// 메인메뉴로 복귀
			case 5:																//주문 정보 변경 함수 호출
			{
				OH1.OrderInfoEdit(CH, PH);
			}break;																// 메인메뉴로 복귀
			case 6:
			{
				system("cls");													//화면 전환
			}break;																// 메인메뉴로 복귀
			}
		}
	} while (flag == 0);
}

#endif // !_UI_H_