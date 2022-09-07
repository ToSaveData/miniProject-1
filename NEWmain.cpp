#include <algorithm>
#include <string>
#include <conio.h>														//_getch() 함수 실행을 위한 헤더
#include "Client.h"
#include "Product.h"
#include "OrderInfo.h"
#include "ClientHandler.h"
#include "ProductHandler.h"
#include "OrderInfoHandler.h"
#include "UI.h"

int main()
{
	int n = 0, x = 0;													// int형 변수를 입력 받을 n, x 선언
	bool flag = true;													// while문의 반복 여부를 결정할  bool형 flag 변수
	ClientHandler CH;													// 고객 정보가 담긴 CH 객체 선언
	ProductHandler PH;													// 제품 정보가 담긴 PH 객체 선언
	OrderInfoHandler OH(CH, PH);										// 주문 정보가 담긴 OH 객체 선언
																		// 고객정보와 제품 정보 활용하므로 CH와 PH를 인자로 사용
	
	do {																// 정상값(1~4) 입력까지 do...while문 반복
		start();														// 초기 메뉴 선택 창 출력
		int n = 0;														// firstQuestion의 입력값 받을 변수 n 초기화
		do{
		firstQuestion(n);												// switch case문을 실행할 n을 입력받음
		if (n < 1 || n > 4)												// switch case문 예외처리
			cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
		else	flag = false;											// do...while 문 탈출을 위해 flag에 false 대입
		} while (flag);													// 정상값(1~4)이 입력될 경우 탈출
		
		switch (n)														// 입력된 n값을 바탕으로 함수 실행
		{
		case 1: {														// 고객 정보 관리 메뉴 실행
			ClientQ(CH);
			}break;												
		case 2: {
			ProductQ(PH);												// 제품 정보 관리 메뉴 실행
			}break;
		case 3: {
			OrderInfoQ(CH,PH,OH);										// 주문 정보 관리 메뉴 실행
			}break;
		case 4: {
			cout << "정말 종료하시겠습니까? 종료하시려면 9를 입력해주세요.";
			x = getNumber();											// 9를 입력할 경우 종료, 아니면 다시 초기 메뉴 반복
			}break;
			}
	} while (!(9 == x));												// 9가 입력되기 전까지 반복

	return 0;				
}

int getNumber()															// int형 데이터 입력 예외처리를 위한 int형 입력 함수
{
	char ch;															// 입력값 1글자를 저장할 변수 c
	int n;																// 입력값을 저장 후 반환할 변수 n
	while (true)														// 조건에 맞는 값을 입력할 때까지 반복
	{
		ch = _getch();													// 1글자를 입력받아 ch에 저장
		if (ch >= '0' && ch <= '9')	break;								// ch가 아스키문자 0~9 인 경우에만 while문 탈출
		else															// 숫자가 아닐 경우 모두 잘못된 입력으로 간주
		{
			cout << "───────────────────────────────────────────────────────────────" << endl;
			cout << "잘못된 입력입니다. 다시 입력하세요." << endl;
			cout << "───────────────────────────────────────────────────────────────" << endl;
		}
	}
	n = ch - '0';														// while문을 탈출한 ch를 int형 변수 n에 저장
	return n;															// n을 반환
}

int getBnumber()														// 한 자리 숫자가 아닌 가격같이 큰 숫자를 표현하는 함수
{
	int n, i = 0;														// 반환할 변수 n과 배열 위치를 나타낼 변수 i
	char ch, str[128];													// 입력값을 받을 변수 ch와 반환할 값을 저장하는 배열 str
	while (1) {															// 여러 문자를 입력할 수 있도록 반복문 실행
		do {															//	숫자가 입력될 때까지 반복문 실행
			ch = _getch();												// 입력받은 한 글자를 ch에 저장
			if (ch == '\r' || ch == '\n')								// ch가 enter인 경우
			{
				cout << endl;
				goto END;												//  END로 이동
			}
			else if (ch == '\b' && i > 0)								// 저장된 문자가 1개 이상이고 백스페이스가 입력된 경우
			{
				cout << "\b \b";										// 입력 데이터를 지우고
				i--;													// 저장할 배열 위치를 한칸 앞으로 보냄
			}
			else if(ch < '0' || ch > '9')								// 입력값이 한자리 숫자가 아닌 경우
			{
			cout << "\n───────────────────────────────────────────────────────────────" << endl;
			cout << "잘못된 입력입니다. 다시 입력하세요." << endl;
			cout << "───────────────────────────────────────────────────────────────" << endl;
			i = 0;														// 숫자를 처음 부터 다시 입력
			}		
		} while (ch < '0' || ch > '9');									// 입력값 중 숫자만 반환해서 
		cout << ch;														// 입력된 값을 보여주고
		str[i++] = ch;													// 배열에 한 글자씩 저장
	}
END:																	// enter가 입력된 경우
	str[i++] = '\0';													// 마지막에 NULL값을 입력해줌
	n = atoi(str);														// char형태의 데이터를 int형으로 변환해서 n에 저장
	return n;															// n에 저장된 값 반환
}
