//°¢ ÇÔ¼ö ³»ÀÇ try, catch±¸¹®Àº int Çü ÀÔ·Â »óÈ²¿¡¼­ ´Ù¸¥ ÇüÅÂÀÇ µ¥ÀÌÅÍ°¡ ÀÔ·ÂµÆÀ» °æ¿ì¸¦ Ã³¸®ÇÏ±â À§ÇÔÀÓ.
//goto±¸¹®Àº throwÀÌÈÄ ÀçÀÔ·ÂÀ» ¹Þ±â À§ÇÑ ÁöÁ¡À¸·Î µ¹·ÁÁÜ.

#include "OrderInfoHandler.h"
#include <sstream>
#include <fstream>
#include <iostream>
using namespace std;

OrderInfoHandler::OrderInfoHandler(ClientHandler& CH, ProductHandler& PH) : CInfo(CH), PInfo(PH) 
{
    ifstream file; //ÆÄÀÏ Ãâ·Â °´Ã¼ »ý¼º
    file.open("orderinfoinfo.txt"); //ÀÔ·ÂÆÄÀÏ ÀÌ¸§
    if (!file.fail())
    {
        while (!file.eof()) // end of file => true°¡ µÇ´Â ÁöÁ¡¿¡¼­ ¸¶Áö¸·
        {
            vector<string> row = parseOCSV(file, ',');
            if (row.size())
            {
                int oid = stoi(row[0]); //stringÇü ¹®ÀÚ¸¦ int Çü½ÄÀ¸·Î ¹Ù²ã¼­ ³Ö¾îÁØ´Ù
                int odate = stoi(row[1]); //stringÇü ¹®ÀÚ¸¦ int Çü½ÄÀ¸·Î ¹Ù²ã¼­ ³Ö¾îÁØ´Ù
                int onumber = stoi(row[2]); //stringÇü ¹®ÀÚ¸¦ int Çü½ÄÀ¸·Î ¹Ù²ã¼­ ³Ö¾îÁØ´Ù
                int oPID = stoi(row[4]); //stringÇü ¹®ÀÚ¸¦ int Çü½ÄÀ¸·Î ¹Ù²ã¼­ ³Ö¾îÁØ´Ù
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

void OrderInfoHandler::OrderInfoEnroll() // ÁÖ¹®ÄÚµå(PK)´Â ÀÚµ¿»ý¼º, ÁÖ¹®ÀÏÀÚ, ÁÖ¹®¼ö·®, °í°´PK, Á¦Ç° PK ÀÔ·Â ÈÄ Á¤º¸ ÀúÀå
{
    int x;
    string s;
    OrderInfo* OrderInfoInfo1 = new OrderInfo;
    
    int orderCode = MakeOrderCode();
    OrderInfoInfo1->setOrderCode(orderCode);
OTO1:
    cout << "ÁÖ¹®ÀÏÀÚ: ";
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
            cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
            cout << "Àß¸øµÈ ÀÔ·ÂÀÔ´Ï´Ù." << endl;
            cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
            goto OTO1;
        }
    }
    OrderInfoInfo1->setOrderDate(x);
OTO2:
    cout << "ÁÖ¹®¼ö·®: ";
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
            cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
            cout << "Àß¸øµÈ ÀÔ·ÂÀÔ´Ï´Ù." << endl;
            cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
            goto OTO2;
        }
    }
    OrderInfoInfo1->setOrderNumber(x);
    
    cout << "CID(Á¾·á: -1): ";
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
            cout << "ÀÔ·ÂÇÏ½Å CID´Â µî·ÏµÇÁö ¾ÊÀº CIDÀÔ´Ï´Ù." << endl;
    } while (1);
OTO3:
    cout << "PID(Á¾·á: -1): ";

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
                cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
                cout << "Àß¸øµÈ ÀÔ·ÂÀÔ´Ï´Ù." << endl;
                cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
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
            cout << "ÀÔ·ÂÇÏ½Å PID´Â µî·ÏµÇÁö ¾ÊÀº PIDÀÔ´Ï´Ù." << endl;
    } while (1);
    OrderInfoInfo1->setPID(x);
    OrderInfoInfo.push_back(OrderInfoInfo1);
}

void OrderInfoHandler::OrderInfoSearchShow(ClientHandler& CH, ProductHandler &PH) // ¸ðµç ÁÖ¹® Á¤º¸ Áß ÁÖ¹®ÄÚµå(PK)¿Í ÀÏÄ¡ÇÏ´Â ÁÖ¹® Á¤º¸ Ç×¸ñ Ãâ·Â
{
    int ordercode;
    cout << "Ã£À¸½Ã´Â ÁÖ¹® ÄÚµå¸¦ ÀÔ·ÂÇÏ¼¼¿ä. ";
    cin >> ordercode;

    auto it = find_if(OrderInfoInfo.begin(), OrderInfoInfo.end(), [=](OrderInfo* O)
        { return (*O).getOrderCode() == ordercode; });

    if (it != OrderInfoInfo.end())
    {
        cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
        cout << "ÁÖ¹®ÄÚµå: " << (*it)->getOrderCode() << " / ÁÖ¹®ÀÏÀÚ: " << (*it)->getOrderDate() << " / ÁÖ¹®¼ö·®: "
            << (*it)->getOrderNumber() << endl << "Á¦Ç° °¡°Ý: " << getPPrice((*it)->getPID(), PH) << " / ÃÑ °¡°Ý: " 
            << (getPPrice((*it)->getPID(), PH)) * ((*it)->getOrderNumber()) << endl;
        cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
    }
    else
        cout << "ÀÏÄ¡ÇÏ´Â µ¥ÀÌÅÍ°¡ ¾ø½À´Ï´Ù." << endl;
}

void OrderInfoHandler::OrderInfoShowlist(ClientHandler& CH,ProductHandler& PH) // µî·ÏµÈ ¸ðµç ÁÖ¹® Á¤º¸ Ãâ·Â
{
    int cnt = 0;
    if (OrderInfoInfo.empty() == false)
    {
        for (auto O : OrderInfoInfo)
        {
            cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
            cout << "µ¥ÀÌÅÍ Çà: " << cnt++ << endl;
            cout << "ÁÖ¹®ÄÚµå: " << O->getOrderCode() << " / ÁÖ¹®ÀÏÀÚ: " << O->getOrderDate() << endl
                << "°í°´¼º¸í: " << getCName(O->getCID(), CH) << " / °í°´ÁÖ¼Ò: " << getCAddress(O->getCID(), CH) << endl
                << "ÁÖ¹®¼ö·®: " << O->getOrderNumber() << " / Á¦Ç° °¡°Ý: " << getPPrice(O->getPID(), PH)
                << " / ÃÑ °¡°Ý: " << (getPPrice(O->getPID(), PH)) * (O->getOrderNumber()) << endl;
            cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
        }
    }
    else
        cout << "µî·ÏµÈ µ¥ÀÌÅÍ°¡ ¾ø½À´Ï´Ù." << endl;
}

void OrderInfoHandler::OrderInfoRemove(ClientHandler& CH, ProductHandler& PH) //Æ¯Á¤ ÁÖ¹®Á¤º¸(Çà)À» Á¦°Å
{
    int n;
    if (OrderInfoInfo.empty() == false)
    {
        OrderInfoShowlist(CInfo, PInfo);
OTO4:   cout << "»èÁ¦ÇÒ µ¥ÀÌÅÍ ÇàÀ» ÀÔ·ÂÇÏ¼¼¿ä.";
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
                cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
                cout << "Àß¸øµÈ ÀÔ·ÂÀÔ´Ï´Ù." << endl;
                cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
                goto OTO4;
            }
        }
        else{
        if (n >= OrderInfoInfo.size() || n < 0)
            cout << "ÀÔ·ÂµÈ Çà¿¡ µ¥ÀÌÅÍ°¡ ¾ø½À´Ï´Ù." << endl;
        else
        {
            OrderInfoInfo.erase(OrderInfoInfo.begin() + n);
            cout << "»èÁ¦°¡ ¿Ï·áµÇ¾ú½À´Ï´Ù." << endl;
        }
        }
    }
    else
        cout << "µî·ÏµÈ µ¥ÀÌÅÍ°¡ ¾ø½À´Ï´Ù." << endl;
}

void OrderInfoHandler::OrderInfoEdit(ClientHandler& CH, ProductHandler& PH) // Æ¯Á¤ ÁÖ¹®Á¤º¸(Çà)ÀÇ Æ¯Á¤ Ç×¸ñ(¿­) °ªÀ» º¯°æ
{
    int m, n, x;
    string s;
    if (OrderInfoInfo.empty() == false)
    {
        OrderInfoShowlist(CInfo, PInfo);
        cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
OTO5:
        cout << "º¯°æÇÒ µ¥ÀÌÅÍ ÇàÀ» ÀÔ·ÂÇÏ¼¼¿ä.";
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
                    cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
                    cout << "Àß¸øµÈ ÀÔ·ÂÀÔ´Ï´Ù." << endl;
                    cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
                    goto OTO5;
                }
            }
            if (n >= OrderInfoInfo.size() || n < 0)
                cout << "ÀÔ·ÂµÈ Çà¿¡ µ¥ÀÌÅÍ°¡ ¾ø½À´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä" << endl;
        } while (n >= OrderInfoInfo.size() || n < 0);

        cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
OTO6:   cout << "º¯°æÇÒ µ¥ÀÌÅÍ ¿­À» ÀÔ·ÂÇÏ¼¼¿ä.";
        cout << "1: ÁÖ¹® ÀÏÀÚ / 2: ÁÖ¹® ¼ö·®" << endl;
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
                    cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
                    cout << "Àß¸øµÈ ÀÔ·ÂÀÔ´Ï´Ù." << endl;
                    cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
                    goto OTO6;
                }
            }
            if (m > 2 || m < 1)
                cout << "Àß¸øµÈ ¼ýÀÚÀÔ´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä." << endl;
        } while (m > 2 || m < 1);
        cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
        cout << "º¯°æÇÒ µ¥ÀÌÅÍ ³»¿ëÀ» ÀÔ·ÂÇÏ¼¼¿ä.";

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
        cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
        cout << "µ¥ÀÌÅÍ º¯°æÀÌ ¿Ï·áµÇ¾ú½À´Ï´Ù." << endl;
        cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
    }
    else
        cout << "µî·ÏµÈ µ¥ÀÌÅÍ°¡ ¾ø½À´Ï´Ù." << endl;
}

string OrderInfoHandler::getCName(string phoneNumber, ClientHandler& CH) // °í°´PK¸¦ È°¿ëÇØ °í°´ ¼º¸í ÃßÃâ
{
    string Cname = CInfo.ClientInforeturn(phoneNumber)->getName();
    return Cname;
}

string OrderInfoHandler::getCAddress(string phoneNumber, ClientHandler& CH)// °í°´PK¸¦ È°¿ëÇØ °í°´ ÁÖ¼Ò ÃßÃâ
{
    string CAdress = CInfo.ClientInforeturn(phoneNumber)->getAddress();
    return CAdress;
}

string OrderInfoHandler::getPName(int productID, ProductHandler &PH)// Á¦Ç°PK¸¦ È°¿ëÇØ Á¦Ç°¸í ÃßÃâ
{
    string Pname = PInfo.ProductInfoReturn(productID)->getProductName();
    return Pname;
}

int OrderInfoHandler::getPPrice(int productID, ProductHandler& PH)// Á¦Ç°PK¸¦ È°¿ëÇØ Á¦Ç° °¡°Ý ÃßÃâ
{
   int price = PInfo.ProductInfoReturn(productID)->getProductPrice();
   return price;
}

int OrderInfoHandler::MakeOrderCode()// ÁÖ¹®ÄÚµå´Â 100,000¹øºÎÅÍ ÀÚµ¿ »ý¼º
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
            if (file.peek() == '\n') file.get(); //peek(): ´ÙÀ½ ¹®ÀÚ¸¦ º»´Ù. => ´ÙÀ½ ¹®ÀÚ°¡ ÁÙ¹Ù²ÞÀÌ¸é ¼­½ÄÈ­µÇÁö 
            //¾ÊÀº µ¥ÀÌÅÍ¸¦ °¡Á®¿Â´Ù. 
            string s = ss.str();
            s.erase(0, s.find_first_not_of(t)); //find_first_not_of(¹®ÀÚ¿­): ÁöÁ¤µÈ ¹®ÀÚ¿­°ú ÀÏÄ¡ÇÏÁö ¾Ê´Â 
            //Ã¹¹øÂ° °ªÀ» °Ë»ö, erase(½ÃÀÛÀÎµ¦½º, ³¡ÀÎµ¦½º(Æ÷ÇÔX)) => ½ÃÀÛÀÎµ¦½ººÎÅÍ ³¡ ÀÎµ¦½º±îÁö °Ë»ö
            s.erase(s.find_last_not_of(t) + 1); //tÀÇ ¹Ù·Î µÞ ÁöÁ¡±îÁö »èÁ¦ => NULL¹®ÀÚ »èÁ¦
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