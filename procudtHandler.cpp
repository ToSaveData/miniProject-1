#include <sstream>
#include <fstream>
#include "ProductHandler.h"

extern int getNumber();
extern int getBnumber();

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
    cout << "productinfo.txt ��� �Ϸ�" << endl;
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
    cout << "��ǰ ����: ";
    x = getBnumber();
    PInfo1->setProductPrice(x);
    cout << "��ǰ ����: ";
    cin >> s;
    PInfo1->setProductSort(s);
    s.clear();
    ProductInfo.push_back(PInfo1);

    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "��� �Ͻ÷��� �ƹ� ���ڰ��̳� �Է��ϼ���.";
    x = getNumber();
    system("cls");
}

void ProductHandler::productSearch() //�迭�� ����� ������ �˻��ؼ� ��ġ�ϴ� ���� �� �� ���
{
    int n, productID;
    string s; 
    cout << "ã���ô� ��ǰ�� ID�� �Է��ϼ���. ";
    productID = getBnumber(); // cin >> productid;
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

    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "��� �Ͻ÷��� �ƹ� ���ڰ��̳� �Է��ϼ���.";
    n = getNumber();
    system("cls");
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
    string s;
    if (ProductInfo.empty() == false)
    {
        productShowlist();
        cout << "������ ������ ���� �Է��ϼ���.";
        n = getBnumber();
        
        if (n >= ProductInfo.size() || n < 0)
            cout << "�Էµ� �࿡ �����Ͱ� �����ϴ�." << endl;
        else
        {
            ProductInfo.erase(ProductInfo.begin() + n);
            cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
        }
    }
    else
        cout << "��ϵ� �����Ͱ� �����ϴ�." << endl;

    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "��� �Ͻ÷��� �ƹ� ���ڰ��̳� �Է��ϼ���.";
    n = getNumber();
    system("cls");
}

void ProductHandler::productEdit() // �Էµ� ���� �� Ư�� ���� Ư�� �� ������ ����
{
    int n, m, x;
    string s;
    if (ProductInfo.empty() == false)
    {
        productShowlist();
        cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "������ ������ ���� �Է��ϼ���.";
        do {
            n = getBnumber();
            if (n >= ProductInfo.size() || n < 0)
                cout << "�Էµ� �࿡ �����Ͱ� �����ϴ�. �ٽ� �Է��ϼ���" << endl;
        } while (n >= ProductInfo.size() || n < 0);

        cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "1: ��ǰ�� / 2: ��ǰ ���� / 3: ��ǰ ����" << endl;
        cout << "������ ������ ���� �Է��ϼ���.";
        do {
            m = getNumber();
            if (m < 1 || m > 3)
                cout << "�߸��� �����Դϴ�. �ٽ� �Է��ϼ���" << endl;
        } while (m < 1 || m > 3);
        cout << "\n������������������������������������������������������������������������������������������������������������������������������" << endl;
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
            x = getBnumber();
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

    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "��� �Ͻ÷��� �ƹ� ���ڰ��̳� �Է��ϼ���.";
    x = getNumber();
    system("cls");
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