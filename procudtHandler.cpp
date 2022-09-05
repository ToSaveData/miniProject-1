//陝 л熱 頂曖 try, catch掘僥擎 int ⑽ 殮溘 鼻�窒□� 棻艇 ⑽鷓曖 等檜攪陛 殮溘腑擊 唳辦蒂 籀葬ж晦 嬪л歜.

#include "ProductHandler.h"
using namespace std;
#include <sstream>
#include <fstream>

ProductHandler::ProductHandler()
{
    ifstream file; //だ橾 轎溘 偌羹 儅撩
    file.open("productinfo.txt"); //殮溘だ橾 檜葷
    if (!file.fail()) 
    {
        while (!file.eof()) // end of file => true陛 腎朝 雖薄縑憮 葆雖虞 
        { 
            vector<string> row = parsePCSV(file, ',');
            if (row.size()) 
            {
                int pid = stoi(row[0]); //string⑽ 僥濠蒂 int ⑽衝戲煎 夥脯憮 厥橫遽棻
                int pprice = stoi(row[2]); //string⑽ 僥濠蒂 int ⑽衝戲煎 夥脯憮 厥橫遽棻
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

void ProductHandler::productEnroll() // 薯ヶID(PK)朝 濠翕儅撩, 薯ヶ貲, 薯ヶ陛問, 薯ヶ謙盟 殮溘 �� 薑爾 盪濰
{
    int x;
    string s;
    Product* PInfo1 = new Product;
    int productID = makeProductID();
    PInfo1->setProductID(productID);
    cout << "薯ヶ貲: ";
    cin >> s;
    PInfo1->setProductName(s);
    s.clear();
PTO1:    
    cout << "薯ヶ 陛問: ";
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
            goto PTO1;
        }
    }
    PInfo1->setProductPrice(x);
    cout << "薯ヶ 謙盟: ";
    cin >> s;
    PInfo1->setProductSort(s);
    s.clear();
    ProductInfo.push_back(PInfo1);
}

void ProductHandler::productSearch() //寡翮縑 盪濰脹 薑爾蒂 匐儀п憮 橾纂ж朝 薑爾 и 還 轎溘
{
    int productID;
PTO2:    
    cout << "瓊戲衛朝 薯ヶ曖 ID蒂 殮溘ж撮蹂. ";
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
            cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
            cout << "澀跤脹 殮溘殮棲棻." << endl;
            cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
            goto PTO2;
        }
    }

    auto it = find_if(ProductInfo.begin(), ProductInfo.end(), [=](Product* p)
        { return (*p).getProductID() == productID; });

    if (it != ProductInfo.end())
    {
        cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
        cout << "薯ヶ ID: " << (*it)->getProductID() << " / 薯ヶ貲: " << (*it)->getProductName() << " / 薯ヶ 陛問: " 
            << (*it)->getProductPrice() << endl << "薯ヶ 謙盟: " << (*it)->getProductSort() << endl;
        cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
    }
    else
        cout << "橾纂ж朝 等檜攪陛 橈蝗棲棻." << endl;
}

void ProductHandler::productShowlist() //殮溘脹 賅萇 薯ヶ 薑爾 轎溘
{
    int cnt = 0;
    if (ProductInfo.empty() == false)
    {
        for (auto P : ProductInfo)
        {
            cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
            cout << "等檜攪 ч: " << cnt++ << endl;
            cout << "薯ヶ ID: " << P->getProductID() << " / 薯ヶ貲: " << P->getProductName() << " / 薯ヶ 陛問: "
                << P->getProductPrice() << endl << "薯ヶ 謙盟: " << P->getProductSort() << endl;
            cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
        }
    }

    else
        cout << "蛔煙脹 等檜攪陛 橈蝗棲棻." << endl;
}

void ProductHandler::productRemove() // 殮溘脹 薑爾 醞 и ч 薯剪
{
    int n;
    if (ProductInfo.empty() == false)
    {
        productShowlist();
PTO3:   cout << "餉薯й 等檜攪 ч擊 殮溘ж撮蹂.";
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
                goto PTO3;
            }
        }
        else{
            if (n >= ProductInfo.size() || n < 0)
                cout << "殮溘脹 ч縑 等檜攪陛 橈蝗棲棻." << endl;
            else
            {
                ProductInfo.erase(ProductInfo.begin() + n);
                cout << "餉薯陛 諫猿腎歷蝗棲棻." << endl;
            }
        }
    }
    else
        cout << "蛔煙脹 等檜攪陛 橈蝗棲棻." << endl;
}

void ProductHandler::productEdit() // 殮溘脹 薑爾 醞 か薑 ч曖 か薑 翮 等檜攪 滲唳
{
    int n, m, x;
    string s;
    if (ProductInfo.empty() == false)
    {
        productShowlist();
        cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
PTO4:   cout << "滲唳й 等檜攪 ч擊 殮溘ж撮蹂.";
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
                    goto PTO4;
                }
            }
            if (n >= ProductInfo.size() || n < 0)
                cout << "殮溘脹 ч縑 等檜攪陛 橈蝗棲棻. 棻衛 殮溘ж撮蹂" << endl;
        } while (n >= ProductInfo.size() || n < 0);

        cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
PTO5:   cout << "1: 薯ヶ貲 / 2: 薯ヶ 陛問 / 3: 薯ヶ 謙盟" << endl;
        cout << "滲唳й 等檜攪 翮擊 殮溘ж撮蹂.";
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
                    goto PTO5;
                }
            }
            if (m < 1 || m > 3)
                cout << "澀跤脹 璋濠殮棲棻. 棻衛 殮溘ж撮蹂" << endl;
        } while (m < 1 || m > 3);
        cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
        cout << "滲唳й 等檜攪 頂辨擊 殮溘ж撮蹂.";
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
        cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
        cout << "等檜攪 滲唳檜 諫猿腎歷蝗棲棻." << endl;
        cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
    }
    else
        cout << "蛔煙脹 等檜攪陛 橈蝗棲棻." << endl;
}

Product* ProductHandler::ProductInfoReturn(int& productID) // 薯ヶ薑爾曖 PK諦 橾纂ж朝 偌羹 奩�素� 嬪и л熱(OrderInfoHandler縑憮 �倏�)
{
    auto it = find_if(ProductInfo.begin(), ProductInfo.end(), [=](Product *p)
        { return (*p).getProductID() == productID; });
    
    if (it != ProductInfo.end()) 
        return *it;
}

int ProductHandler::makeProductID()// 薯ヶ囀萄朝 1,000廓睡攪 濠翕 儅撩
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