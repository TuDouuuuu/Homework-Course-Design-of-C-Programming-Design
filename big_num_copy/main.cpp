#include"class.h"
#include<iostream>
using namespace std;
int main(){
	BigInt a("123");BigInt b("321");
	BigInt c=a+b;
	c.print();
}