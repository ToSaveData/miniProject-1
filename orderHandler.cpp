#include "orderInfoHandler.h"

void orderInfoHandler::OrderInfoEnroll()
{
    int x;
    string s;
    OrderInfo* OrderInfoInfo1 = new OrderInfo;
    
    cout << "�ֹ��ڵ�: ";
    cin >> s;
    OrderInfoInfo1->setOrderCode(s);
    s.clear();
    cout << "�ֹ�����: ";
    cin >> x;
    OrderInfoInfo1->setOrderDate(x);
    cout << "�ֹ�����: ";
    cin >> x;
    OrderInfoInfo1->setOrderNumber(x);
    cout << "CID: ";
    cin >> s;
    OrderInfoInfo1->setCID(s);
    s.clear();
    cout << "PID: ";
    cin >> x;
    OrderInfoInfo1->setPID(x);
    OrderInfoInfo.push_back(OrderInfoInfo1);
}

void orderInfoHandler::OrderInfoSearchShow(string& ordercode, clientHandler& CH, productHandler &PH)
{
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

void orderInfoHandler::OrderInfoShowlist()
{
    for (auto O : OrderInfoInfo)
    {
        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "�ֹ��ڵ�: " << O->getOrderCode() << " / �ֹ�����: " << O->getOrderDate() << " / �ֹ�����: "
            << O->getOrderNumber() << endl << "CID: " << O->getCID() << " / PID: " << O->getPID() << endl;
        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
    }
}

void orderInfoHandler::OrderInfoRemove()
{
    int n;
    cout << "������ ������ ���� �Է��ϼ���.";
    cin >> n;
    if (n > OrderInfoInfo.size() || n < 0)
        cout << "�Էµ� �࿡ �����Ͱ� �����ϴ�." << endl;
    else
    {
        OrderInfoInfo.erase(OrderInfoInfo.begin() + n);
        cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
    }
}

void orderInfoHandler::OrderInfoEdit()
{
    int m, n, x;
    string s;
    cout << "������ ������ ���� �Է��ϼ���.";
    cin >> n;
    cout << "������ ������ ���� �Է��ϼ���.";
    cin >> m;
    cout << "������ ������ ������ �Է��ϼ���.";

    switch (m)
    {
    case 0:
    {
        cin >> s;
        OrderInfoInfo[n]->setOrderCode(s);
        s.clear();
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
        s.clear();
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
        s.clear();
    }break;
    }
    cout << "������ ������ �Ϸ�Ǿ����ϴ�." << endl;
}

string orderInfoHandler::getCName(string phoneNumber, clientHandler& CH)
{
    string Cname = CInfo.ClientInforeturn(phoneNumber)->getName();
    return Cname;
}

string orderInfoHandler::getCAddress(string phoneNumber, clientHandler& CH)
{
    string Adress = CInfo.ClientInforeturn(phoneNumber)->getAddress();
    return Adress;
}

string orderInfoHandler::getPName(int productID, productHandler &PH)
{
    string Pname = PInfo.ProductInfoReturn(productID)->getProductName();
    return Pname;
}

int orderInfoHandler::getPPrice(int productID, productHandler& PH)
{
   int price = PInfo.ProductInfoReturn(productID)->getProductPrice();
   return price;
}