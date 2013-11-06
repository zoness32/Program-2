//--------------------------------------------------------------
// Program: Program 1
// Course: CpS 111
// Name: Taylor Eernisse 580187
// Date: 9/15/11
// Description: defines each method in fraction.cpp
//--------------------------------------------------------------

#ifndef __FRACTION_H
#define __FRACTION_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>

using namespace std;

enum values { NUM, DEN };

class Fraction
{
    private:
        int num, den;

        void reduce();
        static int gcd(int num1, int num2);

    public:
        Fraction();
        Fraction(int numX);
        Fraction(int numX, int denX);
        Fraction(string str);
        Fraction(double d);
        int getNum();
        int getDen();
        void setNum(int newNum);
        void setDen(int newDen);
        void setNumDen(int newNum, int newDen);
        Fraction& operator = (const Fraction& frac);
        Fraction& operator = (const int& i);
        Fraction& operator = (const double& d);
        Fraction& operator = (const float& f);
        Fraction& operator = (const string& str);
        friend const Fraction operator + (const Fraction& first, const int& second);
        friend const Fraction operator + (const Fraction& first, const Fraction& second);
        friend const Fraction operator - (const Fraction& first, const int& second);
        friend const Fraction operator - (const Fraction& first, const Fraction& second);
        friend const Fraction operator * (const Fraction& first, const int& second);
        friend const Fraction operator * (const Fraction& first, const Fraction& second);
        friend const Fraction operator / (const Fraction& first, const int& second);
        friend const Fraction operator / (const Fraction& first, const Fraction& second);
        Fraction& operator += (const Fraction& obj);
        Fraction& operator += (const int& i);
        Fraction& operator -= (const Fraction& obj);
        Fraction& operator -= (const int& i);
        Fraction& operator *= (const Fraction& obj);
        Fraction& operator *= (const int& i);
        Fraction& operator /= (const Fraction& obj);
        Fraction& operator /= (const int& i);
        Fraction& operator ++ (void);
        Fraction operator ++ (int);
        Fraction& operator -- (void);
        Fraction operator -- (int);
        friend const bool operator < (const Fraction& first, const Fraction& second);
        friend const bool operator < (const Fraction& first, const int& second);
        friend const bool operator > (const Fraction& first, const Fraction& second);
        friend const bool operator > (const Fraction& first, const int& i);
        friend const bool operator == (const Fraction& first, const Fraction& second);
        friend const bool operator == (const Fraction& first, const int& second);
        friend const bool operator >= (const Fraction& first, const Fraction& second);
        friend const bool operator >= (const Fraction& first, const int& second);
        friend const bool operator <= (const Fraction& first, const Fraction& second);
        friend const bool operator <= (const Fraction& first, const int& second);
        friend const bool operator != (const Fraction& first, const Fraction& second);
        friend std::ostream& operator << (std::ostream& os, const Fraction& obj);
        friend std::istream& operator >> (std::istream& is, Fraction& obj);
        int operator [] (values v);
        operator int();
        operator char*();
        friend const bool Greater(const Fraction& a, const Fraction& b);
        bool isEqual(Fraction b);
        static bool Equals(Fraction a, Fraction b);
        string toString();
};

#endif // FRACTION_H
