#pragma once
#include<queue>
#include "BSTree.h"
#include"Transaction.h"
#include "Account.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<vector>
#include <string>
using namespace std;

class Bank {
public:
	Bank(const string& file_name);
	~Bank();

	bool ReadFile(const string& file_name);
	void ProcessQueue();
	void Display();

private:
	queue<Transaction> transactions_list_;
	BSTree account_list_;  
};
