#define BITTYPE int
#define MAXBIT 1007
class BigInt {
private:
    BITTYPE bit[MAXBIT];
    bool negative;//负数标志

public:
    BigInt();                //默认构造函数，值为0
    BigInt(const int);        //构造函数
    BigInt(const char *);    //构造函数
    BigInt(const BigInt &);    //复制构造函数
    
    /*重载赋值运算符*/
    BigInt& operator=(const BigInt&);
    BigInt& operator=(const int        );

    /*重载算数运算符*/
    BigInt operator+(const BigInt&    )const;
    BigInt operator+(const int        )const;
    BigInt operator-(const BigInt&    )const;
    BigInt operator-(const int        )const;
    BigInt operator*(const BigInt&    )const;
    BigInt operator*(const int        )const;
    BigInt operator/(const int        )const;
    int    operator%(const int        )const;
    
    /*重载比较运算符*/
    bool operator>(const BigInt&    )const;
    bool operator>(const int        )const;
    bool operator>=(const BigInt&    )const;
    bool operator>=(const int        )const;
    bool operator<(const BigInt&    )const;
    bool operator<(const int        )const;
    bool operator<=(const BigInt&    )const;
    bool operator<=(const int        )const;
    bool operator==(const BigInt&    )const;
    bool operator==(const int        )const;
    bool operator!=(const BigInt&    )const;
    bool operator!=(const int        )const;
    
    void print()        const;//输出数值
    bool isZero()        const;//是否为0
    bool isPositive()    const;//是否为正数
    bool isNegative()    const;//是否为负数
    bool nonNegative()    const;//是否为非负数

private:
    BigInt opposite()const;//取相反数
    BigInt absoluteAdd(const BigInt&)const;//加上绝对值
    BigInt absoluteMinus(const BigInt&)const;//减去绝对值小于自身的数的绝对值
    bool   absoluteEqual(const BigInt&)const;//绝对值等于
    bool   absoluteGreater(const BigInt&)const;//绝对值大于
    bool   absoluteEqualGreater(const BigInt&)const;//绝对值大于等于
};
