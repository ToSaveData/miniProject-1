#include <string>
#include <fstream>
#include <sstream>
#include "ClientHandler.h"

extern int getNumber();                                                         //0~9������ ���ڸ� �Է��ϴ� �Լ�
extern int getBnumber();                                                        //�����̳� ��¥ �� ū ���� �Է� �Լ�

ClientHandler::ClientHandler()                                                  //������
{
    ifstream file;                                                              //���� �Է� ��ü ����
    file.open("clientinfo.txt");                                                //�Է����� �̸� ���� �� ����
    if (!file.fail())                                                           //���� �Է� ���п� ���� ����ó��
    {
        while (!file.eof())                                                     // file�� ������ while�� �ݺ�
        { 
            vector<string> row = parseCCSV(file, ',');                          //,������ ���е� file �����͸� row�� ����
            if (row.size())                                                     //row�� ����� �����Ͱ� �ִٸ�
            {
                Client* c = new Client(row[0], row[1], row[2], row[3], row[4]); //string ������ �����͸� Client ��ü�� ����
                ClientInfo.push_back(c);                                        //Client ��ü�� ����� ������ ��������  
                                                                                //�����ϴ� �迭�� �Է�
            }
        }
    }
    cout << "clientinfo.txt ��� �Ϸ�" << endl;
}

ClientHandler::~ClientHandler()                                                 //�Ҹ���
{
    ofstream file;                                                              //���� ��� ��ü ����
    file.open("clientinfo.txt");                                                //��� ���� �̸� ���� �� ����
    if (!file.fail())                                                           //���� ��� ���п� ���� ����ó��
    {
        for (const auto& v : ClientInfo)                                        //����� ��� �������� ���� �ݺ�
        {
            Client* c = v;                                                      //Client ��ü�� ����� ������ ����
            file << c->getName() << ", " << c->getBirthday() << ", ";           //�� ����� �� ��������� 
                                                                                //, ������ �߶� �Է�
            file << c->getPhoneNumber() << ", " << c->getAddress();             //�� ��ȭ��ȣ�� �ּҸ� , ������ �߶� �Է�
            file << ", " << c->getEmailAddress() << endl;                       //�� �̸����� , ������ �߶� �Է�
        }
    }
    file.close();                                                               //���� �ݱ�
}
void ClientHandler::ClientEnroll()                                              //�� ���� ���
{
    string s;                                                                   //string ������ ���� �Է��� �ޱ� ���� ����
    int n;                                                                      //int ������ ���� �Է��� �ޱ� ���� ����
    Client* CInfo1 = new Client;                                                //�� ���� ������ ���� Client* ������  
                                                                                //��ü ���� �� �ʱ�ȭ
    cout << "����: ";
    cin >> s;                                                                   // �� ���� �Է�
    CInfo1->setName(s);                                                         // �� ������ ��ü�� ����
    s.clear();                                                                  // s�� �����ϱ� ���� ���� ����
    cout << "�������(ex.220830): ";
    cin >> s;                                                                   //�� ������� �Է�
    CInfo1->setBirthday(s);                                                     //�� ��������� ��ü�� ����
    s.clear();                                                                  //s�� �����ϱ� ���� ���� ����
    cout << "��ȭ��ȣ(ex.010-1234-5678): ";
    cin >> s;                                                                   //�� ��ȭ��ȣ �Է�
    CInfo1->setPhoneNumber(s);                                                  //�� ��ȭ��ȣ�� ��ü�� ����
    s.clear();                                                                  //s�� �����ϱ� ���� ���� ����
    cout << "�ּ�(ex.����� ���α� ��ȭ��): ";
    cin.ignore();                                                               // ���� �� ����(enter)�� ����
    getline(cin, s, '\n');                                                      // '\n'�� ���� ������ �Է�, �ּҿ� �ִ� 
                                                                                // ������� �Է¹ޱ� ����
    CInfo1->setAddress(s);                                                      //�� �ּҸ� ��ü�� ����
    s.clear();                                                                  //s�� �����ϱ� ���� ���� ����
    cout << "�̸����ּ�(ex.example@gmail.com): ";
    cin >> s;                                                                   //�� �̸����ּ� �Է�
    CInfo1->setEmailAddress(s);                                                 //�� �̸����ּҸ� ��ü�� ����
    s.clear();                                                                  //s�� �����ϱ� ���� ���� ����
    ClientInfo.push_back(CInfo1);                                               //��ü�� ����� ������ vector �迭�� ����

    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "��� �Ͻ÷��� �ƹ� ���ڰ��̳� �Է��ϼ���.";
    n = getNumber();                                                            //�ƹ� ���� �Է�
    system("cls");                                                              //ȭ�� ��ȯ
}


void ClientHandler::ClientSearch()                                              // ��� �� ���� �� ��ȭ��ȣ(PK)�� ��ġ�ϴ� 
{                                                                               // �׸��� ������ ���
    int n;                                                                      //int ������ ���� �Է��� �ޱ� ���� ����
    string phoneNumber;                                                         // phoneNumber�� find_if�� �����ϱ� ���� ����  
    cout << "ã���ô� ���� ��ȭ��ȣ�� �Է��ϼ���(010-xxxx-xxxx). ";
    cin >> phoneNumber;                                                         //�˻��� ���� �� ��ȭ��ȣ(PK)�� �Է�

    auto it = find_if(ClientInfo.begin(), ClientInfo.end(), [=](Client* c)      //ClientInfo(�������� �����ϴ� vector)���� 
        { return (*c).getPhoneNumber() == phoneNumber; });                      //��ġ�ϴ� ��ü�� it ���� ��ȯ
    if (it != ClientInfo.end())                                                 //it�� ���� end�� �ƴϸ�
    {
        cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "�̸�: " << (*it)->getName() << " / �������: " << (*it)->getBirthday() << " / ��ȭ��ȣ: " 
            << (*it)->getPhoneNumber() << endl << "�ּ�: " << (*it)->getAddress() 
            << " / �̸��� �ּ�: " << (*it)->getEmailAddress() << endl;
        cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    }                                                                           //it ��ü�� ���� �� ����, �� �������,
                                                                                //�� ��ȭ��ȣ, �� �ּ�, �� �̸��� �ּҸ�
                                                                                //���
    else                                                                        //it�� ���� ����Ű�� ���� end���
        cout << "��ġ�ϴ� �����Ͱ� �����ϴ�." << endl;

    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "��� �Ͻ÷��� �ƹ� ���ڰ��̳� �Է��ϼ���.";
    n = getNumber();                                                            //�ƹ� ���� �Է�
    system("cls");                                                              //ȭ�� ��ȯ
}

void ClientHandler::ClientShowlist()                                            // ��ϵ� ��� �� ���� ���
{
    int cnt = 0;                                                                // ������ �� ����� ���� int�� ���� ����, �ʱ�ȭ
    string s;
    if (ClientInfo.empty() == false)                                            // �������� ��� �迭�� �����Ͱ� ������ ���
    {
        for (auto C : ClientInfo)                                               // �� ������ ��� �������� ����ŭ �ݺ�
        {
            cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
            cout << "������ ��: " << cnt++ << endl;
            cout << "�̸�: " << C->getName() << " / �������: " << C->getBirthday() << " / ��ȭ��ȣ: " << C->getPhoneNumber()
                << endl << "�ּ�: " << C->getAddress() << " / �̸��� �ּ�: " << C->getEmailAddress() << endl;
            cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
        }                                                                       //it ��ü�� ���� �� ����, �� �������,
                                                                                //�� ��ȭ��ȣ, �� �ּ�, �� �̸��� �ּҸ�
                                                                                //���                                                 
    }

    else if(ClientInfo.empty() == true)                                         // �������� ��� �迭�� �����Ͱ� ���� ���    
        cout << "��ϵ� �����Ͱ� �����ϴ�." << endl;
}

void ClientHandler::ClientRemove()                                              //Ư�� ������(��)�� ����
{
    int n;                                                                      // �޴� ����(�� �ڸ� ���� ����)�� ���� int�� ����
    if (ClientInfo.empty() == false)                                            // �������� ��� �迭�� �����Ͱ� ������ ���
    {
        ClientShowlist();                                                       // ���� ��ϵ� �� ����� ������
        cout << "�����Ͻ� ������ �� ��ȣ�� �Է��ϼ���.";                        
        n = getBnumber();                                                       // ������ ������ �� ��ȣ �Է�
        if (n >= ClientInfo.size() || n < 0)                                    // �Էµ� �࿡ �����Ͱ� ���� ���    
            cout << "�Էµ� �࿡ �����Ͱ� �����ϴ�." << endl;
        else
        {
            ClientInfo.erase(ClientInfo.begin() + n);                           // �Է��� �࿡ �������� ��� �迭�� 
                                                                                // �����Ͱ� ���� ���
            cout << "������ �Ϸ�Ǿ����ϴ�." << endl;                           // �Է��� ���� ������ ��ü ����
        }
    }
    else
        cout << "��ϵ� �����Ͱ� �����ϴ�." << endl;                            // �������� ��� �迭�� �����Ͱ� ���� ���

    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "��� �Ͻ÷��� �ƹ� ���ڰ��̳� �Է��ϼ���.";                        
    n = getNumber();                                                            // �ƹ� ���� �Է�
    system("cls");                                                              // ȭ�� ��ȯ
}

void ClientHandler::ClientEdit()                                                // Ư�� ������(��)�� Ư�� �׸�(��) ���� ����
{
    int m, n;                                                                   // ����� int �� ��� �� ���� �Է¹޴� ����
    string s;                                                                   // ����� string �� �Է°��� �޴� ����
    if (ClientInfo.empty() == false)                                            // �������� ��� �迭�� �����Ͱ� ������ ��� 
    {
        ClientShowlist();                                                       // ���� ��ϵ� �� ����� ������
        cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "������ ������ ���� �Է��ϼ���.";
        do {                                                                    // ����� �����Ͱ� �ִ� ���� �Է��� ������ �ݺ�
            n = getBnumber();                                                   // ������ ������ �� �Է�
            if (n >= ClientInfo.size() || n < 0)                                // �Էµ� �� ���� �迭 ������ ���� ���
                cout << "�Էµ� �࿡ �����Ͱ� �����ϴ�. �ٽ� �Է��ϼ���" << endl;
        } while (n >= ClientInfo.size() || n < 0);
        cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "0: �̸� / 1: ������� / 2: ��ȭ��ȣ /" << endl << " 3: �ּ� / 4: �̸��� �ּ�" << endl;
        cout << "������ ������ ���� �Է��ϼ���.";                                
        do {
            m = getNumber();                                                    // ������ ������ �� �Է�
            if (m > 4 || m < 0)                                                 // �Էµ� �� ���� �迭 ������ ���� ���
                cout << "�Էµ� ���� �����Ͱ� �����ϴ�. �ٽ� �Է��ϼ���" << endl;
        } while (m > 4 || m < 0);                                               
        cout << "\n������������������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "������ ������ ������ �Է��ϼ���.";
       
        switch (m)
        {
        case 0:                                                                 // �̸��� �����ϴ� ���
        {
            cin >> s;                                                           // ������ �̸� �Է�
            ClientInfo[n]->setName(s);                                          // ���õ� ���� �̸��� �Էµ� ������ ����
            s.clear();                                                          // �Էµ� ���� ����
        }break;
        case 1:                                                                 // ��������� �����ϴ� ���
        {
            cin >> s;                                                           // ������ ������� �Է�
            ClientInfo[n]->setBirthday(s);                                      // ���õ� ���� ��������� �Էµ� ������ ����
            s.clear();                                                          // �Էµ� ���� ����
        }break;
        case 2:                                                                 // ��ȭ��ȣ�� �����ϴ� ���
        {
            cin >> s;                                                           // ������ ��ȭ��ȣ �Է�
            ClientInfo[n]->setPhoneNumber(s);                                   // ���õ� ���� ��ȭ��ȣ�� �Էµ� ������ ����
            s.clear();                                                          // �Էµ� ���� ����
        }break;
        case 3:                                                                 // �ּҸ� �����ϴ� ���
        {
            getline(cin, s, '\n');                                              // enter �Է� ������ �Էµ� ������ �ּ� �Է�
            ClientInfo[n]->setAddress(s);                                       // ���õ� ���� �ּҸ� �Էµ� ������ ����
            s.clear();                                                          // �Էµ� ���� ����
        }break;
        case 4:                                                                 // �̸����� �����ϴ� ���
        {
            cin >> s;                                                           // ������ �̸��� �Է�
            ClientInfo[n]->setEmailAddress(s);                                  // ���õ� ���� �̸����� �Էµ� ������ ����
            s.clear();                                                          // �Էµ� ���� ����
        }break;
        }
        cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "������ ������ �Ϸ�Ǿ����ϴ�." << endl;
        cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    }
    else                                                                        // �������� ��� �迭�� �����Ͱ� ���� ���
        cout << "��ϵ� �����Ͱ� �����ϴ�." << endl;

    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "��� �Ͻ÷��� �ƹ� ���ڰ��̳� �Է��ϼ���.";
    n = getNumber();                                                            //�ƹ� ���� �Է�
    system("cls");                                                              //ȭ�� ��ȯ
}

Client* ClientHandler::ClientInforeturn(string& phoneNumber)                    // �������� PK�� ��ġ�ϴ� 
                                                                                // ��ü ��ȯ(OrderInfoHandler���� Ȱ��)
{
    Client* c = nullptr;                                                        // ��ü �ʱ�ȭ
    auto it = find_if(ClientInfo.begin(), ClientInfo.end(), [=](Client* c)      // �Էµ� phoneNumber�� ���� ��ü�� it�� ����
        { return (*c).getPhoneNumber() == phoneNumber; });              
    if (it != ClientInfo.end())                                                 // it�� �� ���� �迭�� �ִ� ���
    {
        c = *it;                                                                // it�� ���� ���� ��ü�� �����ؼ� ��ȯ
    }
    else                                                                        // it�� �� ���� �迭�� ���� ���
    {
        string name = "", birthday = "", phoneNumber = "", address = "", emailAddress = "";     
        *c = { name, birthday ,phoneNumber, address, emailAddress };            // �ʱⰪ�� �����ؼ� ��ȯ
    }
    return c;
}

bool ClientHandler::HasCID(string phoneNumber)                                  // OrderInfoHandler���� �Է��ϴ� ��
                                                                                // ��ȭ��ȣ(PK)�� �ִ��� Ȯ�����ִ� �Լ�
{
    auto it = find_if(ClientInfo.begin(), ClientInfo.end(), [=](Client* c)      // �Էµ� phoneNumber�� �� ���� �迭����
        { return (*c).getPhoneNumber() == phoneNumber; });                      // ��ġ�ϴ� ��ü�� it�� ����
    return (it != ClientInfo.end())?true:false;                                 // ��ü�� �ִٸ� true ��ȯ, ���ٸ� false ��ȯ
}

vector<string> ClientHandler::parseCCSV(istream& file, char delimiter)          // �����ڿ��� �Էµ� ���� �����͸� ,������
{                                                                               // �ܾ �о���� ���� �Լ�
    stringstream ss;                                                            // ���� �����͸� ��� ���� ������ ������ 
                                                                                // ������ ���� �����ϴ� ���� ss 
    vector<string> row;                                                         // �ϼ��� �ܾ �����ϱ� ���� vector�� ���� row
    string t = " \n\r\t";                                                       // �ܾ� �ϼ������� �����ϱ� ���� ��谪 t

    while (!file.eof())                                                         // ������ ������ while���� �ݺ�
    {
        char c = file.get();                                                    // ������ �����͸� �ѱ��ھ� c�� ����
        if (c == delimiter || c == '\r' || c == '\n')                           // c�� �Էµ� ���ڰ� �����̳� ,�� ���
        {
            if (file.peek() == '\n') file.get();                                // ���� ���ڰ� �ٹٲ��̸� ����ȭ���� 
                                                                                // ���� �����͸� �����´�. 
            string s = ss.str();                                                // �о�� ���ڿ��� s�� ��´�
            s.erase(0, s.find_first_not_of(t));                                 // find_first_not_of(���ڿ�): ������ ���ڿ��� 
                                                                                // ��ġ���� �ʴ� ù��° ���� �˻� ��
                                                                                // ��ġ���� �ʴ� ���� ����
            s.erase(s.find_last_not_of(t) + 1);                                 // t�� �ٷ� �� �������� ���� => NULL���� ����
                row.push_back(s);                                               // ���� ���ڿ��� row�� ����(���� ������ �ϼ�) 
            ss.str("");                                                         // ���� ss �ʱ�ȭ
            if (c != delimiter) break;                                          // c ���� ,�� �ƴ� ��� Ż��
        }
        else                                                                    // c�� �Էµ� ���ڰ� �����̳� ,�� �ƴ� ���
        {
            ss << c;                                                            // ss�� c���� ����
        }
    }
    return row;                                                                 // row�� ����� vector ��ȯ
}
