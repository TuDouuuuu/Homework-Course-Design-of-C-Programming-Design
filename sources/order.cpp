#include"order.h"
#include<string>
#include<iostream>
//构造函数
Order::Order(string n1,string n2,int p,int n,int s){
	c.ReName(n1);
}
string Order::ReturnCompanyName(){
	return c.ReturnName();
}
int main(){
	Order a("pikachu");
	std::cout<<a.ReturnCompanyName()<<endl;
}