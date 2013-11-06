#include "fraction.h"
#include "unittest.h"
#include <vector>

int main()
{
    // Fraction(int, int) tests ------------------------------------------------------------

    Fraction f1(3,4);
    UnitTest t;
    Fraction fracs[8];

    t.test(3, 4, f1, "test 1");

    // Fraction = Fraction = Fraction tests ------------------------------------------------------------

    Fraction f2 = f1;
    t.test(3, 4, f2, "= test 1");

    // Fraction = int tests ------------------------------------------------------------

    f2 = f1 = 5;
    t.test(5, 1, f1, "= int test 1");

    // Fraction = string tests ------------------------------------------------------------

    Fraction f3;
    f3 = "3343/3897";
    t.test(3343, 3897, f3, "= string test 1");

    Fraction f4 = 7.86;
    t.test(393, 50, f4, "= double test");

    fracs[0] = f3;
    fracs[1] = f4;
    f2 = f3 = f4;
    t.test(393, 50, f2, fracs, 2, "f2 = f3 = f4 test");

    // reduce tests ------------------------------------------------------------

    f3 = "4/8";
    t.test(4, 8, 1, 2, f3, "= string reduce test");

    Fraction f5(8, 13);
    f4 = "3/4";
    f5 = "3/4";
    fracs[0] = f4;
    fracs[1] = f5;
    f3 = f4 + f5;
    t.test(3, 2, f3, fracs, 2, "f3 = f4 + f5 reduce test");

    // Fraction = Fraction + int tests ------------------------------------------

    fracs[0] = f3;
    f4 = f3 + 3;
    t.test(9, 2, f4, fracs, 1, "f4 = f3 + 3 test");

    // Fraction = Fraction + Fraction tests ------------------------------------------------------------

    f5.setNumDen(8, 13);
    fracs[0] = f4;
    fracs[1] = f5;
    f3 = f4 + f5;

    t.test(133, 26, f3, fracs, 2, "f3 = f4 + f5 test");

    // Fraction = Fraction - Fraction tests ------------------------------------------------------------

    Fraction f6(4, 9);
    Fraction f7(3, 8);

    Fraction f8 = f6 - f7;
    fracs[0] = f6;
    fracs[1] = f7;
    t.test(5, 72, f8, fracs, 2, "f8 = f6 - f7 test");

    // Fraction = Fraction - int tests ------------------------------------------------------------

    Fraction f9(8, 5);
    Fraction f10;

    fracs[0] = f9;
    f10 = f9 - 4;
    t.test(-12, 5, f10, fracs, 1, "f10 = f9 - 4 test");

    // Fraction = Fraction * Fraction tests ------------------------------------------------------------

    Fraction f11(3, 8);
    Fraction f12(4, 9);

    Fraction f13 = f11 * f12;
    fracs[0] = f11;
    fracs[1] = f12;
    t.test(1, 6, f13, fracs, 2, "f13 = f11 * f12 test");

    // Fraction = Fraction * int tests ------------------------------------------------------------

    Fraction f14(3, 8);

    Fraction f15 = f14 * 3 * 2;
    fracs[0] = f14;
    t.test(9, 4, f15, fracs, 1, "f15 = f14 * 3 * 2 test");

    // Fraction = Fraction / Fraction tests ------------------------------------------------------------

    Fraction f16(2, 5);
    Fraction f17(3, 10);

    Fraction f18 = f16 / f17;
    fracs[0] = f16;
    fracs[1] = f17;
    t.test(4, 3, f18, fracs, 2, "f18 = f16 / f17 test");

    // Fraction = Fraction / int tests ------------------------------------------------------------

    Fraction f19(4, 9);

    Fraction f20 = f19 + 5;
    fracs[0] = f19;
    t.test(49, 9, f20, fracs, 1, "f20 = f19 + 5 test");

    // Fraction = int + Fraction tests -------------------------------------------------------------------

    Fraction f21(3, 5);
    Fraction f22 = f21 + 2;

    fracs[0] = f21;
    t.test(13, 5, f22, fracs, 1, "f22 = 4 + f21 + 2 test");

    // Fraction += Fraction tests --------------------------------------------------------------------

    Fraction f23(3, 8);
    Fraction f24(3, 11);
    fracs[0] = f23;
    fracs[1] = f24;

    f24 += f23;
    t.test(57, 88, f24, fracs, 2, "f24 += f23 test");

    f24.setNumDen(3, 8);
    fracs[1] = f24;
    f24 += f23;
    t.test(3, 4, f24, fracs, 2, "f24 += f23 test 2");

    // Fraction += int tests --------------------------------------------------------------------------

    Fraction f25(4, 9);
    f25 += 4;
    t.test(40, 9, f25, "f25 += 4 test");

    // Fraction -= Fraction tests --------------------------------------------------------------------

    Fraction f26(5, 8);
    Fraction f27(8, 11);
    fracs[0] = f26;
    fracs[1] = f27;

    f27 -= f26;
    t.test(9, 88, f27, fracs, 2, "f26 -= f25 test");

    // Fraction -= int tests --------------------------------------------------------------------------

    Fraction f28(8, 3);
    f28 -= 7;
    t.test(-13, 3, f28, "f28 -= 7 test");

    // Fraction *= Fraction tests --------------------------------------------------------------------

    Fraction f29(5, 8);
    Fraction f30(8, 11);
    fracs[0] = f29;
    fracs[1] = f30;

    f30 *= f29;
    t.test(5, 11, f30, fracs, 2, "f29 *= f30 test");

    // Fraction *= int tests --------------------------------------------------------------------------

    Fraction f31(8, 3);
    f31 *= 7;
    t.test(56, 3, f31, "f31 *= 7 test");

    // Fraction /= Fraction tests --------------------------------------------------------------------

    Fraction f32(7, 8);
    Fraction f33(8, 5);
    fracs[0] = f32;
    fracs[1] = f33;

    f33 /= f32;
    t.test(64, 35, f33, fracs, 2, "f33 /= f32 test");

    // Fraction /= int tests --------------------------------------------------------------------------

    Fraction f34(8, 3);
    f34 /= 7;
    t.test(8, 21, f34, "f34 /= 7 test");

    // ++Fraction tests --------------------------------------------------------------------------------

    Fraction f35(5, 9);
    ++f35;
    t.test(14, 9, f35, "++f35 test");

    // Fraction++ tests --------------------------------------------------------------------------------

    Fraction f36(5, 8);
    Fraction f37 = f36++;
    t.test(5, 8, f37, "f36++ test for f37");
    t.test(13, 8, f36, "f36++ test for f36");

    // --Fraction tests --------------------------------------------------------------------------------

    Fraction f38(5, 9);
    --f38;
    t.test(-4, 9, f38, "--f38 test");

    // Fraction-- tests --------------------------------------------------------------------------------

    Fraction f39(5, 8);
    Fraction f40 = f39--;
    t.test(5, 8, f40, "f39-- test for f40");
    t.test(-3, 8, f39, "f39-- test for f39");

    // Fraction < Fraction tests ------------------------------------------------------------------------

    Fraction f41(3, 8);
    Fraction f42(2, 7);
    bool lessThan = f41 < f42;

    fracs[0] = f41;
    fracs[1] = f42;
    t.test(false, lessThan, fracs, 2, "f41 < f42 test");

    // Fraction < int tests -----------------------------------------------------------------------------

    Fraction f43(6, 13);
    fracs[0] = f43;
    lessThan = f43 < 2;
    t.test(true, lessThan, fracs, 1, "f43 < 2 test");

    // Fraction > Fraction tests ------------------------------------------------------------------------

    Fraction f44(3, 8);
    Fraction f45(2, 7);
    lessThan = f44 > f45;

    fracs[0] = f44;
    fracs[1] = f45;
    t.test(true, lessThan, fracs, 2, "f44 > f45 test");

    // Fraction > int tests -----------------------------------------------------------------------------

    Fraction f46(6, 13);
    fracs[0] = f46;
    lessThan = f46 > 2;
    t.test(false, lessThan, fracs, 1, "f46 > 2 test");

    // Fraction <= Fraction tests -----------------------------------------------------------------------

    Fraction f47(3, 8);
    Fraction f48(2, 7);
    lessThan = f47 <= f48;

    fracs[0] = f47;
    fracs[1] = f48;
    t.test(false, lessThan, fracs, 2, "f47 <= f48 test");

    // Fraction <= int tests ----------------------------------------------------------------------------

    Fraction f49(6, 13);
    fracs[0] = f49;
    lessThan = f49 <= 2;
    t.test(true, lessThan, fracs, 1, "f49 <= 2 test");

    // Fraction >= Fraction tests -----------------------------------------------------------------------

    Fraction f50(3, 8);
    Fraction f51(2, 7);
    lessThan = f50 >= f51;

    fracs[0] = f50;
    fracs[1] = f51;
    t.test(true, lessThan, fracs, 2, "f50 >= f51 test");

    // Fraction >= int tests ----------------------------------------------------------------------------

    Fraction f52(6, 13);
    fracs[0] = f52;
    lessThan = f52 >= 2;
    t.test(false, lessThan, fracs, 1, "f52 >= 2 test");

    // Fraction != Fraction tests -----------------------------------------------------------------------

    Fraction f61(3, 4);
    Fraction f62(3, 4);
    fracs[0] = f61;
    fracs[1] = f62;
    bool equal = f61 != f62;
    t.test(false, equal, fracs, 2, "f61 != f62 test");

    // cout << Fraction tests ---------------------------------------------------------------------------

    Fraction f53(5, 8);
    cout << "\nTest for cout << f53\n" << "f53 is:\t\t\t5/8\nResult:\t\t\t" << f53 << endl;

    // cin >> Fraction tests ----------------------------------------------------------------------------

    //Fraction f54;
    //cout << "\nEnter a fraction (#/# format): ";
    //cin >> f54;
    //cout << "You entered:\t\t\t" << f54 << endl;

    // Fraction[] tests ---------------------------------------------------------------------------------

    Fraction f55(3, 23);

    t.test(3, 23, f55[NUM], f55[DEN], "f55[] test");

    // --------

    Fraction f56;
    f56 = .7689;

    cout << f56 << endl;

    f56 = -.0075000;
    cout << f56 << endl;

    f56 = .375;
    t.test(.375, 3, 8, f56, "f56 = .375 test");

    Fraction f57(.75);
    t.test(3, 4, f57[NUM], f57[DEN], "Fraction(double) test");

    // (int)Fraction tests ------------------------------------------------------------------------------------

    Fraction f58(4, 9);
    int i = (int)f58;
    t.test(0, i, f58, "(int)f58 test", 0.0);

    Fraction f59(86, 3);
    i = (int)f59;
    t.test(28, i, f59, "(int)f59 test", 0.0);

    // (char*)Fraction tests ----------------------------------------------------------------------------------

    Fraction f60(5, 8);
    char* fraction = (char*)f60;
    cout << fraction;


    t.errors();

}
