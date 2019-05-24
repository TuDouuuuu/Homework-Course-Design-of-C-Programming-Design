#include<iostream>
#include<cstdio>
#include<string>
#include<fstream>

#include"order.h"

void menu(){
	cout<<"		================================================="<<endl;
	cout<<"			Welcome to the order manage system!!"<<endl;
	cout<<"				1.Add a new order"<<endl;
	cout<<"				2.Change an order's information"<<endl;
	cout<<"				3.display all orders"<<endl;
	cout<<"				4.Find some orders"<<endl;
	cout<<"				5.Delete an order"<<endl;
	cout<<"		================================================="<<endl;
}

int main(){
	cout<<"Loading..."<<endl;
	ifstream inFile;
	inFile.open("..\\\\data_example\\data.txt");
	ofstream outFile;
	outFile.open("..\\\\data_example\\data.txt");
	static int cnt=0;
	Order root(cnt);cnt++;
	string s1,s2;int temp,p,n;
	Order* u=&root;
	while(inFile>>temp>>s1>>s2>>p>>n){
		u=u->create(u,cnt,s1,s2,p,n);
		cnt++;
	}
	/*int op;
	while(cin>>op){

	}
	*/
	root.search("-D","ddsaf",&root);

	cout<<"Welcome to the Order manage system!!"<<endl;


/*
	char *savePath = "..\\\\data_example\\test1.txt";
    if(remove(savePath)==0)
    {
        cout<<"删除成功"<<endl;        
    }
    else
    {
        cout<<"删除失败"<<endl;        
    }
*/

	//ofstream cout("..\\\\data_example\\test1.txt");
}