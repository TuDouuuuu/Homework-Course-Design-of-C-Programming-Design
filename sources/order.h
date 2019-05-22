#include"Product.h"
#include<string>
using namespace std;
class Order{
private:
	int no;
	Company c;Product p;
	int num;int sum;
	Order *next=NULL;
public:
	Order(string n1="No Name",string n2="No Name",int p=0,int n=0,int s=0);

	void display(bool x);
	void connectNode(Order *a,Order *b);
	int str_int(string x);

	Order* create(Order* x);
	void search(string op,string n,Order *now);
	void del(string op,string n,Order *now);

	string ReturnCompanyName();
	string ReturnProductName();
	int ReturnProductPrize();
	int ReturnNo();
};

