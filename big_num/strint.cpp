#include"strInt.h"
strInt::strInt(){
    memset(bit,0,sizeof(bit));
    negative = false;
}

strInt::strInt(const int n){
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

strInt::strInt(const char *s){
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

strInt::strInt(const strInt& n){
    memcpy(bit,n.bit,sizeof(bit));
    negative = n.negative;
}

strInt& strInt::operator=(const strInt& n){
    memcpy(bit,n.bit,sizeof(bit));
    negative = n.negative;
    return *this;
}

strInt& strInt::operator=(const int n){
    return *this = strInt(n);
}

strInt strInt::add(const strInt& n){
    if ((!negative && !n.negative) || (negative && n.negative)) {
        return this->absAdd(n);
    }
    else {
        if (absEqual(n)) return strInt();
        else if (absEqualGreater(n)) return this->absMinus(n);
        else return n.absMinus(*this);
    }
}

strInt strInt::sub(const strInt& n){
    return this->add(n.op());
}

strInt strInt::mul(const strInt& n){
    if (isZero() || n.isZero()) return strInt();
    strInt bi = strInt();
    if ((!negative && !n.negative) || (negative && n.negative)) {
        bi.negative = false;
    }
    else bi.negative = true;
    for (int i=0; i<MAXN; ++i) for (int j=0; j<MAXN-i; ++j) {
        bi.bit[i+j] += bit[i] * n.bit[j];
    }
    for (int i=0; i<MAXN-1; ++i) {//进位
        bi.bit[i+1] += bi.bit[i] / 10;
        bi.bit[i] %= 10;
    }
    return bi;
}


//strInt strInt::operator/(const int n)const{//除以0直接返回0
strInt strInt::div(const strInt& n){
    /*if (isZero() || n==0) return strInt();
    strInt bi = strInt();
    if ((!negative && n>0) || (negative && n<0)) {
        bi.negative = false;
    }
    else bi.negative = true;
    int div = 0;//累计除数
    for (int i=MAXN-1; i>=0; --i) {
        div = div * 10 + bit[i];
        bi.bit[i] = div / n;
        div %= n;
    }
    return bi;*/
    if(n.bit=="0") throw MyDivideZero();
    if(this<n) return string("0");
    StrInt ss;
    ss.sign = (a.sign==b.sign ? "" : "-");

    string s, y(a.num.substr(0, b.num.length()-1));
    for(int i=b.num.length()-1; i<a.num.length(); ++i){
        int cnt=0;
        for(y=(y=="0"? string(1,a.num[i]): y+a.num[i]); !absLess( y, b.num ); cnt++)
            y = subing( y, b.num );
        s += char(cnt+'0');
        }
    int pos = s.find_first_not_of('0');
    ss.num = (pos!=string::npos ? s.substr(pos) : s);
    return ss;
}
/*
int strInt::operator%(const int n)const{
    int mod = 0;//累计余数
    for (int i=MAXN-1; i>=0; --i) {
        //mod = ((mod*(MAXN+1)) + bit[i]) % n;
        mod = ((mod*10) + bit[i]) % n;
    }
    return mod;
}*/

bool strInt::operator>(const strInt& n)const{
    if (!negative && n.negative) return true;
    else if (negative && !n.negative) return false;
    else if (!negative && !n.negative) return absGreater(n);
    else return n.absGreater(*this);
}

bool strInt::operator>(const int n)const{
    return *this > strInt(n);
}

bool strInt::operator>=(const strInt& n)const{
    if (!negative && n.negative) return true;
    else if (negative && !n.negative) return false;
    else if (!negative && !n.negative) return absEqualGreater(n);
    else return n.absEqualGreater(*this);
}

bool strInt::operator>=(const int n)const{
    return *this >= strInt(n);
}

bool strInt::operator<(const strInt& n)const{
    return n > *this;
}

bool strInt::operator<(const int n)const{
    return *this < strInt(n);
}

bool strInt::operator<=(const strInt& n)const{
    return n >= *this;
}

bool strInt::operator<=(const int n)const{
    return *this <= strInt(n);
}

bool strInt::operator==(const strInt& n)const{
    if (negative != n.negative) return false;
    for (int i=0; i<MAXN; ++i) {
        if (bit[i] != n.bit[i]) return false;
    }
    return true;
}

bool strInt::operator==(const int n)const{
    return *this == strInt(n);
}

bool strInt::operator!=(const strInt& n)const{
    if (negative != n.negative) return true;
    for (int i=0; i<MAXN; ++i) {
        if (bit[i] != n.bit[i]) return true;
    }
    return false;
}

bool strInt::operator!=(const int n)const{
    return *this != strInt(n);
}

void strInt::print()const{
    if (negative) printf("-");
    int pos = MAXN - 1;
    for (; pos>0; --pos) {
        if (bit[pos]) break;
    }
    for (int i=pos; i>=0; --i) printf("%d",bit[i]);
}

bool strInt::isZero()const{
    bool zeroFlag = true;
    for (int i=0; i<MAXN; ++i) {
        if (bit[i] != 0) {
            zeroFlag = false;
            break;
        }
    }
    return zeroFlag;
}

bool strInt::isPositive()const{
    return !negative && !isZero();
}

bool strInt::isNegative()const{
    return negative;
}

bool strInt::nonNegative()const{
    return !negative;
}

strInt strInt::op()const{
    strInt n(*this);
    if (!n.isZero()) n.negative = !n.negative;
    return n;
}

strInt strInt::absAdd(const strInt& n)const{
    strInt bi(*this);
    int next = 0;//进位
    for (int i=0; i<MAXN; ++i) {
        bi.bit[i] = (bit[i] + n.bit[i] + next) % 10;
        next   = (bit[i] + n.bit[i] + next) / 10;
    }
    return bi;
}

strInt strInt::absMinus(const strInt& n)const{
    strInt bi(*this);
    for (int i=MAXN-1; i>=0; --i) {
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

bool strInt::absEqual(const strInt& n)const{
    for (int i=0; i<MAXN; ++i) {
        if (bit[i] != n.bit[i]) return false;
    }
    return true;
}

bool strInt::absGreater(const strInt& n)const{
    for (int i=MAXN-1; i>=0; --i) {
        if (bit[i]>n.bit[i]) return true;
        else if (bit[i]<n.bit[i]) return false;
    }
    return false;
}

bool strInt::absEqualGreater(const strInt& n)const{
    for (int i=MAXN-1; i>=0; --i) {
        if (bit[i]>n.bit[i]) return true;
        else if (bit[i]<n.bit[i]) return false;
    }
    return true;
}
