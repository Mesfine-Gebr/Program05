#include "Bank.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

Bank::Bank(const string& file_name)
{
    ReadFile(file_name);
}

Bank::~Bank()
{
    account_list_.CleanUp();
}

bool Bank::ReadFile(const string& file_name)
{
    string text;
    string vText;
    stringstream ss;
    ifstream fileReader(file_name);
    Transaction transaction;

    //  Read file line by line
    while (getline (fileReader, text))
    {
        vector<string> v;
        ss = text;
        //  Split line into separate strings and store in a vector
        while (getline(ss, vText, ' '))
        v.push_back(vText);

        //  Creates transaction based on type
        switch (v[0])
        {
            case "O":
                transaction = new Transaction('O', stoi(v[3]), v[1], v[2]);
                break;

            case "D":
            case "W":
                int id = stoi(v[1]) / 10;
                int fund = stoi(v[1]) % 10;
                transaction = new Transaction(v[0].c_str(), id, fund, v[2]);
                break;

            case "T":
                int oId = stoi(v[1]) / 10;
                int oFund = stoi(v[1]) % 10;
                int fId = stoi(v[3]) / 10;
                int fFund = stoi(v[3]) % 10;
                transaction = new Transaction('T', oId, oFund, fId, fFund, v[2]);
                break;

            case "H":
                if (v[1].size() == 4)
                transaction = new Transaction('H', v[1]);
                else
                {
                    int id = stoi(v[1]) / 10;
                    int fund = stoi(v[1]) % 10;
                    Transaction('H', id, fund);
                }   //  if/else
                break;
        }   //  end switch (v[0])
        transactions_list_.push(transaction)
    }   //  end while (getline (fileReader, text))
    fileReader.close();
}

void Bank::ProcessQueue()
{
    Transaction transaction;
    while (transactions_list_.empty())  //  Until queue is empty
    {
        transaction = transactions_list_.pop();
        switch (transaction.type())
        {
            case 'O':
                if (transaction.account_id() > 999 && transaction.account_id() < 10000)
                {
                    Account account = new Account(transaction.first_name(), transaction.last_name(), transation.account_id());
                    bool result = account_list_.Insert(account);
                    if (!result)
                    cerr << "ERROR: Account " << account.getUserAccountID() << " is already opened. Transaction refused." << endl;
                }
                else
                cerr << "ERROR: " << transaction.account_id() "is an invalid account ID. Transaction refused.(Account IDs must be 4 digits)" << endl;
                break;

            case 'D':
                if (transaction.account_id() > 999 && transaction.account_id() < 10000)
                {
                    Account* account;
                    bool result = account_list_.Retrieve(transaction.account_id(), account)
                    if (result)
                    {
                        account.transferRecord(transaction, transaction.fund_id());
                        account.addAccount(transaction.fund_id(), transaction.amount());
                    }
                    else
                    cerr << "ERROR: Account " << transaction.account_id() << " not found. Transaction refused." << endl;
                }
                else
                cerr << "ERROR: " << transaction.account_id() "is an invalid account ID. Transaction refused.(Account IDs must be 4 digits)" << endl;
                break;
            
            case 'W':
                if (transaction.account_id() > 999 && transaction.account_id() < 10000)
                {
                    Account* account;
                    bool result = account_list_.Retrieve(transaction.account_id(), account);
                    if (result)
                    account.substractFund(transaction.fund_id(), transaction.amount(), transaction);
                    else
                    cerr << "ERROR: Account " << account.getUserAccountID() << " not found. Transaction refused" << endl;
                }
                else
                cerr << "ERROR: " << transaction.account_id() "is an invalid account ID. Transaction refused.(Account IDs must be 4 digits)" << endl;
                break;

            case 'T':
                if (transaction.account_id() > 999 && transaction.account_id() < 10000)
                {
                    Account* initialAccount;
                    Account* finalAccount;
                    bool initial = account_list_.Retrieve(transaction.account_id(), initialAccount);
                    bool final = account_list_.Retrieve(transaction.destination_account_id(), finalAccount);
                    if (intial && final)
                    {
                        if (initial.getUserBalance(transaction.fund_id) >= transaction.amount())
                        {
                            initialAccount.substractAcc(transaction.fund_id(), transaction.amount());
                            finalAccount.Deposit(transaction.destination_fund_id(), transaction.destination_account_id());
                            initialAccount.transferRecord(transaction.fund_id(), transaction);
                            finalAccount.transferRecord(transaction.destination_fund_id(), transaction);
                        }
                        else
                        cerr << "ERROR: Fund's balance is too low to transfer amount. Transaction refused." << endl;
                    }
                    else
                    cerr << "ERROR: Account(s) not found." << endl;
                }
                else
                cerr << "ERROR: " << transaction.account_id() "is an invalid account ID. Transaction refused.(Account IDs must be 4 digits)" << endl;
                break;

            case 'H':
                if (transaction.account_id() > 999 && transaction.account_id() < 10000)
                {
                    Account* account;
                    bool result = account_list_.Retrieve(transaction.account_id(), account);
                    if (result)
                    {
                        if (transaction.fund_id() < 0)
                        account.printHistoryAccount();
                        else
                        account.printHistoryFund(transaction.fund_id());
                    }
                    else
                    cerr << "ERROR: Account " << account.getUserAccountID() << " not found. Transaction refused" << endl;
                }
                else
                cerr << "ERROR: " << transaction.account_id() "is an invalid account ID. Transaction refused.(Account IDs must be 4 digits)" << endl;
                break;
        }   //  end switch (transaction.type())
    }   //  end while (transactions_list_.empty())
}

void BSTree Display()
{
    account_list_.Display();
}