//°¢ ÇÔ¼ö ³»ÀÇ try, catch±¸¹®Àº int Çü ÀÔ·Â »óÈ²¿¡¼­ ´Ù¸¥ ÇüÅÂÀÇ µ¥ÀÌÅÍ°¡ ÀÔ·ÂµÆÀ» °æ¿ì¸¦ Ã³¸®ÇÏ±â À§ÇÔÀÓ.

#include "ProductHandler.h"
using namespace std;
#include <sstream>
#include <fstream>

ProductHandler::ProductHandler()
{
    ifstream file; //ÆÄÀÏ Ãâ·Â °´Ã¼ »ý¼º
    file.open("productinfo.txt"); //ÀÔ·ÂÆÄÀÏ ÀÌ¸§
    if (!file.fail()) 
    {
        while (!file.eof()) // end of file => true°¡ µÇ´Â ÁöÁ¡¿¡¼­ ¸¶Áö¸· 
        { 
            vector<string> row = parsePCSV(file, ',');
            if (row.size()) 
            {
                int pid = stoi(row[0]); //stringÇü ¹®ÀÚ¸¦ int Çü½ÄÀ¸·Î ¹Ù²ã¼­ ³Ö¾îÁØ´Ù
                int pprice = stoi(row[2]); //stringÇü ¹®ÀÚ¸¦ int Çü½ÄÀ¸·Î ¹Ù²ã¼­ ³Ö¾îÁØ´Ù
                Product* p = new Product(pid, row[1], pprice, row[3]);
                ProductInfo.push_back(p);
            }
        }
    }
}

ProductHandler::~ProductHandler()
{
    ofstream file;
    file.open("productinfo.txt");
    if (!file.fail()) 
    {
        for (const auto& v : ProductInfo) 
        {
            Product* p = v;
            file << p->getProductID() << ", " << p->getProductName() << ", ";
            file << p->getProductPrice() << ", ";
            file << p->getProductSort() << endl;
        }
    }
    file.close();
}

void ProductHandler::productEnroll() // Á¦Ç°ID(PK)´Â ÀÚµ¿»ý¼º, Á¦Ç°¸í, Á¦Ç°°¡°Ý, Á¦Ç°Á¾·ù ÀÔ·Â ÈÄ Á¤º¸ ÀúÀå
{
    int x;
    string s;
    Product* PInfo1 = new Product;
    int productID = makeProductID();
    PInfo1->setProductID(productID);
    cout << "Á¦Ç°¸í: ";
    cin >> s;
    PInfo1->setProductName(s);
    s.clear();
PTO1:    
    cout << "Á¦Ç° °¡°Ý: ";
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
            goto PTO1;
        }
    }
    PInfo1->setProductPrice(x);
    cout << "Á¦Ç° Á¾·ù: ";
    cin >> s;
    PInfo1->setProductSort(s);
    s.clear();
    ProductInfo.push_back(PInfo1);
}

void ProductHandler::productSearch() //¹è¿­¿¡ ÀúÀåµÈ Á¤º¸¸¦ °Ë»öÇØ¼­ ÀÏÄ¡ÇÏ´Â Á¤º¸ ÇÑ ÁÙ Ãâ·Â
{
    int productID;
PTO2:    
    cout << "Ã£À¸½Ã´Â Á¦Ç°ÀÇ ID¸¦ ÀÔ·ÂÇÏ¼¼¿ä. ";
    cin >> productID;
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
            goto PTO2;
        }
    }

    auto it = find_if(ProductInfo.begin(), ProductInfo.end(), [=](Product* p)
        { return (*p).getProductID() == productID; });

    if (it != ProductInfo.end())
    {
        cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
        cout << "Á¦Ç° ID: " << (*it)->getProductID() << " / Á¦Ç°¸í: " << (*it)->getProductName() << " / Á¦Ç° °¡°Ý: " 
            << (*it)->getProductPrice() << endl << "Á¦Ç° Á¾·ù: " << (*it)->getProductSort() << endl;
        cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
    }
    else
        cout << "ÀÏÄ¡ÇÏ´Â µ¥ÀÌÅÍ°¡ ¾ø½À´Ï´Ù." << endl;
}

void ProductHandler::productShowlist() //ÀÔ·ÂµÈ ¸ðµç Á¦Ç° Á¤º¸ Ãâ·Â
{
    int cnt = 0;
    if (ProductInfo.empty() == false)
    {
        for (auto P : ProductInfo)
        {
            cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
            cout << "µ¥ÀÌÅÍ Çà: " << cnt++ << endl;
            cout << "Á¦Ç° ID: " << P->getProductID() << " / Á¦Ç°¸í: " << P->getProductName() << " / Á¦Ç° °¡°Ý: "
                << P->getProductPrice() << endl << "Á¦Ç° Á¾·ù: " << P->getProductSort() << endl;
            cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
        }
    }

    else
        cout << "µî·ÏµÈ µ¥ÀÌÅÍ°¡ ¾ø½À´Ï´Ù." << endl;
}

void ProductHandler::productRemove() // ÀÔ·ÂµÈ Á¤º¸ Áß ÇÑ Çà Á¦°Å
{
    int n;
    if (ProductInfo.empty() == false)
    {
        productShowlist();
PTO3:   cout << "»èÁ¦ÇÒ µ¥ÀÌÅÍ ÇàÀ» ÀÔ·ÂÇÏ¼¼¿ä.";
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
                goto PTO3;
            }
        }
        else{
            if (n >= ProductInfo.size() || n < 0)
                cout << "ÀÔ·ÂµÈ Çà¿¡ µ¥ÀÌÅÍ°¡ ¾ø½À´Ï´Ù." << endl;
            else
            {
                ProductInfo.erase(ProductInfo.begin() + n);
                cout << "»èÁ¦°¡ ¿Ï·áµÇ¾ú½À´Ï´Ù." << endl;
            }
        }
    }
    else
        cout << "µî·ÏµÈ µ¥ÀÌÅÍ°¡ ¾ø½À´Ï´Ù." << endl;
}

void ProductHandler::productEdit() // ÀÔ·ÂµÈ Á¤º¸ Áß Æ¯Á¤ ÇàÀÇ Æ¯Á¤ ¿­ µ¥ÀÌÅÍ º¯°æ
{
    int n, m, x;
    string s;
    if (ProductInfo.empty() == false)
    {
        productShowlist();
        cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
PTO4:   cout << "º¯°æÇÒ µ¥ÀÌÅÍ ÇàÀ» ÀÔ·ÂÇÏ¼¼¿ä.";
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
                    goto PTO4;
                }
            }
            if (n >= ProductInfo.size() || n < 0)
                cout << "ÀÔ·ÂµÈ Çà¿¡ µ¥ÀÌÅÍ°¡ ¾ø½À´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä" << endl;
        } while (n >= ProductInfo.size() || n < 0);

        cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
PTO5:   cout << "1: Á¦Ç°¸í / 2: Á¦Ç° °¡°Ý / 3: Á¦Ç° Á¾·ù" << endl;
        cout << "º¯°æÇÒ µ¥ÀÌÅÍ ¿­À» ÀÔ·ÂÇÏ¼¼¿ä.";
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
                    goto PTO5;
                }
            }
            if (m < 1 || m > 3)
                cout << "Àß¸øµÈ ¼ýÀÚÀÔ´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä" << endl;
        } while (m < 1 || m > 3);
        cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
        cout << "º¯°æÇÒ µ¥ÀÌÅÍ ³»¿ëÀ» ÀÔ·ÂÇÏ¼¼¿ä.";
        switch (m)
        {
        case 1:
        {
            cin >> s;
            ProductInfo[n]->setProductName(s);
            s.clear();
        }break;
        case 2:
        {
            cin >> x;
            ProductInfo[n]->setProductPrice(x);
        }break;
        case 3:
        {
            cin >> s;
            ProductInfo[n]->setProductSort(s);
            s.clear();
        }break;
        }
        cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
        cout << "µ¥ÀÌÅÍ º¯°æÀÌ ¿Ï·áµÇ¾ú½À´Ï´Ù." << endl;
        cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
    }
    else
        cout << "µî·ÏµÈ µ¥ÀÌÅÍ°¡ ¾ø½À´Ï´Ù." << endl;
}

Product* ProductHandler::ProductInfoReturn(int& productID) // Á¦Ç°Á¤º¸ÀÇ PK¿Í ÀÏÄ¡ÇÏ´Â °´Ã¼ ¹ÝÈ¯À» À§ÇÑ ÇÔ¼ö(OrderInfoHandler¿¡¼­ È°¿ë)
{
    auto it = find_if(ProductInfo.begin(), ProductInfo.end(), [=](Product *p)
        { return (*p).getProductID() == productID; });
    
    if (it != ProductInfo.end()) 
        return *it;
}

int ProductHandler::makeProductID()// Á¦Ç°ÄÚµå´Â 1,000¹øºÎÅÍ ÀÚµ¿ »ý¼º
{

    if (ProductInfo.size() == 0)
        return 1000;
    else if(ProductInfo.size() > 0)
    {
        int i = (*ProductInfo.rbegin())->getProductID();
        return ++i;
    }
}


bool ProductHandler::HasPID(int &productID)
{
    auto it = find_if(ProductInfo.begin(), ProductInfo.end(), [=](Product* p)
        { return (*p).getProductID() == productID; });
    return (it != ProductInfo.end()) ? true : false;
}

vector<string> ProductHandler::parsePCSV(istream& file, char delimiter)
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