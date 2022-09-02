#include "ProductHandler.h"

void ProductHandler::productEnroll()
{
    int x;
    string s;
    Product* PInfo1 = new Product;
    int productID = makeProductID();
    PInfo1->setProductID(productID);
    cout << "제품명: ";
    cin >> s;
    PInfo1->setProductName(s);
    s.clear();
    cout << "제품 가격: ";
    cin >> x;
    PInfo1->setProductPrice(x);
    cout << "제품 종류: ";
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
        cout << "───────────────────────────────────────────────────────────────" << endl;
        cout << "제품 ID: " << (*it)->getProductID() << " / 제품명: " << (*it)->getProductName() << " / 제품 가격: " 
            << (*it)->getProductPrice() << endl << "제품 종류: " << (*it)->getProductSort() << endl;
        cout << "───────────────────────────────────────────────────────────────" << endl;
    }
    else
        cout << "일치하는 데이터가 없습니다." << endl;
}
void ProductHandler::productShowlist()
{
    for (auto P : ProductInfo)
    {
        cout << "───────────────────────────────────────────────────────────────" << endl;
        cout << "제품 ID: " << P->getProductID() << " / 제품명: " << P->getProductName() << " / 제품 가격: "
        << P->getProductPrice() << endl << "제품 종류: " << P->getProductSort() << endl;
        cout << "───────────────────────────────────────────────────────────────" << endl;
    }
}
void ProductHandler::productRemove()
{
    int n;
    cout << "삭제할 데이터 행을 입력하세요.";
    cin >> n;
    if (n > ProductInfo.size() || n < 0)
        cout << "입력된 행에 데이터가 없습니다." << endl;
    else
    {
        ProductInfo.erase(ProductInfo.begin() + n);
        cout << "삭제가 완료되었습니다." << endl;
    }
}

void ProductHandler::productEdit()
{
    int n, m, x;
    string s;
    cout << "───────────────────────────────────────────────────────────────" << endl;
    cout << "변경할 데이터 행을 입력하세요.";
    cin >> n;
    cout << "───────────────────────────────────────────────────────────────" << endl;
    cout << "변경할 데이터 열을 입력하세요.";
    cin >> m;
    cout << "───────────────────────────────────────────────────────────────" << endl;
    cout << "변경할 데이터 내용을 입력하세요.";
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
    cout << "───────────────────────────────────────────────────────────────" << endl;
    cout << "데이터 변경이 완료되었습니다." << endl;
    cout << "───────────────────────────────────────────────────────────────" << endl;
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