#ifndef _IOSTREAM_
#define _IOSTREAM_
#include<string>
#include<vector>
//using std::string;
using namespace std;

class Order{
private:
	static int no;int n;
	string company_name,product_name;
	double price;int num;double sum;
public:
	void read();
	void add(string c_n,string p_n,int p,int n);
	void change(int no);
	void del(int no);
	void display(int no);
	void search(int no);
	void c_n_search(string c_n);
	void p_n_search(string p_n);
	void compan_cul(string c_n);
	void save();
	Order(){n=no;no++;}
	void test(){
		printf("%d\n",n);
	}
};
int Order::no=1;

#endif
