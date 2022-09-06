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
	cout << "*                      ��ǰ ���� ���α׷�" << "                      *" << endl;
	cout << "*                      1. �� ���� ����" << "                       *" << endl;
	cout << "*                      2. ��ǰ ���� ����" << "                       *" << endl;
	cout << "*                      3. �ֹ� ���� ����" << "                       *" << endl;
	cout << "*                      4. ���α׷� ����" << "                        *" << endl;
	cout << "****************************************************************" << endl;
	cout << endl;
}

void firstQuestion(int &n)
{
	cout << "��ȣ�� �Է��ϼ���." << endl;
	n = getNumber();
}

void ClientQ(ClientHandler& CH)
{
	int m = 0 , n = 0;
	int flag = 0;
	string s="";	
	
	do {
		cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
		cout << "1. �� ���� ��� / 2. �� ��� ��ȸ / 3. �� ���� �˻� " << endl;
		cout << "4. �� ���� ���� / 5. �� ���� ���� / 6. �ڷ� ����" << endl;
		cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
		m = getNumber();
		if (m < 1 || m > 6)
			cout << "�߸��� ��ȣ�Դϴ�. �ٽ� �Է��ϼ���." << endl;
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
					cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
					cout << "��� �Ͻ÷��� �ƹ� ���ڰ��̳� �Է��ϼ���.";
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
	cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
	cout << "1. ��ǰ ���� ��� / 2. ��ǰ ��� ��ȸ / 3. ��ǰ ���� �˻� " << endl;
	cout << "4. ��ǰ ���� ���� / 5. ��ǰ ���� ���� / 6. �ڷ� ����" << endl;
	cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
	do{
		m = getNumber();
	if(m < 1 || m > 6)
		cout << "�߸��� ��ȣ�Դϴ�. �ٽ� �Է��ϼ���." << endl;
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
				cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
				cout << "��� �Ͻ÷��� �ƹ� ���ڰ��̳� �Է��ϼ���.";
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
	cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
	cout << "1. �ֹ� ���� ��� / 2. �ֹ� ��� ��ȸ / 3. �ֹ� ���� �˻� " << endl;
	cout << "4. �ֹ� ���� ���� / 5. �ֹ� ���� ���� / 6. �ڷ� ����" << endl;
	cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
	do {
		m = getNumber();
		if (m < 1 || m > 6)
			cout << "�߸��� ��ȣ�Դϴ�. �ٽ� �Է��ϼ���." << endl;
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
				cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
				cout << "��� �Ͻ÷��� �ƹ� ���ڰ��̳� �Է��ϼ���.";
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