// razlomak.h
#ifndef RAZLOMAK_H_INCLUDED
#define RAZLOMAK_H_INCLUDED

#include <string>
#include <iostream>

class Razlomak
{
private:
    int i; // imenilac -> b / i
    int b; // brojilac -> b / i
public:
    Razlomak(int x = 0, int y = 1) : b(x), i(y) {}

    std::string ime();

    int brojilac() {return b;}
    int imenilac() {return i;}

    friend Razlomak operator* (const Razlomak &a, const Razlomak &b);
    friend Razlomak operator*=(Razlomak &a, const Razlomak &b);

    friend Razlomak operator+ (const Razlomak &a, const Razlomak &b);
    friend Razlomak operator+=(Razlomak &a, const Razlomak &b);

    friend Razlomak operator- (const Razlomak &a, const Razlomak &b);
    friend Razlomak operator-=(Razlomak &a, const Razlomak &b);

    friend Razlomak operator/ (const Razlomak &a, const Razlomak &b);
    friend Razlomak operator/=(Razlomak &a, const Razlomak &b);

    friend std::istream& operator>>(std::istream& in, Razlomak &b);
    friend std::ostream& operator<<(std::ostream& out, const Razlomak &b);

    friend bool operator >  (const Razlomak &a, const Razlomak &b);
    friend bool operator <  (const Razlomak &a, const Razlomak &b);
    friend bool operator == (const Razlomak &a, const Razlomak &b);
    friend bool operator != (const Razlomak &a, const Razlomak &b);
    friend bool operator >= (const Razlomak &a, const Razlomak &b);
    friend bool operator <= (const Razlomak &a, const Razlomak &b);

    friend Razlomak operator+(const Razlomak &a) {return a;}
    friend Razlomak operator-(Razlomak &a) {a.b = -a.b; return a;}

    operator double() {return (double(b) / double(i)) ;}
};

#endif // RAZLOMAK_H_INCLUDED

----------------------------------------------------------------------------------------------
//razlomak.cpp

#include "razlomak.h"

std::string Razlomak::ime()
{
    return "Razlomak";
}

Razlomak operator* (const Razlomak &a, const Razlomak &b)
{
    Razlomak rez;
    rez.b = a.b * b.b;
    rez.i = a.i * b.i;
    return rez;
}

Razlomak operator*=(Razlomak &a, const Razlomak &b)
{
    return a = a * b;
}

Razlomak operator+ (const Razlomak &a, const Razlomak &b)
{
    Razlomak rez;
    rez.b = a.b * b.i + b.b * a.i;
    rez.i = a.i * b.i;
    return rez;
}

Razlomak operator+=(Razlomak &a, const Razlomak &b)
{
    return a = a + b;
}

Razlomak operator- (const Razlomak &a, const Razlomak &b)
{
    Razlomak rez;
    rez.b = a.b * b.i - b.b * a.i;
    rez.i = a.i * b.i;
    return rez;
}

Razlomak operator-=(Razlomak &a, const Razlomak &b)
{
    return a = a - b;
}

Razlomak operator/ (const Razlomak &a, const Razlomak &b)
{
    Razlomak rez;
    rez.b = a.b * b.i;
    rez.i = a.i * b.b;
    return rez;
}

Razlomak operator/=(Razlomak &a, const Razlomak &b)
{
    return a = a / b;
}

bool operator >  (const Razlomak &a, const Razlomak &b){
    return ( (double(a.b) / double(a.i) ) > (double(b.b) / double(b.i) ) );
}
bool operator <  (const Razlomak &a, const Razlomak &b){
    return ( (double(a.b) / double(a.i) ) < (double(b.b) / double(b.i) ) );
}
bool operator == (const Razlomak &a, const Razlomak &b){
    return ( (double(a.b) / double(a.i) ) == (double(b.b) / double(b.i) ) );
}
bool operator != (const Razlomak &a, const Razlomak &b){
    return !(a == b);
}
bool operator >= (const Razlomak &a, const Razlomak &b){
    return !(a < b);
}
bool operator <= (const Razlomak &a, const Razlomak &b){
    return !(a > b);
}

std::istream& operator >> (std::istream& in, Razlomak &x){
    char c; // znak podeljeno ... npr. : 3 / 5
    in >> x.b >> c >> x.i;
    return in;
}

std::ostream& operator<<(std::ostream& out, const Razlomak &b){
    out << b.b << " / " << b.i ;
    return out;
}

------------------------------------------------------------------------------------------
// main.cpp
#include "razlomak.h"

using namespace std;

int main()
{
    Razlomak a(3,5);
    Razlomak b(5,10);

    if(a > b)
        cout << " a > b" << endl;
    else
        cout << " b >= a" << endl;

    a *= b;

    std::cout << a << std::endl;

    double c = a;

    cout << "a = " << a << "\tc = " << c <<endl;

    return 0;
}

