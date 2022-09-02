#include "ProductHandler.h"

void ProductHandler::productEnroll()
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
    cin >> x;
    PInfo1->setProductPrice(x);
    cout << "��ǰ ����: ";
    cin >> s;
    PInfo1->setProductSort(s);
    s.clear();
    ProductInfo.push_back(PInfo1);
}

void ProductHandler::productSearch(int &productID)
{
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
void ProductHandler::productShowlist()
{
    for (auto P : ProductInfo)
    {
        cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
        cout << "��ǰ ID: " << P->getProductID() << " / ��ǰ��: " << P->getProductName() << " / ��ǰ ����: "
        << P->getProductPrice() << endl << "��ǰ ����: " << P->getProductSort() << endl;
        cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    }
}
void ProductHandler::productRemove()
{
    int n;
    cout << "������ ������ ���� �Է��ϼ���.";
    cin >> n;
    if (n > ProductInfo.size() || n < 0)
        cout << "�Էµ� �࿡ �����Ͱ� �����ϴ�." << endl;
    else
    {
        ProductInfo.erase(ProductInfo.begin() + n);
        cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
    }
}

void ProductHandler::productEdit()
{
    int n, m, x;
    string s;
    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "������ ������ ���� �Է��ϼ���.";
    cin >> n;
    cout << "������������������������������������������������������������������������������������������������������������������������������" << endl;
    cout << "������ ������ ���� �Է��ϼ���.";
    cin >> m;
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

Product* ProductHandler::ProductInfoReturn(int& productID)
{
    auto it = find_if(ProductInfo.begin(), ProductInfo.end(), [=](Product *p)
        { return (*p).getProductID() == productID; });
    
    if (it != ProductInfo.end()) 
        return *it;
}

int ProductHandler::makeProductID()
{

    if (ProductInfo.size() == 0)
        return 1000;
    else if(ProductInfo.size() > 0)
    {
        int i = (*ProductInfo.rbegin())->getProductID();
        return ++i;
    }
}