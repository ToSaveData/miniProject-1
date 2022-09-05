//陝 л熱 頂曖 try, catch掘僥擎 int ⑽ 殮溘 鼻�窒□� 棻艇 ⑽鷓曖 等檜攪陛 殮溘腑擊 唳辦蒂 籀葬ж晦 嬪л歜.

#include "ClientHandler.h"
#include <string>
#include <fstream>
#include <sstream>
ClientHandler::ClientHandler()
{
    ifstream file; //だ橾 轎溘 偌羹 儅撩
    file.open("clientinfo.txt"); //殮溘だ橾 檜葷
    if (!file.fail()) 
    {
        while (!file.eof()) // end of file => true陛 腎朝 雖薄縑憮 葆雖虞
        { 
            vector<string> row = parseCCSV(file, ',');
            if (row.size()) 
            {
                Client* c = new Client(row[0], row[1], row[2], row[3], row[4]);
                ClientInfo.push_back(c);
            }
        }
    }
}

ClientHandler::~ClientHandler()
{
    ofstream file;
    file.open("clientinfo.txt");
    if (!file.fail()) 
    {
        for (const auto& v : ClientInfo) 
        {
            Client* c = v;
            file << c->getName() << ", " << c->getBirthday() << ", ";
            file << c->getPhoneNumber() << ", ";
            file << c->getAddress() << ", " << c->getEmailAddress() << endl;
        }
    }
    file.close();
}
void ClientHandler::ClientEnroll()// 撩貲, 儅喇錯橾, 瞪�食醽�, 輿模, 檜詭橾 輿模 殮溘 �� 薑爾 盪濰
{
    string s;
    cout << "檜葷: ";
    cin >> s;
    Client* CInfo1 = new Client;
    CInfo1->setName(s);
    s.clear();
    cout << "儅喇錯橾(ex.220830): ";
    cin >> s;
    CInfo1->setBirthday(s);
    s.clear();
    cout << "瞪�食醽�(ex.010-1234-5678): ";
    cin >> s;
    CInfo1->setPhoneNumber(s);
    s.clear();
    cout << "輿模(ex.憮選衛 謙煎掘 ���音�): ";
    cin.ignore(); // 擅曖 и 旋濠(enter)蒂 鼠衛ж朝 唳辦
    getline(cin, s, '\n'); // '\n'陛 菟橫螢 陽梱雖 嫡啊棻
    CInfo1->setAddress(s);
    s.clear();
    cout << "檜詭橾輿模(ex.example@gmail.com): "; // 棻寞賊 翱塊蜂 �捏虜� 嬪л
    cin >> s;
    CInfo1->setEmailAddress(s);
    s.clear();
    ClientInfo.push_back(CInfo1);
}


void ClientHandler::ClientSearch() // 賅萇 堅偌 薑爾 醞 瞪�食醽�(PK)陛 橾纂ж朝 о跡曖 堅偌薑爾 轎溘
{
    string phoneNumber;
    cout << "瓊戲衛朝 堅偌曖 瞪�食醽ㄧ� 殮溘ж撮蹂(010-xxxx-xxxx). ";
    cin >> phoneNumber;

    auto it = find_if(ClientInfo.begin(), ClientInfo.end(), [=](Client* c) 
        { return (*c).getPhoneNumber() == phoneNumber; });
    
    if (it != ClientInfo.end())
    {
        cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
        cout << "檜葷: " << (*it)->getName() << " / 儅喇錯橾: " << (*it)->getBirthday() << " / 瞪�食醽�: " << (*it)->getPhoneNumber()
            << endl << "輿模: " << (*it)->getAddress() << " / 檜詭橾 輿模: " << (*it)->getEmailAddress() << endl;
        cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
    }
    else
        cout << "橾纂ж朝 等檜攪陛 橈蝗棲棻." << endl;
}

void ClientHandler::ClientShowlist() // 蛔煙脹 賅萇 堅偌 薑爾 轎溘
{
    int cnt = 0;
    if (ClientInfo.empty() == false)
    {
        for (auto C : ClientInfo)
        {
            cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
            cout << "等檜攪 ч: " << cnt++ << endl;
            cout << "檜葷: " << C->getName() << " / 儅喇錯橾: " << C->getBirthday() << " / 瞪�食醽�: " << C->getPhoneNumber()
                << endl << "輿模: " << C->getAddress() << " / 檜詭橾 輿模: " << C->getEmailAddress() << endl;
            cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
        }
    }

    else if(ClientInfo.empty() == true)
        cout << "蛔煙脹 等檜攪陛 橈蝗棲棻." << endl;
}

void ClientHandler::ClientRemove() //か薑 堅偌薑爾(ч)擊 薯剪
{
    int n;
    if (ClientInfo.empty() == false)
    {
        ClientShowlist();
        cout << "餉薯ж褒 等檜攪 ч 廓�ㄧ� 殮溘ж撮蹂.";
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
            }
        }
        else{
            if (n >= ClientInfo.size() || n < 0)
                cout << "殮溘脹 ч縑 等檜攪陛 橈蝗棲棻." << endl;
            else
            {
                ClientInfo.erase(ClientInfo.begin() + n);
                cout << "餉薯陛 諫猿腎歷蝗棲棻." << endl;
            }
        }
    }
    else
        cout << "蛔煙脹 等檜攪陛 橈蝗棲棻." << endl;
}

void ClientHandler::ClientEdit() // か薑 堅偌薑爾(ч)曖 か薑 о跡(翮) 高擊 滲唳
{
    int m, n;
    string s;
    if (ClientInfo.empty() == false)
    {
        ClientShowlist();
        cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
CTO1:   cout << "滲唳й 等檜攪 ч擊 殮溘ж撮蹂.";
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
                    goto CTO1;
                }
            }
            if (n >= ClientInfo.size() || n < 0)
                cout << "殮溘脹 ч縑 等檜攪陛 橈蝗棲棻. 棻衛 殮溘ж撮蹂" << endl;
        } while (n >= ClientInfo.size() || n < 0);
        cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
        cout << "0: 檜葷 / 1: 儅喇錯橾 / 2: 瞪�食醽� /" << endl << " 3: 輿模 / 4: 檜詭橾 輿模" << endl;
CTO2:   cout << "滲唳й 等檜攪 翮擊 殮溘ж撮蹂.";
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
                    goto CTO2;
                }
            }
            if (m > 4 || m < 0)
                cout << "殮溘脹 翮縑 等檜攪陛 橈蝗棲棻. 棻衛 殮溘ж撮蹂" << endl;
        } while (m > 4 || m < 0);
        cout << "式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式" << endl;
        cout << "滲唳й 等檜攪 頂辨擊 殮溘ж撮蹂.";
        cin >> s;
        switch (m)
        {
        case 0:
        {
            ClientInfo[n]->setName(s);
            s.clear();
        }break;
        case 1:
        {
            ClientInfo[n]->setBirthday(s);
            s.clear();
        }break;
        case 2:
        {
            ClientInfo[n]->setPhoneNumber(s);
            s.clear();
        }break;
        case 3:
        {
            ClientInfo[n]->setAddress(s);
            s.clear();
        }break;
        case 4:
        {
            ClientInfo[n]->setEmailAddress(s);
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

Client* ClientHandler::ClientInforeturn(string& phoneNumber) // 堅偌薑爾曖 PK諦 橾纂ж朝 偌羹 奩��(OrderInfoHandler縑憮 �倏�)
{
    Client* c = nullptr;
    auto it = find_if(ClientInfo.begin(), ClientInfo.end(), [=](Client* c)
        { return (*c).getPhoneNumber() == phoneNumber; });
    if (it != ClientInfo.end())
    {
        c = *it;
        return *it;
    }
    
}

bool ClientHandler::HasCID(string phoneNumber)
{
    auto it = find_if(ClientInfo.begin(), ClientInfo.end(), [=](Client* c)
        { return (*c).getPhoneNumber() == phoneNumber; });
    return (it != ClientInfo.end())?true:false;
}

vector<string> ClientHandler::parseCCSV(istream& file, char delimiter)
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
