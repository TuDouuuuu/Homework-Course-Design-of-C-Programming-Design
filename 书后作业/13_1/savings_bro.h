#ifndef HEADER_SAVINGS
#define HEADER_SAVINGS
#include"account.h"
#include<string>
using std::string;
class Savings:public Account{
	static double minBalance;
public:
	Savings(string acntNo,double balan=0.0):Account(acntNo,balan){}
	virtual void display()const;
	virtual void withdrawal(double amount);
};
#endif