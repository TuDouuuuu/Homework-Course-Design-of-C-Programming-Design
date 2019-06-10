#ifndef HEADER_ACCOUNT
#define HEADER_ACCOUNT
#include <string>
using std::string;
class Account{
protected:
	string acntNumber;
	double balance;
public:
	Account(string acntNo,double balan=0.0);
	virtual void display()const=0;
	double getBalan()const{return balance;}
	void deposit(double amount){balance+=amount;}
	bool operator==(const Account& a){return acntNumber==a.acntNumber;}
	virtual void withdrawal(double amount)=0;
	string getAcntNo()const{ return acntNumber; }
};
#endif