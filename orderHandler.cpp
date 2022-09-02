#include "OrderInfoHandler.h"

void OrderInfoHandler::OrderInfoEnroll()
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

void OrderInfoHandler::OrderInfoSearchShow(string& ordercode, ClientHandler& CH, ProductHandler &PH)
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

void OrderInfoHandler::OrderInfoShowlist(ProductHandler& PH)
{
    for (auto O : OrderInfoInfo)
    {
        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "�ֹ��ڵ�: " << O->getOrderCode() << " / �ֹ�����: " << O->getOrderDate() << " / �ֹ�����: "
            << O->getOrderNumber() << endl << "��ǰ ����: " << getPPrice(O->getPID(), PH) << " / �� ����: "
            << (getPPrice(O->getPID(), PH)) * (O->getOrderNumber()) << endl;
        cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
    }
}

void OrderInfoHandler::OrderInfoRemove()
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

void OrderInfoHandler::OrderInfoEdit()
{
    int m, n, x;
    string s;
    cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "������ ������ ���� �Է��ϼ���.";
    cin >> n;
    cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "������ ������ ���� �Է��ϼ���.";
    cin >> m;
    cout << "��������������������������������������������������������������������������������������������������������������������" << endl;
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

string OrderInfoHandler::getCName(string phoneNumber, ClientHandler& CH)
{
    string Cname = CInfo.ClientInforeturn(phoneNumber)->getName();
    return Cname;
}

string OrderInfoHandler::getCAddress(string phoneNumber, ClientHandler& CH)
{
    string CAdress = CInfo.ClientInforeturn(phoneNumber)->getAddress();
    return CAdress;
}

string OrderInfoHandler::getPName(int productID, ProductHandler &PH)
{
    string Pname = PInfo.ProductInfoReturn(productID)->getProductName();
    return Pname;
}

int OrderInfoHandler::getPPrice(int productID, ProductHandler& PH)
{
   int price = PInfo.ProductInfoReturn(productID)->getProductPrice();
   return price;
}