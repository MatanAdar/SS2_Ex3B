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

    CHECK(a == 2/5);

    a.setNumerator(4);

    CHECK(a == 4/5);

    a.setDenominator(7);

    CHECK(a == 4/7);

    a.setDenominator(6);

    CHECK(a == 2/3);
}


TEST_CASE("Checking the fraction is most reduced"){

    Fraction a(3,6);

    CHECK(a == 3/6);

    a.setNumerator(4);

    CHECK(a == 2/3);

}

TEST_CASE("Checking if operator + and == working successfully"){

    Fraction a(1,4);
    Fraction b(1,2);

    CHECK(a+b == 3/4);

    CHECK(a+2.3 == 2.55);

    Fraction c(1,2);

    CHECK(b+c == 1);

    CHECK(2.5+c == 3);


}


TEST_CASE("Checking if operator - and == working successfully"){

    Fraction a(1,4);
    Fraction b(1,2);

    CHECK(a-b == -1/4);

    CHECK(2.3-b == 1.8);

    Fraction c(1,2);

    CHECK(b-c == 0);

    CHECK(c-2.5 == -2);
}


TEST_CASE("Checking if operator * and == working successfully"){

    Fraction a(1,4);
    Fraction b(1,2);

    CHECK(a*b == 1/8);

    a.setNumerator(3);
    a.setDenominator(5);

    CHECK(a*b == 3/10);

    CHECK(2.3*b == 1.15);

    Fraction c(1,2);

    CHECK(b*c == 1/4);

    CHECK(c*2.5 == 1.25);
}


TEST_CASE("Checking if operator / and == working successfully"){

    Fraction a(1,4);
    Fraction b(1,2);

    CHECK(a/b == 1/2);

    CHECK(2.3/a == 0.575);

    Fraction c(1,2);

    CHECK(b/c == 1);

    CHECK(c/2.5 == 1/5);
}


TEST_CASE("Checking if operator ++ and operator -- working successfully "){

    Fraction a(1/2);
    Fraction b(3,5);

    Fraction c = a++;
    CHECK(c == 1/2);
    CHECK(a == 3/2);

    Fraction d = ++b;
    CHECK(d == 8/5);
    CHECK(b == 8/5);


    Fraction h = a--;
    CHECK(h == 3/2);
    CHECK(a ==1/2);

    Fraction k = --b;
    CHECK(k == 3/5);
    CHECK(b == 3/5);


}