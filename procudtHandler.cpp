#include <sstream>
#include <fstream>
#include "ProductHandler.h"

extern int getNumber();                                                         // 0~9������ ���ڸ� �Է��ϴ� �Լ�
extern int getBnumber();                                                        // �����̳� ��¥ �� ū ���� �Է� �Լ�

ProductHandler::ProductHandler()                                                // ������
{
    ifstream file;                                                              //���� ��� ��ü ����
    file.open("productinfo.txt");                                               //�Է����� �̸� ���� �� ����
    if (!file.fail())                                                           //���� �Է� ���п� ���� ����ó��
    {
        while (!file.eof())                                                     // file�� ������ while�� �ݺ�
        { 
            vector<string> row = parsePCSV(file, ',');                          //,������ ���е� file �����͸� row�� ����
            if (row.size())                                                     //row�� ����� �����Ͱ� �ִٸ�
            {
                int pid = stoi(row[0]);                                         //string�� ���ڸ� int �������� �ٲ㼭 �־��ش�
                int pprice = stoi(row[2]);                                  
                Product* p = new Product(pid, row[1], pprice, row[3]);          //�Էµ� �����͸� Product ��ü�� ����
                ProductInfo.push_back(p);                                       //Product ��ü�� ����� ������ ��ǰ������  
                                                                                //�����ϴ� �迭�� �Է�
            }
        }
    }
    cout << "productinfo.txt ��� �Ϸ�" << endl;
}

ProductHandler::~ProductHandler()                                               // �Ҹ���
{
    ofstream file;                                                              //���� ��� ��ü ����
    file.open("productinfo.txt");                                               //��� ���� �̸� ���� �� ����
    if (!file.fail())                                                           //���� ��� ���п� ���� ����ó��
    {
        for (const auto& v : ProductInfo)                                       //����� ��� ��ǰ������ ���� �ݺ�
        {
            Product* p = v;                                                     //Product ��ü�� ����� ��ǰ���� ����
            file << p->getProductID() << ", " << p->getProductName() << ", ";   //��ǰID�� ��ǰ���� ,������ �߶� �Է�
            file << p->getProductPrice() << ", ";                               //��ǰ ������ , ������ �߶� �Է�
            file << p->getProductSort() << endl;                                //��ǰ ������ , ������ �߶� �Է�
        }
    }
    file.close();                                                               //���� �ݱ�
}

void ProductHandler::productEnroll()                                            //��ǰ ���� ���
{
    int x;                                                                      //int ������ ���� �Է��� �ޱ� ���� ����
    string s;                                                                   //string ������ ���� �Է��� �ޱ� ���� ����
    Product* PInfo1 = new Product;                                              //��ǰ ���� ������ ���� Product* ������  
                                                                                //��ü ���� �� �ʱ�ȭ
    int productID = makeProductID();                                            //��ǰID ���� �� productID ������ ����
    PInfo1->setProductID(productID);                                            //��ǰ ID�� ��ü�� ����
    cout << "��ǰ��: ";                                                         
    cin >> s;                                                                   //��ǰ�� �Է�
    PInfo1->setProductName(s);                                                  //��ǰ���� ��ü�� ����
    s.clear();                                                                  //s�� �����ϱ� ���� ���� ����
    cout << "��ǰ ����: ";
    x = getBnumber();                                                           //��ǰ���� �Է�
    PInfo1->setProductPrice(x);                                                 //��ǰ ������ ��ü�� ����
    cout << "��ǰ ����: ";
    cin >> s;                                                                   //��ǰ ���� �Է�
    PInfo1->setProductSort(s);                                                  //��ǰ ������ ��ü�� ����
    s.clear();                                                                  //s�� �����ϱ� ���� ���� ����
    ProductInfo.push_back(PInfo1);                                              //��ü�� ����� ������ vector �迭�� ����

    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "��� �Ͻ÷��� �ƹ� ���ڰ��̳� �Է��ϼ���.";
    x = getNumber();                                                            //�ƹ� ���� �Է�
    system("cls");                                                              //ȭ�� ��ȯ
}

void ProductHandler::productSearch()                                            // ��� ��ǰ ���� �� ��ȭ��ȣ(PK)�� ��ġ�ϴ�
{                                                                               // �׸��� ��ǰ���� ���
    int n, productID;                                                           // productID�� find_if�� �����ϱ� ���� ����
                                                                                // n�� int ������ �Է��� �ޱ� ���� ����
    string s;                                                                   // string ������ ���� �Է��� �ޱ� ���� ����
    cout << "ã���ô� ��ǰ�� ID�� �Է��ϼ���. ";
    productID = getBnumber();                                                   // ��ǰID�� �Է�
    auto it = find_if(ProductInfo.begin(), ProductInfo.end(), [=](Product* p)   //ProductInfo(��ǰ ������ �����ϴ� vector)���� 
        { return (*p).getProductID() == productID; });                          //��ġ�ϴ� ��ü�� it ���� ��ȯ

    if (it != ProductInfo.end())                                                //it�� ���� end�� �ƴϸ�
    {
        cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "��ǰ ID: " << (*it)->getProductID() << " / ��ǰ��: " << (*it)->getProductName() << " / ��ǰ ����: " 
            << (*it)->getProductPrice() << endl << "��ǰ ����: " << (*it)->getProductSort() << endl;
        cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    }                                                                           //it ��ü�� ���� ��ǰID, ��ǰ��, ��ǰ ����,
                                                                                //��ǰ ������ ���
    else                                                                        //it�� ���� ����Ű�� ���� end���
        cout << "��ġ�ϴ� �����Ͱ� �����ϴ�." << endl;

    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "��� �Ͻ÷��� �ƹ� ���ڰ��̳� �Է��ϼ���.";
    n = getNumber();                                                            //�ƹ� ���ڳ� �Է�
    system("cls");                                                              //ȭ�� ��ȯ
}

void ProductHandler::productShowlist()                                          //�Էµ� ��� ��ǰ ���� ���
{
    int cnt = 0;                                                                // ������ �� ����� ���� int�� ���� ����, �ʱ�ȭ                                                               
    if (ProductInfo.empty() == false)                                           // ��ǰ ������ ��� �迭�� �����Ͱ� ������ ���
    {
        for (auto P : ProductInfo)                                              // ��ǰ ������ ��� �������� ����ŭ �ݺ�
        {
            cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
            cout << "������ ��: " << cnt++ << endl;
            cout << "��ǰ ID: " << P->getProductID() << " / ��ǰ��: " << P->getProductName() << " / ��ǰ ����: "
                << P->getProductPrice() << endl << "��ǰ ����: " << P->getProductSort() << endl;
            cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
        }                                                                      //P ��ü�� ���� ��ǰID, ��ǰ��, ��ǰ ����,
                                                                               //��ǰ ������ ��� 
    }

    else                                                                       //P�� ���� ����Ű�� ���� end���
        cout << "��ϵ� �����Ͱ� �����ϴ�." << endl;
}

void ProductHandler::productRemove()                                           // Ư�� ��ǰ ����(��)�� ����
{
    int n;                                                                     // �޴� ����(�� �ڸ� ���� ����)�� ���� int�� ����  
    if (ProductInfo.empty() == false)                                          // ��ǰ ������ ��� �迭�� �����Ͱ� ������ ���
    {
        productShowlist();                                                     // ���� ��ϵ� ��ǰ ����� ������
        cout << "������ ������ ���� �Է��ϼ���.";
        n = getBnumber();                                                      // ������ ������ �� ��ȣ �Է�
        
        if (n >= ProductInfo.size() || n < 0)                                  // �Էµ� �࿡ �����Ͱ� ���� ��� 
            cout << "�Էµ� �࿡ �����Ͱ� �����ϴ�." << endl;
        else                                                                   // �Է��� �࿡ ��ǰ ������ ��� �迭�� 
        {                                                                      // �����Ͱ� ���� ���
            ProductInfo.erase(ProductInfo.begin() + n);                        // �Է��� ���� ������ ��ü ����
            cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
        }
    }
    else                                                                       // ��ǰ������ ��� �迭�� �����Ͱ� ���� ���
        cout << "��ϵ� �����Ͱ� �����ϴ�." << endl;

    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "��� �Ͻ÷��� �ƹ� ���ڰ��̳� �Է��ϼ���.";
    n = getNumber();                                                            //�ƹ� ���� �Է�
    system("cls");                                                              //ȭ�� ��ȯ
}

void ProductHandler::productEdit()                                              // Ư�� ��ǰ ����(��)�� Ư�� �׸�(��) ���� ����
{
    int n, m, x;                                                                // ����� int�� ��� �� ���� �Է¹޴� ����
    string s;                                                                   // ����� string �� �Է°��� �޴� ����
    if (ProductInfo.empty() == false)                                           // ��ǰ ������ ��� �迭�� �����Ͱ� ������ ���
    {
        productShowlist();                                                      // ���� ��ϵ� ��ǰ ����� ������
        cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "������ ������ ���� �Է��ϼ���.";
        do {                                                                    // ����� �����Ͱ� �ִ� ���� �Է��� ������ �ݺ�
            n = getBnumber();                                                   // ������ ������ �� �Է�
            if (n >= ProductInfo.size() || n < 0)                               // �Էµ� �� ���� �迭 ������ ���� ���
                cout << "�Էµ� �࿡ �����Ͱ� �����ϴ�. �ٽ� �Է��ϼ���" << endl;
        } while (n >= ProductInfo.size() || n < 0);

        cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "1: ��ǰ�� / 2: ��ǰ ���� / 3: ��ǰ ����" << endl;
        cout << "������ ������ ���� �Է��ϼ���.";
        do {
            m = getNumber();                                                   // ������ ������ �� �Է�
            if (m < 1 || m > 3)                                                // �Էµ� �� ���� �迭 ������ ���� ���
                cout << "�߸��� �����Դϴ�. �ٽ� �Է��ϼ���" << endl;
        } while (m < 1 || m > 3);
        cout << "\n������������������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "������ ������ ������ �Է��ϼ���.";
        switch (m)
        {
        case 1:                                                                 // ��ǰ���� �����ϴ� ���
        {
            cin >> s;                                                           // ������ ��ǰ�� �Է�
            ProductInfo[n]->setProductName(s);                                  // ���õ� ���� ��ǰ���� �Էµ� ������ ����
            s.clear();                                                          // �Էµ� ���� ����
        }break;
        case 2:                                                                 // ��ǰ������ �����ϴ� ���
        {
            x = getBnumber();                                                   // ������ ��ǰ ���� �Է�
            ProductInfo[n]->setProductPrice(x);                                 // ���õ� ���� ��ǰ ������ �Էµ� ������ ����
        }break;
        case 3:                                                                 // ��ǰ ������ �����ϴ� ���
        {
            cin >> s;                                                           // ������ ��ǰ ���� �Է�
            ProductInfo[n]->setProductSort(s);                                  // ���õ� ���� ��ǰ ������ �Էµ� ������ ����
            s.clear();                                                          // �Էµ� ���� ����
        }break;
        }
        cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "������ ������ �Ϸ�Ǿ����ϴ�." << endl;
        cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    }
    else                                                                        // ��ǰ ������ ��� �迭�� �����Ͱ� ���� ���
        cout << "��ϵ� �����Ͱ� �����ϴ�." << endl;

    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "��� �Ͻ÷��� �ƹ� ���ڰ��̳� �Է��ϼ���.";
    x = getNumber();                                                            //�ƹ� ���� �Է�
    system("cls");                                                              //ȭ�� ��ȯ
}

Product* ProductHandler::ProductInfoReturn(int& productID)                    // ��ǰ ������ PK�� ��ġ�ϴ� 
{                                                                             // ��ü ��ȯ(OrderInfoHandler���� Ȱ��)
    Product* p = nullptr;                                                     // ��ü �ʱ�ȭ
    auto it = find_if(ProductInfo.begin(), ProductInfo.end(), [=](Product *p) // �Էµ� productID�� ���� ��ü�� it�� ����
        { return (*p).getProductID() == productID; });
    
    if (it != ProductInfo.end())                                               // it�� ��ǰ ���� �迭�� �ִ� ���
    { 
        p = *it;                                                               // it�� ���� ���� ��ü�� �����ؼ� ��ȯ
    }
    else                                                                       // it�� ��ǰ ���� �迭�� ���� ���
    {
        int ID = 0, productPrice = 0;
        string productName = "", productSort = "";
        *p = { ID, productName, productPrice, productSort };                    // �ʱⰪ�� �����ؼ� ��ȯ
    }
    return p;
}

int ProductHandler::makeProductID()                                             // ��ǰ�ڵ带 �ڵ� �����ϴ� �Լ�
{
    int ret = -1;                                                               // int�� ��ȯ ���� -1�� �ʱ�ȭ
    if (ProductInfo.size() == 0)                                                // ���� ��ϵ� ��ǰ ������ ������
        ret = 1000;                                                             // ��ǰ ������ 1000�� �Է��ؼ� ��ȯ
    else if(ProductInfo.size() > 0)                                             // �̹� ��ϵ� ��ǰ ������ ������
    {
        ret = (*ProductInfo.rbegin())->getProductID();                          //��ǰ������ �������� �ִ� ��ǰID�� ret�� ����
        ++ret;                                                                  //ret�� 1�� ���ؼ� ��ȯ
    }

    return ret;                                                                 //�� ��� ��찡 �ƴ϶�� -1�� ��ȯ
}


bool ProductHandler::HasPID(int &productID)                                     // OrderInfoHandler���� �Է��ϴ� ��ǰID(PK)��
                                                                                // ��ǰ ������ �ִ��� Ȯ�����ִ� �Լ�
{
    auto it = find_if(ProductInfo.begin(), ProductInfo.end(), [=](Product* p)   // �Էµ� productID�� ��ǰ ���� �迭����
        { return (*p).getProductID() == productID; });                          // ��ġ�ϴ� ��ü�� it�� ����
    return (it != ProductInfo.end()) ? true : false;                            // ��ü�� �ִٸ� true ��ȯ, ���ٸ� false ��ȯ
}

vector<string> ProductHandler::parsePCSV(istream& file, char delimiter)         // �����ڿ��� �Էµ� ���� �����͸� ,������
{                                                                               // �ܾ �о���� ���� �Լ�
    stringstream ss;                                                            // ���� �����͸� ��� ���� ������ ������ 
                                                                                // ������ ���� �����ϴ� ���� ss 
    vector<string> row;                                                         // �ϼ��� �ܾ �����ϱ� ���� vector�� ���� row
    string t = " \n\r\t";                                                       // �ܾ� �ϼ������� �����ϱ� ���� ��谪 t

    while (!file.eof())                                                         // ������ ������ while���� �ݺ�
    {
        char c = file.get();                                                    // ������ �����͸� �ѱ��ھ� c�� ����
        if (c == delimiter || c == '\r' || c == '\n')                           // c�� �Էµ� ���ڰ� �����̳� ,�� ���
        {
            if (file.peek() == '\n') file.get();                                // ���� ���ڰ� �ٹٲ��̸� ����ȭ���� 
                                                                                // ���� �����͸� �����´�. 
            string s = ss.str();                                                // �о�� ���ڿ��� s�� ��´�
            s.erase(0, s.find_first_not_of(t));                                 // find_first_not_of(���ڿ�): ������ ���ڿ��� 
                                                                                // ��ġ���� �ʴ� ù��° ���� �˻� ��
                                                                                // ��ġ���� �ʴ� ���� ����
            s.erase(s.find_last_not_of(t) + 1);                                 // t�� �ٷ� �� �������� ���� => NULL���� ����
            row.push_back(s);                                               // ���� ���ڿ��� row�� ����(���� ������ �ϼ�) 
            ss.str("");                                                         // ���� ss �ʱ�ȭ
            if (c != delimiter) break;                                          // c ���� ,�� �ƴ� ��� Ż��
        }
        else                                                                    // c�� �Էµ� ���ڰ� �����̳� ,�� �ƴ� ���
        {
            ss << c;                                                            // ss�� c���� ����
        }
    }
    return row;                                                                 // row�� ����� vector ��ȯ
}