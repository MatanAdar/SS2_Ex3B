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

            // Fraction(int numerator) : numerator(numerator) , denominator(1){}

            Fraction(int numerator, int denominator);

            Fraction(float num);

            // // copy constructor
            // Fraction(const Fraction& other);

            // // move constructor
            // Fraction(Fraction&& other) noexcept;

            // // move assignment operator
            // Fraction& operator=(Fraction&& other) noexcept;

            // // copy assignment operator
            // Fraction& operator=(const Fraction& other);




            int getNumerator() const;

            int getDenominator() const;

            // void setNumerator(int num1);
            
            // void setDenominator(int num2);


            Fraction operator+ (const Fraction& other_fraction) const;

            friend Fraction operator+ (const Fraction& fraction , const float num);

            friend const Fraction operator+ (const float num, const Fraction& fraction);


            Fraction operator- (const Fraction& other_fraction) const;

            friend Fraction operator- (const Fraction& fraction , const float num);

            friend const Fraction operator- (const float num, const Fraction& fraction);


            Fraction operator* (const Fraction& other_fraction) const;

            friend Fraction operator* (const Fraction& fraction ,const float num);

            friend Fraction operator* (const float num, const Fraction& fraction);


            Fraction operator/ (const Fraction& other_fraction) const;

            friend Fraction operator/ (const Fraction& fraction , const float num);

            friend Fraction operator/ (const float num, const Fraction& fraction);


            bool operator== (const Fraction& other_fraction) const;

            friend bool operator== (const Fraction& fraction , const float num);

            friend bool operator== (const float num , const Fraction& other_fraction);


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

            //destructor
            // ~Fraction();
    };
}







#endif
