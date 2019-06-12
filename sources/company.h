#ifndef _HEADER_COMPANY_
#define _HEADER_COMPANY_
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