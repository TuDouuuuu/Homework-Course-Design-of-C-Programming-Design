#ifndef HEADER_COMPANY
#define HEADER_COMPANY
#include <string>
using std::string;
class Company{
protected:
	string name;
public:
	Company(string n="No Name");//构造函数
	void ReName(string n);//修改公司名字
	string ReturnName();//返回公司名字
};
#endif