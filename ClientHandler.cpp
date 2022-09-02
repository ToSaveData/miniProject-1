#include "ClientHandler.h"

void ClientHandler::ClientEnroll()
{
    string s;
    cout << "이름: ";
    cin >> s;
    Client* CInfo1 = new Client;
    CInfo1->setName(s);
    s.clear();
    cout << "생년월일(ex.220830): ";
    cin >> s;
    CInfo1->setBirthday(s);
    s.clear();
    cout << "전화번호(ex.010-1234-5678): ";
    cin >> s;
    CInfo1->setPhoneNumber(s);
    s.clear();
    cout << "주소(ex.서울특별시): ";
    cin >> s; // '\n'가 들어올 때까지 받겠다
    CInfo1->setAddress(s);
    s.clear();
    cout << "이메일주소(ex.example@gmail.com): ";
    cin >> s;
    CInfo1->setEmailAddress(s);
    s.clear();
    ClientInfo.push_back(CInfo1);
}


void ClientHandler::ClientSearch(string &phoneNumber)
{
    auto it = find_if(ClientInfo.begin(), ClientInfo.end(), [=](Client* c) 
        { return (*c).getPhoneNumber() == phoneNumber; });
    
    if (it != ClientInfo.end())
    {
        cout << "───────────────────────────────────────────────────────────────" << endl;
        cout << "이름: " << (*it)->getName() << " / 생년월일: " << (*it)->getBirthday() << " / 전화번호: " << (*it)->getPhoneNumber()
            << endl << "주소: " << (*it)->getAddress() << " / 이메일 주소: " << (*it)->getEmailAddress() << endl;
        cout << "───────────────────────────────────────────────────────────────" << endl;
    }
    else
        cout << "일치하는 데이터가 없습니다." << endl;
}

void ClientHandler::ClientShowlist()
{
    for (auto C : ClientInfo)
    {
        cout << "───────────────────────────────────────────────────────────────" << endl;
        cout << "이름: " << C->getName() << " / 생년월일: " << C->getBirthday() << " / 전화번호: " << C->getPhoneNumber()
        << endl << "주소: " << C->getAddress() << " / 이메일 주소: " << C->getEmailAddress() <<  endl;
        cout << "───────────────────────────────────────────────────────────────" << endl;
    }
}

void ClientHandler::ClientRemove()
{
    int n;
    cout << "삭제할 데이터 행을 입력하세요.";
    cin >> n;
    if (n > ClientInfo.size() || n < 0)
        cout << "입력된 행에 데이터가 없습니다." << endl;
    else
    {
        ClientInfo.erase(ClientInfo.begin() + n);
        cout << "삭제가 완료되었습니다." << endl;
    }
}

void ClientHandler::ClientEdit()
{
    int m, n;
    string s;
    cout << "───────────────────────────────────────────────────────────────" << endl;
    cout << "변경할 데이터 행을 입력하세요.";
    cin >> n;
    cout << "───────────────────────────────────────────────────────────────" << endl;
    cout << "변경할 데이터 열을 입력하세요.";
    cin >> m;
    cout << "───────────────────────────────────────────────────────────────" << endl;
    cout << "변경할 데이터 내용을 입력하세요.";
    cin >> s;
    switch (m)
    {
        case 0:
        {
            ClientInfo[n]->setName(s);
            s.clear();
        }break;
        case 1:
        {
            ClientInfo[n]->setBirthday(s);
            s.clear();
        }break;
        case 2:
        {
            ClientInfo[n]->setPhoneNumber(s);
            s.clear();
        }break;
        case 3:
        {
            ClientInfo[n]->setAddress(s);
            s.clear();
        }break;
        case 4:
        {
            ClientInfo[n]->setEmailAddress(s);
            s.clear();
        }break;
    }
    cout << "───────────────────────────────────────────────────────────────" << endl;
    cout << "데이터 변경이 완료되었습니다." << endl;
    cout << "───────────────────────────────────────────────────────────────" << endl;
}

Client* ClientHandler::ClientInforeturn(string& phoneNumber)
{
    Client* c = nullptr;
    auto it = find_if(ClientInfo.begin(), ClientInfo.end(), [=](Client* c)
        { return (*c).getPhoneNumber() == phoneNumber; });
    if (it != ClientInfo.end())
    {
        c = *it;
        return *it;
    }
    
}