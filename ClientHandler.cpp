#include <string>
#include <fstream>
#include <sstream>
#include "ClientHandler.h"

extern int getNumber();                                                         //0~9까지의 숫자만 입력하는 함수
extern int getBnumber();                                                        //가격이나 날짜 등 큰 숫자 입력 함수

ClientHandler::ClientHandler()                                                  //생성자
{
    ifstream file;                                                              //파일 입력 객체 생성
    file.open("clientinfo.txt");                                                //입력파일 이름 지정 후 열기
    if (!file.fail())                                                           //파일 입력 실패에 대한 예외처리
    {
        while (!file.eof())                                                     // file의 끝까지 while문 반복
        { 
            vector<string> row = parseCCSV(file, ',');                          //,단위로 구분된 file 데이터를 row에 저장
            if (row.size())                                                     //row에 저장된 데이터가 있다면
            {
                Client* c = new Client(row[0], row[1], row[2], row[3], row[4]); //string 형식의 데이터를 Client 객체에 저장
                ClientInfo.push_back(c);                                        //Client 객체에 저장된 정보를 고객정보를  
                                                                                //관리하는 배열에 입력
            }
        }
    }
    cout << "clientinfo.txt 출력 완료" << endl;
}

ClientHandler::~ClientHandler()                                                 //소멸자
{
    ofstream file;                                                              //파일 출력 객체 생성
    file.open("clientinfo.txt");                                                //출력 파일 이름 지정 후 열기
    if (!file.fail())                                                           //파일 출력 실패에 대한 예외처리
    {
        for (const auto& v : ClientInfo)                                        //저장된 모든 고객정보에 대해 반복
        {
            Client* c = v;                                                      //Client 객체에 저장된 고객정보 대입
            file << c->getName() << ", " << c->getBirthday() << ", ";           //고객 성명과 고객 생년월일을 
                                                                                //, 단위로 잘라서 입력
            file << c->getPhoneNumber() << ", " << c->getAddress();             //고객 전화번호와 주소를 , 단위로 잘라서 입력
            file << ", " << c->getEmailAddress() << endl;                       //고객 이메일을 , 단위로 잘라서 입력
        }
    }
    file.close();                                                               //파일 닫기
}
void ClientHandler::ClientEnroll()                                              //고객 정보 등록
{
    string s;                                                                   //string 형태의 정보 입력을 받기 위한 변수
    int n;                                                                      //int 형태의 정보 입력을 받기 위한 변수
    Client* CInfo1 = new Client;                                                //고객 정보 저장을 위한 Client* 형태의  
                                                                                //객체 선언 및 초기화
    cout << "성명: ";
    cin >> s;                                                                   // 고객 성명 입력
    CInfo1->setName(s);                                                         // 고객 성명을 객체에 저장
    s.clear();                                                                  // s를 재사용하기 위한 버퍼 비우기
    cout << "생년월일(ex.220830): ";
    cin >> s;                                                                   //고객 생년월일 입력
    CInfo1->setBirthday(s);                                                     //고객 생년월일을 객체에 저장
    s.clear();                                                                  //s를 재사용하기 위한 버퍼 비우기
    cout << "전화번호(ex.010-1234-5678): ";
    cin >> s;                                                                   //고객 전화번호 입력
    CInfo1->setPhoneNumber(s);                                                  //고객 전화번호를 객체에 저장
    s.clear();                                                                  //s를 재사용하기 위한 버퍼 비우기
    cout << "주소(ex.서울시 종로구 혜화동): ";
    cin.ignore();                                                               // 앞의 한 글자(enter)를 무시
    getline(cin, s, '\n');                                                      // '\n'가 들어올 때까지 입력, 주소에 있는 
                                                                                // 띄어쓰기까지 입력받기 위함
    CInfo1->setAddress(s);                                                      //고객 주소를 객체에 저장
    s.clear();                                                                  //s를 재사용하기 위한 버퍼 비우기
    cout << "이메일주소(ex.example@gmail.com): ";
    cin >> s;                                                                   //고객 이메일주소 입력
    CInfo1->setEmailAddress(s);                                                 //고객 이메일주소를 객체에 저장
    s.clear();                                                                  //s를 재사용하기 위한 버퍼 비우기
    ClientInfo.push_back(CInfo1);                                               //객체에 저장된 정보를 vector 배열에 저장

    cout << "───────────────────────────────────────────────────────────────" << endl;
    cout << "계속 하시려면 아무 숫자값이나 입력하세요.";
    n = getNumber();                                                            //아무 숫자 입력
    system("cls");                                                              //화면 전환
}


void ClientHandler::ClientSearch()                                              // 모든 고객 정보 중 전화번호(PK)가 일치하는 
{                                                                               // 항목의 고객정보 출력
    int n;                                                                      //int 형태의 정보 입력을 받기 위한 변수
    string phoneNumber;                                                         // phoneNumber는 find_if를 실행하기 위한 인자  
    cout << "찾으시는 고객의 전화번호를 입력하세요(010-xxxx-xxxx). ";
    cin >> phoneNumber;                                                         //검색을 위한 고객 전화번호(PK)를 입력

    auto it = find_if(ClientInfo.begin(), ClientInfo.end(), [=](Client* c)      //ClientInfo(고객정보를 저장하는 vector)에서 
        { return (*c).getPhoneNumber() == phoneNumber; });                      //일치하는 객체인 it 변수 반환
    if (it != ClientInfo.end())                                                 //it의 값이 end가 아니면
    {
        cout << "───────────────────────────────────────────────────────────────" << endl;
        cout << "이름: " << (*it)->getName() << " / 생년월일: " << (*it)->getBirthday() << " / 전화번호: " 
            << (*it)->getPhoneNumber() << endl << "주소: " << (*it)->getAddress() 
            << " / 이메일 주소: " << (*it)->getEmailAddress() << endl;
        cout << "───────────────────────────────────────────────────────────────" << endl;
    }                                                                           //it 객체가 가진 고객 성명, 고객 생년월일,
                                                                                //고객 전화번호, 고객 주소, 고객 이메일 주소를
                                                                                //출력
    else                                                                        //it의 값이 가리키는 곳이 end라면
        cout << "일치하는 데이터가 없습니다." << endl;

    cout << "───────────────────────────────────────────────────────────────" << endl;
    cout << "계속 하시려면 아무 숫자값이나 입력하세요.";
    n = getNumber();                                                            //아무 숫자 입력
    system("cls");                                                              //화면 전환
}

void ClientHandler::ClientShowlist()                                            // 등록된 모든 고객 정보 출력
{
    int cnt = 0;                                                                // 데이터 행 출력을 위한 int형 변수 선언, 초기화
    string s;
    if (ClientInfo.empty() == false)                                            // 고객정보가 담긴 배열에 데이터가 존재할 경우
    {
        for (auto C : ClientInfo)                                               // 고객 정보에 담긴 데이터의 수만큼 반복
        {
            cout << "───────────────────────────────────────────────────────────────" << endl;
            cout << "데이터 행: " << cnt++ << endl;
            cout << "이름: " << C->getName() << " / 생년월일: " << C->getBirthday() << " / 전화번호: " << C->getPhoneNumber()
                << endl << "주소: " << C->getAddress() << " / 이메일 주소: " << C->getEmailAddress() << endl;
            cout << "───────────────────────────────────────────────────────────────" << endl;
        }                                                                       //it 객체가 가진 고객 성명, 고객 생년월일,
                                                                                //고객 전화번호, 고객 주소, 고객 이메일 주소를
                                                                                //출력                                                 
    }

    else if(ClientInfo.empty() == true)                                         // 고객정보가 담긴 배열에 데이터가 없을 경우    
        cout << "등록된 데이터가 없습니다." << endl;
}

void ClientHandler::ClientRemove()                                              //특정 고객정보(행)을 제거
{
    int n;                                                                      // 메뉴 선택(한 자리 숫자 정수)를 위한 int형 변수
    if (ClientInfo.empty() == false)                                            // 고객정보가 담긴 배열에 데이터가 존재할 경우
    {
        ClientShowlist();                                                       // 현재 등록된 고객 목록을 보여줌
        cout << "삭제하실 데이터 행 번호를 입력하세요.";                        
        n = getBnumber();                                                       // 삭제할 데이터 행 번호 입력
        if (n >= ClientInfo.size() || n < 0)                                    // 입력된 행에 데이터가 없을 경우    
            cout << "입력된 행에 데이터가 없습니다." << endl;
        else
        {
            ClientInfo.erase(ClientInfo.begin() + n);                           // 입력한 행에 고객정보가 담긴 배열의 
                                                                                // 데이터가 있을 경우
            cout << "삭제가 완료되었습니다." << endl;                           // 입력한 행의 데이터 전체 삭제
        }
    }
    else
        cout << "등록된 데이터가 없습니다." << endl;                            // 고객정보가 담긴 배열에 데이터가 없는 경우

    cout << "───────────────────────────────────────────────────────────────" << endl;
    cout << "계속 하시려면 아무 숫자값이나 입력하세요.";                        
    n = getNumber();                                                            // 아무 숫자 입력
    system("cls");                                                              // 화면 전환
}

void ClientHandler::ClientEdit()                                                // 특정 고객정보(행)의 특정 항목(열) 값을 변경
{
    int m, n;                                                                   // 변경될 int 형 행과 열 값을 입력받는 변수
    string s;                                                                   // 변경될 string 형 입력값을 받는 변수
    if (ClientInfo.empty() == false)                                            // 고객정보가 담긴 배열에 데이터가 존재할 경우 
    {
        ClientShowlist();                                                       // 현재 등록된 고객 목록을 보여줌
        cout << "───────────────────────────────────────────────────────────────" << endl;
        cout << "변경할 데이터 행을 입력하세요.";
        do {                                                                    // 변경될 데이터가 있는 행을 입력할 때까지 반복
            n = getBnumber();                                                   // 변경할 데이터 행 입력
            if (n >= ClientInfo.size() || n < 0)                                // 입력된 행 값이 배열 범위에 없을 경우
                cout << "입력된 행에 데이터가 없습니다. 다시 입력하세요" << endl;
        } while (n >= ClientInfo.size() || n < 0);
        cout << "───────────────────────────────────────────────────────────────" << endl;
        cout << "0: 이름 / 1: 생년월일 / 2: 전화번호 /" << endl << " 3: 주소 / 4: 이메일 주소" << endl;
        cout << "변경할 데이터 열을 입력하세요.";                                
        do {
            m = getNumber();                                                    // 변경할 데이터 열 입력
            if (m > 4 || m < 0)                                                 // 입력된 열 값이 배열 범위에 없을 경우
                cout << "입력된 열에 데이터가 없습니다. 다시 입력하세요" << endl;
        } while (m > 4 || m < 0);                                               
        cout << "\n───────────────────────────────────────────────────────────────" << endl;
        cout << "변경할 데이터 내용을 입력하세요.";
       
        switch (m)
        {
        case 0:                                                                 // 이름을 변경하는 경우
        {
            cin >> s;                                                           // 변경할 이름 입력
            ClientInfo[n]->setName(s);                                          // 선택된 행의 이름을 입력된 값으로 변경
            s.clear();                                                          // 입력된 버퍼 제거
        }break;
        case 1:                                                                 // 생년월일을 변경하는 경우
        {
            cin >> s;                                                           // 변경할 생년월일 입력
            ClientInfo[n]->setBirthday(s);                                      // 선택된 행의 생년월일을 입력된 값으로 변경
            s.clear();                                                          // 입력된 버퍼 제거
        }break;
        case 2:                                                                 // 전화번호를 변경하는 경우
        {
            cin >> s;                                                           // 변경할 전화번호 입력
            ClientInfo[n]->setPhoneNumber(s);                                   // 선택된 행의 전화번호를 입력된 값으로 변경
            s.clear();                                                          // 입력된 버퍼 제거
        }break;
        case 3:                                                                 // 주소를 변경하는 경우
        {
            getline(cin, s, '\n');                                              // enter 입력 전까지 입력된 변경할 주소 입력
            ClientInfo[n]->setAddress(s);                                       // 선택된 행의 주소를 입력된 값으로 변경
            s.clear();                                                          // 입력된 버퍼 제거
        }break;
        case 4:                                                                 // 이메일을 변경하는 경우
        {
            cin >> s;                                                           // 변경할 이메일 입력
            ClientInfo[n]->setEmailAddress(s);                                  // 선택된 행의 이메일을 입력된 값으로 변경
            s.clear();                                                          // 입력된 버퍼 제거
        }break;
        }
        cout << "───────────────────────────────────────────────────────────────" << endl;
        cout << "데이터 변경이 완료되었습니다." << endl;
        cout << "───────────────────────────────────────────────────────────────" << endl;
    }
    else                                                                        // 고객정보가 담긴 배열에 데이터가 없을 경우
        cout << "등록된 데이터가 없습니다." << endl;

    cout << "───────────────────────────────────────────────────────────────" << endl;
    cout << "계속 하시려면 아무 숫자값이나 입력하세요.";
    n = getNumber();                                                            //아무 숫자 입력
    system("cls");                                                              //화면 전환
}

Client* ClientHandler::ClientInforeturn(string& phoneNumber)                    // 고객정보의 PK와 일치하는 
                                                                                // 객체 반환(OrderInfoHandler에서 활용)
{
    Client* c = nullptr;                                                        // 객체 초기화
    auto it = find_if(ClientInfo.begin(), ClientInfo.end(), [=](Client* c)      // 입력된 phoneNumber와 같은 객체를 it에 대입
        { return (*c).getPhoneNumber() == phoneNumber; });              
    if (it != ClientInfo.end())                                                 // it가 고객 정보 배열에 있는 경우
    {
        c = *it;                                                                // it가 가진 값을 객체에 대입해서 반환
    }
    else                                                                        // it가 고객 정보 배열에 없는 경우
    {
        string name = "", birthday = "", phoneNumber = "", address = "", emailAddress = "";     
        *c = { name, birthday ,phoneNumber, address, emailAddress };            // 초기값을 대입해서 반환
    }
    return c;
}

bool ClientHandler::HasCID(string phoneNumber)                                  // OrderInfoHandler에서 입력하는 고객
                                                                                // 전화번호(PK)가 있는지 확인해주는 함수
{
    auto it = find_if(ClientInfo.begin(), ClientInfo.end(), [=](Client* c)      // 입력된 phoneNumber가 고객 정보 배열에서
        { return (*c).getPhoneNumber() == phoneNumber; });                      // 일치하는 객체를 it에 대입
    return (it != ClientInfo.end())?true:false;                                 // 객체가 있다면 true 반환, 없다면 false 반환
}

vector<string> ClientHandler::parseCCSV(istream& file, char delimiter)          // 생성자에서 입력된 파일 데이터를 ,단위로
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
