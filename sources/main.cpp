#include<fstream>
#include"company.h"
#include"product.h"
#include"order.h"
#include"ex.h"

void menu(){//输出菜单
	cout<<endl;
	cout<<"		===================================================="<<endl;
	cout<<"			Welcome to the order manage system!!"<<endl;
	cout<<"				1.Add a new order"<<endl;
	cout<<"				2.Change an order's information"<<endl;
	cout<<"				3.display all orders"<<endl;
	cout<<"				4.Find some orders"<<endl;
	cout<<"				5.Delete an order"<<endl;	
	cout<<"				6.Count a company's order"<<endl;
	cout<<"				7.Save and exit"<<endl;

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

	string s1,s2;int temp,p,n,s;//读入数据暂存使用

	//读入已有数据
	Order* u=&root;
	while(inFile>>temp>>s1>>s2>>p>>n){
		u=u->createFromFile(u,temp,s1,s2,p,n);
		cnt=temp+1;
	}
	inFile.close();

	//开始进行菜单操作
	string op;
	
	int flag=0;
	while(1){
		try{menu();
			cin>>op;
			if(op.length()>1)throw exOp();
			if(op[0]<'1'||op[0]>'7')throw exOp();
			int opp;opp=op[0]-'0';
			switch(opp){
				case 1:u=u->createFromKeyboard(cnt);cnt++;break;
				case 2:root.revise();break;
				case 3:root.allDisplay();break;
				case 4:root.search();break;
				case 5:root.del();break;
				case 6:root.companyCnt();break;
				case 7:flag=1;break;
				default:throw exOp();
			}
			if(flag)break;
			menu();
		}
		catch(ex& e){
			cout<<e.getWhat()<<endl;//menu();
		}
	}

	//输出文件用：
	ofstream outFile;
	outFile.open("..\\\\data_example\\data.txt");
	u=&root;u=u->ReturnNext();
	while(u!=NULL){
		outFile<<u->ReturnNo()<<'\t'<<u->ReturnCompanyName()<<'\t'<<u->ReturnProductName()<<'\t'<<u->ReturnProductPrize()<<'\t'<<u->ReturnNum()<<endl;
		u=u->ReturnNext();
	}
	
	outFile.close();
	//ofstream cout("..\\\\data_example\\test1.txt");
}