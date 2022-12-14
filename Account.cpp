#include <iostream>
#include "Account.h"


Account:: Account() {}

// Constructor function fill up user information and fund type
Account:: Account(string fName, string lName, int accID){

    firstName = fName;
    lastName = lName;
    userAccID = accID;

    string listFundName[] = {"Money Marekt", "Prime Money Market", "Long-Term Bond", "Short-Term Bound", 
                        "500-Index Fund", "Captial Value Fund", "Growth Equity Fund", "Value Fund", "Value Stock Index"};

    for(int f = 0; f < 10; f < f++){

        arrFund[f].set_fund_name(listFundName[f]);
    }                  
}


int Account :: getUserAccountID() const {

    return userAccID;
}

void Account:: addAccount(int fundValue, int amount){

    arrFund[fundValue].Deposit(amount);
}




void Account:: substractAcc(int fundID, int amount){

    arrFund[fundID].WithDraw(amount);
}


// Simllar account link together to withdraw the transaction if one account less desire amount share the remain amount fill up on the second account and then set balance.
void Account:: similarAccount(int firstAccFund, int secondAccFund, int amountFund){

    if((arrFund[firstAccFund].balance() + arrFund[secondAccFund].balance()) >= amountFund) {   

        int currentBalance = arrFund[firstAccFund].balance();

        arrFund[firstAccFund].WithDraw(currentBalance);

        Transaction transactionHistory('W', getUserAccountID(), firstAccFund, currentBalance);

        arrFund[firstAccFund].Log(transactionHistory);

        amountFund = amountFund - currentBalance;

        arrFund[secondAccFund].WithDraw(amountFund);

        Transaction transactionHistroy01('W', getUserAccountID(), secondAccFund, amountFund);

        arrFund[secondAccFund].Log(transactionHistroy01);

    }
    else
    {

            int currBalance = arrFund[firstAccFund].balance(); 
            if(currBalance > amountFund)
            {

                arrFund[firstAccFund].WithDraw(currBalance); 

                Transaction trasnsactionHistroy_1('W', getUserAccountID(), firstAccFund, currBalance); 

                arrFund[firstAccFund].Log(trasnsactionHistroy_1); 

                amountFund = amountFund - currBalance;
            
            }
            if(arrFund[secondAccFund].userBalanceCheck(amountFund))
            { 

                arrFund[secondAccFund].WithDraw(amountFund); 

                Transaction transactionHistroy('W', getUserAccountID(), secondAccFund, amountFund);

                arrFund[secondAccFund].Log(transactionHistroy); 

            }
            else {

                cerr <<" ERROR: Insefficent Amount to make transaction"<<amountFund<< " "<<"on this account"<<firstName<< " "<< lastName<< " " <<getFundName(amountFund)<<endl;

                Transaction transactionHistroy('W', getUserAccountID(), secondAccFund, amountFund); 

                arrFund[secondAccFund].Log(transactionHistroy);  

            }
    


    }


}

// SubstractFund function help widthdraw of money each fund types and then check user balance. If user has sufficient balance make transaction and then substract the withdraw amount, otherwise display error message 
bool Account:: substractFund( int tranVal, int amount, Transaction valTrans)
{

    if(tranVal == MONEY_MARKET || tranVal == PRIME_MONEY_MARKET || tranVal == LONG_TERM_BOUND || tranVal == SHORT_TERM_BOUND)
    {

        if(tranVal == MONEY_MARKET || tranVal == PRIME_MONEY_MARKET)
        {

            if(arrFund[tranVal].userBalanceCheck(amount))
            {

            arrFund[tranVal].userBalanceCheck(amount);
            arrFund[tranVal].WithDraw(amount);
            return true;

            }
            else if((arrFund[MONEY_MARKET].balance() + arrFund[PRIME_MONEY_MARKET].balance()) >= amount)
            {

                if(tranVal == MONEY_MARKET)
                {

                    similarAccount(MONEY_MARKET, PRIME_MONEY_MARKET, amount);
                    return true;

                }
                else {

                    similarAccount(PRIME_MONEY_MARKET, MONEY_MARKET, amount);

                    return false;

                }
            }
            else 
            {
                
                displayError(amount, getUserFirstName(), getUserLastName(), tranVal);
                if(tranVal == MONEY_MARKET)
                {

                    similarAccount(MONEY_MARKET, PRIME_MONEY_MARKET, amount);

                    return true;
                }
                else
                {

                    similarAccount(PRIME_MONEY_MARKET, MONEY_MARKET, amount);

                    return false;
                }

                return false;
            }
        }

    
        else if (tranVal == SHORT_TERM_BOUND || tranVal == LONG_TERM_BOUND)
        {

            if(arrFund[tranVal].userBalanceCheck(amount))
            {

                arrFund[tranVal].WithDraw(amount);
                arrFund[tranVal].Log(valTrans);
                return true;
            }
            else if (((arrFund[SHORT_TERM_BOUND].balance() + arrFund[LONG_TERM_BOUND].balance()) >= amount))
            {

                if(tranVal == LONG_TERM_BOUND) 
                {

                    similarAccount(LONG_TERM_BOUND, SHORT_TERM_BOUND, amount);
                }
                else {

                    similarAccount(SHORT_TERM_BOUND, LONG_TERM_BOUND, amount);
                }

            }
            else 
            {

                displayError(amount, getUserFirstName(), getUserLastName(), tranVal);
                if(tranVal == LONG_TERM_BOUND)
                {

                    similarAccount(LONG_TERM_BOUND, SHORT_TERM_BOUND, amount);
                }
                else 
                {

                    similarAccount(SHORT_TERM_BOUND, LONG_TERM_BOUND, amount);
                }

                
            }
        }

        return false;

    }

    else {

        if(arrFund[tranVal].userBalanceCheck(amount))
        {

            arrFund[tranVal].WithDraw(amount);
            arrFund[tranVal].Log(valTrans);
            return true;
        }
        else
        {
            displayError(amount, getUserLastName(), getUserLastName(), tranVal);
            return false;

        }


    }
        
}

void Account:: displayError(int amount, string fName, string lName, int fundValue) 
{    


    cerr << "ERROR: NOT Sufficient fund on this account"<< amount << "on this account "<< firstName <<" "<< lastName << " " << getFundName(fundValue) <<endl;
    //Transaction transctionHistroy('W', getUserAccountID(), fundValue, "Not valid account", amount ); 
    //arrFund[fundValue].Log(transctionHistroy); 

}

void Account:: transferRecord(Transaction tranAmount, int fundValueNum){

    arrFund[fundValueNum].Log(tranAmount);
}
void Account:: printHistoryAccount(){

    cout << "Account Transaction Histroy " << firstName << " "<< lastName << " "<< "Transaction Fund date and amount" <<endl;
    for (int a = 0; a < 10; a++)
    {
        arrFund[a].PrintAllHistory();
    }
}

void Account:: printHistoryFund(int fundIdNum){

    cout << " Account Transaction Histroy "<< firstName << " " << lastName << " " << getFundName(fundIdNum) << " $ "<<getUserBalance(fundIdNum) << endl;
    arrFund[fundIdNum].PrintAllHistory();

}

void Account:: setUserFundID(int fundValue)
{
    userFundID = fundValue;
    
}

int Account:: getUserBalance(int fundValue) const
{
    return arrFund[fundValue].balance();

}

string Account:: getUserLastName() const
{

    return lastName;
}
string Account:: getUserFirstName() const
{

    return firstName;
}

string Account:: getFundName(int fundValue)
{

    return arrFund[fundValue].fund_name();

}

// Overloading operator function
Account& Account:: operator = (const Account &acc)
{

    userAccID = acc.userAccID;
    userFundID = acc.userFundID;
    firstName = acc.firstName;
    lastName = acc.lastName;

    return *this;
}

bool Account:: operator == (const Account &acc) const 
{

    if(this->firstName == acc.firstName && this->lastName == acc.lastName && this->userAccID == acc.userAccID && this->userFundID == acc.userFundID)
    {
        return true;

    }
    else {

        return false;
    }
}

bool Account:: operator != (const Account &acc) const
{

    return !(*this == acc);

}

bool Account:: operator >= (const Account &acc) const
 {

    return (*this > acc || *this == acc);
}

bool Account:: operator <= (const Account &acc) const
{

    return (*this > acc || *this == acc);
}

 bool Account:: operator > (const Account &acc) const {

    if(userAccID > acc.userAccID){

        return true;
    }
    else {
        return false;
    }


 }

 bool Account:: operator < (const Account &acc) const {

    if(userAccID < acc.userAccID){

        return true;
    }
    else {
        return false;
    }

 }


ostream& operator<<(ostream &ost, Account &acctVal)
{

    ost << acctVal.getUserFirstName() << " " << acctVal.getUserLastName() << " USER ID "<< acctVal.getUserAccountID() << endl;
    for(int j = 0; j < 10; j++)
    {

        ost << " "<< acctVal.getFundName(j) << " Balance is $: "<< acctVal.getUserBalance(j);
        ost << endl;
    }

    return ost;

}

Account:: ~Account() {

}

