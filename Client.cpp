#include "Client.h"

string Client::getName() const { return m_name; }
void Client::setName(string& name)
{
	m_name = name;
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
void Client::setEamilAddress(string& emailAddress)
{
	m_emailAddress = emailAddress;
}