#pragma once
#ifndef _PRODUCTHANDLER_H_
#define _PRODUCTHANDLER_H_

#include <vector>
#include "Product.h"

class ProductHandler
{
public:
	ProductHandler();
	~ProductHandler();
	void productEnroll();
	void productSearch();
	void productShowlist();
	void productRemove();
	void productEdit();
	Product* ProductInfoReturn(int&);
	int makeProductID();
	bool HasPID(int&);
	vector<string> parsePCSV(istream&, char);

private:
	vector<Product*> ProductInfo;
};

#endif // !_PRODUCTHANDLER_H_
