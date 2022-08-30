#include "Client.h"

#include <vector>
#include <algorithm>

int main()
{
	vector<Client*> ClientInfo;
	Client *CInfo1 = new Client("Park Jin Seok", "010-0000-1111", "Heyhwa");
	ClientInfo.push_back(CInfo1);

	for_each(ClientInfo.begin(), ClientInfo.end(), [](Client* C) {
		cout << C->getName() << " : " << C->getPhoneNumber()<< " : " << C->getAddress()<< endl;
		});



	return 0;
}