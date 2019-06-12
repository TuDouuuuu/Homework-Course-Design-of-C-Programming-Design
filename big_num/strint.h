#ifndef _HEADER_STRINT_
#define _HEADER_STRINT_
#include<string>
#include<cstring>
using namespace std;
const int MAXN=1007;
class strInt{
private:
	 int bit[MAXN];
	 bool negative;

	 strInt op()const;
	 strInt absAdd(const strInt&)const;
	 strInt absMinus(const strInt&)const;
	 bool absEqual(const strInt&)const;
	 bool absGreater(const strInt&)const;
	 bool absEqualGreater(const strInt&)const;

public:
	strInt();
	strInt(const int);
	strInt(const char *);
	strInt(const strInt &);

	strInt& operator=(const strInt&);
	strInt& operator=(const int);

	/*strInt operator+(const strInt&)const;
	strInt operator+(const int)const;
	strInt operator-(const strInt&)const;
	strInt operator-(const int)const;
	strInt operator*(const strInt&)const;
	strInt operator*(const int)const;
	strInt operator/(const int)const;
	int operator%(const int)const;*/
	strInt add(const strInt&);//+
	strInt sub(const strInt&);//-
	strInt mul(const strInt&);//*
	strInt div(const strInt&);///

	bool operator>(const strInt&)const;
	bool operator>(const int)const;
	bool operator>=(const strInt&)const;
	bool operator>=(const int)const;
	bool operator<(const strInt&)const;
	bool operator<(const int)const;
	bool operator<=(const strInt&)const;
	bool operator<=(const int)const;
	bool operator==(const strInt&)const;
	bool operator==(const int)const;
	bool operator!=(const strInt&    )const;
    bool operator!=(const int        )const;

    void print()        const;//输出数值
    bool isZero()        const;//是否为0
    bool isPositive()    const;//是否为正数
    bool isNegative()    const;//是否为负数
    bool nonNegative()    const;//是否为非负数
};
#endif