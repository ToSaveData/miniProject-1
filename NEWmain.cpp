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
	start();
	clientHandler CH;
	productHandler PH;
	do {
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
	} while (1);

	
	return 0;
}