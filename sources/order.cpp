#include"order.h"
#include<string>
#include<iostream>
#include<cstring>
#include<iomanip>
//构造函数
Order::Order(int nono,string n1,string n2,int pp,int n){
	no=nono;
	c.ReName(n1);p.ReName(n2);p.RePrize(pp);num=n;sum=n*pp;
}

//辅助函数
void Order::connectNode(Order *a,Order *b){
	a->next=b;
}
void Order::display(bool x){//0是格式输出
	if(x)cout<<setiosflags(ios::left)<<"|"<<setw(15)<<no<<"|"<<setw(15)<<c.ReturnName()<<"|"<<setw(15)<<p.ReturnName()<<"|"<<setw(15)<<p.ReturnPrize()<<"|"<<setw(15)<<num<<"|"<<setw(15)<<sum<<"|"<<endl;
	else cout<<setiosflags(ios::left)<<"|"<<setw(15)<<"Order ID"<<"|"<<setw(15)<<"Company's Name"<<"|"<<setw(15)<<"Product's Name"<<"|"<<setw(15)<<"Prize"<<"|"<<setw(15)<<"Quantity"<<"|"<<setw(15)<<"Sum"<<"|"<<endl;
}
int Order::str_int(string s){//string型转int型
	int len=s.length();	
	int ans=0;
	for(int i=len-1;i>=0;i--){
		ans=ans*10+s[i]-'0';
	}
	return ans;
}

//操作函数集：
//创造新节点的函数
Order* Order::createFromFile(Order* x,int nono,string n1,string n2,int p,int n){
	Order* v=new Order(nono,n1,n2,p,n);
	next=v;
	return v;
}
Order* Order::createFromKeyboard(int nono){//,string n1,string n2,int p,int n){
	string s1,s2;int p,n;//读入数据暂存使用
	cout<<"Please input company's name:";cin>>s1;
	cout<<"Please input product's name:";cin>>s2;
	cout<<"Please input product's prize:";cin>>p;
	cout<<"Please input product's number:";cin>>n;

	Order* v=new Order(nono,s1,s2,p,n);
	next=v;
	return v;
}

//打印所有结点
void Order::allDisplay(){
	Order* u=next;
	cout<<"There are results:"<<endl;
	display(0);//cout<<setiosflags(ios::left)<<"|"<<setw(15)<<"Order ID"<<"|"<<setw(15)<<"Company's Name"<<"|"<<setw(15)<<"Product's Name"<<"|"<<setw(15)<<"Prize"<<"|"<<setw(15)<<"Quantity"<<"|"<<setw(15)<<"Sum"<<"|"<<endl;
	while(u!=NULL){
		u->display(1);
		u=u->next;
	}
}

//查询函数
void Order::search(){
	Order *u=next;
	//获取修改的参数
	int op;string n;
	//menu
	cout<<"		===================================================="<<endl;
	cout<<"			Welcome to the order manage system!!"<<endl;
	cout<<"				1.Abuut the ID of the order"<<endl;
	cout<<"				2.About the name of the company"<<endl;
	cout<<"				3.About the name of the product"<<endl;
	cout<<"				4.About the prize of the product"<<endl;
	cout<<"		===================================================="<<endl;
	cout<<"Please input the charastic you want to search:";cin>>op;
	cout<<"Please input the parameter of the charastic:";cin>>n;



	switch(op){
		case 1://-N
			cout<<"There are results:"<<endl;
			display(0);//cout<<setiosflags(ios::left)<<"|"<<setw(15)<<"Order ID"<<"|"<<setw(15)<<"Company's Name"<<"|"<<setw(15)<<"Product's Name"<<"|"<<setw(15)<<"Prize"<<"|"<<setw(15)<<"Quantity"<<"|"<<setw(15)<<"Sum"<<"|"<<endl;
			while(u!=NULL){
				if(u->ReturnNo()==str_int(n)){
					u->display(1);break;
				}
				u=u->next;
			}
			break;
		case 2://-C
			cout<<"There are results:"<<endl;
			display(0);//cout<<setiosflags(ios::left)<<"|"<<setw(15)<<"Order ID"<<"|"<<setw(15)<<"Company's Name"<<"|"<<setw(15)<<"Product's Name"<<"|"<<setw(15)<<"Prize"<<"|"<<setw(15)<<"Quantity"<<"|"<<setw(15)<<"Sum"<<"|"<<endl;
			while(u!=NULL){
				if(u->ReturnCompanyName()==n)u->display(1);
				u=u->next;
			}
			break;
		case 3://-PN
			cout<<"There are results:"<<endl;
			display(0);//cout<<setiosflags(ios::left)<<"|"<<setw(15)<<"Order ID"<<"|"<<setw(15)<<"Company's Name"<<"|"<<setw(15)<<"Product's Name"<<"|"<<setw(15)<<"Prize"<<"|"<<setw(15)<<"Quantity"<<"|"<<setw(15)<<"Sum"<<"|"<<endl;
			while(u!=NULL){
				if(u->ReturnProductName()==n)u->display(1);
				u=u->next;
			}
			break;
		case 4://-PP
			cout<<"There are results:"<<endl;
			display(0);//cout<<setiosflags(ios::left)<<"|"<<setw(15)<<"Order ID"<<"|"<<setw(15)<<"Company's Name"<<"|"<<setw(15)<<"Product's Name"<<"|"<<setw(15)<<"Prize"<<"|"<<setw(15)<<"Quantity"<<"|"<<setw(15)<<"Sum"<<"|"<<endl;
			while(u!=NULL){
				if(u->ReturnProductPrize()==str_int(n))u->display(1);
				u=u->next;
			}
			break;
		default:cout<<"Unknow opeartion!!"<<endl;
	}

	//以下为魔改命令行版
	/*if(op=="-C"){//查询公司名称	
		cout<<"There are results:"<<endl;
		display(0);//cout<<setiosflags(ios::left)<<"|"<<setw(15)<<"Order ID"<<"|"<<setw(15)<<"Company's Name"<<"|"<<setw(15)<<"Product's Name"<<"|"<<setw(15)<<"Prize"<<"|"<<setw(15)<<"Quantity"<<"|"<<setw(15)<<"Sum"<<"|"<<endl;
		while(u!=NULL){
			if(u->ReturnCompanyName()==n)u->display(1);
			u=u->next;
		}
	}
	else if(op=="-PN"){//查询产品名称
		cout<<"There are results:"<<endl;
		display(0);//cout<<setiosflags(ios::left)<<"|"<<setw(15)<<"Order ID"<<"|"<<setw(15)<<"Company's Name"<<"|"<<setw(15)<<"Product's Name"<<"|"<<setw(15)<<"Prize"<<"|"<<setw(15)<<"Quantity"<<"|"<<setw(15)<<"Sum"<<"|"<<endl;
		while(u!=NULL){
			if(u->ReturnProductName()==n)u->display(1);
			u=u->next;
		}
	}
	else if(op=="-PP"){//查询产品单价
		cout<<"There are results:"<<endl;
		display(0);//cout<<setiosflags(ios::left)<<"|"<<setw(15)<<"Order ID"<<"|"<<setw(15)<<"Company's Name"<<"|"<<setw(15)<<"Product's Name"<<"|"<<setw(15)<<"Prize"<<"|"<<setw(15)<<"Quantity"<<"|"<<setw(15)<<"Sum"<<"|"<<endl;
		while(u!=NULL){
			if(u->ReturnProductPrize()==str_int(n))u->display(1);
			u=u->next;
		}
	}
	else if(op=="-N"){//查询某个编号
		cout<<"There are results:"<<endl;
		display(0);//cout<<setiosflags(ios::left)<<"|"<<setw(15)<<"Order ID"<<"|"<<setw(15)<<"Company's Name"<<"|"<<setw(15)<<"Product's Name"<<"|"<<setw(15)<<"Prize"<<"|"<<setw(15)<<"Quantity"<<"|"<<setw(15)<<"Sum"<<"|"<<endl;
		while(u!=NULL){
			if(u->ReturnNo()==str_int(n)){
				u->display(1);break;
			}
			u=u->next;
		}
	}
	else if(op=="-D"){//输出所有
		cout<<"There are results:"<<endl;
		display(0);//cout<<setiosflags(ios::left)<<"|"<<setw(15)<<"Order ID"<<"|"<<setw(15)<<"Company's Name"<<"|"<<setw(15)<<"Product's Name"<<"|"<<setw(15)<<"Prize"<<"|"<<setw(15)<<"Quantity"<<"|"<<setw(15)<<"Sum"<<"|"<<endl;
		while(u!=NULL){
			u->display(1);
			u=u->next;
		}
	}
	else{
		cout<<"Unknow opeartion!!"<<endl;
	}*/
}
//删除函数
void Order::del(string op,string n,Order *now){
	Order* v=now;
	Order* u=v->next;
	if(op=="-C"){//删除公司名称
		while(u!=NULL){
			if(u->ReturnCompanyName()==n){
				v->next=u->next;
				delete u;
				u=u->next;
			}
		}
	}
	else if(op=="-PN"){//删除产品名称
		while(u!=NULL){
			if(u->ReturnProductName()==n){
				v->next=u->next;
				delete u;
				u=u->next;
			}
		}
	}
	else if(op=="-PP"){//删除产品单价
		while(u!=NULL){
			if(u->ReturnProductPrize()==str_int(n)){
				v->next=u->next;
				delete u;
				u=u->next;
			}
		}
	}
	else if(op=="-N"){//删除某个编号
		while(u!=NULL){
			if(u->ReturnNo()==str_int(n)){
				v->next=u->next;
				delete u;
				u=u->next;
			}
		}
	}
	else{
		cout<<"Unknow opeartion!!"<<endl;
	}
}
//修改订单信息
void Order::revise(){
	//获取修改的参数
	int x,op;string n;
	cout<<"Please know the ID of order first!"<<endl;
	cout<<"Please input the ID of the order:";cin>>x;
	//menu
	cout<<"		===================================================="<<endl;
	cout<<"			Welcome to the order manage system!!"<<endl;
	cout<<"				1.Change the name of the company"<<endl;
	cout<<"				2.Change the name of the product"<<endl;
	cout<<"				3.Change the prize of the product"<<endl;
	cout<<"		===================================================="<<endl;
	cout<<"Please input the place you want to change:";cin>>op;
	cout<<"Please input the parameter you want to change to:";cin>>n;


	Order *u=next;
	while(u!=NULL){
		//cout<<"u->ReturnNo()="<<u->ReturnNo()<<endl;
		if(u->ReturnNo()==x){

			switch(op){
				case 1:u->c.ReName(n);break;
				case 2:u->p.ReName(n);break;
				case 3:u->p.RePrize(str_int(n));break;
				default:cout<<"Unknow opeartion!!"<<endl;
			}
			return ;
			//以下为魔改命令行组件
			/*if(op=="-C")u->c.ReName(n);
			else if(op=="-PN")u->p.ReName(n);
			else if(op=="-PP")u->p.RePrize(str_int(n));
			else cout<<"Unknow opeartion!!"<<endl;
			return ;*/
		}
		u=u->next;
	}
	cout<<"Cannot find the order!!"<<endl;
}

//返回值的函数
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