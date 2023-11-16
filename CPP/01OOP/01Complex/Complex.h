//
//  Complex.h
//  Complex

#ifndef __COMPLEX_H__
#define __COMPLEX_H__
#include <iostream>
#include <cmath>

using namespace std;

class Complex;
Complex& __doapl(Complex& ths, const Complex& comp);
Complex& __doami(Complex& ths, const Complex& comp);
Complex& __doaml(Complex& ths, const Complex& comp);
Complex& __doadi(Complex& ths, const Complex& comp);

class Complex {
public:
    Complex(double real = 0, double imag = 0) : re(real), im(imag) {};
    double real() const {return re;}
    double imag() const {return im;}
    Complex& operator += (const Complex&);
    Complex& operator -= (const Complex&);
    Complex& operator *= (const Complex&);
    Complex& operator /= (const Complex&);
private:
    double re, im;
    friend Complex& __doapl(Complex*, const Complex&);
    friend Complex& __doami(Complex*, const Complex&);
    friend Complex& __doaml(Complex*, const Complex&);
    friend Complex& __doadi(Complex*, const Complex&);
};

inline ostream& operator << (ostream& os, const Complex& comp) {
    return os << "[" << comp.real() << ", " << comp.imag() << "]";
}

inline double real (const Complex& x) {
    return x.real();
}

inline double imag (const Complex& x) {
    return x.imag();
}

inline Complex operator + (const Complex& x) {
    return x;
}

inline Complex operator - (const Complex& x) {
    return Complex(-x.real(), -x.imag());
}

inline Complex operator + (const Complex& x, const Complex& y) {
    return Complex(x.real()+y.real(), x.imag()+y.imag());
}

inline Complex operator + (const double x, const Complex& y) {
    return Complex(x+y.real(), y.imag());
}

inline Complex operator + (const Complex& x, const double y) {
    return Complex(x.real()+y, x.imag());
}

inline Complex operator - (const Complex& x, const Complex& y) {
    return Complex(x.real()-y.real(), x.imag()-y.imag());
}

inline Complex operator - (const double x, const Complex& y) {
    return Complex(x-y.real(), y.imag());
}

inline Complex operator - (const Complex& x, const double y) {
    return Complex(x.real()-y, x.imag());
}

inline Complex operator * (const Complex& x, const Complex& y) {
    return Complex(x.real()*y.real(), x.imag()*y.imag());
}

inline Complex operator * (const double x, const Complex& y) {
    return Complex(x*y.real(), y.imag());
}

inline Complex operator * (const Complex& x, const double y) {
    return Complex(x.real()*y, x.imag());
}

inline Complex operator / (const Complex& x, const Complex& y) {
    return Complex(x.real()/y.real(), x.imag()/y.imag());
}

inline Complex operator / (const Complex& x, const double y) {
    return Complex(x.real()/y, x.imag());
}

inline Complex operator / (const double x, const Complex& y) {
    return Complex(x/y.real(), y.imag());
}

inline Complex& __doapl(Complex* ths, const Complex& comp) {
    ths->re += comp.re;
    ths->im += comp.im;
    return *ths;
}

inline Complex& Complex::operator += (const Complex& comp) {
    return __doapl(this, comp);
}

inline Complex& __doami(Complex* ths, const Complex& comp) {
    ths->re -= comp.re;
    ths->im -= comp.im;
    return *ths;
}

inline Complex& Complex::operator -= (const Complex& comp) {
    return __doami(this, comp);
}

inline Complex& __doaml(Complex* ths, const Complex& comp) {
    ths->re *= comp.re;
    ths->im *= comp.im;
    return *ths;
}

inline Complex& Complex::operator *= (const Complex& comp) {
    return __doaml(this, comp);
}

inline Complex& __doadi(Complex* ths, const Complex& comp) {
    if (comp.re != 0 && comp.im != 0) {
        ths->re /= comp.re;
        ths->im /= comp.im;
    }
    return *ths;
}

inline Complex& Complex::operator /= (const Complex& comp) {
    return __doadi(this, comp);
}

inline bool operator == (const Complex& x, const Complex& y) {
    return (x.real() == y.real()) && (x.imag() == y.imag());
}

inline bool operator == (const Complex& x, const double y) {
    return (x.real() == y) && (x.imag() == 0);
}

inline bool operator == (const double x, const Complex& y) {
    return (x == y.real()) && (y.imag() == 0);
}

inline bool operator != (const Complex& x, const Complex& y) {
    return (x.real() != y.real()) || (x.imag() != y.imag());
}

inline bool operator != (const Complex& x, const double y) {
    return (x.real() != y) || (x.imag() != 0);
}

inline bool operator != (const double x, const Complex& y) {
    return (x != y.real()) || (y.imag() != 0);
}

inline Complex conj (const Complex& comp) {
    return Complex(comp.real(), -comp.imag());
}

inline double norm (const Complex& comp) {
    return comp.real()*comp.real()+comp.imag()*comp.imag();
}

inline Complex polar (const double r, const double t) {
    return Complex(r*cos(t), r*sin(t));
}

#endif
/* Complex_h */
