//°¢ ÇÔ¼ö ³»ÀÇ try, catch±¸¹®Àº int Çü ÀÔ·Â »óÈ²¿¡¼­ ´Ù¸¥ ÇüÅÂÀÇ µ¥ÀÌÅÍ°¡ ÀÔ·ÂµÆÀ» °æ¿ì¸¦ Ã³¸®ÇÏ±â À§ÇÔÀÓ.

#include "ClientHandler.h"
#include <string>
#include <fstream>
#include <sstream>
ClientHandler::ClientHandler()
{
    ifstream file; //ÆÄÀÏ Ãâ·Â °´Ã¼ »ý¼º
    file.open("clientinfo.txt"); //ÀÔ·ÂÆÄÀÏ ÀÌ¸§
    if (!file.fail()) 
    {
        while (!file.eof()) // end of file => true°¡ µÇ´Â ÁöÁ¡¿¡¼­ ¸¶Áö¸·
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
void ClientHandler::ClientEnroll()// ¼º¸í, »ý³â¿ùÀÏ, ÀüÈ­¹øÈ£, ÁÖ¼Ò, ÀÌ¸ÞÀÏ ÁÖ¼Ò ÀÔ·Â ÈÄ Á¤º¸ ÀúÀå
{
    string s;
    cout << "ÀÌ¸§: ";
    cin >> s;
    Client* CInfo1 = new Client;
    CInfo1->setName(s);
    s.clear();
    cout << "»ý³â¿ùÀÏ(ex.220830): ";
    cin >> s;
    CInfo1->setBirthday(s);
    s.clear();
    cout << "ÀüÈ­¹øÈ£(ex.010-1234-5678): ";
    cin >> s;
    CInfo1->setPhoneNumber(s);
    s.clear();
    cout << "ÁÖ¼Ò(ex.¼­¿ï½Ã Á¾·Î±¸ ÇýÈ­µ¿): ";
    cin.ignore(); // ¾ÕÀÇ ÇÑ ±ÛÀÚ(enter)¸¦ ¹«½ÃÇÏ´Â °æ¿ì
    getline(cin, s, '\n'); // '\n'°¡ µé¾î¿Ã ¶§±îÁö ¹Þ°Ú´Ù
    CInfo1->setAddress(s);
    s.clear();
    cout << "ÀÌ¸ÞÀÏÁÖ¼Ò(ex.example@gmail.com): "; // ´Ù¹æ¸é ¿¬¶ô¸Á È®º¸¸¦ À§ÇÔ
    cin >> s;
    CInfo1->setEmailAddress(s);
    s.clear();
    ClientInfo.push_back(CInfo1);
}


void ClientHandler::ClientSearch() // ¸ðµç °í°´ Á¤º¸ Áß ÀüÈ­¹øÈ£(PK)°¡ ÀÏÄ¡ÇÏ´Â Ç×¸ñÀÇ °í°´Á¤º¸ Ãâ·Â
{
    string phoneNumber;
    cout << "Ã£À¸½Ã´Â °í°´ÀÇ ÀüÈ­¹øÈ£¸¦ ÀÔ·ÂÇÏ¼¼¿ä(010-xxxx-xxxx). ";
    cin >> phoneNumber;

    auto it = find_if(ClientInfo.begin(), ClientInfo.end(), [=](Client* c) 
        { return (*c).getPhoneNumber() == phoneNumber; });
    
    if (it != ClientInfo.end())
    {
        cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
        cout << "ÀÌ¸§: " << (*it)->getName() << " / »ý³â¿ùÀÏ: " << (*it)->getBirthday() << " / ÀüÈ­¹øÈ£: " << (*it)->getPhoneNumber()
            << endl << "ÁÖ¼Ò: " << (*it)->getAddress() << " / ÀÌ¸ÞÀÏ ÁÖ¼Ò: " << (*it)->getEmailAddress() << endl;
        cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
    }
    else
        cout << "ÀÏÄ¡ÇÏ´Â µ¥ÀÌÅÍ°¡ ¾ø½À´Ï´Ù." << endl;
}

void ClientHandler::ClientShowlist() // µî·ÏµÈ ¸ðµç °í°´ Á¤º¸ Ãâ·Â
{
    int cnt = 0;
    if (ClientInfo.empty() == false)
    {
        for (auto C : ClientInfo)
        {
            cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
            cout << "µ¥ÀÌÅÍ Çà: " << cnt++ << endl;
            cout << "ÀÌ¸§: " << C->getName() << " / »ý³â¿ùÀÏ: " << C->getBirthday() << " / ÀüÈ­¹øÈ£: " << C->getPhoneNumber()
                << endl << "ÁÖ¼Ò: " << C->getAddress() << " / ÀÌ¸ÞÀÏ ÁÖ¼Ò: " << C->getEmailAddress() << endl;
            cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
        }
    }

    else if(ClientInfo.empty() == true)
        cout << "µî·ÏµÈ µ¥ÀÌÅÍ°¡ ¾ø½À´Ï´Ù." << endl;
}

void ClientHandler::ClientRemove() //Æ¯Á¤ °í°´Á¤º¸(Çà)À» Á¦°Å
{
    int n;
    if (ClientInfo.empty() == false)
    {
        ClientShowlist();
        cout << "»èÁ¦ÇÏ½Ç µ¥ÀÌÅÍ Çà ¹øÈ£¸¦ ÀÔ·ÂÇÏ¼¼¿ä.";
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
            }
        }
        else{
            if (n >= ClientInfo.size() || n < 0)
                cout << "ÀÔ·ÂµÈ Çà¿¡ µ¥ÀÌÅÍ°¡ ¾ø½À´Ï´Ù." << endl;
            else
            {
                ClientInfo.erase(ClientInfo.begin() + n);
                cout << "»èÁ¦°¡ ¿Ï·áµÇ¾ú½À´Ï´Ù." << endl;
            }
        }
    }
    else
        cout << "µî·ÏµÈ µ¥ÀÌÅÍ°¡ ¾ø½À´Ï´Ù." << endl;
}

void ClientHandler::ClientEdit() // Æ¯Á¤ °í°´Á¤º¸(Çà)ÀÇ Æ¯Á¤ Ç×¸ñ(¿­) °ªÀ» º¯°æ
{
    int m, n;
    string s;
    if (ClientInfo.empty() == false)
    {
        ClientShowlist();
        cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
CTO1:   cout << "º¯°æÇÒ µ¥ÀÌÅÍ ÇàÀ» ÀÔ·ÂÇÏ¼¼¿ä.";
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
                    goto CTO1;
                }
            }
            if (n >= ClientInfo.size() || n < 0)
                cout << "ÀÔ·ÂµÈ Çà¿¡ µ¥ÀÌÅÍ°¡ ¾ø½À´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä" << endl;
        } while (n >= ClientInfo.size() || n < 0);
        cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
        cout << "0: ÀÌ¸§ / 1: »ý³â¿ùÀÏ / 2: ÀüÈ­¹øÈ£ /" << endl << " 3: ÁÖ¼Ò / 4: ÀÌ¸ÞÀÏ ÁÖ¼Ò" << endl;
CTO2:   cout << "º¯°æÇÒ µ¥ÀÌÅÍ ¿­À» ÀÔ·ÂÇÏ¼¼¿ä.";
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
                    goto CTO2;
                }
            }
            if (m > 4 || m < 0)
                cout << "ÀÔ·ÂµÈ ¿­¿¡ µ¥ÀÌÅÍ°¡ ¾ø½À´Ï´Ù. ´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä" << endl;
        } while (m > 4 || m < 0);
        cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
        cout << "º¯°æÇÒ µ¥ÀÌÅÍ ³»¿ëÀ» ÀÔ·ÂÇÏ¼¼¿ä.";
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
        cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
        cout << "µ¥ÀÌÅÍ º¯°æÀÌ ¿Ï·áµÇ¾ú½À´Ï´Ù." << endl;
        cout << "¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡¦¡" << endl;
    }
    else
        cout << "µî·ÏµÈ µ¥ÀÌÅÍ°¡ ¾ø½À´Ï´Ù." << endl;
}

Client* ClientHandler::ClientInforeturn(string& phoneNumber) // °í°´Á¤º¸ÀÇ PK¿Í ÀÏÄ¡ÇÏ´Â °´Ã¼ ¹ÝÈ¯(OrderInfoHandler¿¡¼­ È°¿ë)
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
