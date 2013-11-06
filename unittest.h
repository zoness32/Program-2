#ifndef UNITTEST_H
#define UNITTEST_H

#include "fraction.h"
#include <iostream>
#include <vector>

class UnitTest
{
private:
    int numErrors;
public:
    UnitTest();

    void test(int expNum, int expDen, Fraction obj, string testNum);
    void test(bool exp, bool act, string testNum);
    void test(int expNum, int expDen, int actNum, int actDen, string testNum);
    void test(int expNum, int actNum, string testNum);
    void test( Fraction obj, const char& cstr, string testNum);
    void errors();
};

#endif // TEST_H
