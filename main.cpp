#include "Client.h"
#include "Product.h"
#include "OrderInfo.h"
#include <vector>
#include <algorithm>
#include <string>
int main()
{
    int n, m, x;
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
        cout << "몇번을 입력하시겠습니까 ? (종료: -1)" << endl;
        cin >> n;

        switch (n)
        {
            case 1:
            {
                cout << "1) 1. 입력 / 2. 조회 / 3. 삭제 / 4. 변경" << endl;
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
                        cin.ignore(); // 앞의 한 글자(enter)를 무시하는 경우
                        getline(cin, s, '\n'); // '\n'가 들어올 때까지 받겠다
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

                    case 3:
                    {
                        cout << "삭제할 데이터 행을 입력하세요.";
                        cin >> n;
                        ClientInfo.erase(ClientInfo.begin() + n);
                        cout << "삭제가 완료되었습니다." << endl;
                    }break;

                    case 4:
                    {
                        cout << "변경할 데이터 행을 입력하세요.";
                        cin >> n;
                        cout << "변경할 데이터 열을 입력하세요.";
                        cin >> m;
                        cout << "변경할 데이터 내용을 입력하세요.";
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
                        cout << "데이터 변경이 완료되었습니다." << endl;
                        break;
                    }break;
                }break;
            }break;

            case 2:
            {
                cout << "2) 1. 입력 / 2. 조회 / 3. 삭제 / 4. 변경" << endl;
                cin >> n;

                switch (n)
                {
                case 1:
                    {
                        cout << "ID: ";
                        cin >> x;
                        Product* PInfo1 = new Product;
                        PInfo1->setProductID(x);
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
                    }break;
                case 2:
                    {
                        for_each(ProductInfo.begin(), ProductInfo.end(), [](Product* P) {
                            cout << P->getProductID() << " : " << P->getProductName() << " : "
                                << P->getProductPrice() << " : " << P->getProductSort() << endl; });
                    }break;
                case 3:
                    {
                        cout << "삭제할 데이터 행을 입력하세요.";
                        cin >> n;
                        ProductInfo.erase(ProductInfo.begin() + n);
                        cout << "삭제가 완료되었습니다." << endl;
                    }break;
                case 4:
                    {
                        cout << "변경할 데이터 행을 입력하세요.";
                        cin >> n;
                        cout << "변경할 데이터 열을 입력하세요.";
                        cin >> m;
                        cout << "변경할 데이터 내용을 입력하세요.";
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
                        cout << "데이터 변경이 완료되었습니다."<< endl;
                        break;
                    }break;
                }break;
            }
            case 3:
            {
                cout << "3) 1. 주문 / 2. 조회 / 3. 취소" << endl;
                cin >> n;
            }break;
        }
    } while (!(n == -1));
        
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
