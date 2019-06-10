#include<iostream>
class Animal{
private:
	int itsWeight;
	int itsAge;
public:
	void setValue(Animal& ta,int tw,int tn){
		ta.itsWeight=tw;
		ta.itsAge=tn;
	}
};
int main(){
	Animal peppy;
	peppy.setValue(peppy,7,9);
}