#ifndef _CLIENTHANDLER_H_
#define _CLIENTHANDLER_H_

#include <vector>
#include "Client.h"

class ClientHandler // 고객 정보 관리 기능 클래스
{
public:
	ClientHandler(); //생성자
	~ClientHandler(); //소멸자
	void ClientEnroll(); //고객 정보 입력
	void ClientSearch(); //고객 정보 검색
	void ClientShowlist(); //고객 정보 조회
	void ClientRemove(); //고객 정보 삭제
	void ClientEdit(); //고객 정보 수정
	Client* ClientInforeturn(string&); //인자와 일치하는 고객 정보가 담긴 vector<Product*> 객체 1개 반환
	bool HasCID(string key); //주문정보 클래스에서 입력하는 고객 전화번호가 고객정보에 있는지 확인해주는 함수
	vector<string> parseCCSV(istream&, char); //생성자에서 파일 입력시 파일 데이터를 ,단위로 단어로 잘라라서 저장해주는 함수

private:
	vector<Client*> ClientInfo; //고객 정보를 보관하는 vector 배열
};

#endif // !_CLIENTHANDLER_H_
