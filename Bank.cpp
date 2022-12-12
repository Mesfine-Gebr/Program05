#include "Bank.h"

#include <iostream>
#include <fstream>

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
    char type;
    ifstream fileReader(file_name);
    while (getline (fileReader, text))
    transactions_list_.push(text);
    fileReader.close();
}

void Bank::ProcessQueue()
{
    string text;
    while(!transactions_list_.IsEmpty)
    {
        text = transactions_list.pop();
        switch(text.at(0))
        {
            case O:
                //  Add account to account_list
                
                break;
            case D:
            case W:
                //  Access account_list
                break;
            
        }
    }
}