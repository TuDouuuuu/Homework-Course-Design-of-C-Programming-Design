#ifndef _HEADER_EX_
#define _HEADER_EX_
class ex{
public:
	virtual string getWhat()=0;
};
class exOp:public ex{
public:
	string getWhat(){return "Unkown Operation.";}
};
class exNull:public ex{
public:
	string getWhat(){return "Not Find";}
};
#endif