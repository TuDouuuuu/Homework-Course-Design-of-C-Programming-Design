#ifndef _IOSTEAM_
#define _IOSTEAM_
#include"product.h"
#include<string>
Product::Product(string n,int p){
	name=n;prize=p;
}

void Product::ReName(string n){
	name=n;
}
void Product::RePrize(int p){
	prize=p;
}

string Product::ReturnName(){
	return name;
}

int Product::ReturnPrize(){
	return prize;
}
int main(){
	Product a;
	std::cout<<a.ReturnName()<<" "<<a.ReturnPrize()<<endl;
	string n;
	cin>>n;
	a.ReName(n);
	std::cout<<a.ReturnName()<<" "<<a.ReturnPrize()<<endl;
	//Product b("cyz");
	//std::cout<<b.ReturnName()<<" "<<b.ReturnPrize()<<endl;
	/*Product c(,39);
	std::cout<<c.ReturnName()<<" "<<c.ReturnPrize()<<endl;*/
}
#endif