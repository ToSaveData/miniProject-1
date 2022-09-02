#pragma once
#ifndef _CLIENTHANDLER_H_
#define _CLIENTHANDLER_H_
#include "Client.h"
#include <vector>

class ClientHandler
{
public:
	void ClientEnroll();
	void ClientSearch(string&);
	void ClientShowlist();
	void ClientRemove();
	void ClientEdit();
	Client* ClientInforeturn(string&);

private:
	vector<Client*> ClientInfo;
};

#endif // !_CLIENTHANDLER_H_
