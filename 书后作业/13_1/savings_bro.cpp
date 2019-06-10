#include<iostream>
#include"savings_bro.h"
double Savings::minBalance=0;
void Savings::display()const{
	std::cout<<"Savings ";
	Account::display();
}
void Savings::withdrawal(double amount){
	if(balance+ minBalance<amount)
		std::cout<<"Insufficient funds withdrawal: "<<amount<<"\n";
	else
		balance-=amount;
}