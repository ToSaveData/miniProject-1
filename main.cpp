#include "Client.h"
#include "Product.h"
#include "OrderInfo.h"
#include <vector>
#include <algorithm>

int main()
{
    int n;
    cout << "****************************************************************" << endl;
    cout << "                       ��ǰ ���� ���α׷�" << endl;
    cout << "                       1. �� ���� ����" << endl;
    cout << "                       2. ��ǰ ���� ����" << endl;
    cout << "                       3. ���� ���� ����" << endl;
    cout << "****************************************************************" << endl;
    cout << endl;
    cout << "����� �Է��Ͻðڽ��ϱ� ? (����: 0)" << endl;
    do {
        cin >> n;

        switch (n)
        {
            case 1:
            {
                cout << "1) �Է� / ��ȸ / ���� / ����" << endl;
                cin >> n;

            }
            break;

            case 2:
            {
                cout << "2) �Է� / ��ȸ / ���� / ����" << endl;
            }
            break;

            case 3:
            {
                cout << "3) �ֹ� / ��ȸ / ���" << endl;
            }
            break;
        }
    } while (n == 0);

    
    
	
    
    
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
