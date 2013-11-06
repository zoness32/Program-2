//--------------------------------------------------------------
// Program: Program 1
// Course: CpS 111
// Name: Taylor Eernisse 580187
// Date: 9/15/11
// Description: contains the methods for the Fraction class
//--------------------------------------------------------------

#include "fraction.h"
#include <cstring>
#include "math.h"

//--------------------------------------------------------------
// void reduce()
// Purpose:
// Limitations: none
// Assumptions: none
// Returns: nothing
//--------------------------------------------------------------

void Fraction::reduce()
{
    int num = getNum();
    int den = getDen();
    int greater;
    int lesser;
    int remainder;
    int gcd;

    if (num < 0 && den < 0) // if both terms are negative, the fraction is positive
    {
        num = abs(num);
        den = abs(den);
    }

    if (num == 0)
    {
        setDen(1); // ensure that Fraction is reduced to 0/1
    }
    else if (abs(num) > abs(den))
    {
        greater = num;
        lesser = den;

        // the following +-20 lines implement Euclid's algorithm for finding the GCD of two numbers
        remainder = greater % lesser;

        if (remainder != 0)
        {
            do
            {
                remainder = greater % lesser;
                greater = lesser;
                lesser = remainder;
            } while (greater % lesser != 0);
        }
        else if (remainder == 0) // if the remainder is 0, either the numerator can be divided into the denominator or vice versa
        {
            if (abs(den) > abs(num))
            {
                den = den / num;
                num = 1;
            }
            else if (abs(den) < abs(num))
            {
                num = num / den;
                den = 1;
            }

            remainder = 1;
        }

        gcd = abs(remainder); // take the absolute value of the remainder to prevent negative errors since remainders are never < 0

        setNum(num / gcd);
        setDen(den / gcd);
    }
    else if (abs(den) > abs(num))
    {
        greater = den;
        lesser = num;

        remainder = greater % lesser;

        if (remainder != 0 && num % remainder != 0)
        {
            do
            {
                remainder = greater % lesser;
                greater = lesser;
                lesser = remainder;
            } while (greater % lesser != 0);
        }

        else if (remainder == 0) // fraction is already in reduced form
        {
            if (abs(den) > abs(num))
            {
                den = den / num;
                num = 1;
            }
            else {  } // if the fraction is a whole number, do nothing

            remainder = 1;
        }

        setNum(num / abs(remainder));
        setDen(den / abs(remainder));
    }
    else if (abs(num) == abs(den))
    {
        if (num < den) // numerator is negative
        {
            setNum(-1);
        }
        else
        {
            setNum(1);
        }

        setDen(1);
    }
}

//--------------------------------------------------------------
// static int gcd(int number1, number2)
// Purpose: to calculate the greatest common divisor of two numbers
// Limitations: none
// Assumptions: none
// Returns: the gcd in int form
//--------------------------------------------------------------

int Fraction::gcd(int number1, int number2)
{
    int rem;
    int rem2;

    rem = number1 % number2;
    rem2 = rem;

    if (rem != 0 && number2 % rem != 0)
    {
        rem = number2 % rem;
        rem2 = rem;

        rem2 = rem;
        do
        {
            rem2 = rem;
            rem = rem % rem2;
        } while (rem % rem2 != 0);
    }
    else if (rem == 0)
    {
        if (number1 > number2)
        {
            rem2 = number1 / number2;
        }
        else if (number1 < number2)
        {
            rem2 = number2 / number1;
        }
    }

    return abs(rem2);
}

//--------------------------------------------------------------
// Fraction(int numX, int denX) constructor
// Purpose: constructs a new Fraction with numerator 'numX' and
//          denominator 'denX'; reduces Fraction to lowest terms
// Limitations: none
// Assumptions: none
// Returns: nothing
//--------------------------------------------------------------

Fraction::Fraction(int numX, int denX) : num(numX), den(denX)
{
    reduce();
}

//--------------------------------------------------------------
// Fraction(int numX) constructor
// Purpose: constructs a new Fraction with numerator 'numX' and
//          denominator 1
// Limitations: none
// Assumptions: none
// Returns: nothing
//--------------------------------------------------------------

Fraction::Fraction(int numX) : num(numX), den(1) {  }

//--------------------------------------------------------------
// Fraction() constructor
// Purpose: constructs a new Fraction with numerator '0' and
//          denominator '1'
// Limitations: none
// Assumptions: none
// Returns: nothing
//--------------------------------------------------------------

Fraction::Fraction() : num(0), den(1) { }

//--------------------------------------------------------------
// Fraction(string str) constructor
// Purpose: constructs a new Fraction using parsed info from
//          'str'; reduces Fraction to lowest terms
// Limitations: none
// Assumptions: none
// Returns: nothing
//--------------------------------------------------------------

Fraction::Fraction(string str) : num(0), den(1)
{
    const char * c_str = str.c_str();

    if ((int)str.find('/', 0) > -1)
    {
    sscanf(c_str, "%d %*c %d", &num, &den);
    }
    else if ((int)str.find('.', 0) > -1)
    {
        double d = strtod(c_str, NULL);
        Fraction f(d);
        this->num = f.num;
        this->den = f.den;
    }


    reduce();
}

//--------------------------------------------------------------
// void setNum(int num)
// Purpose: to set the numerator to 'num'
// Limitations: none
// Assumptions: none
//--------------------------------------------------------------


Fraction::Fraction(double d)
{
    bool isNeg = false;

    if (d < 0) isNeg = true;

    ostringstream oss;
    oss << d;
    string str = oss.str();

    // convert the numbers before and after the decimal point to strings
    string strPreDec = str.substr(0, str.find('.'));
    string strPostDec = str.substr(str.find('.') + 1);

    // convert each string to a C string
    const char* cstrPreDec = strPreDec.c_str();
    const char* cstrPostDec = strPostDec.c_str();

    // calculate the number of digits after the decimal point
    int postDecLen = strlen(cstrPostDec);

    // convert each C string to an int
    int preDec = atoi(cstrPreDec);
    int postDec = atoi(cstrPostDec);

    // the denominator of the fraction should be 10 * the number of digits after the decimal point
    double denom = pow(10, postDecLen);


    if (isNeg) num = -postDec;
    else num = postDec;

    den = denom;

    Fraction frac(num, den);
    frac += preDec;
    frac.reduce();
    num = frac.num;
    den = frac.den;
}

void Fraction::setNum(int newNum)
{
    num = newNum;
}

//--------------------------------------------------------------
// void setDen(int den)
// Purpose: to set the denominator to 'den'
// Limitations: none
// Assumptions: none
//--------------------------------------------------------------

void Fraction::setDen(int newDen)
{
    if (newDen < 0)
    {
        setNum(0 - getNum()); // make numerator negative
    }

    den = abs(newDen);
}

//--------------------------------------------------------------
// void setNumDen(int newNum, int newDen)
// Purpose: sets the numerator and the denominator of the current
//          object to 'newNum' and 'newDen' respectively
// Limitations: none
// Assumptions: none
//--------------------------------------------------------------

void Fraction::setNumDen(int newNum, int newDen)
{
    setNum(newNum);
    setDen(newDen);
}

//--------------------------------------------------------------
// int getNum()
// Purpose: returns 'num'
// Limitations: none
// Assumptions: none
// Returns: the int value 'num'
//--------------------------------------------------------------

int Fraction::getNum()
{
    return num;
}

//--------------------------------------------------------------
// int getDen()
// Purpose: returns 'den'
// Limitations: none
// Assumptions: none
// Returns: the int value 'den'
//--------------------------------------------------------------

int Fraction::getDen()
{
    return den;
}

//--------------------------------------------------------------
// static bool Greater(Fraction a, Fraction b)
// Purpose: compares two Fractions to determine if 'a' is greater
//          than 'b'
// Limitations: none
// Assumptions: none
// Returns: 'true' if 'a' is greater than 'b', 'false' if 'a' is less
//--------------------------------------------------------------

const bool Greater(const Fraction& a, const Fraction& b)
{
    int den_a = a.den;
    int num_a = a.num;
    int den_b = b.den;
    int num_b = b.num;

    if (num_a == den_b && den_a == num_b) //fractions are reciprocals of each other
    {
        if (num_a > num_b)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        int newNum_a = num_a * den_b;
        int newNum_b = num_b * den_a;

        if (newNum_a > newNum_b)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

//--------------------------------------------------------------
// bool isEqual(Fraction b)
// Purpose: to test if the current object is equal to 'b'
// Limitations: none
// Assumptions: none
// Returns: 'true' if 'b' is equal to the current object, 'false' if it is not
//--------------------------------------------------------------

bool Fraction::isEqual(Fraction b)
{
    int num_a = getNum();
    int den_a = getDen();
    int num_b = b.getNum();
    int den_b = b.getDen();

    if (num_a == num_b && den_a == den_b)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//--------------------------------------------------------------
// static bool Equals(Fraction a, Fraction b)
// Purpose: tests if 'a' is equal to 'b'
// Limitations: none
// Assumptions: none
// Returns: 'true' if 'b' is equal to 'a', 'false' if it is not
//--------------------------------------------------------------

bool Fraction::Equals(Fraction a, Fraction b)
{
    bool equals = a.isEqual(b);

    return equals;
}

//--------------------------------------------------------------
// string toString()
// Purpose: to convert the current object to a string
// Limitations: none
// Assumptions: none
// Returns: a formatted string containing the value of the
//          current object
//--------------------------------------------------------------

string Fraction::toString()
{
    string str;
    stringstream ss;

    ss << getNum() << "/" << getDen();
    ss >> str;

    return str;
}

//--------------------------------------------------------------
// Fraction& operator = (const Fraction& frac)
// Purpose: overloads the Fraction = Fraction operator
// Limitations: none
// Assumptions: none
// Returns: a reference to the modified lhs Fraction
//--------------------------------------------------------------

Fraction& Fraction::operator = (const Fraction& frac)
{
    num = frac.num;
    den = frac.den;
    return *this;
}

//--------------------------------------------------------------
// Fraction& operator = (const int& i)
// Purpose: overloads the Fraction = int operator
// Limitations: none
// Assumptions: none
// Returns: a reference to the modified lhs Fraction
//--------------------------------------------------------------

Fraction& Fraction::operator = (const int& i)
{
    num = i;
    den = 1;
    return *this;
}

//--------------------------------------------------------------
// Fraction& operator = (const double& d)
// Purpose: overloads the Fraction = double operator
// Limitations: none
// Assumptions: none
// Returns: a reference to the modified lhs Fraction
//--------------------------------------------------------------

Fraction& Fraction::operator = (const double& d)
{
    Fraction f(d);
    num = f.num;
    den = f.den;
    return *this;
}

//--------------------------------------------------------------
// Fraction& operator = (const float& f)
// Purpose: overloads the Fraction = float operator
// Limitations: none
// Assumptions: none
// Returns: a reference to the modified lhs Fraction
//--------------------------------------------------------------

Fraction& Fraction::operator = (const float& f)
{
    Fraction frac(f);
    num = frac.num;
    den = frac.den;
    return *this;
}

//--------------------------------------------------------------
// Fraction& operator = (const string& str)
// Purpose: overloads the Fraction = string operator
// Limitations: none
// Assumptions: none
// Returns: a reference to the modified lhs Fraction
//--------------------------------------------------------------

Fraction& Fraction::operator = (const string& str)
{
    const char* delimiter = "/";
    char * cstr, *p;

    cstr = new char [str.size() + 1];
    strcpy(cstr, str.c_str());

    num = atoi((strtok(cstr, delimiter)));
    p = (strtok(NULL, delimiter));
    den = atoi(p);

    reduce();

    return *this;
}

//--------------------------------------------------------------
// Fraction& operator + (const Fraction& first, const int& i)
// Purpose: globally overloads the Fraction + int operator
// Limitations: none
// Assumptions: none
// Returns: a Fraction object with the sum
//--------------------------------------------------------------

const Fraction operator + (const Fraction& first, const int& i)
{
    Fraction tmp;
    tmp.num = first.num + (i * first.den);
    tmp.den = first.den;
    tmp.reduce();
    return tmp;
}

//--------------------------------------------------------------
// const Fraction operator + (const Fraction& first, const Fraction& second)
// Purpose: globally overloads the Fraction + Fraction operator
// Limitations: none
// Assumptions: none
// Returns: a Fraction object with the sum
//--------------------------------------------------------------

const Fraction operator + (const Fraction& first, const Fraction& second)
{
    Fraction tmp;
    int a = first.num;
    int b = first.den;
    int c = second.num;
    int d = second.den;

    int num = (a * d) + (b * c);
    int den = b * d;

    tmp.num = num;
    tmp.den = den;
    tmp.reduce();

    return tmp;
}

//--------------------------------------------------------------
// const Fraction operator - (const Fraction& first, const int& i)
// Purpose: globally overloads the Fraction - int operator
// Limitations: none
// Assumptions: none
// Returns: a Fraction object with the difference
//--------------------------------------------------------------

const Fraction operator - (const Fraction& first, const int& i)
{
    Fraction tmp;
    tmp.num = first.num - (i * first.den);
    tmp.den = first.den;
    tmp.reduce();
    return tmp;
}

//--------------------------------------------------------------
// const Fraction operator - (const Fraction& first, const Fraction& second)
// Purpose: globally overloads the Fraction - Fraction operator
// Limitations: none
// Assumptions: none
// Returns: a Fraction object with the difference
//--------------------------------------------------------------

const Fraction operator - (const Fraction& first, const Fraction& second)
{
    Fraction tmp;
    int a = first.num;
    int b = first.den;
    int c = second.num;
    int d = second.den;

    int num = (a * d) - (b * c);
    int den = b * d;

    tmp.num = num;
    tmp.den = den;
    tmp.reduce();

    return tmp;
}

//--------------------------------------------------------------
// const Fraction operator * (const Fraction& first, const int& i)
// Purpose: globally overloads the Fraction * int operator
// Limitations: none
// Assumptions: none
// Returns: a Fraction object with the product
//--------------------------------------------------------------

const Fraction operator * (const Fraction& first, const int& i)
{
    Fraction tmp;
    tmp.num = first.num * i;
    tmp.den = first.den;
    tmp.reduce();
    return tmp;
}

//--------------------------------------------------------------
// const Fraction operator * (const Fraction& first, const Fraction& second)
// Purpose: globally overloads the Fraction * Fraction operator
// Limitations: none
// Assumptions: none
// Returns: a Fraction object with the product
//--------------------------------------------------------------

const Fraction operator * (const Fraction& first, const Fraction& second)
{
    Fraction tmp;
    tmp.num = first.num * second.num;
    tmp.den = first.den * second.den;
    tmp.reduce();
    return tmp;
}

//--------------------------------------------------------------
// const Fraction operator / (const Fraction& first, const int& i)
// Purpose: globally overloads the Fraction / int operator
// Limitations: none
// Assumptions: none
// Returns: a Fraction object with the quotient
//--------------------------------------------------------------

const Fraction operator / (const Fraction& first, const int& i)
{
    Fraction tmp;
    tmp.num = first.num;
    tmp.den = first.den * i;
    tmp.reduce();
    return tmp;
}

//--------------------------------------------------------------
// const Fraction operator / (const Fraction& first, const Fraction& second)
// Purpose: globally overloads the Fraction / Fraction operator
// Limitations: none
// Assumptions: none
// Returns: a Fraction object with the quotient
//--------------------------------------------------------------

const Fraction operator / (const Fraction& first, const Fraction& second)
{
    Fraction tmp;
    tmp.num = first.num * second.den;
    tmp.den = first.den * second.num;
    tmp.reduce();
    return tmp;
}

//--------------------------------------------------------------
// Fraction& operator += (const Fraction& obj)
// Purpose: overloads the Fraction += Fraction operator
// Limitations: none
// Assumptions: none
// Returns: a reference to the modified lhs Fraction
//--------------------------------------------------------------

Fraction& Fraction::operator += (const Fraction& obj)
{
    num = (num * obj.den) + (den * obj.num);
    den = den * obj.den;
    this->reduce();
    return *this;
}

//--------------------------------------------------------------
// Fraction& operator += (const int& i)
// Purpose: overloads the Fraction = int operator
// Limitations: none
// Assumptions: none
// Returns: a reference to the modified lhs Fraction
//--------------------------------------------------------------

Fraction& Fraction::operator += (const int& i)
{
    num += (i * den);
    this->reduce();
    return *this;
}

//--------------------------------------------------------------
// Fraction& operator -= (const Fraction& obj)
// Purpose: overloads the Fraction -= Fraction operator
// Limitations: none
// Assumptions: none
// Returns: a reference to the modified lhs Fraction
//--------------------------------------------------------------

Fraction& Fraction::operator -= (const Fraction& obj)
{
    num = (num * obj.den) - (den * obj.num);
    den = den * obj.den;
    this->reduce();
    return *this;
}

//--------------------------------------------------------------
// Fraction& operator -= (const int& i)
// Purpose: overloads the Fraction -= int operator
// Limitations: none
// Assumptions: none
// Returns: a reference to the modified lhs Fraction
//--------------------------------------------------------------

Fraction& Fraction::operator -= (const int& i)
{
    num -= (i * den);
    this->reduce();
    return *this;
}

//--------------------------------------------------------------
// Fraction& operator *= (const Fraction& obj)
// Purpose: overloads the Fraction *= Fraction operator
// Limitations: none
// Assumptions: none
// Returns: a reference to the modified lhs Fraction
//--------------------------------------------------------------

Fraction& Fraction::operator *= (const Fraction& obj)
{
    num *= obj.num;
    den *= obj.den;
    this->reduce();
    return *this;
}

//--------------------------------------------------------------
// Fraction& operator *= (const int& i)
// Purpose: overloads the Fraction *= int operator
// Limitations: none
// Assumptions: none
// Returns: a reference to the modified lhs Fraction
//--------------------------------------------------------------

Fraction& Fraction::operator *= (const int& i)
{
    num *= i;
    this->reduce();
    return *this;
}

//--------------------------------------------------------------
// Fraction& operator /= (const Fraction& obj)
// Purpose: overloads the Fraction /= Fraction operator
// Limitations: none
// Assumptions: none
// Returns: a reference to the modified lhs Fraction
//--------------------------------------------------------------

Fraction& Fraction::operator /= (const Fraction& obj)
{
    Fraction f;
    f.num = num * obj.den;
    f.den = den * obj.num;
    this->num = f.num;
    this->den = f.den;
    this->reduce();
    return *this;
}

//--------------------------------------------------------------
// Fraction& operator /= (const int& i)
// Purpose: overloads the Fraction /= int operator
// Limitations: none
// Assumptions: none
// Returns: a reference to the modified lhs Fraction
//--------------------------------------------------------------

Fraction& Fraction::operator /= (const int& i)
{
    Fraction f(i, 1);

    num *= f.den;
    den *= f.num;
    this->reduce();
    return *this;
}

//--------------------------------------------------------------
// Fraction& operator ++ (void)
// Purpose: overloads the ++Fraction operator
// Limitations: none
// Assumptions: none
// Returns: a reference to the modified object
//--------------------------------------------------------------

Fraction& Fraction::operator ++ (void)
{
    num += den;
    return *this;
}

//--------------------------------------------------------------
// Fraction& operator ++ (int)
// Purpose: overloads the Fraction++ operator
// Limitations: none
// Assumptions: none
// Returns: a reference to the modified object
//--------------------------------------------------------------

Fraction Fraction::operator ++ (int)
{
    Fraction tmp = *this;
    num += den;
    return tmp;
}

//--------------------------------------------------------------
// Fraction& operator -- (void)
// Purpose: overloads the ++Fraction operator
// Limitations: none
// Assumptions: none
// Returns: a reference to the modified object
//--------------------------------------------------------------

Fraction& Fraction::operator -- (void)
{
    num -= den;
    return *this;
}

//--------------------------------------------------------------
// Fraction& operator -- (int)
// Purpose: overloads the Fraction++ operator
// Limitations: none
// Assumptions: none
// Returns: a reference to the modified object
//--------------------------------------------------------------

Fraction Fraction::operator -- (int)
{
    Fraction tmp = *this;
    num -= den;
    return tmp;
}

//--------------------------------------------------------------
// const bool operator < (const Fraction& first, const Fraction& second)
// Purpose: globally overloads the Fraction < Fraction operator
// Limitations: none
// Assumptions: none
// Returns: true or false depending on if the first obj is less than the second
//--------------------------------------------------------------

const bool operator < (const Fraction& first, const Fraction& second)
{
    bool greaterThan = Greater(first, second);

    return !greaterThan;
}

//--------------------------------------------------------------
// const Fraction operator < (const Fraction& first, const int& i)
// Purpose: globally overloads the Fraction < int operator
// Limitations: none
// Assumptions: none
// Returns: true or false depending on if the Fraction is less than the int
//--------------------------------------------------------------

const bool operator < (const Fraction& first, const int& i)
{
    Fraction f(i, 1);
    bool greaterThan = Greater(first, f);

    return !greaterThan;
}

//--------------------------------------------------------------
// const bool operator > (const Fraction& first, const Fraction& second)
// Purpose: globally overloads the Fraction > Fraction operator
// Limitations: none
// Assumptions: none
// Returns: true or false depending on if the first obj is greater than the second
//--------------------------------------------------------------

const bool operator > (const Fraction& first, const Fraction& second)
{
    bool greaterThan = Greater(first, second);

    return greaterThan;
}

//--------------------------------------------------------------
// const Fraction operator > (const Fraction& first, const int& i)
// Purpose: globally overloads the Fraction > int operator
// Limitations: none
// Assumptions: none
// Returns: true or false depending on if the Fraction is greater than the int
//--------------------------------------------------------------

const bool operator > (const Fraction& first, const int& i)
{
    Fraction f(i, 1);

    bool greaterThan = Greater(first, f);
    return greaterThan;
}

//--------------------------------------------------------------
// const bool operator == (const Fraction& first, const Fraction& second)
// Purpose: globally overloads the Fraction == Fraction operator
// Limitations: none
// Assumptions: none
// Returns: true or false depending on if the first obj is equal to the second
//--------------------------------------------------------------

const bool operator == (const Fraction& first, const Fraction& second)
{
    if (first.num == second.num && first.den == second.den) return true;
    else return false;
}

//--------------------------------------------------------------
// const Fraction operator == (const Fraction& first, const int& i)
// Purpose: globally overloads the Fraction == int operator
// Limitations: none
// Assumptions: none
// Returns: true or false depending on if the Fraction is equal to the int
//--------------------------------------------------------------

const bool operator == (const Fraction& first, const int& i)
{
    Fraction f(i, 1);

    if (first.num == f.num && first.den == f.den) return true;
    else return false;
}

//--------------------------------------------------------------
// const bool operator >= (const Fraction& first, const Fraction& second)
// Purpose: globally overloads the Fraction >= Fraction operator
// Limitations: none
// Assumptions: none
// Returns: true or false depending on if the first obj is greater than or equal to the second
//--------------------------------------------------------------

const bool operator >= (const Fraction& first, const Fraction& second)
{
    if (first.num == second.num && first.den == second.den) return true;
    else
    {
        bool greaterThan = Greater(first, second);

        return greaterThan;
    }
}

//--------------------------------------------------------------
// const Fraction operator >= (const Fraction& first, const int& i)
// Purpose: globally overloads the Fraction >= int operator
// Limitations: none
// Assumptions: none
// Returns: true or false depending on if the Fraction is greater than or equal to the int
//--------------------------------------------------------------

const bool operator >= (const Fraction& first, const int& i)
{
    Fraction f(i, 1);

    if (first.num == f.num && first.den == f.den) return true;
    else
    {
        bool greaterThan = Greater(first, f);

        return greaterThan;
    }
}

//--------------------------------------------------------------
// const bool operator <= (const Fraction& first, const Fraction& second)
// Purpose: globally overloads the Fraction <= Fraction operator
// Limitations: none
// Assumptions: none
// Returns: true or false depending on if the first obj is less than or equal to the second
//--------------------------------------------------------------

const bool operator <= (const Fraction& first, const Fraction& second)
{
    if (first.num == second.num && first.den == second.den) return true;
    else
    {
        bool greaterThan = Greater(first, second);

        return !greaterThan;
    }
}

//--------------------------------------------------------------
// const Fraction operator <= (const Fraction& first, const int& i)
// Purpose: globally overloads the Fraction <= int operator
// Limitations: none
// Assumptions: none
// Returns: true or false depending on if the Fraction is less than or equal to the int
//--------------------------------------------------------------

const bool operator <= (const Fraction& first, const int& i)
{
    Fraction f(i, 1);

    if (first.num == f.num && first.den == f.den) return true;
    else
    {
        bool greaterThan = Greater(first, f);

        return !greaterThan;
    }
}

//--------------------------------------------------------------
// const bool operator != (const Fraction& first, const Fraction& second)
// Purpose: globally overloads the Fraction != Fraction operator
// Limitations: none
// Assumptions: none
// Returns: true or false depending on if the first obj is equal to the second
//--------------------------------------------------------------

const bool operator != (const Fraction& first, const Fraction& second)
{
    if (first.num == second.num && first.den == second.den) return false;
    else return true;
}

//--------------------------------------------------------------
// std::ostream& operator << (std::ostream os, const Fraction& obj)
// Purpose: overloads the << operator to output Fraction objects
// Limitations: none
// Assumptions: none
// Returns: an ostream object with the properly parsed Fraction data
//--------------------------------------------------------------

std::ostream& operator << (std::ostream& os, const Fraction& obj)
{
    os << obj.num << "/" << obj.den;
    return os;
}

//--------------------------------------------------------------
// std::istream& operator >> (std::istream& is, Fraction& obj)
// Purpose: overloads the >> operator to input Fraction objects
// Limitations: none
// Assumptions: none
// Returns: an istream object after assigning the parsed values to 'obj'
//--------------------------------------------------------------

std::istream& operator >> (std::istream& is, Fraction& obj)
{
    int num, den;
    char dummy;

    is >> num;
    is >> dummy;
    is >> den;
    obj.setNum(num);
    obj.setDen(den);
    obj.reduce();
    return is;
}

//--------------------------------------------------------------
// int Fraction::operator [] (values v)
// Purpose: overloads [] operator
// Limitations: none
// Assumptions: none
// Returns: the object's 'num' or 'den' value depending on the enumerator passed
//--------------------------------------------------------------

int Fraction::operator [] (values v)
{
    if (v == NUM) return num;
    else if (v == DEN) return den;
}

//--------------------------------------------------------------
// Fraction::operator int()
// Purpose: overloads the (int) typecast
// Limitations: none
// Assumptions: none
// Returns: a Fraction converted to an int
//--------------------------------------------------------------

Fraction::operator int()
{
    if (abs(num) < abs(den)) return 0;

    int number = num / den;
    return number;
}

//--------------------------------------------------------------
// Fraction::operator char*()
// Purpose: overloads the (char*) typecast
// Limitations: none
// Assumptions: none
// Returns: a Fraction converted to a char array
//--------------------------------------------------------------

Fraction::operator char*()
{
    ostringstream oss;
    oss << num << "/" << den;
    string str = oss.str();
    int length = str.size();

    // convert string to a C string
    char cstr[256];
    str.copy(cstr, 256, 0);
    cstr[length + 1] = '\0';
    char* cstrPtr = cstr;
    return cstrPtr;
}
