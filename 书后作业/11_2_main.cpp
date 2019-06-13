#include"11_2_class.h"
#include<iostream>
#include<string>
using namespace std;
int main(){
	string s1,s2;
	while(cin>>s1>>s2){
		strInt ex1(s1);strInt ex2(s2);
		cout<<add(ex1,ex2).display()<<endl;
	}
}