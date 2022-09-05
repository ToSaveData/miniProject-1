//�� �Լ� ���� try, catch������ int �� �Է� ��Ȳ���� �ٸ� ������ �����Ͱ� �Էµ��� ��츦 ó���ϱ� ������.

#include "ProductHandler.h"
using namespace std;
#include <sstream>
#include <fstream>

ProductHandler::ProductHandler()
{
    ifstream file; //���� ��� ��ü ����
    file.open("productinfo.txt"); //�Է����� �̸�
    if (!file.fail()) 
    {
        while (!file.eof()) // end of file => true�� �Ǵ� �������� ������ 
        { 
            vector<string> row = parsePCSV(file, ',');
            if (row.size()) 
            {
                int pid = stoi(row[0]); //string�� ���ڸ� int �������� �ٲ㼭 �־��ش�
                int pprice = stoi(row[2]); //string�� ���ڸ� int �������� �ٲ㼭 �־��ش�
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

void ProductHandler::productEnroll() // ��ǰID(PK)�� �ڵ�����, ��ǰ��, ��ǰ����, ��ǰ���� �Է� �� ���� ����
{
    int x;
    string s;
    Product* PInfo1 = new Product;
    int productID = makeProductID();
    PInfo1->setProductID(productID);
    cout << "��ǰ��: ";
    cin >> s;
    PInfo1->setProductName(s);
    s.clear();
PTO1:    
    cout << "��ǰ ����: ";
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
            cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
            cout << "�߸��� �Է��Դϴ�." << endl;
            cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
            goto PTO1;
        }
    }
    PInfo1->setProductPrice(x);
    cout << "��ǰ ����: ";
    cin >> s;
    PInfo1->setProductSort(s);
    s.clear();
    ProductInfo.push_back(PInfo1);
}

void ProductHandler::productSearch() //�迭�� ����� ������ �˻��ؼ� ��ġ�ϴ� ���� �� �� ���
{
    int productID;
PTO2:    
    cout << "ã���ô� ��ǰ�� ID�� �Է��ϼ���. ";
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
            cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
            cout << "�߸��� �Է��Դϴ�." << endl;
            cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
            goto PTO2;
        }
    }

    auto it = find_if(ProductInfo.begin(), ProductInfo.end(), [=](Product* p)
        { return (*p).getProductID() == productID; });

    if (it != ProductInfo.end())
    {
        cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "��ǰ ID: " << (*it)->getProductID() << " / ��ǰ��: " << (*it)->getProductName() << " / ��ǰ ����: " 
            << (*it)->getProductPrice() << endl << "��ǰ ����: " << (*it)->getProductSort() << endl;
        cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    }
    else
        cout << "��ġ�ϴ� �����Ͱ� �����ϴ�." << endl;
}

void ProductHandler::productShowlist() //�Էµ� ��� ��ǰ ���� ���
{
    int cnt = 0;
    if (ProductInfo.empty() == false)
    {
        for (auto P : ProductInfo)
        {
            cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
            cout << "������ ��: " << cnt++ << endl;
            cout << "��ǰ ID: " << P->getProductID() << " / ��ǰ��: " << P->getProductName() << " / ��ǰ ����: "
                << P->getProductPrice() << endl << "��ǰ ����: " << P->getProductSort() << endl;
            cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
        }
    }

    else
        cout << "��ϵ� �����Ͱ� �����ϴ�." << endl;
}

void ProductHandler::productRemove() // �Էµ� ���� �� �� �� ����
{
    int n;
    if (ProductInfo.empty() == false)
    {
        productShowlist();
PTO3:   cout << "������ ������ ���� �Է��ϼ���.";
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
                cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
                cout << "�߸��� �Է��Դϴ�." << endl;
                cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
                goto PTO3;
            }
        }
        else{
            if (n >= ProductInfo.size() || n < 0)
                cout << "�Էµ� �࿡ �����Ͱ� �����ϴ�." << endl;
            else
            {
                ProductInfo.erase(ProductInfo.begin() + n);
                cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
            }
        }
    }
    else
        cout << "��ϵ� �����Ͱ� �����ϴ�." << endl;
}

void ProductHandler::productEdit() // �Էµ� ���� �� Ư�� ���� Ư�� �� ������ ����
{
    int n, m, x;
    string s;
    if (ProductInfo.empty() == false)
    {
        productShowlist();
        cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
PTO4:   cout << "������ ������ ���� �Է��ϼ���.";
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
                    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
                    cout << "�߸��� �Է��Դϴ�." << endl;
                    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
                    goto PTO4;
                }
            }
            if (n >= ProductInfo.size() || n < 0)
                cout << "�Էµ� �࿡ �����Ͱ� �����ϴ�. �ٽ� �Է��ϼ���" << endl;
        } while (n >= ProductInfo.size() || n < 0);

        cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
PTO5:   cout << "1: ��ǰ�� / 2: ��ǰ ���� / 3: ��ǰ ����" << endl;
        cout << "������ ������ ���� �Է��ϼ���.";
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
                    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
                    cout << "�߸��� �Է��Դϴ�." << endl;
                    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
                    goto PTO5;
                }
            }
            if (m < 1 || m > 3)
                cout << "�߸��� �����Դϴ�. �ٽ� �Է��ϼ���" << endl;
        } while (m < 1 || m > 3);
        cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "������ ������ ������ �Է��ϼ���.";
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
        cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "������ ������ �Ϸ�Ǿ����ϴ�." << endl;
        cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    }
    else
        cout << "��ϵ� �����Ͱ� �����ϴ�." << endl;
}

Product* ProductHandler::ProductInfoReturn(int& productID) // ��ǰ������ PK�� ��ġ�ϴ� ��ü ��ȯ�� ���� �Լ�(OrderInfoHandler���� Ȱ��)
{
    auto it = find_if(ProductInfo.begin(), ProductInfo.end(), [=](Product *p)
        { return (*p).getProductID() == productID; });
    
    if (it != ProductInfo.end()) 
        return *it;
}

int ProductHandler::makeProductID()// ��ǰ�ڵ�� 1,000������ �ڵ� ����
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
            if (file.peek() == '\n') file.get(); //peek(): ���� ���ڸ� ����. => ���� ���ڰ� �ٹٲ��̸� ����ȭ���� 
            //���� �����͸� �����´�. 
            string s = ss.str();
            s.erase(0, s.find_first_not_of(t)); //find_first_not_of(���ڿ�): ������ ���ڿ��� ��ġ���� �ʴ� 
            //ù��° ���� �˻�, erase(�����ε���, ���ε���(����X)) => �����ε������� �� �ε������� �˻�
            s.erase(s.find_last_not_of(t) + 1); //t�� �ٷ� �� �������� ���� => NULL���� ����
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