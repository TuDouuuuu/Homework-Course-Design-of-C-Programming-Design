/*#ifndef _COMPANY_H
#define _COMPANY_H
#ifndef _PRODUCT_H
#define _PRODUCT_H*/
#include"Product.h"
#include<string>
using namespace std;
class Order{
private:
	int no;
	Company c;Product p;
	int num;int sum;
public:
	Order(string n1="No Name",string n2="No Name",int p=0,int n=0,int s=0);
	void op(string s1,string p,string n);
	void del(string );
	string ReturnCompanyName();
};
/*
#endif 
#endif*/