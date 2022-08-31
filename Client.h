#pragma once
#ifndef _CLIENT_H_ //한 번만 정의되도록 하기 위함
#define	_CLIENT_H_

#include <iostream>
using namespace std;

class Client
{
public:
	Client(string name = "", string birthday = "", string phoneNumber = "", string address = "", string emailAddress = "")
		: m_name(name), m_birthday(birthday), m_phoneNumber(phoneNumber), m_address(address), m_emailAddress(emailAddress) {}
	string getName() const;
	void setName(string&); // 주소만 복사함으로써 메모리 사용을 줄이고 속도를 빠르게 하기 위함
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

#endif // !_CLIENT_H_ (클라이언트 헤드의 마지막임을 알려주기 위한 주석임)
