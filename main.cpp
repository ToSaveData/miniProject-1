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
    cout << "                       ��ǰ ���� ���α׷�" << endl;
    cout << "                       1. �� ���� ����" << endl;
    cout << "                       2. ��ǰ ���� ����" << endl;
    cout << "                       3. ���� ���� ����" << endl;
    cout << "****************************************************************" << endl;
    cout << endl;
    
    do {
        cout << "����� �Է��Ͻðڽ��ϱ� ? (����: -1)" << endl;
        cin >> n;

        switch (n)
        {
            case 1:
            {
                cout << "1) 1. �Է� / 2. ��ȸ / 3. ���� / 4. ����" << endl;
                cin >> n;
                switch (n)
                {
                    case 1:
                    {
                        cout << "�̸�: ";
                        cin >> s;
                        Client* CInfo1 = new Client;
                        CInfo1->setName(s);
                        s.clear();
                        cout << "�������(ex.220830): ";
                        cin >> s;
                        CInfo1->setBirthday(s);
                        s.clear();
                        cout << "��ȭ��ȣ(ex.010-1234-5678): ";
                        cin >> s;
                        CInfo1->setPhoneNumber(s);
                        s.clear();
                        cout << "�ּ�(ex.����� ���α� ��ȭ��): ";
                        cin.ignore(); // ���� �� ����(enter)�� �����ϴ� ���
                        getline(cin, s, '\n'); // '\n'�� ���� ������ �ްڴ�
                        CInfo1->setAddress(s);
                        s.clear();
                        cout << "�̸����ּ�(ex.example@gmail.com): ";
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
                        cout << "������ ������ ���� �Է��ϼ���.";
                        cin >> n;
                        ClientInfo.erase(ClientInfo.begin() + n);
                        cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
                    }break;

                    case 4:
                    {
                        cout << "������ ������ ���� �Է��ϼ���.";
                        cin >> n;
                        cout << "������ ������ ���� �Է��ϼ���.";
                        cin >> m;
                        cout << "������ ������ ������ �Է��ϼ���.";
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
                        cout << "������ ������ �Ϸ�Ǿ����ϴ�." << endl;
                        break;
                    }break;
                }break;
            }break;

            case 2:
            {
                cout << "2) 1. �Է� / 2. ��ȸ / 3. ���� / 4. ����" << endl;
                cin >> n;

                switch (n)
                {
                case 1:
                    {
                        cout << "ID: ";
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
                    }break;
                case 2:
                    {
                        for_each(ProductInfo.begin(), ProductInfo.end(), [](Product* P) {
                            cout << P->getProductID() << " : " << P->getProductName() << " : "
                                << P->getProductPrice() << " : " << P->getProductSort() << endl; });
                    }break;
                case 3:
                    {
                        cout << "������ ������ ���� �Է��ϼ���.";
                        cin >> n;
                        ProductInfo.erase(ProductInfo.begin() + n);
                        cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
                    }break;
                case 4:
                    {
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
                        cout << "������ ������ �Ϸ�Ǿ����ϴ�."<< endl;
                        break;
                    }break;
                }break;
            }
            case 3:
            {
                cout << "3) 1. �ֹ� / 2. ��ȸ / 3. ���" << endl;
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
