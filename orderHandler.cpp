//陝 л熱 頂曖 try, catch掘僥擎 int ⑽ 殮溘 鼻�窒□� 棻艇 ⑽鷓曖 等檜攪陛 殮溘腑擊 唳辦蒂 籀葬ж晦 嬪л歜.
//goto掘僥擎 throw檜�� 營殮溘擊 嫡晦 嬪и 雖薄戲煎 給溥邀.

#include "OrderInfoHandler.h"
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

OrderInfoHandler::OrderInfoHandler(ClientHandler& CH, ProductHandler& PH) : CInfo(CH), PInfo(PH) 
{
    ifstream file; //だ橾 轎溘 偌羹 儅撩
    file.open("orderinfoinfo.txt"); //殮溘だ橾 檜葷
    if (!file.fail())
    {
        while (!file.eof()) // end of file => true陛 腎朝 雖薄縑憮 葆雖虞
        {
            vector<string> row = parseOCSV(file, ',');
            if (row.size())
            {
                int oid = stoi(row[0]); //string⑽ 僥濠蒂 int ⑽衝戲煎 夥脯憮 厥橫遽棻
                int odate = stoi(row[1]); //string⑽ 僥濠蒂 int ⑽衝戲煎 夥脯憮 厥橫遽棻
                int onumber = stoi(row[2]); //string⑽ 僥濠蒂 int ⑽衝戲煎 夥脯憮 厥橫遽棻
                int oPID = stoi(row[4]); //string⑽ 僥濠蒂 int ⑽衝戲煎 夥脯憮 厥橫遽棻
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

void OrderInfoHandler::OrderInfoEnroll() // 輿僥囀萄(PK)朝 濠翕儅撩, 輿僥橾濠, 輿僥熱榆, 堅偌PK, 薯ヶ PK 殮溘 �� 薑爾 盪濰
{
    int x;
    string s;
    OrderInfo* OrderInfoInfo1 = new OrderInfo;
    
    int orderCode = MakeOrderCode();
    OrderInfoInfo1->setOrderCode(orderCode);
OTO1:
    cout << "輿僥橾濠: ";
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
            cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
            cout << "澀跤脹 殮溘殮棲棻." << endl;
            cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
            goto OTO1;
        }
    }
    OrderInfoInfo1->setOrderDate(x);
OTO2:
    cout << "輿僥熱榆: ";
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
            cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
            cout << "澀跤脹 殮溘殮棲棻." << endl;
            cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
            goto OTO2;
        }
    }
    OrderInfoInfo1->setOrderNumber(x);
    
    cout << "CID(謙猿: -1): ";
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
            cout << "殮溘ж褐 CID朝 蛔煙腎雖 彊擎 CID殮棲棻." << endl;
    } while (1);
OTO3:
    cout << "PID(謙猿: -1): ";

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
                cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
                cout << "澀跤脹 殮溘殮棲棻." << endl;
                cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
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
            cout << "殮溘ж褐 PID朝 蛔煙腎雖 彊擎 PID殮棲棻." << endl;
    } while (1);
    OrderInfoInfo1->setPID(x);
    OrderInfoInfo.push_back(OrderInfoInfo1);
}

void OrderInfoHandler::OrderInfoSearchShow(ClientHandler& CH, ProductHandler &PH) // 賅萇 輿僥 薑爾 醞 輿僥囀萄(PK)諦 橾纂ж朝 輿僥 薑爾 о跡 轎溘
{
    int ordercode;
    cout << "瓊戲衛朝 輿僥 囀萄蒂 殮溘ж撮蹂. ";
    cin >> ordercode;

    auto it = find_if(OrderInfoInfo.begin(), OrderInfoInfo.end(), [=](OrderInfo* O)
        { return (*O).getOrderCode() == ordercode; });

    if (it != OrderInfoInfo.end())
    {
        cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
        cout << "輿僥囀萄: " << (*it)->getOrderCode() << " / 輿僥橾濠: " << (*it)->getOrderDate() << " / 輿僥熱榆: "
            << (*it)->getOrderNumber() << endl << "薯ヶ 陛問: " << getPPrice((*it)->getPID(), PH) << " / 識 陛問: " 
            << (getPPrice((*it)->getPID(), PH)) * ((*it)->getOrderNumber()) << endl;
        cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
    }
    else
        cout << "橾纂ж朝 等檜攪陛 橈蝗棲棻." << endl;
}

void OrderInfoHandler::OrderInfoShowlist(ClientHandler& CH,ProductHandler& PH) // 蛔煙脹 賅萇 輿僥 薑爾 轎溘
{
    int cnt = 0;
    if (OrderInfoInfo.empty() == false)
    {
        for (auto O : OrderInfoInfo)
        {
            cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
            cout << "等檜攪 ч: " << cnt++ << endl;
            cout << "輿僥囀萄: " << O->getOrderCode() << " / 輿僥橾濠: " << O->getOrderDate() << endl
                << "堅偌撩貲: " << getCName(O->getCID(), CH) << " / 堅偌輿模: " << getCAddress(O->getCID(), CH) << endl
                << "輿僥熱榆: " << O->getOrderNumber() << " / 薯ヶ 陛問: " << getPPrice(O->getPID(), PH)
                << " / 識 陛問: " << (getPPrice(O->getPID(), PH)) * (O->getOrderNumber()) << endl;
            cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
        }
    }
    else
        cout << "蛔煙脹 等檜攪陛 橈蝗棲棻." << endl;
}

void OrderInfoHandler::OrderInfoRemove(ClientHandler& CH, ProductHandler& PH) //か薑 輿僥薑爾(ч)擊 薯剪
{
    int n;
    if (OrderInfoInfo.empty() == false)
    {
        OrderInfoShowlist(CInfo, PInfo);
OTO4:   cout << "餉薯й 等檜攪 ч擊 殮溘ж撮蹂.";
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
                cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
                cout << "澀跤脹 殮溘殮棲棻." << endl;
                cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
                goto OTO4;
            }
        }
        else{
        if (n >= OrderInfoInfo.size() || n < 0)
            cout << "殮溘脹 ч縑 等檜攪陛 橈蝗棲棻." << endl;
        else
        {
            OrderInfoInfo.erase(OrderInfoInfo.begin() + n);
            cout << "餉薯陛 諫猿腎歷蝗棲棻." << endl;
        }
        }
    }
    else
        cout << "蛔煙脹 等檜攪陛 橈蝗棲棻." << endl;
}

void OrderInfoHandler::OrderInfoEdit(ClientHandler& CH, ProductHandler& PH) // か薑 輿僥薑爾(ч)曖 か薑 о跡(翮) 高擊 滲唳
{
    int m, n, x;
    string s;
    if (OrderInfoInfo.empty() == false)
    {
        OrderInfoShowlist(CInfo, PInfo);
        cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
OTO5:
        cout << "滲唳й 等檜攪 ч擊 殮溘ж撮蹂.";
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
                    cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
                    cout << "澀跤脹 殮溘殮棲棻." << endl;
                    cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
                    goto OTO5;
                }
            }
            if (n >= OrderInfoInfo.size() || n < 0)
                cout << "殮溘脹 ч縑 等檜攪陛 橈蝗棲棻. 棻衛 殮溘ж撮蹂" << endl;
        } while (n >= OrderInfoInfo.size() || n < 0);

        cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
OTO6:   cout << "滲唳й 等檜攪 翮擊 殮溘ж撮蹂.";
        cout << "1: 輿僥 橾濠 / 2: 輿僥 熱榆" << endl;
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
                    cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
                    cout << "澀跤脹 殮溘殮棲棻." << endl;
                    cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
                    goto OTO6;
                }
            }
            if (m > 2 || m < 1)
                cout << "澀跤脹 璋濠殮棲棻. 棻衛 殮溘ж撮蹂." << endl;
        } while (m > 2 || m < 1);
        cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
        cout << "滲唳й 等檜攪 頂辨擊 殮溘ж撮蹂.";

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
        cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
        cout << "等檜攪 滲唳檜 諫猿腎歷蝗棲棻." << endl;
        cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
    }
    else
        cout << "蛔煙脹 等檜攪陛 橈蝗棲棻." << endl;
}

string OrderInfoHandler::getCName(string phoneNumber, ClientHandler& CH) // 堅偌PK蒂 �倏踿� 堅偌 撩貲 蹺轎
{
    string Cname = CInfo.ClientInforeturn(phoneNumber)->getName();
    return Cname;
}

string OrderInfoHandler::getCAddress(string phoneNumber, ClientHandler& CH)// 堅偌PK蒂 �倏踿� 堅偌 輿模 蹺轎
{
    string CAdress = CInfo.ClientInforeturn(phoneNumber)->getAddress();
    return CAdress;
}

string OrderInfoHandler::getPName(int productID, ProductHandler &PH)// 薯ヶPK蒂 �倏踿� 薯ヶ貲 蹺轎
{
    string Pname = PInfo.ProductInfoReturn(productID)->getProductName();
    return Pname;
}

int OrderInfoHandler::getPPrice(int productID, ProductHandler& PH)// 薯ヶPK蒂 �倏踿� 薯ヶ 陛問 蹺轎
{
   int price = PInfo.ProductInfoReturn(productID)->getProductPrice();
   return price;
}

int OrderInfoHandler::MakeOrderCode()// 輿僥囀萄朝 100,000廓睡攪 濠翕 儅撩
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
            if (file.peek() == '\n') file.get(); //peek(): 棻擠 僥濠蒂 獄棻. => 棻擠 僥濠陛 還夥翎檜賊 憮衝�音Щ� 
            //彊擎 等檜攪蒂 陛螳螞棻. 
            string s = ss.str();
            s.erase(0, s.find_first_not_of(t)); //find_first_not_of(僥濠翮): 雖薑脹 僥濠翮婁 橾纂ж雖 彊朝 
            //羅廓簞 高擊 匐儀, erase(衛濛檣策蝶, 部檣策蝶(んлX)) => 衛濛檣策蝶睡攪 部 檣策蝶梱雖 匐儀
            s.erase(s.find_last_not_of(t) + 1); //t曖 夥煎 萌 雖薄梱雖 餉薯 => NULL僥濠 餉薯
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