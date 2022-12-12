#include "Bank.h"

#include <iostream>
#include <fstream>
#include <vector>

Bank::Bank(const string& file_name)
{
    //  To-do
}

Bank::~Bank()
{
    //  To-do
}

bool Bank::ReadFile(const string& file_name)
{
    string text;
    string vText;
    stringstream ss;
    ifstream fileReader(file_name);
    Transaction transaction;

    while (getline (fileReader, text))
    {
        vector<string> v;
        ss = text;
        while (getline(ss, vText, ' '))
        v.push_back(vText);

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
    while (transactions_list_.empty())
    {
        transaction = transactions_list_.pop();
        switch (transaction.type())
        {
            case 'O':
                Account account = new Account(transaction.first_name(), transaction.last_name(), transation.account_id());
                account_list_.Insert(account);
                break;

            case 'D':
                
        }
    }

}