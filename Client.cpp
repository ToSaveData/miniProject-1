#include "Client.h"

string Client::getName() const { return m_name; } //고객 성명 반환
void Client::setName(string& name) //고객 성명 입력
{
	m_name = name;
}

string Client::getBirthday() const { return m_birthday; } //고객 생년월일 반환
void Client::setBirthday(string& birthday) //고객 생년월일 입력
{
	m_birthday = birthday;
}

string Client::getPhoneNumber() const { return m_phoneNumber; } //고객 전화번호 반환
void Client::setPhoneNumber(string& phoneNumber) //고객 전화번호 입력
{
	m_phoneNumber = phoneNumber;
}

string Client::getAddress() const { return m_address; } //고객 주소 반환
void Client::setAddress(string& address) //고객 주소 입력
{
	m_address = address;
}

string Client::getEmailAddress() const { return m_emailAddress; } //고객 이메일주소 반환
void Client::setEmailAddress(string& emailAddress) //고객 이메일주소 입력
{
	m_emailAddress = emailAddress;
}

bool Client::operator==(string phoneNumber) const
{
	return (this->m_phoneNumber == phoneNumber);
}
// ==연산자 오버로딩, string 형식의 전화번호를 비교하여 일치하는 값을 도출하도록 하기 위함