#include"class.cpp"
using namespace std;

int main(){
	std::vector<Order> v;
	Order o1;
	v.push_back(o1);
	v[0].test();
}