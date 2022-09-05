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
	
	do {
		start();
TO:
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
			cout << "───────────────────────────────────────────────────────────────" << endl;
			cout << "잘못된 입력입니다." << endl;
			cout << "───────────────────────────────────────────────────────────────" << endl;
			break;
		}
		cout << "───────────────────────────────────────────────────────────────" << endl;
		cout << "계속 하시려면 아무 값이나 입력하세요(종료: -1).";
		cin >> s;
		system("cls");
	} while (!(s == "-1"));
	
	if (!(s == "-1"))
		goto TO;

	return 0;
}