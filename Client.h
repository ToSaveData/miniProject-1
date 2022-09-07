#ifndef _CLIENT_H_ 
#define	_CLIENT_H_

#include <iostream>
using namespace std;

class Client //고객 정보의 요소를 소유하는 클래스
{
public:// 주소만 복사함으로써 메모리 사용을 줄이고 속도를 빠르게 하기 위해 레퍼런스 변수를 인자로 사용
	Client(string name = "", string birthday = "", string phoneNumber = "", string address = "", string emailAddress = "")
		: m_name(name), m_birthday(birthday), m_phoneNumber(phoneNumber), m_address(address), m_emailAddress(emailAddress) {}
	//생성자
	string getName() const; //고객 성명 반환
	void setName(string&); //고객 성명 입력
	string getBirthday() const; //고객 생년월일 반환
	void setBirthday(string&); //고객 생년월일 입력
	string getPhoneNumber() const; //고객 전화번호 반환
	void setPhoneNumber(string&); //고객 전화번호 입력
	string getAddress() const; //고객 주소 반환
	void setAddress(string&); //고객 주소 입력
	string getEmailAddress() const; //고객 이메일주소 반환
	void setEmailAddress(string&); //고객 이메일주소 입력
	bool operator==(string phoneNumber) const; 
	// ==연산자 오버로딩, string 형식의 전화번호를 비교하여 일치하는 값을 도출하도록 하기 위함

private:
	string m_name; //고객 성명
	string m_birthday; //고객 생년월일
	string m_phoneNumber; //고객 전화번호, PK
	string m_address; //고객 주소
	string m_emailAddress; //고객 이메일주소
};

#endif // !_CLIENT_H_
