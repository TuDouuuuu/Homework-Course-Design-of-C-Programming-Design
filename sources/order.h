#ifndef _HEADER_ORDER_
#define _HEADER_ORDER_
#include"Product.h"
#include"Company.h"
#include"ex.h"
#include<string>
#include<iostream>
#include<cstring>
#include<iomanip>
using namespace std;
class Order{
private:
	int no;
	Company c;Product p;
	int num;int sum;
	Order *next=NULL;

	void display(bool x);
	void connectNode(Order *a,Order *b);
	int str_int(string x);
public:
	Order(int nono,string n1="No Name",string n2="No Name",int p=0,int n=0);

	Order* createFromFile(Order* x,int nono,string n1="No Name",string n2="No Name",int p=0,int n=0);
	Order* createFromKeyboard(int nono);
	void allDisplay();
	void search();
	void del();
	void revise();
	void companyCnt();

	string ReturnCompanyName();
	string ReturnProductName();
	int ReturnProductPrize();
	int ReturnNo();
	int ReturnNum();
	Order* ReturnNext();
};
#endif