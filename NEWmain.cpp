#include "Client.h"
#include "Product.h"
#include "OrderInfo.h"
#include "clientHandler.h"
#include "productHandler.h"
#include "orderInfoHandler.h"
#include "UI.h"
#include <algorithm>
#include <string>

int main()
{
	int n = 0, m = 0, x = 0;
	string s="";
	clientHandler CH;
	productHandler PH;
	orderInfoHandler OH(CH, PH);
	
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
			cout << "잘못된 입력입니다." << endl;
			break;
		}

		cout << "계속 하시려면 아무 값이나 입력하세요(종료: -1).";
		cin >> n;
		system("cls");
	} while (!(n==-1));
	
	if (!(n == -1))
		goto TO;

	return 0;
}