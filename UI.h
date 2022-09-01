#ifndef _UI_H_
#define _UI_H_

#include "orderInfoHandler.h"
#include "clientHandler.h"
#include "productHandler.h"
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
	//int n;
	do 
	{
		cout << "��ȣ�� �Է��ϼ���. (����: -1)" << endl;
		cin >> n;

		if (n > 3 || n < -1 || n == 0)
		{
			cout << "�߸��� ��ȣ�Դϴ�. �ٽ� �Է��ϼ���." << endl;
		}
		else   break;
	} while (!(n ==- 1));
	//return n;
}

void ClientQ(clientHandler& CH)
{
	int m=0;
	string s="";	
	
	cout << "1) 1. �� ���� ��� / 2. �� ��� ��ȸ / 3. �� ���� �˻� / 4. �� ���� ���� / 5. �� ���� ����" << endl;
	cin >> m;
	
	switch (m)
	{
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

void ProductQ(productHandler& PH)
{
	int x = 0,m = 0;
	string s = "";

	cout << "2) 1. ��ǰ ���� ��� / 2. ��ǰ ��� ��ȸ / 3. ��ǰ ���� �˻� / 4. ��ǰ ���� ���� / 5. ��ǰ ���� ����" << endl;
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

void OrderInfoQ(orderInfoHandler& OH)
{
	int x = 0, m = 0;
	string s = "";

	cout << "3) 1. �ֹ� ���� ��� / 2. �ֹ� ��� ��ȸ / 3. �ֹ� ���� �˻� / 4. �ֹ� ���� ���� / 5. �ֹ� ���� ����" << endl;
	cin >> m;

	switch (m)
	{
	case 1:
	{
		OH.OrderInfoEnroll();
	}break;
	case 2:
	{
		OH.OrderInfoShowlist();
	}break;
	case 3:
	{
		cout << "ã�� ��ǰ�� ID�� �Է��ϼ���. ";
		cin >> s;
		OH.OrderInfoSearch(s);
	}break;
	case 4:
	{
		OH.OrderInfoRemove();
	}break;
	case 5:
	{
		OH.OrderInfoEdit();
	}break;
	}
}


//cout << "3) 1. ��ǰ ���� ��� / 2. ��ǰ ��� ��ȸ / 3. ��ǰ ���� �˻� / 4. ��ǰ ���� ���� / 5. ��ǰ ���� ����" << endl;

#endif // !_UI_H_



