#ifndef _ORDERINFOHANDLER_H_
#define _ORDERINFOHANDLER_H_

#include <vector>
#include "OrderInfo.h"
#include "ClientHandler.h"
#include "ProductHandler.h"

class OrderInfoHandler //주문 정보 관리 기능 클래스
{
public:
	OrderInfoHandler(ClientHandler& CH, ProductHandler& PH); //생성자
	~OrderInfoHandler(); //소멸자
	void OrderInfoEnroll(); //주문정보 등록
	void OrderInfoSearchShow(ClientHandler&, ProductHandler&); //주문정보 검색, 제품 정보와 고객정보를 포함하여 인자 사용
	void OrderInfoShowlist(ClientHandler&, ProductHandler&); //주문정보 조회, 제품 정보와 고객정보를 포함하여 인자 사용
	void OrderInfoRemove(ClientHandler&, ProductHandler&); //주문정보 삭제, 제품 정보와 고객정보를 포함하여 인자 사용
	void OrderInfoEdit(ClientHandler&, ProductHandler&); //주문정보 변경, 제품 정보와 고객정보를 포함하여 인자 사용
	string getCName(string, ClientHandler&); // 주문정보 조회에서 고객 이름을 반환해주는 함수
	string getCAddress(string, ClientHandler&); // 주문정보 조회에서 고객 주소를 반환해주는 함수
	string getPName(int, ProductHandler&); // 주문정보 조회에서 제품명을 반환해주는 함수
	int getPPrice(int, ProductHandler&); // 주문정보 조회에서 제품 가격을 반환해주는 함수
	int MakeOrderCode(); // 주문코드(PK)를 생성하는 함수
	vector<string> parseOCSV(istream&, char); //생성자에서 파일 입력시 파일 데이터를 ,단위로 단어로 잘라라서 저장해주는 함수
	
private:
	vector<OrderInfo*> OrderInfoInfo; //주문 정보를 보관하는 vector 배열
	ClientHandler &CInfo; //주문정보에서 필요한 고객 정보를 가져오기 위한 고객정보
	ProductHandler &PInfo; //주문정보에서 필요한 제품 정보를 가져오기 위한 제품 정보
};

#endif // !_ORDERINFOHANDLER_H_
