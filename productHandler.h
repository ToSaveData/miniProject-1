#pragma once
#ifndef _PRODUCTHANDLER_H_
#define _PRODUCTHANDLER_H_
#include "Product.h"
#include <vector>

class productHandler
{
public:
	void productEnroll();
	void productSearch(int&);
	void productShowlist();
	void productRemove();
	void productEdit();
private:
	vector<Product*> ProductInfo;
};

#endif // !_PRODUCTHANDLER_H_
