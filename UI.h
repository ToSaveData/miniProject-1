#ifndef _UI_H_
#define _UI_H_

#include <iostream>
#include "OrderInfoHandler.h"
#include "ClientHandler.h"
#include "ProductHandler.h"
#include "Client.h"
#include "Product.h"
#include "OrderInfo.h"

using namespace std;
extern int getNumber();                                                         //0~9梱雖曖 璋濠虜 殮溘ж朝 л熱

void start()																	//衛濛 �飛橉� 檣攪む檜蝶蒂 轎溘ж朝 л熱
{
	cout << endl;
	cout << "****************************************************************" << endl;
	cout << "*                      鼻ヶ 婦葬 Щ煎斜極" << "                      *" << endl;
	cout << "*                      1. 堅偌 薑爾 婦葬" << "                       *" << endl;
	cout << "*                      2. 鼻ヶ 薑爾 婦葬" << "                       *" << endl;
	cout << "*                      3. 輿僥 薑爾 婦葬" << "                       *" << endl;
	cout << "*                      4. Щ煎斜極 謙猿" << "                        *" << endl;
	cout << "****************************************************************" << endl;
	cout << endl;
}

void firstQuestion(int &n)														//羅 殮溘擊 蹂羶ж堅 殮溘嫡朝 л熱
{
	cout << "廓�ㄧ� 殮溘ж撮蹂." << endl;
	n = getNumber();															//檣濠 i縑 廓�� 殮溘
}

void ClientQ(ClientHandler& CH)													//堅偌 薑爾 婦葬 晦棟擊 掘⑷и л熱
{
	int m = 0 , n = 0;															//int⑽ 殮溘擊 嫡晦 嬪и 滲熱
	int flag = 0;																//while僥曖 驍轎擊 嬪и 滲熱
	
	do {																		//詭景縑 氈朝 廓�ㄧ� 殮溘й 陽梱雖 奩犒
		cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
		cout << "1. 堅偌 薑爾 蛔煙 / 2. 堅偌 跡煙 褻�� / 3. 堅偌 薑爾 匐儀 " << endl;
		cout << "4. 堅偌 薑爾 餉薯 / 5. 堅偌 薑爾 滲唳 / 6. 菴煎 陛晦" << endl;
		cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
		m = getNumber();														//廓�� 殮溘
		if (m < 1 || m > 6)														//澀跤脹 廓�� 殮溘衛
			cout << "澀跤脹 廓��殮棲棻. 棻衛 殮溘ж撮蹂." << endl;
		else		
		{
			flag = 1;															//do...while僥 驍轎褻勒戲煎 滲唳
			switch (m)															//廓�� 殮溘縑 評艇 詭景 摹鷗
			{
			case 1:																//堅偌 薑爾 蛔煙 л熱 ��轎
				{
					CH.ClientEnroll();
				}break;															// 詭檣詭景煎 犒敝
			case 2:																//堅偌 薑爾 褻�� л熱 ��轎
				{
					CH.ClientShowlist();
					cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
					cout << "啗樓 ж衛溥賊 嬴鼠 璋濠高檜釭 殮溘ж撮蹂.";
					n = getNumber();											//嬴鼠 璋濠 殮溘
					system("cls");												//�飛� 瞪��
				}break;															// 詭檣詭景煎 犒敝
			case 3:																//堅偌 薑爾 匐儀 л熱 ��轎
				{
					CH.ClientSearch();
				}break;															// 詭檣詭景煎 犒敝
			case 4:																//堅偌 薑爾 餉薯 л熱 ��轎
				{
					CH.ClientRemove();
				}break;															// 詭檣詭景煎 犒敝
			case 5:																//堅偌 薑爾 滲唳 л熱 ��轎
				{
					CH.ClientEdit();
				}break;															// 詭檣詭景煎 犒敝
			case 6: 
				{
					system("cls");												//�飛� 瞪��
				}break;															// 詭檣詭景煎 犒敝
			}
		}
	} while (flag == 0);
}

void ProductQ(ProductHandler& PH)												//薯ヶ 薑爾 婦葬 晦棟擊 掘⑷и л熱
{
	int x = 0,m = 0, flag = 0;													//int⑽ 殮溘 滲熱菟婁 while僥 驍轎辨 滲熱 flag
	cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "1. 薯ヶ 薑爾 蛔煙 / 2. 薯ヶ 跡煙 褻�� / 3. 薯ヶ 薑爾 匐儀 " << endl;
	cout << "4. 薯ヶ 薑爾 餉薯 / 5. 薯ヶ 薑爾 滲唳 / 6. 菴煎 陛晦" << endl;
	cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
	do{																			//詭景縑 氈朝 廓�ㄧ� 殮溘й 陽梱雖 奩犒
		m = getNumber();														//廓�� 殮溘
	if(m < 1 || m > 6)															//澀跤脹 廓�� 殮溘衛
		cout << "澀跤脹 廓��殮棲棻. 棻衛 殮溘ж撮蹂." << endl;
	else{
		flag = 1;																//do...while僥 驍轎褻勒戲煎 滲唳
		switch (m)																//廓�� 殮溘縑 評艇 詭景 摹鷗
		{
		case 1:																	//薯ヶ 薑爾 蛔煙 л熱 ��轎
			{
				PH.productEnroll();
			}break;																// 詭檣詭景煎 犒敝
		case 2:																	//薯ヶ 薑爾 褻�� л熱 ��轎
			{
				PH.productShowlist();
				cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
				cout << "啗樓 ж衛溥賊 嬴鼠 璋濠高檜釭 殮溘ж撮蹂.";
				x = getNumber();												//嬴鼠 璋濠 殮溘
				system("cls");													//�飛� 瞪��
			}break;																// 詭檣詭景煎 犒敝
		case 3:																	//薯ヶ 薑爾 匐儀 л熱 ��轎
			{
				PH.productSearch();
			}break;																// 詭檣詭景煎 犒敝
		case 4:																	//薯ヶ 薑爾 餉薯 л熱 ��轎
			{
				PH.productRemove();
			}break;																// 詭檣詭景煎 犒敝
		case 5:																	//薯ヶ 薑爾 滲唳 л熱 ��轎
			{
				PH.productEdit();
			}break;																// 詭檣詭景煎 犒敝
		case 6:																	//薯ヶ 薑爾 蛔煙 л熱 ��轎		
			{
				system("cls");													//�飛� 瞪��
			}break;																// 詭檣詭景煎 犒敝
		}
	}
	} while (flag == 0);
}

void OrderInfoQ(ClientHandler& CH, ProductHandler& PH, OrderInfoHandler& OH1)   //輿僥 薑爾 婦葬 晦棟擊 掘⑷и л熱
{
	int x = 0, m = 0, flag = 0;													//int⑽ 殮溘 滲熱菟婁 while僥 驍轎辨 滲熱 flag
	cout << endl;
	cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
	cout << "1. 輿僥 薑爾 蛔煙 / 2. 輿僥 跡煙 褻�� / 3. 輿僥 薑爾 匐儀 " << endl;
	cout << "4. 輿僥 薑爾 餉薯 / 5. 輿僥 薑爾 滲唳 / 6. 菴煎 陛晦" << endl;
	cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
	do {																		//詭景縑 氈朝 廓�ㄧ� 殮溘й 陽梱雖 奩犒
		m = getNumber();														//廓�� 殮溘
		if (m < 1 || m > 6)														//澀跤脹 廓�� 殮溘衛
			cout << "澀跤脹 廓��殮棲棻. 棻衛 殮溘ж撮蹂." << endl;
		else {
			flag = 1;															//do...while僥 驍轎褻勒戲煎 滲唳
			switch (m)															//廓�� 殮溘縑 評艇 詭景 摹鷗
			{
			case 1:																//輿僥 薑爾 蛔煙 л熱 ��轎
			{
				OH1.OrderInfoEnroll();
			}break;																// 詭檣詭景煎 犒敝
			case 2:																//輿僥 薑爾 褻�� л熱 ��轎
			{
				OH1.OrderInfoShowlist(CH, PH);
				cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
				cout << "啗樓 ж衛溥賊 嬴鼠 璋濠高檜釭 殮溘ж撮蹂.";
				x = getNumber();												//嬴鼠 璋濠 殮溘
				system("cls");													//�飛� 瞪��
			}break;																// 詭檣詭景煎 犒敝
			case 3:																//輿僥 薑爾 匐儀 л熱 ��轎
			{
				OH1.OrderInfoSearchShow(CH, PH);
			}break;																// 詭檣詭景煎 犒敝
			case 4:																//輿僥 薑爾 餉薯 л熱 ��轎
			{
				OH1.OrderInfoRemove(CH, PH);
			}break;																// 詭檣詭景煎 犒敝
			case 5:																//輿僥 薑爾 滲唳 л熱 ��轎
			{
				OH1.OrderInfoEdit(CH, PH);
			}break;																// 詭檣詭景煎 犒敝
			case 6:
			{
				system("cls");													//�飛� 瞪��
			}break;																// 詭檣詭景煎 犒敝
			}
		}
	} while (flag == 0);
}

#endif // !_UI_H_