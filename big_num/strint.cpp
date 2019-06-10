#include<string>
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

	strInt operator+(const strInt&)const;
	strInt operator+(const int)const;
	strInt operator-(const strInt&)const;
	strInt operator-(const int)const;
	strInt operator*(const strInt&)const;
	strInt operator*(const int)const;
	strInt operator/(const int)const;
	int operator%(const int)const;

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
}