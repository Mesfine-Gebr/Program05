#pragma once
#include <iostream>
#include <string>
#include "Transaction.h"
#include "Fund.h"
using namespace std;

const int FUND_Type = 10;
const int MONEY_MARKET = 0;
const int PRIME_MONEY_MARKET = 1;
const int LONG_TERM_BOUND = 2;
const int SHORT_TERM_BOUND = 3;


class Account {

public:
    Account();
    Account(string fName, string lName, int accID);
    ~Account();

    void addAccount(int fundValue, int amount);
    void transferRecord(Transaction tranAmount, int fundValueNum);
    void substractFund( Transaction tranVal, int amount, Transaction valTrans);
    void similarAccount(int prFun, int secoFund, int amountFund);
    void printHistory();
    void printHistoryFundState(int funValueNum);
    void displayError(int amount, string fName, string lName, int fundValueNum);

    int getUserAccountID();
    int getUserBalance(int fundValueNum) const;
    string getFundName(int funValueNum);
    string getUserFirstName() const;
    string getUserLastName() const;
    void setUserFundID(int fundValueNum);

private:
    int userAccID;
    int userFundID;
    string firstName, lastName;
    Fund arrFund[FUND_Type];

    friend ostream& operator<<(ostream &outPut, Account &acctVal);

};