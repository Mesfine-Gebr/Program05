#pragma once
#include <iostream>
#include <string>
#include "Transaction.h"
#include "Fund.h"
using namespace std;

// Global varaible declaration  
const int FUND_TYPE = 10;
const int MONEY_MARKET = 0;
const int PRIME_MONEY_MARKET = 1;
const int LONG_TERM_BOUND = 2;
const int SHORT_TERM_BOUND = 3;


class Account {

public:

    // Constructor and destructor
    Account();
    Account(string fName, string lName, int accID);
    ~Account();

    //Member Function declaration
    void addAccount(int fundValue, int amount);
    void transferRecord(Transaction tranAmount, int fundValueNum);
    bool substractFund( int tranVal, int amount, Transaction valTrans);
    void similarAccount(int firstAccFund, int secondAccFund, int amountFund);
    void printHistoryAccount();
    void printHistoryFund(int funValueNum);
    void displayError(int amount, string fName, string lName, int fundValue);


    //Getter and Setter function declaration
    void setUserFundID(int fundValue);
    int getUserBalance(int fundValue) const;
    int getUserAccountID() const;
    string getFundName(int fundIdNum);
    string getUserFirstName() const;
    string getUserLastName() const;


    //Overloading operator
    Account& operator = (const Account &acc);
    bool operator == (const Account &acc) const;
    bool operator != (const Account &acc) const;
    bool operator >= (const Account &acc) const;
    bool operator <= (const Account &acc) const;
    bool operator > (const Account &acc) const;
    bool operator < (const Account &acc) const;
    
    // private Members data
private:
    int userAccID;
    int userFundID;
    string firstName, lastName;
    Fund arrFund[FUND_TYPE];

    friend ostream& operator<<(ostream &ost, Account &acctVal);

};



