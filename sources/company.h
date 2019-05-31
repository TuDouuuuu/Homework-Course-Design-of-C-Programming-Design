#include<string>
using namespace std;
class Company{
protected:
	string name;
public:
	Company(string n="No Name");//构造函数
	void ReName(string n);//修改公司名字
	string ReturnName();//返回公司名字
};