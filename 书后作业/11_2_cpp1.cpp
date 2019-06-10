#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include"11_2_class.h"
#define MAXBIT 1007
#define BITTYPE int

BigInt::BigInt()
{
    memset(bit,0,sizeof(bit));
    negative = false;
}

BigInt::BigInt(const int n)
{
    memset(bit,0,sizeof(bit));
    int nn = n;
    if (nn>=0) negative = false;
    else {
        negative = true;
        nn = -nn;
    }
    int pos = 0;
    while (nn) {
        bit[pos++] = nn % 10;
        nn /= 10;
    }
}

BigInt::BigInt(const char *s)
{
    int len = strlen(s);
    bool valid = true;//符合数字格式
    if (len >= 2) {
        if (s[0]!='+' && s[0]!='-' && !isdigit(s[0])) valid = false;
        for (int i=1; i<len; ++i) {
            if (!isdigit(s[i])) valid = false;
        }
    }
    else if (len == 1) {
        if (!isdigit(s[0])) valid = false;
    }
    if (len==0 || !valid) {
        memset(bit,0,sizeof(bit));
        negative = false;
        return;
    }
    int beg = 0, end = len-1;
    if (s[0] == '+') {
        negative = false;
        ++beg;
    }
    else if (s[0] == '-') {
        bool zeroFlag = true;
        for (int i=1; i<len; ++i) {
            if (s[i]!='0') {
                zeroFlag = false;
                break;
            }
        }
        if (zeroFlag) negative = false;
        else negative = true;
        ++beg;
    }
    else negative = false;
    memset(bit,0,sizeof(bit));
    for (int i=beg; i<=end; ++i) {
        bit[len-1-i] = s[i] - '0';
    }
}

BigInt::BigInt(const BigInt& n)
{
    memcpy(bit,n.bit,sizeof(bit));
    negative = n.negative;
}

BigInt& BigInt::operator=(const BigInt& n)
{
    memcpy(bit,n.bit,sizeof(bit));
    negative = n.negative;
    return *this;
}

BigInt& BigInt::operator=(const int n)
{
    return *this = BigInt(n);
}

BigInt BigInt::operator+(const BigInt& n)const
{
    printf("adffdsafdasfds\n");
    if ((!negative && !n.negative) || (negative && n.negative)) {
        return this->absoluteAdd(n);
    }
    else {
        if (absoluteEqual(n)) return BigInt();
        else if (absoluteEqualGreater(n)) return this->absoluteMinus(n);
        else return n.absoluteMinus(*this);
    }
}

BigInt BigInt::operator+(const int n)const
{
    return *this + BigInt(n);
}

BigInt BigInt::operator-(const BigInt& n)const
{
    return *this + n.opposite();
}

BigInt BigInt::operator-(const int n)const
{
    return *this - BigInt(n);
}

BigInt BigInt::operator*(const BigInt& n)const
{
    if (isZero() || n.isZero()) return BigInt();
    BigInt bi = BigInt();
    if ((!negative && !n.negative) || (negative && n.negative)) {
        bi.negative = false;
    }
    else bi.negative = true;
    for (int i=0; i<MAXBIT; ++i) for (int j=0; j<MAXBIT-i; ++j) {
        bi.bit[i+j] += bit[i] * n.bit[j];
    }
    for (int i=0; i<MAXBIT-1; ++i) {//进位
        bi.bit[i+1] += bi.bit[i] / 10;
        bi.bit[i] %= 10;
    }
    return bi;
}

BigInt BigInt::operator*(const int n)const
{
    return *this * BigInt(n);
}

BigInt BigInt::operator/(const int n)const
{//除以0直接返回0
    if (isZero() || n==0) return BigInt();
    BigInt bi = BigInt();
    if ((!negative && n>0) || (negative && n<0)) {
        bi.negative = false;
    }
    else bi.negative = true;
    int div = 0;//累计除数
    for (int i=MAXBIT-1; i>=0; --i) {
        div = div * 10 + bit[i];
        bi.bit[i] = div / n;
        div %= n;
    }
    return bi;
}

int BigInt::operator%(const int n)const
{
    int mod = 0;//累计余数
    for (int i=MAXBIT-1; i>=0; --i) {
        //mod = ((mod*(MAXBIT+1/*??*/)) + bit[i]) % n;
        mod = ((mod*10) + bit[i]) % n;
    }
    return mod;
}

bool BigInt::operator>(const BigInt& n)const
{
    if (!negative && n.negative) return true;
    else if (negative && !n.negative) return false;
    else if (!negative && !n.negative) return absoluteGreater(n);
    else return n.absoluteGreater(*this);
}

bool BigInt::operator>(const int n)const
{
    return *this > BigInt(n);
}

bool BigInt::operator>=(const BigInt& n)const
{
    if (!negative && n.negative) return true;
    else if (negative && !n.negative) return false;
    else if (!negative && !n.negative) return absoluteEqualGreater(n);
    else return n.absoluteEqualGreater(*this);
}

bool BigInt::operator>=(const int n)const
{
    return *this >= BigInt(n);
}

bool BigInt::operator<(const BigInt& n)const
{
    return n > *this;
}

bool BigInt::operator<(const int n)const
{
    return *this < BigInt(n);
}

bool BigInt::operator<=(const BigInt& n)const
{
    return n >= *this;
}

bool BigInt::operator<=(const int n)const
{
    return *this <= BigInt(n);
}

bool BigInt::operator==(const BigInt& n)const
{
    if (negative != n.negative) return false;
    for (int i=0; i<MAXBIT; ++i) {
        if (bit[i] != n.bit[i]) return false;
    }
    return true;
}

bool BigInt::operator==(const int n)const
{
    return *this == BigInt(n);
}

bool BigInt::operator!=(const BigInt& n)const
{
    if (negative != n.negative) return true;
    for (int i=0; i<MAXBIT; ++i) {
        if (bit[i] != n.bit[i]) return true;
    }
    return false;
}

bool BigInt::operator!=(const int n)const
{
    return *this != BigInt(n);
}

void BigInt::print()const
{
    if (negative) printf("-");
    int pos = MAXBIT - 1;
    for (; pos>0; --pos) {
        if (bit[pos]) break;
    }
    for (int i=pos; i>=0; --i) printf("%d",bit[i]);
}

bool BigInt::isZero()const
{
    bool zeroFlag = true;
    for (int i=0; i<MAXBIT; ++i) {
        if (bit[i] != 0) {
            zeroFlag = false;
            break;
        }
    }
    return zeroFlag;
}

bool BigInt::isPositive()const
{
    return !negative && !isZero();
}

bool BigInt::isNegative()const
{
    return negative;
}

bool BigInt::nonNegative()const
{
    return !negative;
}

BigInt BigInt::opposite()const
{
    BigInt n(*this);
    if (!n.isZero()) n.negative = !n.negative;
    return n;
}

BigInt BigInt::absoluteAdd(const BigInt& n)const
{
    BigInt bi(*this);
    int next = 0;//进位
    for (int i=0; i<MAXBIT; ++i) {
        bi.bit[i] = (bit[i] + n.bit[i] + next) % 10;
        next   = (bit[i] + n.bit[i] + next) / 10;
    }
    return bi;
}

BigInt BigInt::absoluteMinus(const BigInt& n)const
{
    BigInt bi(*this);
    for (int i=MAXBIT-1; i>=0; --i) {
        if (bi.bit[i]>=n.bit[i]) bi.bit[i] -= n.bit[i];
        else {//借位
            int borrow = i + 1;//借位位
            while (bi.bit[borrow]==0) ++borrow;
            --bi.bit[borrow];
            for (int j=i+1; j<borrow; ++j) bi.bit[j] = 9;
            bi.bit[i] = bi.bit[i] + 10 - n.bit[i];
        }
    }
    return bi;
}

bool BigInt::absoluteEqual(const BigInt& n)const
{
    for (int i=0; i<MAXBIT; ++i) {
        if (bit[i] != n.bit[i]) return false;
    }
    return true;
}

bool BigInt::absoluteGreater(const BigInt& n)const
{
    for (int i=MAXBIT-1; i>=0; --i) {
        if (bit[i]>n.bit[i]) return true;
        else if (bit[i]<n.bit[i]) return false;
    }
    return false;
}

bool BigInt::absoluteEqualGreater(const BigInt& n)const
{
    for (int i=MAXBIT-1; i>=0; --i) {
        if (bit[i]>n.bit[i]) return true;
        else if (bit[i]<n.bit[i]) return false;
    }
    return true;
}

