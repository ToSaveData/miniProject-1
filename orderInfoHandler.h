#ifndef _ORDERINFOHANDLER_H_
#define _ORDERINFOHANDLER_H_

#include <vector>
#include "OrderInfo.h"
#include "ClientHandler.h"
#include "ProductHandler.h"

class OrderInfoHandler //�ֹ� ���� ���� ��� Ŭ����
{
public:
	OrderInfoHandler(ClientHandler& CH, ProductHandler& PH); //������
	~OrderInfoHandler(); //�Ҹ���
	void OrderInfoEnroll(); //�ֹ����� ���
	void OrderInfoSearchShow(ClientHandler&, ProductHandler&); //�ֹ����� �˻�, ��ǰ ������ �������� �����Ͽ� ���� ���
	void OrderInfoShowlist(ClientHandler&, ProductHandler&); //�ֹ����� ��ȸ, ��ǰ ������ �������� �����Ͽ� ���� ���
	void OrderInfoRemove(ClientHandler&, ProductHandler&); //�ֹ����� ����, ��ǰ ������ �������� �����Ͽ� ���� ���
	void OrderInfoEdit(ClientHandler&, ProductHandler&); //�ֹ����� ����, ��ǰ ������ �������� �����Ͽ� ���� ���
	string getCName(string, ClientHandler&); // �ֹ����� ��ȸ���� �� �̸��� ��ȯ���ִ� �Լ�
	string getCAddress(string, ClientHandler&); // �ֹ����� ��ȸ���� �� �ּҸ� ��ȯ���ִ� �Լ�
	string getPName(int, ProductHandler&); // �ֹ����� ��ȸ���� ��ǰ���� ��ȯ���ִ� �Լ�
	int getPPrice(int, ProductHandler&); // �ֹ����� ��ȸ���� ��ǰ ������ ��ȯ���ִ� �Լ�
	int MakeOrderCode(); // �ֹ��ڵ�(PK)�� �����ϴ� �Լ�
	vector<string> parseOCSV(istream&, char); //�����ڿ��� ���� �Է½� ���� �����͸� ,������ �ܾ�� �߶�� �������ִ� �Լ�
	
private:
	vector<OrderInfo*> OrderInfoInfo; //�ֹ� ������ �����ϴ� vector �迭
	ClientHandler &CInfo; //�ֹ��������� �ʿ��� �� ������ �������� ���� ������
	ProductHandler &PInfo; //�ֹ��������� �ʿ��� ��ǰ ������ �������� ���� ��ǰ ����
};

#endif // !_ORDERINFOHANDLER_H_
