#pragma once
#ifndef _CLIENTHANDLER_H_
#define _CLIENTHANDLER_H_
#include "Client.h"
#include <vector>

class ClientHandler
{
public:
	ClientHandler();
	~ClientHandler();
	void ClientEnroll();
	void ClientSearch();
	void ClientShowlist();
	void ClientRemove();
	void ClientEdit();
	Client* ClientInforeturn(string&);
	bool HasCID(string key);
	vector<string> parseCCSV(istream&, char delimiter);

private:
	vector<Client*> ClientInfo;
};

#endif // !_CLIENTHANDLER_H_
