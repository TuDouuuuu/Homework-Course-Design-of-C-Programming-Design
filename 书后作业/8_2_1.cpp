class Cat{
	int itsAge;
public:
	int getAge();
	void setAge(int age);
	void meow();	//喵喵叫
};
int Cat::getAge(){return itsAge;}
void Cat::setAge(int age){itsAge=age;}
void Cat::meow(){std::cout<<"Meow.\n";}
