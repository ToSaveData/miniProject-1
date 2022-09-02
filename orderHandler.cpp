#include "OrderInfoHandler.h"

void OrderInfoHandler::OrderInfoEnroll()
{
    int x;
    string s;
    OrderInfo* OrderInfoInfo1 = new OrderInfo;
    
    cout << "주문코드: ";
    cin >> s;
    OrderInfoInfo1->setOrderCode(s);
    s.clear();
    cout << "주문일자: ";
    cin >> x;
    OrderInfoInfo1->setOrderDate(x);
    cout << "주문수량: ";
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
        cout << "──────────────────────────────────────────────────────────" << endl;
        cout << "주문코드: " << (*it)->getOrderCode() << " / 주문일자: " << (*it)->getOrderDate() << " / 주문수량: "
            << (*it)->getOrderNumber() << endl << "제품 가격: " << getPPrice((*it)->getPID(), PH) << " / 총 가격: " 
            << (getPPrice((*it)->getPID(), PH)) * ((*it)->getOrderNumber()) << endl;
        cout << "──────────────────────────────────────────────────────────" << endl;
    }
    else
        cout << "일치하는 데이터가 없습니다." << endl;
}

void OrderInfoHandler::OrderInfoShowlist(ProductHandler& PH)
{
    for (auto O : OrderInfoInfo)
    {
        cout << "──────────────────────────────────────────────────────────" << endl;
        cout << "주문코드: " << O->getOrderCode() << " / 주문일자: " << O->getOrderDate() << " / 주문수량: "
            << O->getOrderNumber() << endl << "제품 가격: " << getPPrice(O->getPID(), PH) << " / 총 가격: "
            << (getPPrice(O->getPID(), PH)) * (O->getOrderNumber()) << endl;
        cout << "──────────────────────────────────────────────────────────" << endl;
    }
}

void OrderInfoHandler::OrderInfoRemove()
{
    int n;
    cout << "삭제할 데이터 행을 입력하세요.";
    cin >> n;
    if (n > OrderInfoInfo.size() || n < 0)
        cout << "입력된 행에 데이터가 없습니다." << endl;
    else
    {
        OrderInfoInfo.erase(OrderInfoInfo.begin() + n);
        cout << "삭제가 완료되었습니다." << endl;
    }
}

void OrderInfoHandler::OrderInfoEdit()
{
    int m, n, x;
    string s;
    cout << "──────────────────────────────────────────────────────────" << endl;
    cout << "변경할 데이터 행을 입력하세요.";
    cin >> n;
    cout << "──────────────────────────────────────────────────────────" << endl;
    cout << "변경할 데이터 열을 입력하세요.";
    cin >> m;
    cout << "──────────────────────────────────────────────────────────" << endl;
    cout << "변경할 데이터 내용을 입력하세요.";

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
    cout << "──────────────────────────────────────────────────────────" << endl;
    cout << "데이터 변경이 완료되었습니다." << endl;
    cout << "──────────────────────────────────────────────────────────" << endl;
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