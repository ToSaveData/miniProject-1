//�� �Լ� ���� try, catch������ int �� �Է� ��Ȳ���� �ٸ� ������ �����Ͱ� �Էµ��� ��츦 ó���ϱ� ������.

#include "ClientHandler.h"
#include <string>
#include <fstream>
#include <sstream>
ClientHandler::ClientHandler()
{
    ifstream file; //���� ��� ��ü ����
    file.open("clientinfo.txt"); //�Է����� �̸�
    if (!file.fail()) 
    {
        while (!file.eof()) // end of file => true�� �Ǵ� �������� ������
        { 
            vector<string> row = parseCCSV(file, ',');
            if (row.size()) 
            {
                Client* c = new Client(row[0], row[1], row[2], row[3], row[4]);
                ClientInfo.push_back(c);
            }
        }
    }
}

ClientHandler::~ClientHandler()
{
    ofstream file;
    file.open("clientinfo.txt");
    if (!file.fail()) 
    {
        for (const auto& v : ClientInfo) 
        {
            Client* c = v;
            file << c->getName() << ", " << c->getBirthday() << ", ";
            file << c->getPhoneNumber() << ", ";
            file << c->getAddress() << ", " << c->getEmailAddress() << endl;
        }
    }
    file.close();
}
void ClientHandler::ClientEnroll()// ����, �������, ��ȭ��ȣ, �ּ�, �̸��� �ּ� �Է� �� ���� ����
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
    cout << "�ּ�(ex.����� ���α� ��ȭ��): ";
    cin.ignore(); // ���� �� ����(enter)�� �����ϴ� ���
    getline(cin, s, '\n'); // '\n'�� ���� ������ �ްڴ�
    CInfo1->setAddress(s);
    s.clear();
    cout << "�̸����ּ�(ex.example@gmail.com): "; // �ٹ�� ������ Ȯ���� ����
    cin >> s;
    CInfo1->setEmailAddress(s);
    s.clear();
    ClientInfo.push_back(CInfo1);
}


void ClientHandler::ClientSearch() // ��� �� ���� �� ��ȭ��ȣ(PK)�� ��ġ�ϴ� �׸��� ������ ���
{
    string phoneNumber;
    cout << "ã���ô� ���� ��ȭ��ȣ�� �Է��ϼ���(010-xxxx-xxxx). ";
    cin >> phoneNumber;

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

void ClientHandler::ClientShowlist() // ��ϵ� ��� �� ���� ���
{
    int cnt = 0;
    if (ClientInfo.empty() == false)
    {
        for (auto C : ClientInfo)
        {
            cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
            cout << "������ ��: " << cnt++ << endl;
            cout << "�̸�: " << C->getName() << " / �������: " << C->getBirthday() << " / ��ȭ��ȣ: " << C->getPhoneNumber()
                << endl << "�ּ�: " << C->getAddress() << " / �̸��� �ּ�: " << C->getEmailAddress() << endl;
            cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
        }
    }

    else if(ClientInfo.empty() == true)
        cout << "��ϵ� �����Ͱ� �����ϴ�." << endl;
}

void ClientHandler::ClientRemove() //Ư�� ������(��)�� ����
{
    int n;
    if (ClientInfo.empty() == false)
    {
        ClientShowlist();
        cout << "�����Ͻ� ������ �� ��ȣ�� �Է��ϼ���.";
        cin >> n;
        if (cin.fail())
        {
            try 
            {
                cin.clear();
                cin.ignore(100, '\n');
                throw 100;
            }
            catch (...)
            {
                cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
                cout << "�߸��� �Է��Դϴ�." << endl;
                cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
            }
        }
        else{
            if (n >= ClientInfo.size() || n < 0)
                cout << "�Էµ� �࿡ �����Ͱ� �����ϴ�." << endl;
            else
            {
                ClientInfo.erase(ClientInfo.begin() + n);
                cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
            }
        }
    }
    else
        cout << "��ϵ� �����Ͱ� �����ϴ�." << endl;
}

void ClientHandler::ClientEdit() // Ư�� ������(��)�� Ư�� �׸�(��) ���� ����
{
    int m, n;
    string s;
    if (ClientInfo.empty() == false)
    {
        ClientShowlist();
        cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
CTO1:   cout << "������ ������ ���� �Է��ϼ���.";
        do {
            cin >> n;
            if (cin.fail())
            {
                try
                {
                    cin.clear();
                    cin.ignore(100, '\n');
                    throw 100;
                }
                catch (...)
                {
                    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
                    cout << "�߸��� �Է��Դϴ�." << endl;
                    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
                    goto CTO1;
                }
            }
            if (n >= ClientInfo.size() || n < 0)
                cout << "�Էµ� �࿡ �����Ͱ� �����ϴ�. �ٽ� �Է��ϼ���" << endl;
        } while (n >= ClientInfo.size() || n < 0);
        cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "0: �̸� / 1: ������� / 2: ��ȭ��ȣ /" << endl << " 3: �ּ� / 4: �̸��� �ּ�" << endl;
CTO2:   cout << "������ ������ ���� �Է��ϼ���.";
        do {
            cin >> m;
            if (cin.fail())
            {
                try
                {
                    cin.clear();
                    cin.ignore(100, '\n');
                    throw 100;
                }
                catch (...)
                {
                    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
                    cout << "�߸��� �Է��Դϴ�." << endl;
                    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
                    goto CTO2;
                }
            }
            if (m > 4 || m < 0)
                cout << "�Էµ� ���� �����Ͱ� �����ϴ�. �ٽ� �Է��ϼ���" << endl;
        } while (m > 4 || m < 0);
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
    else
        cout << "��ϵ� �����Ͱ� �����ϴ�." << endl;
}

Client* ClientHandler::ClientInforeturn(string& phoneNumber) // �������� PK�� ��ġ�ϴ� ��ü ��ȯ(OrderInfoHandler���� Ȱ��)
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

bool ClientHandler::HasCID(string phoneNumber)
{
    auto it = find_if(ClientInfo.begin(), ClientInfo.end(), [=](Client* c)
        { return (*c).getPhoneNumber() == phoneNumber; });
    return (it != ClientInfo.end())?true:false;
}

vector<string> ClientHandler::parseCCSV(istream& file, char delimiter)
{
    stringstream ss;
    vector<string> row;
    string t = " \n\r\t";

    while (!file.eof()) 
    {
        char c = file.get();
        if (c == delimiter || c == '\r' || c == '\n') 
        {
            if (file.peek() == '\n') file.get(); //peek(): ���� ���ڸ� ����. => ���� ���ڰ� �ٹٲ��̸� ����ȭ���� 
            //���� �����͸� �����´�. 
            string s = ss.str();
            s.erase(0, s.find_first_not_of(t)); //find_first_not_of(���ڿ�): ������ ���ڿ��� ��ġ���� �ʴ� 
            //ù��° ���� �˻�, erase(�����ε���, ���ε���(����X)) => �����ε������� �� �ε������� �˻�
            s.erase(s.find_last_not_of(t) + 1); //t�� �ٷ� �� �������� ���� => NULL���� ����
                row.push_back(s);
            ss.str("");
            if (c != delimiter) break;
        }
        else 
        {
            ss << c;
        }
    }
    return row;
}
