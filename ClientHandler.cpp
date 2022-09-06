#include <string>
#include <fstream>
#include <sstream>
#include "ClientHandler.h"

extern int getNumber();
extern int getBnumber();

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
    cout << "clientinfo.txt ��� �Ϸ�" << endl;
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
    int n;
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

    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "��� �Ͻ÷��� �ƹ� ���ڰ��̳� �Է��ϼ���.";
    n = getNumber();
    system("cls");
}


void ClientHandler::ClientSearch() // ��� �� ���� �� ��ȭ��ȣ(PK)�� ��ġ�ϴ� �׸��� ������ ���
{
    int n;
    string phoneNumber, s;
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

    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "��� �Ͻ÷��� �ƹ� ���ڰ��̳� �Է��ϼ���.";
    n = getNumber();
    system("cls");
}

void ClientHandler::ClientShowlist() // ��ϵ� ��� �� ���� ���
{
    int cnt = 0;
    string s;
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
    string s;
    if (ClientInfo.empty() == false)
    {
        ClientShowlist();
        cout << "�����Ͻ� ������ �� ��ȣ�� �Է��ϼ���.";
        n = getBnumber();
        if (n >= ClientInfo.size() || n < 0)
            cout << "�Էµ� �࿡ �����Ͱ� �����ϴ�." << endl;
        else
        {
            ClientInfo.erase(ClientInfo.begin() + n);
            cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
        }
    }
    else
        cout << "��ϵ� �����Ͱ� �����ϴ�." << endl;

    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "��� �Ͻ÷��� �ƹ� ���ڰ��̳� �Է��ϼ���.";
    n = getNumber();
    system("cls");
}

void ClientHandler::ClientEdit() // Ư�� ������(��)�� Ư�� �׸�(��) ���� ����
{
    int m, n;
    string s;
    if (ClientInfo.empty() == false)
    {
        ClientShowlist();
        cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "������ ������ ���� �Է��ϼ���.";
        do {
            n = getBnumber();
            if (n >= ClientInfo.size() || n < 0)
                cout << "�Էµ� �࿡ �����Ͱ� �����ϴ�. �ٽ� �Է��ϼ���" << endl;
        } while (n >= ClientInfo.size() || n < 0);
        cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "0: �̸� / 1: ������� / 2: ��ȭ��ȣ /" << endl << " 3: �ּ� / 4: �̸��� �ּ�" << endl;
        cout << "������ ������ ���� �Է��ϼ���.";
        do {
            m = getNumber();
            if (m > 4 || m < 0)
                cout << "�Էµ� ���� �����Ͱ� �����ϴ�. �ٽ� �Է��ϼ���" << endl;
        } while (m > 4 || m < 0);
        cout << "\n������������������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "������ ������ ������ �Է��ϼ���.";
       
        switch (m)
        {
        case 0:
        {
            cin >> s;
            ClientInfo[n]->setName(s);
            s.clear();
        }break;
        case 1:
        {
            cin >> s;
            ClientInfo[n]->setBirthday(s);
            s.clear();
        }break;
        case 2:
        {
            cin >> s;
            ClientInfo[n]->setPhoneNumber(s);
            s.clear();
        }break;
        case 3:
        {
            cin.ignore();
            getline(cin, s, '\n');
            ClientInfo[n]->setAddress(s);
            s.clear();
        }break;
        case 4:
        {
            cin >> s;
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

    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "��� �Ͻ÷��� �ƹ� ���ڰ��̳� �Է��ϼ���.";
    n = getNumber();
    system("cls");
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
