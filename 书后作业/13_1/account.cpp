#include<iostream>
#include"account.h"
Account::Account(string acntNo,double balan):acntNumber(acntNo),balance(balan){}
void Account::display()const{
	std::cout<<"Account:"+acntNumber+"="<<balance<<"\n";
}