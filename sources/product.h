#include<string>
#include<iostream>
using namespace std;
class Product{
private:
	string name;
	int prize;
public:
	Product(string n="No Name",int p=0);
	void ReName(string n);//修改产品名
	void RePrize(int p);//修改产品价格
	void Re(string n,int p);//修改产品名和产品价格
	string ReturnName();//返回产品名
	int ReturnPrize();//返回产品价格
};