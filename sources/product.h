#ifndef _HEADER_PRODUCT_
#define _HEADER_PRODUCT_
#include"Company.h"
class Product:public Company{
private:
	int prize;
public:
	Product(string n="No Name",int p=0);//构造函数

	void RePrize(int p);//修改产品价格
	void Re(string n,int p);//修改产品名和产品价格
	
	int ReturnPrize();//返回产品价格
};
#endif