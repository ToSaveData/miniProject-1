#include "Client.h"
#include "Product.h"
#include "OrderInfo.h"
#include <vector>
#include <algorithm>
#include <string>
int main()
{
    int n;
    string s;
    vector<Client*> ClientInfo;
    vector<Product*> ProductInfo;
    vector<OrderInfo*> OrderInfoInfo;

    cout << "****************************************************************" << endl;
    cout << "                       상품 관리 프로그램" << endl;
    cout << "                       1. 고객 정보 관리" << endl;
    cout << "                       2. 상품 정보 관리" << endl;
    cout << "                       3. 쇼핑 정보 관리" << endl;
    cout << "****************************************************************" << endl;
    cout << endl;
    
    do {
        cout << "몇번을 입력하시겠습니까 ? (종료: 0)" << endl;
        cin >> n;

        switch (n)
        {
            case 1:
            {
                
                cout << "1) 입력 / 조회 / 삭제 / 변경" << endl;
                cin >> n;
                switch (n)
                {
                    case 1:
                    {
                        cout << "이름: ";
                        cin >> s;
                        Client* CInfo1 = new Client;
                        CInfo1->setName(s);
                        s.clear();
                        cout << "생년월일(ex.220830): ";
                        cin >> s;
                        CInfo1->setBirthday(s);
                        s.clear();
                        cout << "전화번호(ex.010-1234-5678): ";
                        cin >> s;
                        CInfo1->setPhoneNumber(s);
                        s.clear();
                        cout << "주소(ex.서울시 종로구 혜화동): ";
                        cin.ignore(); // 앞의 enter를 무시하는 경우
                        getline(cin, s, '\n');
                        CInfo1->setAddress(s);
                        s.clear();
                        cout << "이메일주소(ex.example@gmail.com): ";
                        cin >> s;
                        CInfo1->setEmailAddress(s);
                        s.clear();
                        ClientInfo.push_back(CInfo1);
                    }break;
                    case 2:
                    {
                        for_each(ClientInfo.begin(), ClientInfo.end(), [](Client* C) {
                            cout << C->getName() << " : " << C->getBirthday() << " : " 
                            << C->getPhoneNumber() << " : " << C->getAddress() << " : " 
                            << C->getEmailAddress() << endl; });
                    }break;
                }
            }break;

            case 2:
            {
                cout << "2) 입력 / 조회 / 삭제 / 변경" << endl;
                cin >> n;

                switch (n)
                {
                    case 1:
                    {
                        cout << "ID: ";
                        cin >> s;
                        Product* PInfo1 = new Product;
                        PInfo1->setID(n);
                        s.clear();
                        cout << "제품명: ";
                        cin >> s;
                        PInfo1->setProductName(s);
                        s.clear();
                        cout << "제품 가격: ";
                        cin >> s;
                        PInfo1->setProductPrice(n);
                        s.clear();
                        cout << "제품 종류: ";
                        cin >> s;
                        PInfo1->setProductSort(s);
                        s.clear();
                        ProductInfo.push_back(PInfo1);
                    }break;
                case 2:
                    {
                        for_each(ProductInfo.begin(), ProductInfo.end(), [](Product* P) {
                        cout << P->getID() << " : " << P->getProductName() << " : "
                         << P->getProductPrice() << " : " << P->getProductSort() << endl; });
                    }break;
                }break;
            }
            case 3:
            {
                cout << "3) 주문 / 조회 / 취소" << endl;
                cin >> n;
            }break;
        }
    } while (!(n == 0));
        
    return 0;
}

//vector<Client*> ClientInfo;
//Client* CInfo1 = new Client("Park Jin Seok", "010-0000-1111", "Heyhwa");
//ClientInfo.push_back(CInfo1);
//
//for_each(ClientInfo.begin(), ClientInfo.end(), [](Client* C) {
//	cout << C->getName() << " : " << C->getPhoneNumber() << " : " << C->getAddress() << endl;
//	});
//cout << endl;
//
//vector<Product*> ProductInfo;
//Product* PInfo = new Product(1000, "T1", 10000, "CT");
//ProductInfo.push_back(PInfo);
//for_each(ProductInfo.begin(), ProductInfo.end(), [](Product* P) {
//	cout << P->getID() << " : " << P->getProductName() << " : " << P->getProductPrice() << " : "
//		<< P->getProductSort() << endl;
//	});
//cout << endl;
//
//vector<OrderInfo*> OrderInfoInfo;
//OrderInfo* OInfo = new OrderInfo("1", 20220830, 3);
//OrderInfoInfo.push_back(OInfo);
//for_each(OrderInfoInfo.begin(), OrderInfoInfo.end(), [](OrderInfo* O) {
//	cout << O->getOrderCode() << " : " << O->getOrderDate() << " : " << O->getOrderNumber() << endl;
//	});
