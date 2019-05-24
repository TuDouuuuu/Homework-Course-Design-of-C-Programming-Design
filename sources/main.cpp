#include<iostream>
#include<cstdio>
#include<string>
#include<fstream>

#include"order.h"

void menu(){
	cout<<endl;
	cout<<"		===================================================="<<endl;
	cout<<"			Welcome to the order manage system!!"<<endl;
	cout<<"				1.Add a new order"<<endl;
	cout<<"				2.Change an order's information"<<endl;
	cout<<"				3.display all orders"<<endl;
	cout<<"				4.Find some orders"<<endl;
	cout<<"				5.Delete an order"<<endl;
	cout<<"				6.save and exit"<<endl;
	cout<<"		===================================================="<<endl;
	cout<<"What opearation do you want to do:";
}

int main(){
	cout<<"Loading..."<<endl;
	ifstream inFile;
	inFile.open("..\\\\data_example\\data.txt");
	
	//构建链表的头（空的
	static int cnt=0;
	Order root(cnt);cnt++;

	string s1,s2;int temp,p,n;//读入数据暂存使用

	//读入已有数据
	Order* u=&root;
	while(inFile>>temp>>s1>>s2>>p>>n){
		u=u->createFromFile(u,cnt,s1,s2,p,n);
		cnt++;
	}

	//用于测试
	/*root.search("-C","cyz",&root);
	menu();*/

	//开始进行菜单操作
	int op;
	menu();
	while(cin>>op){
		switch(op){
			case 1:u=u->createFromKeyboard(cnt);cnt++;break;
			case 2:root.revise();break;
			case 3:root.allDisplay();break;
			case 4:root.search();break;
			//case 5:
		}
		//root.search("-D","adsf",&root);
		menu();
	}



	//输出文件用：
	//ofstream outFile;
	//outFile.open("..\\\\data_example\\data.txt");


	//ofstream cout("..\\\\data_example\\test1.txt");
}