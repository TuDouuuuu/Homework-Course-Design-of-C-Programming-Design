#include<iostream>
#include<fstream>
using namespace std;
#include"savings_bro.h"
#include"checking_bro.h"
#include"accountlist.h"

int main(){
	ifstream cin("account.txt");
	string s;double num;
	AccountList v;
	while(cin>>s>>num){
		if(s[0]=='x'&&num==0)break;
		else if(s[0]=='s'){
			//s=atoi(s.substr(7,s.length()-1).c_str());
			v.add(*(new Savings(s,num)));//new temp(s,num);
		}
		else{
			//s=atoi(s.substr(8,s.length()-1).c_str());
			v.add(*(new Checking(s,num)));
		}
		v.display();
	}
	v.display();
}