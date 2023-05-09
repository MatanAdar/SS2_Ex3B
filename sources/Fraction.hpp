#ifndef FRACTION_HPP
#define FRACTION_HPP

#include <string>

namespace ariel{
    class Fraction{
        private:
            int numerator;
            int denominator;
            int gcd(int nume, int den);
            void reduce();
            void check_Overflow(long numerator,long denominator) const;
        
        public:
            Fraction();

            Fraction(int numerator, int denominator);

            Fraction(float num);

            int getNumerator() const;

            int getDenominator() const;



            Fraction operator+(const Fraction &other_fraction) const;

            Fraction operator+ (float num);

            friend Fraction operator+(float num, const Fraction &fraction);


            Fraction operator- (const Fraction& other_fraction) const;

            Fraction operator- (float num);

            friend Fraction operator- (float num, const Fraction& fraction);


            Fraction operator* (const Fraction& other_fraction) const;

            Fraction operator* (float num);

            friend Fraction operator* (float num, const Fraction& fraction);


            Fraction operator/ (const Fraction& other_fraction) const;

            Fraction operator/ (float num);

            friend Fraction operator/ (float num, const Fraction& fraction);


            bool operator== (const Fraction& other_fraction) const;

            bool operator== (float num);

            friend bool operator== (float num , const Fraction& other_fraction);


            bool operator!= (const Fraction& other_fraction) const;

            bool operator!= (float num);

            friend bool operator!= (float num , const Fraction& other_fraction);


            bool operator> (const Fraction& other_fraction) const;

            bool operator> (float num);

            friend bool operator> (float num ,const Fraction& other_fraction);


            bool operator< (const Fraction& other_fraction) const;

            bool operator< (float num);

            friend bool operator< (float num ,const Fraction& other_fraction);


            bool operator>= (const Fraction& other_fraction) const;

            bool operator>= (float num);

            friend bool operator>= (float num ,const Fraction& other_fraction);


            bool operator<= (const Fraction& other_fraction) const;

            bool operator<= (float num);

            friend bool operator<= (float num ,const Fraction& other_fraction) ;


            const Fraction operator++ (int);

            Fraction& operator++ ();


            const Fraction operator--(int);

            Fraction& operator--();


            friend std::ostream& operator<<(std::ostream& output, const Fraction& fraction);

            friend std::istream& operator>>(std::istream& input, Fraction& fraction);

    };
}







#endif
