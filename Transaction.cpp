#include "Transaction.h"

Transaction::Transaction() {
}
 
// Printing the whole account
Transaction::Transaction(char type, int account_id) {
	this->type_ = type;
	this->account_id_ = account_id;
	this->fund_id_ = -1;
}

// Open account
Transaction::Transaction(char type, int account_id, string first_name, string last_name) {
	this->type_ = type;
	this->account_id_ = account_id;
	this->first_name_ = first_name;
	this->last_name_ = last_name;
}

// Print fund transaction
Transaction::Transaction(char type, int account_id, int fund_id) {
	this->type_ = type;
	this->account_id_ = account_id;
	this->fund_id_ = fund_id;
}

// Deposit or Withdraw
Transaction::Transaction(char type, int account_id, int fund_id, int amount) {
	this->type_ = type;
	this->account_id_ = account_id;
	this->fund_id_ = fund_id;
	this->amount_ = amount;
}

// Transfer 
Transaction::Transaction(char type, int from_account, int from_fund_id, int to_account, int to_fund_id, int amount) {
	this->type_ = type;
	this->account_id_ = from_account;
	this->fund_id_ = from_fund_id;
	this->destination_account_id_ = to_account;
	this->destination_fund_id_ = to_fund_id;
	this->amount_ = amount;
}

// Copy Constructor 
Transaction::Transaction(const Transaction& trans) {
	*this = trans;
}

Transaction::~Transaction() {
}

// Failed Transfer
Transaction::Transaction(char type, int from_account, int from_fund_id, int to_account, int to_fund_id, int amount, string fail) {
	this->type_ = type;
	this->account_id_ = from_account;
	this->fund_id_ = from_fund_id;
	this->destination_account_id_ = to_account;
	this->destination_fund_id_ = to_fund_id;
	this->amount_ = amount;
	this->fail_ = fail;
}

// Failed Deposit or Withdraw
Transaction::Transaction(char type, int account_id, int fund_id, int amount, string fail) {
	this->type_ = type;
	this->account_id_ = account_id;
	this->fund_id_ = fund_id;
	this->amount_ = amount;
	this->fail_ = fail;
}

// Copy Assignment 
Transaction& Transaction::operator=(const Transaction& trans) {
	type_ = trans.type();
	account_id_ = trans.account_id();
	first_name_ = trans.first_name();
	last_name_ = trans.last_name();
	fund_id_ = trans.fund_id();
	destination_account_id_ = trans.destination_account_id();
	destination_fund_id_ = trans.destination_fund_id();
	amount_ = trans.amount();
	fail_ = trans.fail();
	return *this;
}

char Transaction::type() const {
	return type_;
}

string Transaction::first_name() const {
	return first_name_;
}

string Transaction::last_name() const {
	return last_name_;
}

string Transaction::fail() const {
	return fail_;;
}

int Transaction::account_id() const {
	return account_id_;
}

int Transaction::fund_id() const {
	return fund_id_;
}

int Transaction::destination_account_id() const {
	return destination_account_id_;
}

int Transaction::destination_fund_id() const {
	return destination_fund_id_;
}

int Transaction::amount() const {
	return amount_;
}

void Transaction::set_amount(int amount) {
	amount_ = amount;
}

bool Transaction::IsFail() const {
	if (!fail_.empty()) {
		return true;
	}
	return false;
}

ostream& operator<<(ostream& stream, const Transaction& trans) {
	// There is only three types of transaction history to add to history for each fund
	if (trans.type() == 'D' ||trans.type() == 'd' || trans.type() == 'W' || trans.type() == 'w' ) {
		// D and W would have similar transaction flow
		if (trans.IsFail()) {
			stream << " " << trans.type() << " " << trans.account_id() << " " << trans.fund_id() << " " << trans.amount() << " (Failed)";
		} else {
			stream << " " << trans.type() << " " << trans.account_id() << " " << trans.fund_id() << " " << trans.amount();
		}
	} else if (trans.type() == 'T'|| trans.type() == 't') {
		if (trans.IsFail()) {
			stream << " " << trans.type() << " " << trans.account_id() << " " << trans.fund_id() << " "
				<< trans.destination_account_id() << " " << trans.destination_fund_id() << " " << trans.amount() << " (Failed)";
		} else {
			stream << " " << trans.type() << " " << trans.account_id() << " " << trans.fund_id() << " "
				<< trans.destination_account_id() << " " << trans.destination_fund_id() << " " << trans.amount();
		}
	}

	return stream <<endl;
}
