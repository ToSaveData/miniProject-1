#include <algorithm>
#include <string>
#include <conio.h>
#include "Client.h"
#include "Product.h"
#include "OrderInfo.h"
#include "ClientHandler.h"
#include "ProductHandler.h"
#include "OrderInfoHandler.h"
#include "UI.h"

int main()
{
	int n = 0, m = 0, x = 0;
	bool flag = true;
	ClientHandler CH;
	ProductHandler PH;
	OrderInfoHandler OH(CH, PH);
	
	do {
		start();
		int n = 0;
		do{
		firstQuestion(n);
		if (n < 1 || n > 4)
			cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
		else	flag = false;
		} while (flag);
		
		switch (n)
		{
		case 1: {
			ClientQ(CH);
			}break;
		case 2: {
			ProductQ(PH);
			}break;
		case 3: {
			OrderInfoQ(CH,PH,OH);
			}break;
		case 4: {
			cout << "정말 종료하시겠습니까? 종료하시려면 9를 입력해주세요.";
			x = getNumber();
			}break;
			}
	} while (!(9 == x));

	return 0;
}

int getNumber()
{
	char ch;
	int n;
	while (true)
	{
		ch = _getch();
		if (ch >= '0' && ch <= '9')	break;
		else
		{
			cout << "───────────────────────────────────────────────────────────────" << endl;
			cout << "잘못된 입력입니다. 다시 입력하세요." << endl;
			cout << "───────────────────────────────────────────────────────────────" << endl;
		}
	}
	n = ch - '0';
	return n;
}

int getBnumber()
{
	int n, i = 0;
	char ch, str[128];
	while (1) {
		do {
			ch = _getch();
			if (ch == '\r' || ch == '\n')
			{
				cout << endl;
				goto END;
			}
			else if (ch == '\b' && i > 0)
			{
				cout << "\b \b";
				i--;
			}
			else if(ch < '0' || ch > '9')
			{
			cout << "\n───────────────────────────────────────────────────────────────" << endl;
			cout << "잘못된 입력입니다. 다시 입력하세요." << endl;
			cout << "───────────────────────────────────────────────────────────────" << endl;
			i = 0;
			}		
		} while (ch < '0' || ch > '9');
		cout << ch;
		str[i++] = ch;
	}
END:
	str[i++] = '\0';
	n = atoi(str);
	return n;
}
