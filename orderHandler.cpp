#include <sstream>
#include <fstream>
#include <iostream>
#include "OrderInfoHandler.h"

extern int getNumber();                                                         // 0~9까지의 숫자만 입력하는 함수
extern int getBnumber();                                                        // 가격이나 날짜 등 큰 숫자 입력 함수
using namespace std;

OrderInfoHandler::OrderInfoHandler(ClientHandler& CH, ProductHandler& PH) : CInfo(CH), PInfo(PH)    
{                                                                               //생성자
    ifstream file;                                                              //파일 출력 객체 생성
    file.open("orderinfoinfo.txt");                                             //입력파일 이름 지정 후 열기
    if (!file.fail())                                                           //파일 입력 실패에 대한 예외처리
    {
        while (!file.eof())                                                     // file의 끝까지 while문 반복
        {
            vector<string> row = parseOCSV(file, ',');                          //,단위로 구분된 file 데이터를 row에 저장
            if (row.size())                                                     //row에 저장된 데이터가 있다면
            {
                int oid = stoi(row[0]);                                          //string형 문자를 int 형식으로 바꿔서 넣어준다
                int odate = stoi(row[1]);                                        //string형 문자를 int 형식으로 바꿔서 넣어준다
                int onumber = stoi(row[2]);                                      //string형 문자를 int 형식으로 바꿔서 넣어준다
                int oPID = stoi(row[4]);                                         //string형 문자를 int 형식으로 바꿔서 넣어준다
                OrderInfo* o = new OrderInfo(oid, odate, onumber, row[3], oPID); //입력된 데이터를 OrderInfo 객체에 저장
                OrderInfoInfo.push_back(o);                                      //OrderInfo 객체에 저장된 정보를 주문정보를  
                                                                                 //관리하는 배열에 입력
            }
        }
    }
    cout << "orderinfoinfo.txt 출력 완료" << endl;
}

OrderInfoHandler::~OrderInfoHandler()                                             //소멸자
{
    ofstream file;                                                                //파일 출력 객체 생성
    file.open("orderinfoinfo.txt");                                               //출력 파일 이름 지정 후 열기
    if (!file.fail())                                                             //파일 출력 실패에 대한 예외처리
    {
        for (const auto& v : OrderInfoInfo)                                       //저장된 모든 주문정보에 대해 반복
        {
            OrderInfo* o = v;                                                     //OrderInfo 객체에 저장된 주문정보 대입
            file << o->getOrderCode() << ", " << o->getOrderDate() << ", ";       //주문코드와 주문일자를 ,단위로 잘라서 입력
            file << o->getOrderNumber() << ", ";                                  //주문수량을 , 단위로 잘라서 입력
            file << o->getCID() << ", " << o->getPID() << endl;                   //고객 전화번호와 제품ID를 ,단위로 잘라서 입력
        }
    }
    file.close();                                                                 //파일 닫기
}

void OrderInfoHandler::OrderInfoEnroll()                                          //주문 정보 등록
{
    int x;                                                                      //int 형태의 정보 입력을 받기 위한 변수
    string s;                                                                   //string 형태의 정보 입력을 받기 위한 변수
    OrderInfo* OrderInfoInfo1 = new OrderInfo;                                  //주문 정보 저장을 위한 OrderInfo* 형태의  
                                                                                //객체 선언 및 초기화
    int orderCode = MakeOrderCode();                                            //주문코드 생성 후 orderCode 변수에 저장
    OrderInfoInfo1->setOrderCode(orderCode);                                    //주문코드를 객체에 저장
    cout << "주문일자: ";
    x = getBnumber();                                                           //주문일자 입력
    OrderInfoInfo1->setOrderDate(x);                                            //주문일자를 객체에 저장
    cout << "주문수량: ";
    x = getBnumber();                                                           //주문수량 입력
    OrderInfoInfo1->setOrderNumber(x);                                          //주문 수량을 객체에 저장
    
    cout << "CID(종료: 9): ";
    do {                                                                        //고객 정보에 있는 고객 전화번호를 
                                                                                //입력할 때까지 반복
        cin >> s;                                                               //고객 전화번호를 입력
        if (s == "9")                                                           //고객전화번호를 모를 경우 9를 눌러 탈출
            break;
        else if (CInfo.HasCID(s))                                               //입력한 고객 전화번호가 고객 정보에 있을 경우
        {
            OrderInfoInfo1->setCID(s);                                          //고객 전화번호를 객체에 저장
            s.clear();                                                          //s를 재사용하기 위한 버퍼 비우기
            break;
        }
        else if(!CInfo.HasCID(s))                                               //입력한 고객 전화번호가 고객 정보에 없을 경우
            cout << "입력하신 CID는 등록되지 않은 CID입니다." << endl;
    } while (1);

    cout << "PID(종료: 9): ";
    do {                                                                        //제품 정보에 있는 제품ID를 
                                                                                //입력할 때까지 반복
    x = getBnumber();                                                           //제품ID를 입력
        if (9 == x)                                                             //제품ID를 모를 경우 9를 눌러 탈출
            break;
        else if (PInfo.HasPID(x))                                               //입력한 제품ID가 제품 정보에 있을 경우
        {
            OrderInfoInfo1->setPID(x);                                          //제품ID를 객체에 저장
            break;
        }
        else if (!PInfo.HasPID(x))                                              //입력한 제품ID가 제품 정보에 없을 경우
            cout << "입력하신 PID는 등록되지 않은 PID입니다." << endl;
    } while (1);
    OrderInfoInfo.push_back(OrderInfoInfo1);                                    //객체에 저장된 정보를 vector 배열에 저장

    cout << "───────────────────────────────────────────────────────────────" << endl;
    cout << "계속 하시려면 아무 숫자값이나 입력하세요.";
    x = getNumber();                                                            //아무 숫자 입력
    system("cls");                                                              //화면 전환
}

void OrderInfoHandler::OrderInfoSearchShow(ClientHandler& CH, ProductHandler &PH) // 모든 제품 정보 중 전화번호(PK)가 
                                                                                  // 일치하는 항목의 제품정보 출력
{
    int ordercode, n;                                                             //ordercode는 find_if를 실행하기 위한 인자
    string s;                                                                     // n과 s는 입력을 받기 위한 변수
    cout << "찾으시는 주문 코드를 입력하세요. ";
    ordercode = getBnumber();                                                     // 주문코드를 입력

    auto it = find_if(OrderInfoInfo.begin(), OrderInfoInfo.end(), [=](OrderInfo* O) //OrderInfoInfo에서 ordercode와
        { return (*O).getOrderCode() == ordercode; });                              //일치하는 객체인 it 변수 반환

    if (it != OrderInfoInfo.end())                                                  //it의 값이 end가 아니면
    {
        cout << "──────────────────────────────────────────────────────────" << endl;
        cout << "주문코드: " << (*it)->getOrderCode() << " / 주문일자: " << (*it)->getOrderDate() << endl
            << "고객성명: " << getCName((*it)->getCID(), CH) << " / 고객주소: " << getCAddress((*it)->getCID(), CH) << endl
            << "주문수량: " << (*it)->getOrderNumber() << " / 제품 가격: " << getPPrice((*it)->getPID(), PH)
            << " / 총 가격: " << (getPPrice((*it)->getPID(), PH)) * ((*it)->getOrderNumber()) << endl;
        cout << "──────────────────────────────────────────────────────────" << endl;
    }                                                                           //it 객체가 가진 주문코드, 주문일자, 주문수량,
                                                                                //고객 전화번호와 일치하는 고객성명, 고객주소
                                                                                //제품ID와 일치하는 제품가격, 총가격을 출력
    else                                                                        //it의 값이 가리키는 곳이 end라면
        cout << "일치하는 데이터가 없습니다." << endl;

    cout << "───────────────────────────────────────────────────────────────" << endl;
    cout << "계속 하시려면 아무 숫자값이나 입력하세요.";
    n = getNumber();                                                             //아무 숫자나 입력
    system("cls");                                                               //화면 전환
}

void OrderInfoHandler::OrderInfoShowlist(ClientHandler& CH,ProductHandler& PH)   //입력된 주문 제품 정보 출력
{
    int cnt = 0;                                                                 //데이터 행 출력을 위한 int형 변수 선언, 
                                                                                 //초기화
    if (OrderInfoInfo.empty() == false)                                          //주문 정보가 담긴 배열에 데이터가 존재할 경우
    {
        for (auto O : OrderInfoInfo)                                             //주문 정보에 담긴 데이터의 수만큼 반복
        {
            cout << "──────────────────────────────────────────────────────────" << endl;
            cout << "데이터 행: " << cnt++ << endl;
            cout << "주문코드: " << O->getOrderCode() << " / 주문일자: " << O->getOrderDate() << endl
                << "고객성명: " << getCName(O->getCID(), CH) << " / 고객주소: " << getCAddress(O->getCID(), CH) << endl
                << "주문수량: " << O->getOrderNumber() << " / 제품 가격: " << getPPrice(O->getPID(), PH)
                << " / 총 가격: " << (getPPrice(O->getPID(), PH)) * (O->getOrderNumber()) << endl;
            cout << "──────────────────────────────────────────────────────────" << endl;
        }                                                                       //it 객체가 가진 주문코드, 주문일자, 주문수량,
                                                                                //고객 전화번호와 일치하는 고객성명, 고객주소
                                                                                //제품ID와 일치하는 제품가격, 총가격을 출력
    }
    else                                                                        //it의 값이 가리키는 곳이 end라면
        cout << "등록된 데이터가 없습니다." << endl;
}

void OrderInfoHandler::OrderInfoRemove(ClientHandler& CH, ProductHandler& PH)   // 특정 주문 정보(행)을 제거
{
    int n;                                                                      // 메뉴 선택을 위한 int형 변수 선언
    if (OrderInfoInfo.empty() == false)                                         // 주문 정보가 담긴 배열에 데이터가 존재할 경우
    {
        OrderInfoShowlist(CInfo, PInfo);                                        // 현재 등록된 주문 목록을 보여줌
       cout << "삭제할 데이터 행을 입력하세요.";
        n = getBnumber();                                                       // 삭제할 데이터 행 번호 입력
       
        if (n >= OrderInfoInfo.size() || n < 0)                                 // 입력된 행에 데이터가 없을 경우 
            cout << "입력된 행에 데이터가 없습니다." << endl;
        else                                                                    // 입력한 행에 주문 정보가 담긴 배열의 
        {                                                                       // 데이터가 있을 경우
            OrderInfoInfo.erase(OrderInfoInfo.begin() + n);                     // 입력한 행의 데이터 전체 삭제
            cout << "삭제가 완료되었습니다." << endl;
        }
    }
    else                                                                        // 제품정보가 담긴 배열에 데이터가 없는 경우
        cout << "등록된 데이터가 없습니다." << endl;

    cout << "───────────────────────────────────────────────────────────────" << endl;
    cout << "계속 하시려면 아무 숫자값이나 입력하세요.";
    n = getNumber();                                                            //아무 숫자나 입력
    system("cls");                                                              //화면 전환
}

void OrderInfoHandler::OrderInfoEdit(ClientHandler& CH, ProductHandler& PH)     // 특정 주문정보(행)의 특정 항목(열) 값을 변경
{
    int m, n, x;                                                                // 변경될 int형 행과 열 값을 입력받는 변수
    string s;                                                                   // 변경될 string 형 입력값을 받는 변수
    if (OrderInfoInfo.empty() == false)                                         // 주문 정보가 담긴 배열에 데이터가 존재할 경우
    {
        OrderInfoShowlist(CInfo, PInfo);                                        // 현재 등록된 주문 목록을 보여줌
        cout << "──────────────────────────────────────────────────────────" << endl;
        cout << "변경할 데이터 행을 입력하세요.";
        do {                                                                    // 변경될 데이터가 있는 행을 입력할 때까지 반복
            n = getBnumber();                                                   // 변경할 데이터 행 입력
            if (n >= OrderInfoInfo.size() || n < 0)                             // 입력된 행 값이 배열 범위에 없을 경우
                cout << "입력된 행에 데이터가 없습니다. 다시 입력하세요" << endl;
        } while (n >= OrderInfoInfo.size() || n < 0);

        cout << "──────────────────────────────────────────────────────────" << endl;
        cout << "변경할 데이터 열을 입력하세요.";
        cout << "1: 주문 일자 / 2: 주문 수량" << endl;
        do {
            m = getNumber();                                                   // 변경할 데이터 열 입력
            if (m > 2 || m < 1)                                                // 입력된 열 값이 배열 범위에 없을 경우
                cout << "잘못된 숫자입니다. 다시 입력하세요." << endl;
        } while (m > 2 || m < 1);
        cout << "\n──────────────────────────────────────────────────────────" << endl;
        cout << "변경할 데이터 내용을 입력하세요.";

        switch (m)
        {
        case 1:                                                                 //주문 일자를 변경하는 경우
            {
                x = getBnumber();                                               //변경할 주문일자 입력
                OrderInfoInfo[n]->setOrderDate(x);                              //선택된 행의 주문 일자를 입력된 값으로 변경
            }break;
        case 2:                                                                 //주문 수량을 변경하는 경우
            {
                x = getBnumber();                                               //변경할 주문 수량 변경
                OrderInfoInfo[n]->setOrderNumber(x);                            //선택된 행의 주문 수량을 입력된 값으로 변경
            }break;
        }
        cout << "──────────────────────────────────────────────────────────" << endl;
        cout << "데이터 변경이 완료되었습니다." << endl;
        cout << "──────────────────────────────────────────────────────────" << endl;
    }
    else                                                                       // 주문 정보가 담긴 배열에 데이터가 없을 경우
        cout << "등록된 데이터가 없습니다." << endl;

    cout << "───────────────────────────────────────────────────────────────" << endl;
    cout << "계속 하시려면 아무 숫자값이나 입력하세요.";
    x = getNumber();                                                           //아무 숫자 입력
    system("cls");                                                             //화면 전환
}

string OrderInfoHandler::getCName(string phoneNumber, ClientHandler& CH)       // 고객PK를 활용해 고객 성명 추출
{
    string Cname = CInfo.ClientInforeturn(phoneNumber)->getName();
    return Cname;
}

string OrderInfoHandler::getCAddress(string phoneNumber, ClientHandler& CH)     // 고객PK를 활용해 고객 주소 추출
{
    string CAdress = CInfo.ClientInforeturn(phoneNumber)->getAddress();
    return CAdress;
}

string OrderInfoHandler::getPName(int productID, ProductHandler &PH)            // 제품PK를 활용해 제품명 추출
{
    string Pname = PInfo.ProductInfoReturn(productID)->getProductName();
    return Pname;
}

int OrderInfoHandler::getPPrice(int productID, ProductHandler& PH)              // 제품PK를 활용해 제품 가격 추출
{
   int price = PInfo.ProductInfoReturn(productID)->getProductPrice();
   return price;
}

int OrderInfoHandler::MakeOrderCode()                                           // 주문코드를 자동 생성하는 함수
{
    int ret = -1;                                                               // int형 반환 값을 -1로 초기화
    if (OrderInfoInfo.size() == 0)                                              // 현재 등록된 주문 정보가 없으면
        ret = 100000;                                                           // 주문 정보에 100000을 입력해서 반환
    else if (OrderInfoInfo.size() > 0)                                          // 이미 등록된 주문 정보가 있으면
    {
        ret = (*OrderInfoInfo.rbegin())->getOrderCode();                        //주문정보의 마지막에 있는 주문코드 ret에 대입
        ++ret;                                                                  //ret에 1을 더해서 반환
    }
    return ret;                                                                 //이 모든 경우가 아니라면 -1로 반환
}


vector<string> OrderInfoHandler::parseOCSV(istream& file, char delimiter)       // 생성자에서 입력된 파일 데이터를 ,단위로
{                                                                               // 단어를 읽어오기 위한 함수
    stringstream ss;                                                            // 파일 데이터를 띄어 쓰기 단위로 나누고 
                                                                                // 저장한 값을 저장하는 변수 ss 
    vector<string> row;                                                         // 완성된 단어를 저장하기 위한 vector형 변수 row
    string t = " \n\r\t";                                                       // 단어 완성지점을 구분하기 위한 경계값 t

    while (!file.eof())                                                         // 파일의 끝까지 while문을 반복
    {
        char c = file.get();                                                    // 파일의 데이터를 한글자씩 c에 담음
        if (c == delimiter || c == '\r' || c == '\n')                           // c에 입력된 글자가 개행이나 ,인 경우
        {
            if (file.peek() == '\n') file.get();                                // 다음 문자가 줄바꿈이면 서식화되지 
                                                                                // 않은 데이터를 가져온다. 
            string s = ss.str();                                                // 읽어온 문자열을 s에 담는다
            s.erase(0, s.find_first_not_of(t));                                 // find_first_not_of(문자열): 지정된 문자열과 
                                                                                // 일치하지 않는 첫번째 값을 검색 후
                                                                                // 일치하지 않는 값을 삭제
            s.erase(s.find_last_not_of(t) + 1);                                 // t의 바로 뒷 지점까지 삭제 => NULL문자 삭제
            row.push_back(s);                                               // 남은 문자열을 row에 저장(개별 데이터 완성) 
            ss.str("");                                                         // 변수 ss 초기화
            if (c != delimiter) break;                                          // c 값이 ,가 아닌 경우 탈출
        }
        else                                                                    // c에 입력된 글자가 개행이나 ,가 아닌 경우
        {
            ss << c;                                                            // ss에 c문자 저장
        }
    }
    return row;                                                                 // row에 저장된 vector 반환
}