#include "Client.h"

string Client::getName() const { return m_name; } //�� ���� ��ȯ
void Client::setName(string& name) //�� ���� �Է�
{
	m_name = name;
}

string Client::getBirthday() const { return m_birthday; } //�� ������� ��ȯ
void Client::setBirthday(string& birthday) //�� ������� �Է�
{
	m_birthday = birthday;
}

string Client::getPhoneNumber() const { return m_phoneNumber; } //�� ��ȭ��ȣ ��ȯ
void Client::setPhoneNumber(string& phoneNumber) //�� ��ȭ��ȣ �Է�
{
	m_phoneNumber = phoneNumber;
}

string Client::getAddress() const { return m_address; } //�� �ּ� ��ȯ
void Client::setAddress(string& address) //�� �ּ� �Է�
{
	m_address = address;
}

string Client::getEmailAddress() const { return m_emailAddress; } //�� �̸����ּ� ��ȯ
void Client::setEmailAddress(string& emailAddress) //�� �̸����ּ� �Է�
{
	m_emailAddress = emailAddress;
}

bool Client::operator==(string phoneNumber) const
{
	return (this->m_phoneNumber == phoneNumber);
}
// ==������ �����ε�, string ������ ��ȭ��ȣ�� ���Ͽ� ��ġ�ϴ� ���� �����ϵ��� �ϱ� ����