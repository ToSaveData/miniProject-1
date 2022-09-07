#include <sstream>
#include <fstream>
#include <iostream>
#include "OrderInfoHandler.h"

extern int getNumber();                                                         // 0~9������ ���ڸ� �Է��ϴ� �Լ�
extern int getBnumber();                                                        // �����̳� ��¥ �� ū ���� �Է� �Լ�
using namespace std;

OrderInfoHandler::OrderInfoHandler(ClientHandler& CH, ProductHandler& PH) : CInfo(CH), PInfo(PH)    
{                                                                               //������
    ifstream file;                                                              //���� ��� ��ü ����
    file.open("orderinfoinfo.txt");                                             //�Է����� �̸� ���� �� ����
    if (!file.fail())                                                           //���� �Է� ���п� ���� ����ó��
    {
        while (!file.eof())                                                     // file�� ������ while�� �ݺ�
        {
            vector<string> row = parseOCSV(file, ',');                          //,������ ���е� file �����͸� row�� ����
            if (row.size())                                                     //row�� ����� �����Ͱ� �ִٸ�
            {
                int oid = stoi(row[0]);                                          //string�� ���ڸ� int �������� �ٲ㼭 �־��ش�
                int odate = stoi(row[1]);                                        //string�� ���ڸ� int �������� �ٲ㼭 �־��ش�
                int onumber = stoi(row[2]);                                      //string�� ���ڸ� int �������� �ٲ㼭 �־��ش�
                int oPID = stoi(row[4]);                                         //string�� ���ڸ� int �������� �ٲ㼭 �־��ش�
                OrderInfo* o = new OrderInfo(oid, odate, onumber, row[3], oPID); //�Էµ� �����͸� OrderInfo ��ü�� ����
                OrderInfoInfo.push_back(o);                                      //OrderInfo ��ü�� ����� ������ �ֹ�������  
                                                                                 //�����ϴ� �迭�� �Է�
            }
        }
    }
    cout << "orderinfoinfo.txt ��� �Ϸ�" << endl;
}

OrderInfoHandler::~OrderInfoHandler()                                             //�Ҹ���
{
    ofstream file;                                                                //���� ��� ��ü ����
    file.open("orderinfoinfo.txt");                                               //��� ���� �̸� ���� �� ����
    if (!file.fail())                                                             //���� ��� ���п� ���� ����ó��
    {
        for (const auto& v : OrderInfoInfo)                                       //����� ��� �ֹ������� ���� �ݺ�
        {
            OrderInfo* o = v;                                                     //OrderInfo ��ü�� ����� �ֹ����� ����
            file << o->getOrderCode() << ", " << o->getOrderDate() << ", ";       //�ֹ��ڵ�� �ֹ����ڸ� ,������ �߶� �Է�
            file << o->getOrderNumber() << ", ";                                  //�ֹ������� , ������ �߶� �Է�
            file << o->getCID() << ", " << o->getPID() << endl;                   //�� ��ȭ��ȣ�� ��ǰID�� ,������ �߶� �Է�
        }
    }
    file.close();                                                                 //���� �ݱ�
}

void OrderInfoHandler::OrderInfoEnroll()                                          //�ֹ� ���� ���
{
    int x;                                                                      //int ������ ���� �Է��� �ޱ� ���� ����
    string s;                                                                   //string ������ ���� �Է��� �ޱ� ���� ����
    OrderInfo* OrderInfoInfo1 = new OrderInfo;                                  //�ֹ� ���� ������ ���� OrderInfo* ������  
                                                                                //��ü ���� �� �ʱ�ȭ
    int orderCode = MakeOrderCode();                                            //�ֹ��ڵ� ���� �� orderCode ������ ����
    OrderInfoInfo1->setOrderCode(orderCode);                                    //�ֹ��ڵ带 ��ü�� ����
    cout << "�ֹ�����: ";
    x = getBnumber();                                                           //�ֹ����� �Է�
    OrderInfoInfo1->setOrderDate(x);                                            //�ֹ����ڸ� ��ü�� ����
    cout << "�ֹ�����: ";
    x = getBnumber();                                                           //�ֹ����� �Է�
    OrderInfoInfo1->setOrderNumber(x);                                          //�ֹ� ������ ��ü�� ����
    
    cout << "CID(����: 9): ";
    do {                                                                        //�� ������ �ִ� �� ��ȭ��ȣ�� 
                                                                                //�Է��� ������ �ݺ�
        cin >> s;                                                               //�� ��ȭ��ȣ�� �Է�
        if (s == "9")                                                           //����ȭ��ȣ�� �� ��� 9�� ���� Ż��
            break;
        else if (CInfo.HasCID(s))                                               //�Է��� �� ��ȭ��ȣ�� �� ������ ���� ���
        {
            OrderInfoInfo1->setCID(s);                                          //�� ��ȭ��ȣ�� ��ü�� ����
            s.clear();                                                          //s�� �����ϱ� ���� ���� ����
            break;
        }
        else if(!CInfo.HasCID(s))                                               //�Է��� �� ��ȭ��ȣ�� �� ������ ���� ���
            cout << "�Է��Ͻ� CID�� ��ϵ��� ���� CID�Դϴ�." << endl;
    } while (1);

    cout << "PID(����: 9): ";
    do {                                                                        //��ǰ ������ �ִ� ��ǰID�� 
                                                                                //�Է��� ������ �ݺ�
    x = getBnumber();                                                           //��ǰID�� �Է�
        if (9 == x)                                                             //��ǰID�� �� ��� 9�� ���� Ż��
            break;
        else if (PInfo.HasPID(x))                                               //�Է��� ��ǰID�� ��ǰ ������ ���� ���
        {
            OrderInfoInfo1->setPID(x);                                          //��ǰID�� ��ü�� ����
            break;
        }
        else if (!PInfo.HasPID(x))                                              //�Է��� ��ǰID�� ��ǰ ������ ���� ���
            cout << "�Է��Ͻ� PID�� ��ϵ��� ���� PID�Դϴ�." << endl;
    } while (1);
    OrderInfoInfo.push_back(OrderInfoInfo1);                                    //��ü�� ����� ������ vector �迭�� ����

    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "��� �Ͻ÷��� �ƹ� ���ڰ��̳� �Է��ϼ���.";
    x = getNumber();                                                            //�ƹ� ���� �Է�
    system("cls");                                                              //ȭ�� ��ȯ
}

void OrderInfoHandler::OrderInfoSearchShow(ClientHandler& CH, ProductHandler &PH) // ��� ��ǰ ���� �� ��ȭ��ȣ(PK)�� 
                                                                                  // ��ġ�ϴ� �׸��� ��ǰ���� ���
{
    int ordercode, n;                                                             //ordercode�� find_if�� �����ϱ� ���� ����
    string s;                                                                     // n�� s�� �Է��� �ޱ� ���� ����
    cout << "ã���ô� �ֹ� �ڵ带 �Է��ϼ���. ";
    ordercode = getBnumber();                                                     // �ֹ��ڵ带 �Է�

    auto it = find_if(OrderInfoInfo.begin(), OrderInfoInfo.end(), [=](OrderInfo* O) //OrderInfoInfo���� ordercode��
        { return (*O).getOrderCode() == ordercode; });                              //��ġ�ϴ� ��ü�� it ���� ��ȯ

    if (it != OrderInfoInfo.end())                                                  //it�� ���� end�� �ƴϸ�
    {
        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "�ֹ��ڵ�: " << (*it)->getOrderCode() << " / �ֹ�����: " << (*it)->getOrderDate() << endl
            << "������: " << getCName((*it)->getCID(), CH) << " / ���ּ�: " << getCAddress((*it)->getCID(), CH) << endl
            << "�ֹ�����: " << (*it)->getOrderNumber() << " / ��ǰ ����: " << getPPrice((*it)->getPID(), PH)
            << " / �� ����: " << (getPPrice((*it)->getPID(), PH)) * ((*it)->getOrderNumber()) << endl;
        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
    }                                                                           //it ��ü�� ���� �ֹ��ڵ�, �ֹ�����, �ֹ�����,
                                                                                //�� ��ȭ��ȣ�� ��ġ�ϴ� ������, ���ּ�
                                                                                //��ǰID�� ��ġ�ϴ� ��ǰ����, �Ѱ����� ���
    else                                                                        //it�� ���� ����Ű�� ���� end���
        cout << "��ġ�ϴ� �����Ͱ� �����ϴ�." << endl;

    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "��� �Ͻ÷��� �ƹ� ���ڰ��̳� �Է��ϼ���.";
    n = getNumber();                                                             //�ƹ� ���ڳ� �Է�
    system("cls");                                                               //ȭ�� ��ȯ
}

void OrderInfoHandler::OrderInfoShowlist(ClientHandler& CH,ProductHandler& PH)   //�Էµ� �ֹ� ��ǰ ���� ���
{
    int cnt = 0;                                                                 //������ �� ����� ���� int�� ���� ����, 
                                                                                 //�ʱ�ȭ
    if (OrderInfoInfo.empty() == false)                                          //�ֹ� ������ ��� �迭�� �����Ͱ� ������ ���
    {
        for (auto O : OrderInfoInfo)                                             //�ֹ� ������ ��� �������� ����ŭ �ݺ�
        {
            cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
            cout << "������ ��: " << cnt++ << endl;
            cout << "�ֹ��ڵ�: " << O->getOrderCode() << " / �ֹ�����: " << O->getOrderDate() << endl
                << "������: " << getCName(O->getCID(), CH) << " / ���ּ�: " << getCAddress(O->getCID(), CH) << endl
                << "�ֹ�����: " << O->getOrderNumber() << " / ��ǰ ����: " << getPPrice(O->getPID(), PH)
                << " / �� ����: " << (getPPrice(O->getPID(), PH)) * (O->getOrderNumber()) << endl;
            cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
        }                                                                       //it ��ü�� ���� �ֹ��ڵ�, �ֹ�����, �ֹ�����,
                                                                                //�� ��ȭ��ȣ�� ��ġ�ϴ� ������, ���ּ�
                                                                                //��ǰID�� ��ġ�ϴ� ��ǰ����, �Ѱ����� ���
    }
    else                                                                        //it�� ���� ����Ű�� ���� end���
        cout << "��ϵ� �����Ͱ� �����ϴ�." << endl;
}

void OrderInfoHandler::OrderInfoRemove(ClientHandler& CH, ProductHandler& PH)   // Ư�� �ֹ� ����(��)�� ����
{
    int n;                                                                      // �޴� ������ ���� int�� ���� ����
    if (OrderInfoInfo.empty() == false)                                         // �ֹ� ������ ��� �迭�� �����Ͱ� ������ ���
    {
        OrderInfoShowlist(CInfo, PInfo);                                        // ���� ��ϵ� �ֹ� ����� ������
       cout << "������ ������ ���� �Է��ϼ���.";
        n = getBnumber();                                                       // ������ ������ �� ��ȣ �Է�
       
        if (n >= OrderInfoInfo.size() || n < 0)                                 // �Էµ� �࿡ �����Ͱ� ���� ��� 
            cout << "�Էµ� �࿡ �����Ͱ� �����ϴ�." << endl;
        else                                                                    // �Է��� �࿡ �ֹ� ������ ��� �迭�� 
        {                                                                       // �����Ͱ� ���� ���
            OrderInfoInfo.erase(OrderInfoInfo.begin() + n);                     // �Է��� ���� ������ ��ü ����
            cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
        }
    }
    else                                                                        // ��ǰ������ ��� �迭�� �����Ͱ� ���� ���
        cout << "��ϵ� �����Ͱ� �����ϴ�." << endl;

    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "��� �Ͻ÷��� �ƹ� ���ڰ��̳� �Է��ϼ���.";
    n = getNumber();                                                            //�ƹ� ���ڳ� �Է�
    system("cls");                                                              //ȭ�� ��ȯ
}

void OrderInfoHandler::OrderInfoEdit(ClientHandler& CH, ProductHandler& PH)     // Ư�� �ֹ�����(��)�� Ư�� �׸�(��) ���� ����
{
    int m, n, x;                                                                // ����� int�� ��� �� ���� �Է¹޴� ����
    string s;                                                                   // ����� string �� �Է°��� �޴� ����
    if (OrderInfoInfo.empty() == false)                                         // �ֹ� ������ ��� �迭�� �����Ͱ� ������ ���
    {
        OrderInfoShowlist(CInfo, PInfo);                                        // ���� ��ϵ� �ֹ� ����� ������
        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "������ ������ ���� �Է��ϼ���.";
        do {                                                                    // ����� �����Ͱ� �ִ� ���� �Է��� ������ �ݺ�
            n = getBnumber();                                                   // ������ ������ �� �Է�
            if (n >= OrderInfoInfo.size() || n < 0)                             // �Էµ� �� ���� �迭 ������ ���� ���
                cout << "�Էµ� �࿡ �����Ͱ� �����ϴ�. �ٽ� �Է��ϼ���" << endl;
        } while (n >= OrderInfoInfo.size() || n < 0);

        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "������ ������ ���� �Է��ϼ���.";
        cout << "1: �ֹ� ���� / 2: �ֹ� ����" << endl;
        do {
            m = getNumber();                                                   // ������ ������ �� �Է�
            if (m > 2 || m < 1)                                                // �Էµ� �� ���� �迭 ������ ���� ���
                cout << "�߸��� �����Դϴ�. �ٽ� �Է��ϼ���." << endl;
        } while (m > 2 || m < 1);
        cout << "\n��������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "������ ������ ������ �Է��ϼ���.";

        switch (m)
        {
        case 1:                                                                 //�ֹ� ���ڸ� �����ϴ� ���
            {
                x = getBnumber();                                               //������ �ֹ����� �Է�
                OrderInfoInfo[n]->setOrderDate(x);                              //���õ� ���� �ֹ� ���ڸ� �Էµ� ������ ����
            }break;
        case 2:                                                                 //�ֹ� ������ �����ϴ� ���
            {
                x = getBnumber();                                               //������ �ֹ� ���� ����
                OrderInfoInfo[n]->setOrderNumber(x);                            //���õ� ���� �ֹ� ������ �Էµ� ������ ����
            }break;
        }
        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "������ ������ �Ϸ�Ǿ����ϴ�." << endl;
        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
    }
    else                                                                       // �ֹ� ������ ��� �迭�� �����Ͱ� ���� ���
        cout << "��ϵ� �����Ͱ� �����ϴ�." << endl;

    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "��� �Ͻ÷��� �ƹ� ���ڰ��̳� �Է��ϼ���.";
    x = getNumber();                                                           //�ƹ� ���� �Է�
    system("cls");                                                             //ȭ�� ��ȯ
}

string OrderInfoHandler::getCName(string phoneNumber, ClientHandler& CH)       // ��PK�� Ȱ���� �� ���� ����
{
    string Cname = CInfo.ClientInforeturn(phoneNumber)->getName();
    return Cname;
}

string OrderInfoHandler::getCAddress(string phoneNumber, ClientHandler& CH)     // ��PK�� Ȱ���� �� �ּ� ����
{
    string CAdress = CInfo.ClientInforeturn(phoneNumber)->getAddress();
    return CAdress;
}

string OrderInfoHandler::getPName(int productID, ProductHandler &PH)            // ��ǰPK�� Ȱ���� ��ǰ�� ����
{
    string Pname = PInfo.ProductInfoReturn(productID)->getProductName();
    return Pname;
}

int OrderInfoHandler::getPPrice(int productID, ProductHandler& PH)              // ��ǰPK�� Ȱ���� ��ǰ ���� ����
{
   int price = PInfo.ProductInfoReturn(productID)->getProductPrice();
   return price;
}

int OrderInfoHandler::MakeOrderCode()                                           // �ֹ��ڵ带 �ڵ� �����ϴ� �Լ�
{
    int ret = -1;                                                               // int�� ��ȯ ���� -1�� �ʱ�ȭ
    if (OrderInfoInfo.size() == 0)                                              // ���� ��ϵ� �ֹ� ������ ������
        ret = 100000;                                                           // �ֹ� ������ 100000�� �Է��ؼ� ��ȯ
    else if (OrderInfoInfo.size() > 0)                                          // �̹� ��ϵ� �ֹ� ������ ������
    {
        ret = (*OrderInfoInfo.rbegin())->getOrderCode();                        //�ֹ������� �������� �ִ� �ֹ��ڵ� ret�� ����
        ++ret;                                                                  //ret�� 1�� ���ؼ� ��ȯ
    }
    return ret;                                                                 //�� ��� ��찡 �ƴ϶�� -1�� ��ȯ
}


vector<string> OrderInfoHandler::parseOCSV(istream& file, char delimiter)       // �����ڿ��� �Էµ� ���� �����͸� ,������
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