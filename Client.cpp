#include "Client.h"

string Client::getName() const { return m_name; }
void Client::setName(string& name)
{
	m_name = name;
}

string Client::getBirthday() const { return m_birthday; }
void Client::setBirthday(string& birthday)
{
	m_birthday = birthday;
}

string Client::getPhoneNumber() const { return m_phoneNumber; }
void Client::setPhoneNumber(string& phoneNumber)
{
	m_phoneNumber = phoneNumber;
}

string Client::getAddress() const { return m_address; }
void Client::setAddress(string& address)
{
	m_address = address;
}

string Client::getEmailAddress() const { return m_emailAddress; }
void Client::setEmailAddress(string& emailAddress)
{
	m_emailAddress = emailAddress;
}

bool Client::operator==(string phoneNumber) const // ==연산자 오버로딩, 문자열 형식의 전화번호를 비교하여 일치하는 값을 도출하도록 하기 위함
{
	return (this->m_phoneNumber == phoneNumber);
}