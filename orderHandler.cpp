#include <sstream>
#include <fstream>
#include <iostream>
#include "OrderInfoHandler.h"

extern int getNumber();
extern int getBnumber();
using namespace std;

OrderInfoHandler::OrderInfoHandler(ClientHandler& CH, ProductHandler& PH) : CInfo(CH), PInfo(PH) 
{
    ifstream file; //���� ��� ��ü ����
    file.open("orderinfoinfo.txt"); //�Է����� �̸�
    if (!file.fail())
    {
        while (!file.eof()) // end of file => true�� �Ǵ� �������� ������
        {
            vector<string> row = parseOCSV(file, ',');
            if (row.size())
            {
                int oid = stoi(row[0]); //string�� ���ڸ� int �������� �ٲ㼭 �־��ش�
                int odate = stoi(row[1]); //string�� ���ڸ� int �������� �ٲ㼭 �־��ش�
                int onumber = stoi(row[2]); //string�� ���ڸ� int �������� �ٲ㼭 �־��ش�
                int oPID = stoi(row[4]); //string�� ���ڸ� int �������� �ٲ㼭 �־��ش�
                OrderInfo* o = new OrderInfo(oid, odate, onumber, row[3], oPID);
                OrderInfoInfo.push_back(o);
            }
        }
    }
    cout << "orderinfoinfo.txt ��� �Ϸ�" << endl;
}
OrderInfoHandler::~OrderInfoHandler()
{
    ofstream file;
    file.open("orderinfoinfo.txt");
    if (!file.fail())
    {
        for (const auto& v : OrderInfoInfo)
        {
            OrderInfo* o = v;
            file << o->getOrderCode() << ", " << o->getOrderDate() << ", ";
            file << o->getOrderNumber() << ", ";
            file << o->getCID() << ", " << o->getPID() << endl;
        }
    }
    file.close();
}

void OrderInfoHandler::OrderInfoEnroll() // �ֹ��ڵ�(PK)�� �ڵ�����, �ֹ�����, �ֹ�����, ��PK, ��ǰ PK �Է� �� ���� ����
{
    int x;
    string s;
    OrderInfo* OrderInfoInfo1 = new OrderInfo;
    
    int orderCode = MakeOrderCode();
    OrderInfoInfo1->setOrderCode(orderCode);
    cout << "�ֹ�����: ";
    x = getBnumber();
    OrderInfoInfo1->setOrderDate(x);
    cout << "�ֹ�����: ";
    x = getBnumber();
    OrderInfoInfo1->setOrderNumber(x);
    
    cout << "CID(����: 9): ";
    do {
        cin >> s;
        if (s == "9")
            break;
        else if (CInfo.HasCID(s))
        {
            OrderInfoInfo1->setCID(s);
            s.clear();
            break;
        }
        else if(!CInfo.HasCID(s))
            cout << "�Է��Ͻ� CID�� ��ϵ��� ���� CID�Դϴ�." << endl;
    } while (1);

    cout << "PID(����: 9): ";
    do {
    x = getBnumber();
        if (9 == x)
            break;
        else if (PInfo.HasPID(x))
        {
            OrderInfoInfo1->setPID(x);
            break;
        }
        else if (!PInfo.HasPID(x))
            cout << "�Է��Ͻ� PID�� ��ϵ��� ���� PID�Դϴ�." << endl;
    } while (1);
    OrderInfoInfo1->setPID(x);
    OrderInfoInfo.push_back(OrderInfoInfo1);

    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "��� �Ͻ÷��� �ƹ� ���ڰ��̳� �Է��ϼ���.";
    x = getNumber();
    system("cls");
}

void OrderInfoHandler::OrderInfoSearchShow(ClientHandler& CH, ProductHandler &PH) // ��� �ֹ� ���� �� �ֹ��ڵ�(PK)�� ��ġ�ϴ� �ֹ� ���� �׸� ���
{
    int ordercode, n;
    string s;
    cout << "ã���ô� �ֹ� �ڵ带 �Է��ϼ���. ";
    ordercode = getBnumber();

    auto it = find_if(OrderInfoInfo.begin(), OrderInfoInfo.end(), [=](OrderInfo* O)
        { return (*O).getOrderCode() == ordercode; });

    if (it != OrderInfoInfo.end())
    {
        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "�ֹ��ڵ�: " << (*it)->getOrderCode() << " / �ֹ�����: " << (*it)->getOrderDate() << " / �ֹ�����: "
            << (*it)->getOrderNumber() << endl << "��ǰ ����: " << getPPrice((*it)->getPID(), PH) << " / �� ����: " 
            << (getPPrice((*it)->getPID(), PH)) * ((*it)->getOrderNumber()) << endl;
        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
    }
    else
        cout << "��ġ�ϴ� �����Ͱ� �����ϴ�." << endl;

    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "��� �Ͻ÷��� �ƹ� ���ڰ��̳� �Է��ϼ���.";
    n = getNumber();
    system("cls");
}

void OrderInfoHandler::OrderInfoShowlist(ClientHandler& CH,ProductHandler& PH) // ��ϵ� ��� �ֹ� ���� ���
{
    int cnt = 0;
    if (OrderInfoInfo.empty() == false)
    {
        for (auto O : OrderInfoInfo)
        {
            cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
            cout << "������ ��: " << cnt++ << endl;
            cout << "�ֹ��ڵ�: " << O->getOrderCode() << " / �ֹ�����: " << O->getOrderDate() << endl
                << "������: " << getCName(O->getCID(), CH) << " / ���ּ�: " << getCAddress(O->getCID(), CH) << endl
                << "�ֹ�����: " << O->getOrderNumber() << " / ��ǰ ����: " << getPPrice(O->getPID(), PH)
                << " / �� ����: " << (getPPrice(O->getPID(), PH)) * (O->getOrderNumber()) << endl;
            cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
        }
    }
    else
        cout << "��ϵ� �����Ͱ� �����ϴ�." << endl;
}

void OrderInfoHandler::OrderInfoRemove(ClientHandler& CH, ProductHandler& PH) //Ư�� �ֹ�����(��)�� ����
{
    int n;
    string s;
    if (OrderInfoInfo.empty() == false)
    {
        OrderInfoShowlist(CInfo, PInfo);
       cout << "������ ������ ���� �Է��ϼ���.";
        n = getBnumber();
       
        if (n >= OrderInfoInfo.size() || n < 0)
            cout << "�Էµ� �࿡ �����Ͱ� �����ϴ�." << endl;
        else
        {
            OrderInfoInfo.erase(OrderInfoInfo.begin() + n);
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

void OrderInfoHandler::OrderInfoEdit(ClientHandler& CH, ProductHandler& PH) // Ư�� �ֹ�����(��)�� Ư�� �׸�(��) ���� ����
{
    int m, n, x;
    string s;
    if (OrderInfoInfo.empty() == false)
    {
        OrderInfoShowlist(CInfo, PInfo);
        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "������ ������ ���� �Է��ϼ���.";
        do {
            n = getBnumber();
            if (n >= OrderInfoInfo.size() || n < 0)
                cout << "�Էµ� �࿡ �����Ͱ� �����ϴ�. �ٽ� �Է��ϼ���" << endl;
        } while (n >= OrderInfoInfo.size() || n < 0);

        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "������ ������ ���� �Է��ϼ���.";
        cout << "1: �ֹ� ���� / 2: �ֹ� ����" << endl;
        do {
            m = getNumber();
            if (m > 2 || m < 1)
                cout << "�߸��� �����Դϴ�. �ٽ� �Է��ϼ���." << endl;
        } while (m > 2 || m < 1);
        cout << "\n��������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "������ ������ ������ �Է��ϼ���.";

        switch (m)
        {
        case 0:
        {
            x = getBnumber();
            OrderInfoInfo[n]->setOrderCode(x);
        }break;
        case 1:
        {
            x = getBnumber();
            OrderInfoInfo[n]->setOrderDate(x);
        }break;
        case 2:
        {
            x = getBnumber();
            OrderInfoInfo[n]->setOrderNumber(x);
        }break;
        case 3:
        {
            cin >> s;
            OrderInfoInfo[n]->setCID(s);
            s.clear();
        }break;
        case 4:
        {
            x = getBnumber();
            OrderInfoInfo[n]->setPID(x);
        }break;
        }
        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "������ ������ �Ϸ�Ǿ����ϴ�." << endl;
        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
    }
    else
        cout << "��ϵ� �����Ͱ� �����ϴ�." << endl;

    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "��� �Ͻ÷��� �ƹ� ���ڰ��̳� �Է��ϼ���.";
    x = getNumber();
    system("cls");
}

string OrderInfoHandler::getCName(string phoneNumber, ClientHandler& CH) // ��PK�� Ȱ���� �� ���� ����
{
    string Cname = CInfo.ClientInforeturn(phoneNumber)->getName();
    return Cname;
}

string OrderInfoHandler::getCAddress(string phoneNumber, ClientHandler& CH)// ��PK�� Ȱ���� �� �ּ� ����
{
    string CAdress = CInfo.ClientInforeturn(phoneNumber)->getAddress();
    return CAdress;
}

string OrderInfoHandler::getPName(int productID, ProductHandler &PH)// ��ǰPK�� Ȱ���� ��ǰ�� ����
{
    string Pname = PInfo.ProductInfoReturn(productID)->getProductName();
    return Pname;
}

int OrderInfoHandler::getPPrice(int productID, ProductHandler& PH)// ��ǰPK�� Ȱ���� ��ǰ ���� ����
{
   int price = PInfo.ProductInfoReturn(productID)->getProductPrice();
   return price;
}

int OrderInfoHandler::MakeOrderCode()// �ֹ��ڵ�� 100,000������ �ڵ� ����
{

    if (OrderInfoInfo.size() == 0)
        return 100000;
    else if (OrderInfoInfo.size() > 0)
    {
        int i = (*OrderInfoInfo.rbegin())->getOrderCode();
        return ++i;
    }
}

vector<string> OrderInfoHandler::parseOCSV(istream& file, char delimiter)
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