#include "Client.h"
#include "Product.h"
#include "OrderInfo.h"
#include "clientHandler.h"
#include "productHandler.h"
#include "UI.h"
#include <algorithm>
#include <string>

int main()
{
	int n = 0, m = 0, x = 0;
	string s="";

	clientHandler CH;
	productHandler PH;
	do {
		start();
		firstQuestion(n);
		switch (n)
		{
		case 1:
			{
				ClientQ(CH);
			}break;
		case 2:
			{
				ProductQ(PH);
			}break;
		case 3:
			{

			}break;
		}
		cout << "��� �Ͻðڽ��ϱ�? �׸��η��� -1�� �Է��Ͻʽÿ�.";
		cin >> n;
		cout << endl;
	} while (!(n==-1));

	
	return 0;
}