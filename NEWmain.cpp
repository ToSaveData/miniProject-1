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
			cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;
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
			cout << "���� �����Ͻðڽ��ϱ�? �����Ͻ÷��� 9�� �Է����ּ���.";
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
			cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
			cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���." << endl;
			cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
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
			cout << "\n������������������������������������������������������������������������������������������������������������������������������" << endl;
			cout << "�߸��� �Է��Դϴ�. �ٽ� �Է��ϼ���." << endl;
			cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
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
