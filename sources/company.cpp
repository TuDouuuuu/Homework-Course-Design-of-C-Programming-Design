#ifndef _IOSTEAM_
#define _IOSTEAM_
#include"Company.h"
#include<string>
#include<iostream>
//构造函数
Company::Company(string n){
	name=n;
}
//操作函数
void Company::ReName(string n){
	name=n;
}
//返回函数读取数值
string Company::ReturnName(){
	return name;
}
#endif