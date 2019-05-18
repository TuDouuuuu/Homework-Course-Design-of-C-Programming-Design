#include"order.h"
#include<string>
#include<iostream>
#include<cstring>
#include<iomanip>
//构造函数
Order::Order(string n1,string n2,int pp,int n,int s){
	c.ReName(n1);p.ReName(n2);p.RePrize(pp);num=n;sum=s*p.ReturnPrize();
}

void Order::connectNode(Order &a,Order &b){
	a.next=&b;
}
void Order::display(){
	cout<<setiosflags(ios::left)<<"|"<<setw(15)<<"Order ID"<<"|"<<setw(15)<<c.ReturnName()<<"|"<<setw(15)<<p.ReturnName()<<"|"<<setw(15)<<"Prize"<<"|"<<setw(15)<<"Quantity"<<"|"<<setw(15)<<"Sum"<<"|"<<endl;
}

//操作函数
Order* Order::search(string op,string n,Order now){
	Order *u=&now;
	if(op=="-C"){//查询公司名称
		cout<<"There are results:"<<endl;
		cout<<setiosflags(ios::left)<<"|"<<setw(15)<<"Order ID"<<"|"<<setw(15)<<"Company's Name"<<"|"<<setw(15)<<"Product's Name"<<"|"<<setw(15)<<"Prize"<<"|"<<setw(15)<<"Quantity"<<"|"<<setw(15)<<"Sum"<<"|"<<endl;
		while(u!=NULL){
			if(u->ReturnCompanyName()==n)u->display();
			u=u->next;
		}
	}
	else if(op=="-PN"){//查询产品名称
		cout<<"There are results:"<<endl;
		cout<<setiosflags(ios::left)<<"|"<<setw(15)<<"Order ID"<<"|"<<setw(15)<<"Company's Name"<<"|"<<setw(15)<<"Product's Name"<<"|"<<setw(15)<<"Prize"<<"|"<<setw(15)<<"Quantity"<<"|"<<setw(15)<<"Sum"<<"|"<<endl;
		while(u!=NULL){
			if(u->ReturnProductName()==n)u->display();
			u=u->next;
		}
	}
}


//返回函数
string Order::ReturnCompanyName(){
	return c.ReturnName();
}
string Order::ReturnProductName(){
	return p.ReturnName();
}

int main(){
	Order a("pikachu");
	Order b("pikachu","cyz");
	a.connectNode(a,b);
	b.search("-PN","cyz",a);
}