#include "productHandler.h"

void productHandler::productEnroll()
{
    int x;
    string s;

    cout << "��ǰI D: ";
    cin >> x;
    Product* PInfo1 = new Product;
    PInfo1->setProductID(x);
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

void productHandler::productSearch(int &productID)
{
    auto it = find_if(ProductInfo.begin(), ProductInfo.end(), [=](Product* p)
        { return (*p).getProductID() == productID; });

    if (it != ProductInfo.end())
    {
        cout << "��ǰ ID: " << (*it)->getProductID() << ", ��ǰ��: " << (*it)->getProductName() << ", ��ǰ ����: " 
            << (*it)->getProductPrice() << ", ��ǰ ����: " << (*it)->getProductSort() << endl;
    }
    else
        cout << "��ġ�ϴ� �����Ͱ� �����ϴ�." << endl;
}
void productHandler::productShowlist()
{
    for (auto P : ProductInfo)
    {
        cout << "��ǰ ID: " << P->getProductID() << ", ��ǰ��: " << P->getProductName() << ", ��ǰ ����: "
        << P->getProductPrice() << ", ��ǰ ����: " << P->getProductSort() << endl;
    }
}
void productHandler::productRemove()
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

void productHandler::productEdit()
{
    int n, m, x;
    string s;

    cout << "������ ������ ���� �Է��ϼ���.";
    cin >> n;
    cout << "������ ������ ���� �Է��ϼ���.";
    cin >> m;
    cout << "������ ������ ������ �Է��ϼ���.";
    switch (m)
    {
    case 0:
    {
        cin >> x;
        ProductInfo[n]->setProductID(x);
    }break;
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
    cout << "������ ������ �Ϸ�Ǿ����ϴ�." << endl;
}