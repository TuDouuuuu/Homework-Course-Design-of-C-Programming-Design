#include"11_2_class.h"
#include<iostream>
#include<string>
using namespace std;
int main(){
	char *s1,*s2;
	while(cin>>s1>>s2){
		BigInt ex1("123");BigInt ex2("123");
		BigInt ex=ex1.operator+(ex2);
		ex.print();
	}
}