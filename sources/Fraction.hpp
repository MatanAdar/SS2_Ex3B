#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <string>

namespace ariel{
    class Fraction{
        private:
            int numerator;
            int denominator;
        
        public:
            Fraction();

            Fraction(int numerator, int denominator);

            Fraction(float num);

            int gcd(int nume, int den);

            int getNumerator();

            int getDenominator();

            void setNumerator(int num1);
            
            void setDenominator(int num2);


            Fraction operator+ (Fraction& other_fraction);

            Fraction operator+ (float num);

            friend Fraction operator+ (float num, Fraction& fraction);


            Fraction operator- (Fraction& other_fraction);

            Fraction operator- (float num);

            friend Fraction operator- (float num, Fraction& fraction);


            Fraction operator* (Fraction& other_fraction);

            Fraction operator* (float num);

            friend Fraction operator* (float num, Fraction& fraction);


            Fraction operator/ (Fraction& other_fraction);

            Fraction operator/ (float num);

            friend Fraction operator/ (float num, Fraction& fraction);


            bool operator== (const Fraction& other_fraction) const;

            bool operator> (const Fraction& other_fraction) const;

            bool operator< (const Fraction& other_fraction) const;

            bool operator>= (const Fraction& other_fraction) const;

            bool operator<= (const Fraction& other_fraction) const;


            const Fraction operator++ (int);

            Fraction& operator++ ();


            const Fraction operator--(int);

            Fraction& operator--();


            friend std::ostream& operator<<(std::ostream& output, const Fraction& fraction);

            friend std::istream& operator>>(std::istream& input, Fraction& fraction);
    };
}







#endif
