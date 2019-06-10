#include<iostream>
class Stack{
private:
	int nums[15];int pos;
public:
	Stack(){pos=0;}
	void push(int x){
		nums[pos++]=x;
		//std::cout<<"pos="<<pos<<'\n';
		check_full();
	}
	int read(){
		if(!check_empty()){
			std::cout<<"The stack is empty!!"<<'\n';
			return 0;
		}
		return nums[pos-1];
	}
	void pop(){pos--;if(pos<0)pos=0;}
	bool check_empty(){
		if(pos==0)return 0;
		return 1;
	}
	bool check_full(){
		if(pos==12){
			std::cout<<"The stack is booming!!"<<'\n';
			exit(1);
		}
	}
};
int main(){
	Stack s;
	s.push(10);
	s.push(12);
	s.push(14);
	std::cout<<s.read()<<'\n';
	s.pop();
	std::cout<<s.read()<<'\n';
}