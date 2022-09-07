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
extern int getNumber();                                                         //0~9±îÁöÀÇ ¼ýÀÚ¸¸ ÀÔ·ÂÇÏ´Â ÇÔ¼ö

void start()																	//½ÃÀÛ È­¸éÀÇ ÀÎÅÍÆäÀÌ½º¸¦ Ãâ·ÂÇÏ´Â ÇÔ¼ö
{
	cout << endl;
	cout << "****************************************************************" << endl;
	cout << "*                      »óÇ° °ü¸® ÇÁ·Î±×·¥" << "                      *" << endl;
	cout << "*                      1. °í°´ Á¤º¸ °ü¸®" << "                       *" << endl;
	cout << "*                      2. »óÇ° Á¤º¸ °ü¸®" << "                       *" << endl;
	cout << "*                      3. ÁÖ¹® Á¤º¸ °ü¸®" << "                       *" << endl;
	cout << "*                      4. ÇÁ·Î±×·¥ Á¾·á" << "                        *" << endl;
	cout << "****************************************************************" << endl;
	cout << endl;
}

void firstQuestion(int &n)														//Ã¹ ÀÔ·ÂÀ» ¿äÃ»ÇÏ°í ÀÔ·Â¹Þ´Â ÇÔ¼ö
{
	cout << "¹øÈ£¸¦ ÀÔ·ÂÇÏ¼¼¿ä." << endl;
	n = getNumber();															//ÀÎÀÚ i¿¡ ¹øÈ£ ÀÔ·Â
}

void ClientQ(ClientHandler& CH)													//°í°´ Á¤º¸ °ü¸® ±â´ÉÀ» ±¸ÇöÇÑ ÇÔ¼ö
{
	int m = 0 , n = 0;															//intÇü ÀÔ·ÂÀ» ¹Þ±â À§ÇÑ º¯¼ö
	int flag = 0;																//while¹®ÀÇ Å»ÃâÀ» À§ÇÑ º¯¼ö
	
	do {																		//¸Þ´º¿¡ ÀÖ´Â ¹øÈ£¸¦ ÀÔ·ÂÇÒ ¶§±îÁö ¹Ýº¹
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		cout << "1. °í°´ Á¤º¸ µî·Ï / 2. °í°´ ¸ñ·Ï Á¶È¸ / 3. °í°´ Á¤º¸ °Ë»ö " << endl;
		cout << "4. °í°´ Á¤º¸ »èÁ¦ / 5. °í°´ Á¤º¸ º¯°æ / 6. µÚ·Î °¡±â" << endl;
		cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
		m = getNumber();														//¹øÈ£ ÀÔ·Â
		if (m < 1 || m > 6)														//Àß¸øµÈ ¹øÈ£ ÀÔ·Â½Ã
			cout << "Àß¸øµÈ ¹øÈ£ÀÔ´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä." << endl;
		else		
		{
			flag = 1;															//do...while¹® Å»ÃâÁ¶°ÇÀ¸·Î º¯°æ
			switch (m)															//¹øÈ£ ÀÔ·Â¿¡ µû¸¥ ¸Þ´º ¼±ÅÃ
			{
			case 1:																//°í°´ Á¤º¸ µî·Ï ÇÔ¼ö È£Ãâ
				{
					CH.ClientEnroll();
				}break;															// ¸ÞÀÎ¸Þ´º·Î º¹±Í
			case 2:																//°í°´ Á¤º¸ Á¶È¸ ÇÔ¼ö È£Ãâ
				{
					CH.ClientShowlist();
					cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
					cout << "°è¼Ó ÇÏ½Ã·Á¸é ¾Æ¹« ¼ýÀÚ°ªÀÌ³ª ÀÔ·ÂÇÏ¼¼¿ä.";
					n = getNumber();											//¾Æ¹« ¼ýÀÚ ÀÔ·Â
					system("cls");												//È­¸é ÀüÈ¯
				}break;															// ¸ÞÀÎ¸Þ´º·Î º¹±Í
			case 3:																//°í°´ Á¤º¸ °Ë»ö ÇÔ¼ö È£Ãâ
				{
					CH.ClientSearch();
				}break;															// ¸ÞÀÎ¸Þ´º·Î º¹±Í
			case 4:																//°í°´ Á¤º¸ »èÁ¦ ÇÔ¼ö È£Ãâ
				{
					CH.ClientRemove();
				}break;															// ¸ÞÀÎ¸Þ´º·Î º¹±Í
			case 5:																//°í°´ Á¤º¸ º¯°æ ÇÔ¼ö È£Ãâ
				{
					CH.ClientEdit();
				}break;															// ¸ÞÀÎ¸Þ´º·Î º¹±Í
			case 6: 
				{
					system("cls");												//È­¸é ÀüÈ¯
				}break;															// ¸ÞÀÎ¸Þ´º·Î º¹±Í
			}
		}
	} while (flag == 0);
}

void ProductQ(ProductHandler& PH)												//Á¦Ç° Á¤º¸ °ü¸® ±â´ÉÀ» ±¸ÇöÇÑ ÇÔ¼ö
{
	int x = 0,m = 0, flag = 0;													//intÇü ÀÔ·Â º¯¼öµé°ú while¹® Å»Ãâ¿ë º¯¼ö flag
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << "1. Á¦Ç° Á¤º¸ µî·Ï / 2. Á¦Ç° ¸ñ·Ï Á¶È¸ / 3. Á¦Ç° Á¤º¸ °Ë»ö " << endl;
	cout << "4. Á¦Ç° Á¤º¸ »èÁ¦ / 5. Á¦Ç° Á¤º¸ º¯°æ / 6. µÚ·Î °¡±â" << endl;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	do{																			//¸Þ´º¿¡ ÀÖ´Â ¹øÈ£¸¦ ÀÔ·ÂÇÒ ¶§±îÁö ¹Ýº¹
		m = getNumber();														//¹øÈ£ ÀÔ·Â
	if(m < 1 || m > 6)															//Àß¸øµÈ ¹øÈ£ ÀÔ·Â½Ã
		cout << "Àß¸øµÈ ¹øÈ£ÀÔ´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä." << endl;
	else{
		flag = 1;																//do...while¹® Å»ÃâÁ¶°ÇÀ¸·Î º¯°æ
		switch (m)																//¹øÈ£ ÀÔ·Â¿¡ µû¸¥ ¸Þ´º ¼±ÅÃ
		{
		case 1:																	//Á¦Ç° Á¤º¸ µî·Ï ÇÔ¼ö È£Ãâ
			{
				PH.productEnroll();
			}break;																// ¸ÞÀÎ¸Þ´º·Î º¹±Í
		case 2:																	//Á¦Ç° Á¤º¸ Á¶È¸ ÇÔ¼ö È£Ãâ
			{
				PH.productShowlist();
				cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
				cout << "°è¼Ó ÇÏ½Ã·Á¸é ¾Æ¹« ¼ýÀÚ°ªÀÌ³ª ÀÔ·ÂÇÏ¼¼¿ä.";
				x = getNumber();												//¾Æ¹« ¼ýÀÚ ÀÔ·Â
				system("cls");													//È­¸é ÀüÈ¯
			}break;																// ¸ÞÀÎ¸Þ´º·Î º¹±Í
		case 3:																	//Á¦Ç° Á¤º¸ °Ë»ö ÇÔ¼ö È£Ãâ
			{
				PH.productSearch();
			}break;																// ¸ÞÀÎ¸Þ´º·Î º¹±Í
		case 4:																	//Á¦Ç° Á¤º¸ »èÁ¦ ÇÔ¼ö È£Ãâ
			{
				PH.productRemove();
			}break;																// ¸ÞÀÎ¸Þ´º·Î º¹±Í
		case 5:																	//Á¦Ç° Á¤º¸ º¯°æ ÇÔ¼ö È£Ãâ
			{
				PH.productEdit();
			}break;																// ¸ÞÀÎ¸Þ´º·Î º¹±Í
		case 6:																	//Á¦Ç° Á¤º¸ µî·Ï ÇÔ¼ö È£Ãâ		
			{
				system("cls");													//È­¸é ÀüÈ¯
			}break;																// ¸ÞÀÎ¸Þ´º·Î º¹±Í
		}
	}
	} while (flag == 0);
}

void OrderInfoQ(ClientHandler& CH, ProductHandler& PH, OrderInfoHandler& OH1)   //ÁÖ¹® Á¤º¸ °ü¸® ±â´ÉÀ» ±¸ÇöÇÑ ÇÔ¼ö
{
	int x = 0, m = 0, flag = 0;													//intÇü ÀÔ·Â º¯¼öµé°ú while¹® Å»Ãâ¿ë º¯¼ö flag
	cout << endl;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	cout << "1. ÁÖ¹® Á¤º¸ µî·Ï / 2. ÁÖ¹® ¸ñ·Ï Á¶È¸ / 3. ÁÖ¹® Á¤º¸ °Ë»ö " << endl;
	cout << "4. ÁÖ¹® Á¤º¸ »èÁ¦ / 5. ÁÖ¹® Á¤º¸ º¯°æ / 6. µÚ·Î °¡±â" << endl;
	cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
	do {																		//¸Þ´º¿¡ ÀÖ´Â ¹øÈ£¸¦ ÀÔ·ÂÇÒ ¶§±îÁö ¹Ýº¹
		m = getNumber();														//¹øÈ£ ÀÔ·Â
		if (m < 1 || m > 6)														//Àß¸øµÈ ¹øÈ£ ÀÔ·Â½Ã
			cout << "Àß¸øµÈ ¹øÈ£ÀÔ´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä." << endl;
		else {
			flag = 1;															//do...while¹® Å»ÃâÁ¶°ÇÀ¸·Î º¯°æ
			switch (m)															//¹øÈ£ ÀÔ·Â¿¡ µû¸¥ ¸Þ´º ¼±ÅÃ
			{
			case 1:																//ÁÖ¹® Á¤º¸ µî·Ï ÇÔ¼ö È£Ãâ
			{
				OH1.OrderInfoEnroll();
			}break;																// ¸ÞÀÎ¸Þ´º·Î º¹±Í
			case 2:																//ÁÖ¹® Á¤º¸ Á¶È¸ ÇÔ¼ö È£Ãâ
			{
				OH1.OrderInfoShowlist(CH, PH);
				cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
				cout << "°è¼Ó ÇÏ½Ã·Á¸é ¾Æ¹« ¼ýÀÚ°ªÀÌ³ª ÀÔ·ÂÇÏ¼¼¿ä.";
				x = getNumber();												//¾Æ¹« ¼ýÀÚ ÀÔ·Â
				system("cls");													//È­¸é ÀüÈ¯
			}break;																// ¸ÞÀÎ¸Þ´º·Î º¹±Í
			case 3:																//ÁÖ¹® Á¤º¸ °Ë»ö ÇÔ¼ö È£Ãâ
			{
				OH1.OrderInfoSearchShow(CH, PH);
			}break;																// ¸ÞÀÎ¸Þ´º·Î º¹±Í
			case 4:																//ÁÖ¹® Á¤º¸ »èÁ¦ ÇÔ¼ö È£Ãâ
			{
				OH1.OrderInfoRemove(CH, PH);
			}break;																// ¸ÞÀÎ¸Þ´º·Î º¹±Í
			case 5:																//ÁÖ¹® Á¤º¸ º¯°æ ÇÔ¼ö È£Ãâ
			{
				OH1.OrderInfoEdit(CH, PH);
			}break;																// ¸ÞÀÎ¸Þ´º·Î º¹±Í
			case 6:
			{
				system("cls");													//È­¸é ÀüÈ¯
			}break;																// ¸ÞÀÎ¸Þ´º·Î º¹±Í
			}
		}
	} while (flag == 0);
}

#endif // !_UI_H_