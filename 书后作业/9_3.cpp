#include<iostream>
using namespace std;
class CAT{
	int* itsAge;
public:
	CAT():itsAge(new int(5)){}
	CAT(CAT &a){
		itsAge=new int(5);
		for(int i=0;i<5;i++){
			itsAge[i]=a.itsAge[i];
		}
	}
	~CAT(){delete itsAge;}
	int GetAge()const{return *itsAge;}
	void SetAge(int age){*itsAge=age;}	
};
int main(){
	CAT frisky;
	cout<<"frisky's age: "<<frisky.GetAge()<<endl;
	cout<<"SetAge frisky to 6...\n";
	frisky.SetAge(6);
	cout<<"Creating boots from frisky\n";
	CAT boots(frisky);
	cout<<"frisky's age: "<<frisky.GetAge()<<endl;
	cout<<"boots's age: "<<boots.GetAge()<<endl;
	cout<<"setting frisky to 7...\n";
	frisky.SetAge(7);
	cout<<"frisky's age: "<<frisky.GetAge()<<endl;

	cout<<"boots's age: "<<boots.GetAge()<<endl;
}