#pragma once
#include "accounting.h"
//class Accounting;

class Controller{

	Accounting *accounting;
public:
	void getSum();
	void getChecks();
	void getDocuments_by_Date(Date, Date);
	Accounting* getAccounting();
};