#pragma once
#ifndef _CLIENT_H_ //�� ���� ���ǵǵ��� �ϱ� ����
#define	_CLIENT_H_

#include <iostream>
using namespace std;

class Client
{
public:
	Client(string name = "", string birthday = "", string phoneNumber = "", string address = "", string emailAddress = "")
		: m_name(name), m_birthday(birthday), m_phoneNumber(phoneNumber), m_address(address), m_emailAddress(emailAddress) {}
	string getName() const;
	void setName(string&); // �ּҸ� ���������ν� �޸� ����� ���̰� �ӵ��� ������ �ϱ� ����
	string getBirthday() const;
	void setBirthday(string&);
	string getPhoneNumber() const;
	void setPhoneNumber(string&);
	string getAddress() const;
	void setAddress(string&);
	string getEmailAddress() const;
	void setEmailAddress(string&);
	bool operator==(string phoneNumber) const;


private:
	string m_name;
	string m_birthday;
	string m_phoneNumber; //PK
	string m_address;
	string m_emailAddress;
};

#endif // !_CLIENT_H_ (Ŭ���̾�Ʈ ����� ���������� �˷��ֱ� ���� �ּ���)
