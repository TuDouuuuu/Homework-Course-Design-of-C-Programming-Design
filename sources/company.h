#include<string>
using namespace std;
class Company{
protected:
	string name;
public:
	Company(string n="No Name");
	void ReName(string n);
	string ReturnName();
};