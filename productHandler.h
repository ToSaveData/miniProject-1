#ifndef _PRODUCTHANDLER_H_
#define _PRODUCTHANDLER_H_

#include <vector>
#include "Product.h"

class ProductHandler //제품 정보 관리 기능 클래스
{
public:
	ProductHandler(); //생성자
	~ProductHandler(); //소멸자
	void productEnroll(); //제품 정보 등록
	void productSearch(); //제품 정보 검색
	void productShowlist(); //제품 정보 조회
	void productRemove(); //제품 정보 삭제
	void productEdit(); //제품 정보 수정
	Product* ProductInfoReturn(int&); //인자와 일치하는 고객 정보가 담긴 vector<Product*> 객체 1개 반환
	int makeProductID(); //제품 정보 등록
	bool HasPID(int&); //주문정보 클래스에서 입력하는 제품ID가 제품 정보에 있는지 확인해주는 함수
	vector<string> parsePCSV(istream&, char); //생성자에서 파일 입력시 파일 데이터를 ,단위로 단어로 잘라라서 저장해주는 함수

private:
	vector<Product*> ProductInfo; //제품 정보를 보관하는 vector 배열
};

#endif // !_PRODUCTHANDLER_H_
