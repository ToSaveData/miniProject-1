//�� �Լ� ���� try, catch������ int �� �Է� ��Ȳ���� �ٸ� ������ �����Ͱ� �Էµ��� ��츦 ó���ϱ� ������.
//goto������ throw���� ���Է��� �ޱ� ���� �������� ������.

#include "OrderInfoHandler.h"
#include <sstream>
#include <fstream>
#include <iostream>
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
OTO1:
    cout << "�ֹ�����: ";
    cin >> x;
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
            goto OTO1;
        }
    }
    OrderInfoInfo1->setOrderDate(x);
OTO2:
    cout << "�ֹ�����: ";
    cin >> x;
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
            goto OTO2;
        }
    }
    OrderInfoInfo1->setOrderNumber(x);
    
    cout << "CID(����: -1): ";
    do {
        cin >> s;
        if (s == "-1")
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
OTO3:
    cout << "PID(����: -1): ";

    do {
        cin >> x;
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
                goto OTO3;
            }
        }
        if (-1 == x)
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
}

void OrderInfoHandler::OrderInfoSearchShow(ClientHandler& CH, ProductHandler &PH) // ��� �ֹ� ���� �� �ֹ��ڵ�(PK)�� ��ġ�ϴ� �ֹ� ���� �׸� ���
{
    int ordercode;
    cout << "ã���ô� �ֹ� �ڵ带 �Է��ϼ���. ";
    cin >> ordercode;

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
    if (OrderInfoInfo.empty() == false)
    {
        OrderInfoShowlist(CInfo, PInfo);
OTO4:   cout << "������ ������ ���� �Է��ϼ���.";
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
                goto OTO4;
            }
        }
        else{
        if (n >= OrderInfoInfo.size() || n < 0)
            cout << "�Էµ� �࿡ �����Ͱ� �����ϴ�." << endl;
        else
        {
            OrderInfoInfo.erase(OrderInfoInfo.begin() + n);
            cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
        }
        }
    }
    else
        cout << "��ϵ� �����Ͱ� �����ϴ�." << endl;
}

void OrderInfoHandler::OrderInfoEdit(ClientHandler& CH, ProductHandler& PH) // Ư�� �ֹ�����(��)�� Ư�� �׸�(��) ���� ����
{
    int m, n, x;
    string s;
    if (OrderInfoInfo.empty() == false)
    {
        OrderInfoShowlist(CInfo, PInfo);
        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
OTO5:
        cout << "������ ������ ���� �Է��ϼ���.";
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
                    goto OTO5;
                }
            }
            if (n >= OrderInfoInfo.size() || n < 0)
                cout << "�Էµ� �࿡ �����Ͱ� �����ϴ�. �ٽ� �Է��ϼ���" << endl;
        } while (n >= OrderInfoInfo.size() || n < 0);

        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
OTO6:   cout << "������ ������ ���� �Է��ϼ���.";
        cout << "1: �ֹ� ���� / 2: �ֹ� ����" << endl;
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
                    goto OTO6;
                }
            }
            if (m > 2 || m < 1)
                cout << "�߸��� �����Դϴ�. �ٽ� �Է��ϼ���." << endl;
        } while (m > 2 || m < 1);
        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "������ ������ ������ �Է��ϼ���.";

        switch (m)
        {
        case 0:
        {
            cin >> x;
            OrderInfoInfo[n]->setOrderCode(x);
        }break;
        case 1:
        {
            cin >> x;
            OrderInfoInfo[n]->setOrderDate(x);
        }break;
        case 2:
        {
            cin >> x;
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
            cin >> x;
            OrderInfoInfo[n]->setPID(x);
        }break;
        }
        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "������ ������ �Ϸ�Ǿ����ϴ�." << endl;
        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
    }
    else
        cout << "��ϵ� �����Ͱ� �����ϴ�." << endl;
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