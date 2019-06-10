#include<iostream>
#include"checking_bro.h"
Checking::Checking(string acntNo,double balan):Account(acntNo,balan),remittance(other){}
void Checking::display()const{
	std::cout<<"Checking ";
	Account::display();
}
void Checking::withdrawal(double amount){
	if(remittance==remitByPost)
		amount+=30;
	if(remittance==remitByCable)
		amount+=60;
	if(balance<amount)
		std::cout<<"Insufficient funds withdrawal: "<<amount<<"\n";
	else
		balance-=amount;
}