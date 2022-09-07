#ifndef _CLIENTHANDLER_H_
#define _CLIENTHANDLER_H_

#include <vector>
#include "Client.h"

class ClientHandler // �� ���� ���� ��� Ŭ����
{
public:
	ClientHandler(); //������
	~ClientHandler(); //�Ҹ���
	void ClientEnroll(); //�� ���� �Է�
	void ClientSearch(); //�� ���� �˻�
	void ClientShowlist(); //�� ���� ��ȸ
	void ClientRemove(); //�� ���� ����
	void ClientEdit(); //�� ���� ����
	Client* ClientInforeturn(string&); //���ڿ� ��ġ�ϴ� �� ������ ��� vector<Product*> ��ü 1�� ��ȯ
	bool HasCID(string key); //�ֹ����� Ŭ�������� �Է��ϴ� �� ��ȭ��ȣ�� �������� �ִ��� Ȯ�����ִ� �Լ�
	vector<string> parseCCSV(istream&, char); //�����ڿ��� ���� �Է½� ���� �����͸� ,������ �ܾ�� �߶�� �������ִ� �Լ�

private:
	vector<Client*> ClientInfo; //�� ������ �����ϴ� vector �迭
};

#endif // !_CLIENTHANDLER_H_
