#include "doctest.h"
#include "Fraction.hpp"

using namespace ariel;


TEST_CASE("Checking when denominator is 0 it will throw a error"){

    CHECK_THROWS(Fraction(5,0));

    Fraction a(5,3);

    CHECK_THROWS(a.setDenominator(0));
}


TEST_CASE("Checking set function change the Fraction"){

    Fraction a(2,5);

    CHECK(a.getNumerator() == 2);
    CHECK(a.getDenominator() == 5);

    a.setNumerator(4);

    CHECK(a.getNumerator() == 4);
    CHECK(a.getDenominator() == 5);

    a.setDenominator(7);

    CHECK(a.getNumerator() == 4);
    CHECK(a.getDenominator() == 7);

    a.setDenominator(6);

    //fraction reduced because 4/6 can be reduced to 2/3
    CHECK(a.getNumerator() == 2);
    CHECK(a.getDenominator() == 3);

    a.setNumerator(0);

    CHECK(a.getNumerator() == 0);
    CHECK(a.getDenominator() == 3);

    // Checking throw error when set denominator to 0
    CHECK_THROWS(a.setDenominator(0));
}


TEST_CASE("Checking the fraction is most reduced"){

    Fraction a(3,6);

    // ????????????? nned to be reduce right away or no?
    CHECK(a.getNumerator() == 1);
    CHECK(a.getDenominator() == 2);

    a.setNumerator(4);

    //fraction reduced because 4/6 can be reduced to 2/3
    CHECK(a.getNumerator() == 2);
    CHECK(a.getDenominator() == 1);

    a.setDenominator(4);

    //fraction reduced because 2/4 can be reduced to 1/2
    CHECK(a.getNumerator() == 1);
    CHECK(a.getDenominator() == 2);

}


TEST_CASE("Checking if operator + and == working successfully"){

    Fraction a(1,4);
    Fraction b(1,2);

    Fraction c = a+b;

    CHECK(c.getNumerator() == 3);
    CHECK(c.getDenominator() == 4);

    Fraction d = a + 2.3;

    CHECK(d.getNumerator() == 51);
    CHECK(d.getDenominator() == 20);

    Fraction e(1,2);

    CHECK(b+e == Fraction(1,1));

    CHECK(2.5+e == Fraction(3,1));


}


TEST_CASE("Checking if operator - and == working successfully"){

    Fraction a(1,4);
    Fraction b(1,2);

    Fraction result(-1,4);

    CHECK(a-b == result);

    CHECK(2.3-b == Fraction(9,5));

    Fraction c(1,2);

    CHECK(b-c == Fraction(0,1));

    CHECK(c-2.5 == Fraction(-2,1));
}


TEST_CASE("Checking if operator * and == working successfully"){

    Fraction a(1,4);
    Fraction b(1,2);

    CHECK(a*b == Fraction(1,8));

    a.setNumerator(3);
    a.setDenominator(5);

    CHECK(a*b == Fraction(3,10));

    CHECK(2.3*b == Fraction(23,20));

    Fraction c(1,2);

    CHECK(b*c == Fraction(1,4));

    CHECK(c*2.5 == Fraction(5,4));
}


TEST_CASE("Checking if operator / and == working successfully"){

    Fraction a(1,4);
    Fraction b(1,2);

    CHECK(a/b == Fraction(1,2));

    CHECK(2.3/a == Fraction(46,5));

    Fraction c(1,2);

    CHECK(b/c == Fraction(1,1));

    CHECK(c/2.5 == Fraction(1,5));
}


TEST_CASE("Checking if operator ++ and operator -- working successfully "){

    Fraction a(1,2);
    Fraction b(3,5);

    CHECK(a++ == Fraction(1,2));

    Fraction c = a++;
    CHECK(c == Fraction(3,2));
    CHECK(a == Fraction(5,2));

    Fraction d = ++b;
    CHECK(d == Fraction(8,5));
    CHECK(b == Fraction(8,5));


    Fraction h = a--;
    CHECK(h == Fraction(5,2));
    CHECK(a == Fraction(3,2));

    Fraction k = --b;
    CHECK(k == Fraction(3,5));
    CHECK(b == Fraction(3,5));


}