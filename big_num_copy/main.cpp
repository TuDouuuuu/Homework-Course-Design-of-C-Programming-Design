#include"class.h"
#include<iostream>
using namespace std;
int main(){
	char s1[10000],s2[10000];
	while(cin>>s1>>s2){
		BigInt a(s1);BigInt b(s2);
		BigInt c=a+b;
		c.print();
	}
}