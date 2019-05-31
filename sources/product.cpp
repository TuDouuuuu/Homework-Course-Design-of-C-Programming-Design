#include"Product.h"
#include<string>
#include<iostream>

//构造函数
Product::Product(string n,int p){
	name=n;prize=p;
}

//操作系列
void Product::RePrize(int p){//修改产品价格
	prize=p;
}
void Product::Re(string n,int p){//修改价格和名字
	name=n;prize=p;
}

//返回数据系列
int Product::ReturnPrize(){//返回
	return prize;
}
