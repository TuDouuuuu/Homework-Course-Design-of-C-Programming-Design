#include"11_4_class.h"
#include"11_2_class.h"
#include<algorithm>
#include<vector>
using namespace std;
bool cmpp(Complex* x,Complex* y){
	return !cmp(*x,*y);
}

int main(){
	string s1,s2,s3,s4;
	vector<Complex*>v;
	while(cin>>s1>>s2){
		v.push_back(new Complex(s1,s2));
	}
	sort(v.begin(),v.end(),cmpp);
	for(int i=0;i<v.size();i++){
		cout<<*v[i]<<endl;
	}
}