#include"order.h"
#include<string>
#include<iostream>
#include<cstring>
#include<iomanip>
//构造函数
Order::Order(string n1,string n2,int pp,int n,int s){
	c.ReName(n1);p.ReName(n2);p.RePrize(pp);num=n;sum=s*p.ReturnPrize();
}

//辅助函数
void Order::connectNode(Order &a,Order &b){
	a.next=&b;
}
void Order::display(){
	cout<<setiosflags(ios::left)<<"|"<<setw(15)<<"Order ID"<<"|"<<setw(15)<<c.ReturnName()<<"|"<<setw(15)<<p.ReturnName()<<"|"<<setw(15)<<"Prize"<<"|"<<setw(15)<<"Quantity"<<"|"<<setw(15)<<"Sum"<<"|"<<endl;
}
int Order::str_int(string s){
	int len=s.length();
	int ans=0;
	for(int i=len-1;i>=0;i--){
		ans=ans*10+s[i]-'0';
	}
	return ans;
}

//操作函数
//查询函数
void Order::search(string op,string n,Order now){
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
	else if(op=="-PP"){//查询产品单价
		cout<<"There are results:"<<endl;
		cout<<setiosflags(ios::left)<<"|"<<setw(15)<<"Order ID"<<"|"<<setw(15)<<"Company's Name"<<"|"<<setw(15)<<"Product's Name"<<"|"<<setw(15)<<"Prize"<<"|"<<setw(15)<<"Quantity"<<"|"<<setw(15)<<"Sum"<<"|"<<endl;
		while(u!=NULL){
			if(u->ReturnProductPrize()==str_int(n))u->display();
			u=u->next;
		}
	}
	else if(op=="-N"){//查询某个编号
		cout<<"There are results:"<<endl;
		cout<<setiosflags(ios::left)<<"|"<<setw(15)<<"Order ID"<<"|"<<setw(15)<<"Company's Name"<<"|"<<setw(15)<<"Product's Name"<<"|"<<setw(15)<<"Prize"<<"|"<<setw(15)<<"Quantity"<<"|"<<setw(15)<<"Sum"<<"|"<<endl;
		while(u!=NULL){
			if(u->ReturnNo()==str_int(n)){
				u->display();break;
			}
			u=u->next;
		}
	}
	else if(op=="-D"){//输出所有
		cout<<"There are results:"<<endl;
		cout<<setiosflags(ios::left)<<"|"<<setw(15)<<"Order ID"<<"|"<<setw(15)<<"Company's Name"<<"|"<<setw(15)<<"Product's Name"<<"|"<<setw(15)<<"Prize"<<"|"<<setw(15)<<"Quantity"<<"|"<<setw(15)<<"Sum"<<"|"<<endl;
		while(u!=NULL){
			u->display();
			u=u->next;
		}
	}
	else{
		cout<<"Unknow opeartion!!"<<endl;
	}
}
//删除函数


//返回函数
string Order::ReturnCompanyName(){
	return c.ReturnName();
}
string Order::ReturnProductName(){
	return p.ReturnName();
}
int Order::ReturnProductPrize(){
	return p.ReturnPrize();
}
int Order::ReturnNo(){
	return no;
}

int main(){
	Order a("pikachu");
	Order b("pikachu","cyz");
	a.connectNode(a,b);
	b.search("-PN","cyz",a);
}