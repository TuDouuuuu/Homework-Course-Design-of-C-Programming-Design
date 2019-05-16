#include<string>
#include"Company.h"
using namespace std;
class Product:public Company{
private:
	int prize;
public:
	Product(string n="No Name",int p=0);
	void RePrize(int p);//修改产品价格
	void Re(string n,int p);//修改产品名和产品价格
	int ReturnPrize();//返回产品价格
};