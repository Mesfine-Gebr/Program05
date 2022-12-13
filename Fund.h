#pragma once
#include "Transaction.h"
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Fund {
public:
	// Constructors and Destructor
	Fund();
	Fund(string fund_name);
	~Fund();

	// Getters
	string fund_name() const;
	int balance() const;
	void set_fund_name(string fund_name); 
    bool userBalanceCheck(int amountBalance);

    // Actions
	bool Deposit(int amount);
	bool WithDraw(int amount);
	bool Log(Transaction trans);
	void PrintAllHistory();
	void PrintFundHistory();	

private:
	string fund_name_;
	int balance_;
	vector<Transaction> history_transaction_;
};


