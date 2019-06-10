#ifndef HEADER_CHECKING
#define HEADER_CHECKING
#include"account.h"
enum REMIT{remitByPost,remitByCable,other};
class Checking:public Account{
	REMIT remittance;
public:
	Checking(string acntNo,double balan=0.0);
	virtual void withdrawal(double amount);
	virtual void display()const;
	void setRemit(REMIT re){remittance=re;}
};
#endif