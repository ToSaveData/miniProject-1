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
	cout << "*                      ��ǰ ���� ���α׷�" << "                      *" << endl;
	cout << "*                      1. �� ���� ����" << "                       *" << endl;
	cout << "*                      2. ��ǰ ���� ����" << "                       *" << endl;
	cout << "*                      3. ���� ���� ����" << "                       *" << endl;
	cout << "****************************************************************" << endl;
	cout << endl;
}

void firstQuestion(int &n)
{
	do 
	{
		
		cout << "��ȣ�� �Է��ϼ���." << endl;
		cin >> n;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			throw 100;
		}
		
		if (n > 3 || n < 1 || n == 0)
		{
			cout << "�߸��� ��ȣ�Դϴ�. �ٽ� �Է��ϼ���." << endl;
		}
		else   break;
	} while (!(n ==- 1));
}

void ClientQ(ClientHandler& CH)
{
	int m = 0;
	string s="";	
	
	cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
	cout << "1. ��ǰ ���� ��� / 2. ��ǰ ��� ��ȸ / 3. ��ǰ ���� �˻� " << endl;
	cout << "4. ��ǰ ���� ���� / 5. ��ǰ ���� ����" << endl;
	cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
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
		cout << "ã�� ����� ��ȭ��ȣ�� �Է��ϼ���(010-xxxx-xxxx). ";
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
	cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
	cout << "1. ��ǰ ���� ��� / 2. ��ǰ ��� ��ȸ / 3. ��ǰ ���� �˻� " << endl;
	cout << "4. ��ǰ ���� ���� / 5. ��ǰ ���� ����" << endl;
	cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
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
			cout << "ã�� ��ǰ�� ID�� �Է��ϼ���. ";
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

	cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
	cout << "1. ��ǰ ���� ��� / 2. ��ǰ ��� ��ȸ / 3. ��ǰ ���� �˻� " << endl;
	cout << "4. ��ǰ ���� ���� / 5. ��ǰ ���� ����" << endl;
	cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
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
		cout << "ã�� ��ǰ�� ID�� �Է��ϼ���. ";
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


//cout << "3) 1. ��ǰ ���� ��� / 2. ��ǰ ��� ��ȸ / 3. ��ǰ ���� �˻� / 4. ��ǰ ���� ���� / 5. ��ǰ ���� ����" << endl;

#endif // !_UI_H_



