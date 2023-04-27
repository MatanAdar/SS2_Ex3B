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
        
        public:
            Fraction();

            Fraction(int numerator, int denominator);

            Fraction(float num);

            int getNumerator() const{
                return numerator;
            }

            int getDenominator() const{
                return denominator;
            }

            void setNumerator(int num1);
            
            void setDenominator(int num2);


            Fraction operator+ (const Fraction& other_fraction) const;

            friend Fraction operator+ (const Fraction& fraction , float num);

            friend Fraction operator+ (float num, const Fraction& fraction);


            Fraction operator- (const Fraction& other_fraction) const;

            friend Fraction operator- (const Fraction& fraction , float num);

            friend Fraction operator- (float num, const Fraction& fraction);


            Fraction operator* (const Fraction& other_fraction) const;

            friend Fraction operator* (const Fraction& fraction , float num);

            friend Fraction operator* (float num, const Fraction& fraction);


            Fraction operator/ (const Fraction& other_fraction) const;

            friend Fraction operator/ (const Fraction& fraction , float num);

            friend Fraction operator/ (float num, const Fraction& fraction);


            bool operator== (const Fraction& other_fraction) const;

            friend bool operator== (const Fraction& fraction , float num);

            friend bool operator== (float num , const Fraction& other_fraction);


            bool operator> (const Fraction& other_fraction) const;

            friend bool operator> (const Fraction& fraction , float num);

            friend bool operator> (float num ,const Fraction& other_fraction);


            bool operator< (const Fraction& other_fraction) const;

            friend bool operator< (const Fraction& fraction , float num);

            friend bool operator< (float num ,const Fraction& other_fraction);


            bool operator>= (const Fraction& other_fraction) const;

            friend bool operator>= (const Fraction& fraction , float num);

            friend bool operator>= (float num ,const Fraction& other_fraction);


            bool operator<= (const Fraction& other_fraction) const;

            friend bool operator<= (const Fraction& fraction , float num);

            friend bool operator<= (float num ,const Fraction& other_fraction) ;


            const Fraction operator++ (int);

            Fraction& operator++ ();


            const Fraction operator--(int);

            Fraction& operator--();


            friend std::ostream& operator<<(std::ostream& output, const Fraction& fraction);

            friend std::istream& operator>>(std::istream& input, Fraction& fraction);


            //Assignment Operator
            Fraction& operator=(const Fraction& other){
                if(this != &other){
                    this->numerator = other.numerator;
                    this->denominator = other.denominator;
                }
                reduce();
                return *this;
            }
    };
}







#endif
