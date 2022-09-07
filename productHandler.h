#ifndef _PRODUCTHANDLER_H_
#define _PRODUCTHANDLER_H_

#include <vector>
#include "Product.h"

class ProductHandler //��ǰ ���� ���� ��� Ŭ����
{
public:
	ProductHandler(); //������
	~ProductHandler(); //�Ҹ���
	void productEnroll(); //��ǰ ���� ���
	void productSearch(); //��ǰ ���� �˻�
	void productShowlist(); //��ǰ ���� ��ȸ
	void productRemove(); //��ǰ ���� ����
	void productEdit(); //��ǰ ���� ����
	Product* ProductInfoReturn(int&); //���ڿ� ��ġ�ϴ� �� ������ ��� vector<Product*> ��ü 1�� ��ȯ
	int makeProductID(); //��ǰ ���� ���
	bool HasPID(int&); //�ֹ����� Ŭ�������� �Է��ϴ� ��ǰID�� ��ǰ ������ �ִ��� Ȯ�����ִ� �Լ�
	vector<string> parsePCSV(istream&, char); //�����ڿ��� ���� �Է½� ���� �����͸� ,������ �ܾ�� �߶�� �������ִ� �Լ�

private:
	vector<Product*> ProductInfo; //��ǰ ������ �����ϴ� vector �迭
};

#endif // !_PRODUCTHANDLER_H_
