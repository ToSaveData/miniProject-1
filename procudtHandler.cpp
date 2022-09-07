#include <sstream>
#include <fstream>
#include "ProductHandler.h"

extern int getNumber();                                                         // 0~9까지의 숫자만 입력하는 함수
extern int getBnumber();                                                        // 가격이나 날짜 등 큰 숫자 입력 함수

ProductHandler::ProductHandler()                                                // 생성자
{
    ifstream file;                                                              //파일 출력 객체 생성
    file.open("productinfo.txt");                                               //입력파일 이름 지정 후 열기
    if (!file.fail())                                                           //파일 입력 실패에 대한 예외처리
    {
        while (!file.eof())                                                     // file의 끝까지 while문 반복
        { 
            vector<string> row = parsePCSV(file, ',');                          //,단위로 구분된 file 데이터를 row에 저장
            if (row.size())                                                     //row에 저장된 데이터가 있다면
            {
                int pid = stoi(row[0]);                                         //string형 문자를 int 형식으로 바꿔서 넣어준다
                int pprice = stoi(row[2]);                                  
                Product* p = new Product(pid, row[1], pprice, row[3]);          //입력된 데이터를 Product 객체에 저장
                ProductInfo.push_back(p);                                       //Product 객체에 저장된 정보를 제품정보를  
                                                                                //관리하는 배열에 입력
            }
        }
    }
    cout << "productinfo.txt 출력 완료" << endl;
}

ProductHandler::~ProductHandler()                                               // 소멸자
{
    ofstream file;                                                              //파일 출력 객체 생성
    file.open("productinfo.txt");                                               //출력 파일 이름 지정 후 열기
    if (!file.fail())                                                           //파일 출력 실패에 대한 예외처리
    {
        for (const auto& v : ProductInfo)                                       //저장된 모든 제품정보에 대해 반복
        {
            Product* p = v;                                                     //Product 객체에 저장된 제품정보 대입
            file << p->getProductID() << ", " << p->getProductName() << ", ";   //제품ID와 제품명을 ,단위로 잘라서 입력
            file << p->getProductPrice() << ", ";                               //제품 가격을 , 단위로 잘라서 입력
            file << p->getProductSort() << endl;                                //제품 종류를 , 단위로 잘라서 입력
        }
    }
    file.close();                                                               //파일 닫기
}

void ProductHandler::productEnroll()                                            //제품 정보 등록
{
    int x;                                                                      //int 형태의 정보 입력을 받기 위한 변수
    string s;                                                                   //string 형태의 정보 입력을 받기 위한 변수
    Product* PInfo1 = new Product;                                              //제품 정보 저장을 위한 Product* 형태의  
                                                                                //객체 선언 및 초기화
    int productID = makeProductID();                                            //제품ID 생성 후 productID 변수에 저장
    PInfo1->setProductID(productID);                                            //제품 ID를 객체에 저장
    cout << "제품명: ";                                                         
    cin >> s;                                                                   //제품명 입력
    PInfo1->setProductName(s);                                                  //제품명을 객체에 저장
    s.clear();                                                                  //s를 재사용하기 위한 버퍼 비우기
    cout << "제품 가격: ";
    x = getBnumber();                                                           //제품가격 입력
    PInfo1->setProductPrice(x);                                                 //제품 가격을 객체에 저장
    cout << "제품 종류: ";
    cin >> s;                                                                   //제품 종류 입력
    PInfo1->setProductSort(s);                                                  //제품 종류를 객체에 저장
    s.clear();                                                                  //s를 재사용하기 위한 버퍼 비우기
    ProductInfo.push_back(PInfo1);                                              //객체에 저장된 정보를 vector 배열에 저장

    cout << "───────────────────────────────────────────────────────────────" << endl;
    cout << "계속 하시려면 아무 숫자값이나 입력하세요.";
    x = getNumber();                                                            //아무 숫자 입력
    system("cls");                                                              //화면 전환
}

void ProductHandler::productSearch()                                            // 모든 제품 정보 중 전화번호(PK)가 일치하는
{                                                                               // 항목의 제품정보 출력
    int n, productID;                                                           // productID는 find_if를 실행하기 위한 인자
                                                                                // n은 int 형태의 입력을 받기 위한 변수
    string s;                                                                   // string 형태의 정보 입력을 받기 위한 변수
    cout << "찾으시는 제품의 ID를 입력하세요. ";
    productID = getBnumber();                                                   // 제품ID를 입력
    auto it = find_if(ProductInfo.begin(), ProductInfo.end(), [=](Product* p)   //ProductInfo(제품 정보를 저장하는 vector)에서 
        { return (*p).getProductID() == productID; });                          //일치하는 객체인 it 변수 반환

    if (it != ProductInfo.end())                                                //it의 값이 end가 아니면
    {
        cout << "───────────────────────────────────────────────────────────────" << endl;
        cout << "제품 ID: " << (*it)->getProductID() << " / 제품명: " << (*it)->getProductName() << " / 제품 가격: " 
            << (*it)->getProductPrice() << endl << "제품 종류: " << (*it)->getProductSort() << endl;
        cout << "───────────────────────────────────────────────────────────────" << endl;
    }                                                                           //it 객체가 가진 제품ID, 제품명, 제품 가격,
                                                                                //제품 종류를 출력
    else                                                                        //it의 값이 가리키는 곳이 end라면
        cout << "일치하는 데이터가 없습니다." << endl;

    cout << "───────────────────────────────────────────────────────────────" << endl;
    cout << "계속 하시려면 아무 숫자값이나 입력하세요.";
    n = getNumber();                                                            //아무 숫자나 입력
    system("cls");                                                              //화면 전환
}

void ProductHandler::productShowlist()                                          //입력된 모든 제품 정보 출력
{
    int cnt = 0;                                                                // 데이터 행 출력을 위한 int형 변수 선언, 초기화                                                               
    if (ProductInfo.empty() == false)                                           // 제품 정보가 담긴 배열에 데이터가 존재할 경우
    {
        for (auto P : ProductInfo)                                              // 제품 정보에 담긴 데이터의 수만큼 반복
        {
            cout << "───────────────────────────────────────────────────────────────" << endl;
            cout << "데이터 행: " << cnt++ << endl;
            cout << "제품 ID: " << P->getProductID() << " / 제품명: " << P->getProductName() << " / 제품 가격: "
                << P->getProductPrice() << endl << "제품 종류: " << P->getProductSort() << endl;
            cout << "───────────────────────────────────────────────────────────────" << endl;
        }                                                                      //P 객체가 가진 제품ID, 제품명, 제품 가격,
                                                                               //제품 종류를 출력 
    }

    else                                                                       //P의 값이 가리키는 곳이 end라면
        cout << "등록된 데이터가 없습니다." << endl;
}

void ProductHandler::productRemove()                                           // 특정 제품 정보(행)을 제거
{
    int n;                                                                     // 메뉴 선택(한 자리 숫자 정수)을 위한 int형 변수  
    if (ProductInfo.empty() == false)                                          // 제품 정보가 담긴 배열에 데이터가 존재할 경우
    {
        productShowlist();                                                     // 현재 등록된 제품 목록을 보여줌
        cout << "삭제할 데이터 행을 입력하세요.";
        n = getBnumber();                                                      // 삭제할 데이터 행 번호 입력
        
        if (n >= ProductInfo.size() || n < 0)                                  // 입력된 행에 데이터가 없을 경우 
            cout << "입력된 행에 데이터가 없습니다." << endl;
        else                                                                   // 입력한 행에 제품 정보가 담긴 배열의 
        {                                                                      // 데이터가 있을 경우
            ProductInfo.erase(ProductInfo.begin() + n);                        // 입력한 행의 데이터 전체 삭제
            cout << "삭제가 완료되었습니다." << endl;
        }
    }
    else                                                                       // 제품정보가 담긴 배열에 데이터가 없는 경우
        cout << "등록된 데이터가 없습니다." << endl;

    cout << "───────────────────────────────────────────────────────────────" << endl;
    cout << "계속 하시려면 아무 숫자값이나 입력하세요.";
    n = getNumber();                                                            //아무 숫자 입력
    system("cls");                                                              //화면 전환
}

void ProductHandler::productEdit()                                              // 특정 제품 정보(행)의 특정 항목(열) 값을 변경
{
    int n, m, x;                                                                // 변경될 int형 행과 열 값을 입력받는 변수
    string s;                                                                   // 변경될 string 형 입력값을 받는 변수
    if (ProductInfo.empty() == false)                                           // 제품 정보가 담긴 배열에 데이터가 존재할 경우
    {
        productShowlist();                                                      // 현재 등록된 제품 목록을 보여줌
        cout << "───────────────────────────────────────────────────────────────" << endl;
        cout << "변경할 데이터 행을 입력하세요.";
        do {                                                                    // 변경될 데이터가 있는 행을 입력할 때까지 반복
            n = getBnumber();                                                   // 변경할 데이터 행 입력
            if (n >= ProductInfo.size() || n < 0)                               // 입력된 행 값이 배열 범위에 없을 경우
                cout << "입력된 행에 데이터가 없습니다. 다시 입력하세요" << endl;
        } while (n >= ProductInfo.size() || n < 0);

        cout << "───────────────────────────────────────────────────────────────" << endl;
        cout << "1: 제품명 / 2: 제품 가격 / 3: 제품 종류" << endl;
        cout << "변경할 데이터 열을 입력하세요.";
        do {
            m = getNumber();                                                   // 변경할 데이터 열 입력
            if (m < 1 || m > 3)                                                // 입력된 열 값이 배열 범위에 없을 경우
                cout << "잘못된 숫자입니다. 다시 입력하세요" << endl;
        } while (m < 1 || m > 3);
        cout << "\n───────────────────────────────────────────────────────────────" << endl;
        cout << "변경할 데이터 내용을 입력하세요.";
        switch (m)
        {
        case 1:                                                                 // 제품명을 변경하는 경우
        {
            cin >> s;                                                           // 변경할 제품명 입력
            ProductInfo[n]->setProductName(s);                                  // 선택된 행의 제품명을 입력된 값으로 변경
            s.clear();                                                          // 입력된 버퍼 제거
        }break;
        case 2:                                                                 // 제품가격을 변경하는 경우
        {
            x = getBnumber();                                                   // 변경할 제품 가격 입력
            ProductInfo[n]->setProductPrice(x);                                 // 선택된 행의 제품 가격을 입력된 값으로 변경
        }break;
        case 3:                                                                 // 제품 종류를 변경하는 경우
        {
            cin >> s;                                                           // 변경할 제품 종류 입력
            ProductInfo[n]->setProductSort(s);                                  // 선택된 행의 제품 종류를 입력된 값으로 변경
            s.clear();                                                          // 입력된 버퍼 제거
        }break;
        }
        cout << "───────────────────────────────────────────────────────────────" << endl;
        cout << "데이터 변경이 완료되었습니다." << endl;
        cout << "───────────────────────────────────────────────────────────────" << endl;
    }
    else                                                                        // 제품 정보가 담긴 배열에 데이터가 없을 경우
        cout << "등록된 데이터가 없습니다." << endl;

    cout << "───────────────────────────────────────────────────────────────" << endl;
    cout << "계속 하시려면 아무 숫자값이나 입력하세요.";
    x = getNumber();                                                            //아무 숫자 입력
    system("cls");                                                              //화면 전환
}

Product* ProductHandler::ProductInfoReturn(int& productID)                    // 제품 정보의 PK와 일치하는 
{                                                                             // 객체 반환(OrderInfoHandler에서 활용)
    Product* p = nullptr;                                                     // 객체 초기화
    auto it = find_if(ProductInfo.begin(), ProductInfo.end(), [=](Product *p) // 입력된 productID와 같은 객체를 it에 대입
        { return (*p).getProductID() == productID; });
    
    if (it != ProductInfo.end())                                               // it가 제품 정보 배열에 있는 경우
    { 
        p = *it;                                                               // it가 가진 값을 객체에 대입해서 반환
    }
    else                                                                       // it가 제품 정보 배열에 없는 경우
    {
        int ID = 0, productPrice = 0;
        string productName = "", productSort = "";
        *p = { ID, productName, productPrice, productSort };                    // 초기값을 대입해서 반환
    }
    return p;
}

int ProductHandler::makeProductID()                                             // 제품코드를 자동 생성하는 함수
{
    int ret = -1;                                                               // int형 반환 값을 -1로 초기화
    if (ProductInfo.size() == 0)                                                // 현재 등록된 제품 정보가 없으면
        ret = 1000;                                                             // 제품 정보에 1000을 입력해서 반환
    else if(ProductInfo.size() > 0)                                             // 이미 등록된 제품 정보가 있으면
    {
        ret = (*ProductInfo.rbegin())->getProductID();                          //제품정보의 마지막에 있는 제품ID를 ret에 대입
        ++ret;                                                                  //ret에 1을 더해서 반환
    }

    return ret;                                                                 //이 모든 경우가 아니라면 -1로 반환
}


bool ProductHandler::HasPID(int &productID)                                     // OrderInfoHandler에서 입력하는 제품ID(PK)가
                                                                                // 제품 정보에 있는지 확인해주는 함수
{
    auto it = find_if(ProductInfo.begin(), ProductInfo.end(), [=](Product* p)   // 입력된 productID가 제품 정보 배열에서
        { return (*p).getProductID() == productID; });                          // 일치하는 객체를 it에 대입
    return (it != ProductInfo.end()) ? true : false;                            // 객체가 있다면 true 반환, 없다면 false 반환
}

vector<string> ProductHandler::parsePCSV(istream& file, char delimiter)         // 생성자에서 입력된 파일 데이터를 ,단위로
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