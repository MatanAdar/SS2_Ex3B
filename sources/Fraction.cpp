#include "Fraction.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;

/// @brief 
namespace ariel{

    Fraction::Fraction(){

        cout << getNumerator() << "/" << getDenominator() << endl;
    }

    Fraction::Fraction(int n, int d) : numerator(n),denominator(d){
        if(d == 0){
            throw std::invalid_argument("Cant divide by 0");
        }
        // this->numerator = numerator;
        // this->denominator = denominator;

        int gcd = Fraction::gcd(this->numerator,this->denominator);

        this->numerator = this->numerator / gcd;
        this->denominator = this->denominator / gcd;


    }

    Fraction::Fraction(float num){

        this->numerator += num;
        
        
    }

    int Fraction::gcd(int nume, int den) {
        if (den == 0) {
            return nume;
        }
        return gcd(den, nume % den);
    }

    int Fraction::getNumerator(){
        return this->numerator;
    }

    int Fraction::getDenominator(){
        return this->denominator;
    }

    void Fraction::setNumerator(int num1){
        this->numerator = num1;
    }
    
    void Fraction::setDenominator(int num2){
        if(num2 == 0){
            throw std::invalid_argument("cant divide by 0");
        }
        this->denominator = num2;
    }

    

    Fraction Fraction::operator+ (Fraction& fraction){
        
        int new_n = (this->getNumerator() * fraction.getDenominator()) + (fraction.getNumerator() * this->getDenominator());    
        int new_d = (this->getDenominator() * fraction.getDenominator());

        int gcd = Fraction::gcd(new_n,new_d);

        new_n = new_n/gcd;
        new_d = new_d/gcd;
           
        return Fraction(new_n,new_d);
    }



    Fraction Fraction::operator+ (float num){

        // perform the float to fraction
        int num_as_fraction = num*1000;
        int den_as_fraction = 1000;

        int new_n = (this->getNumerator() * den_as_fraction) + (num_as_fraction * this->getDenominator());
        int new_d = this->getDenominator() * den_as_fraction;

        int gcd = Fraction::gcd(new_n,new_d);

        new_n = new_n/gcd;
        new_d = new_d/gcd;

        return Fraction(new_n,new_d);
    }

    Fraction operator+ (float num, Fraction& fraction){

        int num_as_fraction = num*1000;
        int den_as_fraction = 1000;

        return Fraction(num_as_fraction,den_as_fraction) + fraction;
    }



    Fraction Fraction::operator- (Fraction& fraction){

        int new_n = (this->getNumerator() * fraction.getDenominator()) - (fraction.getNumerator() * this->getDenominator());    
        int new_d = (this->getDenominator() * fraction.getDenominator());

        int gcd = Fraction::gcd(new_n,new_d);

        new_n = new_n/gcd;
        new_d = new_d/gcd;

        return Fraction(new_n,new_d);
    }

    Fraction Fraction::operator- (float num){

         // perform the float to fraction
        int num_as_fraction = num*1000;
        int den_as_fraction = 1000;

        int new_n = (this->getNumerator() * den_as_fraction) - (num_as_fraction * this->getDenominator());
        int new_d = this->getDenominator() * den_as_fraction;

        int gcd = Fraction::gcd(new_n,new_d);

        new_n = new_n/gcd;
        new_d = new_d/gcd;

        return Fraction(new_n,new_d);
    }

    Fraction operator- (float num, Fraction& fraction){

        int num_as_fraction = num*1000;
        int den_as_fraction = 1000;

        return Fraction(num_as_fraction,den_as_fraction) - fraction;
    }



    Fraction Fraction::operator* (Fraction& fraction){

        int new_n = (this->getNumerator() * fraction.getNumerator());    
        int new_d = (this->getDenominator() * fraction.getDenominator());

        int gcd = Fraction::gcd(new_n,new_d);

        new_n = new_n/gcd;
        new_d = new_d/gcd;

        return Fraction(new_n,new_d);
    }

    Fraction Fraction::operator* (float num){

         // perform the float to fraction
        int num_as_fraction = num*1000;
        int den_as_fraction = 1000;

        int new_n = (this->getNumerator() * num_as_fraction);    
        int new_d = (this->getDenominator() * den_as_fraction);

        int gcd = Fraction::gcd(new_n,new_d);

        new_n = new_n/gcd;
        new_d = new_d/gcd;

        return Fraction(new_n,new_d);
    }

    Fraction operator* (float num, Fraction& fraction){

        int num_as_fraction = num*1000;
        int den_as_fraction = 1000;

        return Fraction(num_as_fraction,den_as_fraction) * fraction;
    }

    

    Fraction Fraction::operator/ (Fraction& fraction){

        int new_n = (this->getNumerator() * fraction.getDenominator());
        int new_d = (this->getDenominator() * fraction.getNumerator());

        int gcd = Fraction::gcd(new_n,new_d);

        new_n = new_n/gcd;
        new_d = new_d/gcd;

        return Fraction(new_n,new_d);
    }

    Fraction Fraction::operator/ (float num){

       // perform the float to fraction
        int num_as_fraction = num*1000;
        int den_as_fraction = 1000;

        int new_n = (this->getNumerator() * den_as_fraction);    
        int new_d = (this->getDenominator() * num_as_fraction);

        int gcd = Fraction::gcd(new_n,new_d);

        new_n = new_n/gcd;
        new_d = new_d/gcd;

        return Fraction(new_n,new_d);
    }

    Fraction operator/ (float num, Fraction& fraction){

        int num_as_fraction = num*1000;
        int den_as_fraction = 1000;

        return Fraction(num_as_fraction,den_as_fraction) / fraction;
    }



    bool Fraction::operator== (const Fraction& other_fraction) const{

        return (this->numerator == other_fraction.numerator) && (this->denominator == other_fraction.denominator);
    }


    bool Fraction::operator> (const Fraction& other_fraction) const{

        return (this->numerator > other_fraction.numerator) && (this->denominator > other_fraction.denominator);
    }


    bool Fraction::operator< (const Fraction& other_fraction) const{

        return (this->numerator < other_fraction.numerator) && (this->denominator < other_fraction.denominator);
    }


    bool Fraction::operator>= (const Fraction& other_fraction) const{

        return (this->numerator >= other_fraction.numerator) && (this->denominator >= other_fraction.denominator);
    }


    bool Fraction::operator<= (const Fraction& other_fraction) const{

        return (this->numerator <= other_fraction.numerator) && (this->denominator <= other_fraction.denominator);
    }


    // postfix (n++)
    const Fraction Fraction::operator++ (int){

        Fraction cpy = *this;
        *this = *this +1;

        int gcd = Fraction::gcd(this->numerator,this->denominator);
        this->numerator = this->numerator/gcd;
        this->denominator = this->denominator /gcd;

        return cpy;
    }

    //prefix (++n)
    Fraction& Fraction::operator++ (){

        *this = *this + 1;
        return *this;
    }



    //postfix (n--)
    const Fraction Fraction::operator--(int){

        Fraction cpy = *this;
        *this = *this - 1;

        int gcd = Fraction::gcd(this->numerator,this->denominator);
        this->numerator = this->numerator/gcd;
        this->denominator = this->denominator /gcd;

        return cpy;
    }

    //prefix (--n)
    Fraction& Fraction::operator--(){

        *this = *this - 1;
        return *this;
    }





    std::ostream& operator<< (std::ostream& output, const Fraction& fraction){
        cout << fraction.numerator << "/" << fraction.denominator;
        return cout;
    }

    std::istream& operator>>(std::istream& input, Fraction& fraction){
        return input;
    }


}


