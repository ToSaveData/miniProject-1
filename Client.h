#ifndef _CLIENT_H_ 
#define	_CLIENT_H_

#include <iostream>
using namespace std;

class Client //�� ������ ��Ҹ� �����ϴ� Ŭ����
{
public:// �ּҸ� ���������ν� �޸� ����� ���̰� �ӵ��� ������ �ϱ� ���� ���۷��� ������ ���ڷ� ���
	Client(string name = "", string birthday = "", string phoneNumber = "", string address = "", string emailAddress = "")
		: m_name(name), m_birthday(birthday), m_phoneNumber(phoneNumber), m_address(address), m_emailAddress(emailAddress) {}
	//������
	string getName() const; //�� ���� ��ȯ
	void setName(string&); //�� ���� �Է�
	string getBirthday() const; //�� ������� ��ȯ
	void setBirthday(string&); //�� ������� �Է�
	string getPhoneNumber() const; //�� ��ȭ��ȣ ��ȯ
	void setPhoneNumber(string&); //�� ��ȭ��ȣ �Է�
	string getAddress() const; //�� �ּ� ��ȯ
	void setAddress(string&); //�� �ּ� �Է�
	string getEmailAddress() const; //�� �̸����ּ� ��ȯ
	void setEmailAddress(string&); //�� �̸����ּ� �Է�
	bool operator==(string phoneNumber) const; 
	// ==������ �����ε�, string ������ ��ȭ��ȣ�� ���Ͽ� ��ġ�ϴ� ���� �����ϵ��� �ϱ� ����

private:
	string m_name; //�� ����
	string m_birthday; //�� �������
	string m_phoneNumber; //�� ��ȭ��ȣ, PK
	string m_address; //�� �ּ�
	string m_emailAddress; //�� �̸����ּ�
};

#endif // !_CLIENT_H_
