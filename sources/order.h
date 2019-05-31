#include"Product.h"
#include<string>
using namespace std;
class Order{
private:
	int no;
	Company c;Product p;
	int num;int sum;
	Order *next=NULL;

	void display(bool x);
	void connectNode(Order *a,Order *b);
	int str_int(string x);
public:
	Order(int nono,string n1="No Name",string n2="No Name",int p=0,int n=0);

	Order* createFromFile(Order* x,int nono,string n1="No Name",string n2="No Name",int p=0,int n=0);
	Order* createFromKeyboard(int nono);
	void allDisplay();
	void search();
	void del();
	void revise();

	string ReturnCompanyName();
	string ReturnProductName();
	int ReturnProductPrize();
	int ReturnNo();
	int ReturnNum();
	Order* ReturnNext();
};

