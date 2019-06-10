#include"8_2_1.h"
int main(){
	Cat frisky;
	frisky.setAge(5);
	frisky.meow();
	std::cout<<"frisky is a cat who is "<<frisky.getAge()<<" years old.\n";
	frisky.meow();
}