#include "orderInfoHandler.h"

void orderInfoHandler::OrderInfoEnroll()
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

void orderInfoHandler::OrderInfoSearch(string& ordercode)
{
    auto it = find_if(OrderInfoInfo.begin(), OrderInfoInfo.end(), [=](OrderInfo* O)
        { return (*O).getOrderCode() == ordercode; });

    if (it != OrderInfoInfo.end())
    {
        cout << "주문코드: " << (*it)->getOrderCode() << ", 주문일자: " << (*it)->getOrderDate() << ", 주문수량: "
            << (*it)->getOrderNumber() << ", CID: " << (*it)->getCID() << ", PID: " << (*it)->getPID() << endl;
    }
    else
        cout << "일치하는 데이터가 없습니다." << endl;
}

void orderInfoHandler::OrderInfoShowlist()
{
    for (auto O : OrderInfoInfo)
    {
        cout << "주문코드: " << O->getOrderCode() << ", 주문일자: " << O->getOrderDate() << ", 주문수량: "
            << O->getOrderNumber() << ", CID: " << O->getCID() << ", PID: " << O->getPID() << endl;
    }
}

void orderInfoHandler::OrderInfoRemove()
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

void orderInfoHandler::OrderInfoEdit()
{
    int m, n, x;
    string s;
    cout << "변경할 데이터 행을 입력하세요.";
    cin >> n;
    cout << "변경할 데이터 열을 입력하세요.";
    cin >> m;
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
    cout << "데이터 변경이 완료되었습니다." << endl;
}