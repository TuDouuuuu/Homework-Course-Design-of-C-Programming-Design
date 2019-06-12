#ifndef _HEADER_UNEXPECTED_
#define _HEADER_UNEXPECTED_
#include<string>
using std::string;
class unexpect{
public:
	virtual string getWhat()=0;
};
class unexpectedNull:public unexpect{//用于处理非法数字。
public:
	string getWhat(){return "Illegal Number.";}
};
class unexpectedZero:public unexpect{//用于处理除数为0的情况。
public:
	string getWhat(){return "Divide By Zero.";}
};
class unexpectedLarge:public unexpect{//用于处理太大的数据。
public:
	string getWhat(){return "Too Large Number.";}
};
class unexpectedOp:public unexpect{//用于处理奇怪的操作符。
public:
	string getWhat(){return "Illegal Operator.";}
};
#endif