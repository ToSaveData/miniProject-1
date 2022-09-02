#include "ClientHandler.h"

void ClientHandler::ClientEnroll()
{
    string s;
    cout << "�̸�: ";
    cin >> s;
    Client* CInfo1 = new Client;
    CInfo1->setName(s);
    s.clear();
    cout << "�������(ex.220830): ";
    cin >> s;
    CInfo1->setBirthday(s);
    s.clear();
    cout << "��ȭ��ȣ(ex.010-1234-5678): ";
    cin >> s;
    CInfo1->setPhoneNumber(s);
    s.clear();
    cout << "�ּ�(ex.����Ư����): ";
    cin >> s; // '\n'�� ���� ������ �ްڴ�
    CInfo1->setAddress(s);
    s.clear();
    cout << "�̸����ּ�(ex.example@gmail.com): ";
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
        cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "�̸�: " << (*it)->getName() << " / �������: " << (*it)->getBirthday() << " / ��ȭ��ȣ: " << (*it)->getPhoneNumber()
            << endl << "�ּ�: " << (*it)->getAddress() << " / �̸��� �ּ�: " << (*it)->getEmailAddress() << endl;
        cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    }
    else
        cout << "��ġ�ϴ� �����Ͱ� �����ϴ�." << endl;
}

void ClientHandler::ClientShowlist()
{
    for (auto C : ClientInfo)
    {
        cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "�̸�: " << C->getName() << " / �������: " << C->getBirthday() << " / ��ȭ��ȣ: " << C->getPhoneNumber()
        << endl << "�ּ�: " << C->getAddress() << " / �̸��� �ּ�: " << C->getEmailAddress() <<  endl;
        cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    }
}

void ClientHandler::ClientRemove()
{
    int n;
    cout << "������ ������ ���� �Է��ϼ���.";
    cin >> n;
    if (n > ClientInfo.size() || n < 0)
        cout << "�Էµ� �࿡ �����Ͱ� �����ϴ�." << endl;
    else
    {
        ClientInfo.erase(ClientInfo.begin() + n);
        cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
    }
}

void ClientHandler::ClientEdit()
{
    int m, n;
    string s;
    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "������ ������ ���� �Է��ϼ���.";
    cin >> n;
    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "������ ������ ���� �Է��ϼ���.";
    cin >> m;
    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "������ ������ ������ �Է��ϼ���.";
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
    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "������ ������ �Ϸ�Ǿ����ϴ�." << endl;
    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
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