#include "Client.h"
#include "Product.h"
#include "OrderInfo.h"
#include "ClientHandler.h"
#include "ProductHandler.h"
#include "OrderInfoHandler.h"
#include "UI.h"
#include <algorithm>
#include <string>

int main()
{
	int n = 0, m = 0, x = 0;
	string s="";
	ClientHandler CH;
	ProductHandler PH;
	OrderInfoHandler OH(CH, PH);
	
TO:	do {
		start();
		try{
			int n = 0;
			firstQuestion(n);

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
			}
		}

		catch(...){
			cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
			cout << "�߸��� �Է��Դϴ�." << endl;
			cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
			break;
		}
		cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
		cout << "��� �Ͻ÷��� �ƹ� ���̳� �Է��ϼ���(����: -1).";
		cin >> n;
		system("cls");
	} while (!(n==-1));
	
	if (!(n == -1))
		goto TO;

	return 0;
}