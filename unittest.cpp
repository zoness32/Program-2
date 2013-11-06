#include "fraction.h"
#include "unittest.h"
#include <string>
#include <iostream>
#include <windows.h>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

//returns the current attributes
WORD GetConsoleTextAttribute (HANDLE hCon)
{
  CONSOLE_SCREEN_BUFFER_INFO con_info;
  GetConsoleScreenBufferInfo(hCon, &con_info);
  return con_info.wAttributes;
}

UnitTest::UnitTest(): numErrors(0) { }

//--------------------------------------------------------------
// void test(int expNum, int expDen, Fraction obj, string testNum)
// Purpose: tests an object against 'expNum' and 'expDen' and displays
//          both, displaying the actual values in red if they are not the same
// Limitations: none
// Assumptions: none
//--------------------------------------------------------------
void UnitTest::test(int expNum, int expDen, Fraction obj, string testNum)
{
    // handles the changing of the console text color; used to make error text red and easy to spot
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int saved_colors = GetConsoleTextAttribute(hConsole);

    cout << testNum << "\t\t\t";

    if (expNum == obj.getNum() && expDen == obj.getDen())
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "Test passed" << endl;
        SetConsoleTextAttribute(hConsole, saved_colors);
    }
    else
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "Test failed" << endl;
        SetConsoleTextAttribute(hConsole, saved_colors);
        numErrors++;
    }
}

//--------------------------------------------------------------
// void test(bool expected, bool actual, string testNum)
// Purpose: tests 'expected' against 'actual' and displays output in red
//          if they are not the same
// Limitations: none
// Assumptions: none
//--------------------------------------------------------------
void UnitTest::test(bool expected, bool actual, string testNum)
{
    // handles the changing of the console text color; used to make error text red and easy to spot
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int saved_colors = GetConsoleTextAttribute(hConsole);
    string exp, act;

    if (expected == true) exp = "true";
    else exp = "false";

    if (actual == true) act = "true";
    else act = "false";

    cout << testNum << "\t\t\t";

    if (expected == actual)
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "Test passed" << endl;
        SetConsoleTextAttribute(hConsole, saved_colors);
    }
    else
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "Test failed" << endl;
        SetConsoleTextAttribute(hConsole, saved_colors);
        numErrors++;
    }
}

void UnitTest::test(int expNum, int expDen, int actNum, int actDen, string testNum)
{
    // handles the changing of the console text color; used to make error text red and easy to spot
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int saved_colors = GetConsoleTextAttribute(hConsole);

    cout << testNum << "\t\t\t";

    if (expNum == actNum && expDen == actDen)
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "Test passed" << endl;
        SetConsoleTextAttribute(hConsole, saved_colors);
    }
    else
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "Test failed" << endl;
        SetConsoleTextAttribute(hConsole, saved_colors);
        numErrors++;
    }
}

void UnitTest::test(int exp, int act, string testNum)
{
    // handles the changing of the console text color; used to make error text red and easy to spot
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int saved_colors = GetConsoleTextAttribute(hConsole);

    cout << testNum << "\t\t\t";

    if (exp == act)
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "Test passed" << endl;
        SetConsoleTextAttribute(hConsole, saved_colors);
    }
    else
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "Test failed" << endl;
        SetConsoleTextAttribute(hConsole, saved_colors);
        numErrors++;
    }
}

void UnitTest::test(Fraction obj, const char& cstr, string testNum)
{
    // handles the changing of the console text color; used to make error text red and easy to spot
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int saved_colors = GetConsoleTextAttribute(hConsole);

    string str = obj.toString();


    cout << testNum << "\t\t\t";

    if (cstr == str)
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
        cout << "Test passed" << endl;
        SetConsoleTextAttribute(hConsole, saved_colors);
    }
    else
    {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
        cout << "Test failed" << endl;
        SetConsoleTextAttribute(hConsole, saved_colors);
        numErrors++;
    }
}

//--------------------------------------------------------------
// void errors()
// Purpose: displays the number of errors in grey if there are none and
//          in red if there are any
//          if they are not the same
// Limitations: none
// Assumptions: none
//--------------------------------------------------------------
void UnitTest::errors()
{
    // handles the changing of the console text color; used to make error text red and easy to spot
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    const int saved_colors = GetConsoleTextAttribute(hConsole);


    if (numErrors > 0) {
        SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    }

    cout << "\nTotal number of errors: " << numErrors << endl;

    SetConsoleTextAttribute(hConsole, saved_colors);
}
