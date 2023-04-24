#include "Fraction.hpp"
#include <stdio.h>
#include <iostream>

using namespace std;

/// @brief 
namespace ariel{

    Fraction::Fraction(){

        // cout << getNumerator() << "/" << getDenominator() << endl;
    }

    Fraction::Fraction(int n, int d) : numerator(n),denominator(d){
        if(d == 0){
            throw std::invalid_argument("Cant divide by 0");
        }
        // this->numerator =n;
        // this->denominator = d;

        int gcd = Fraction::gcd(this->numerator,this->denominator);

        this->numerator = this->numerator / gcd;
        this->denominator = this->denominator / gcd;

    }

    Fraction::Fraction(float num) : numerator(int(num*1000)) , denominator(1000){

        this->reduce();
        
    }

    int Fraction::gcd(int nume, int den) {
        if (den == 0) {
            return nume;
        }
        return gcd(den, nume % den);
    }

    void Fraction::reduce(){
        if (this->denominator < 0) {
            this->setNumerator(-((this->getNumerator())));
            this->setDenominator(-((this->getDenominator())));
        }
        int gcd = this->gcd(this->getNumerator(), this->getDenominator());
        this->setNumerator(this->getNumerator() / gcd);
        this->setDenominator(this->getDenominator() / gcd);
    }

    int Fraction::getNumerator(){
        return this->numerator;
    }

    int Fraction::getDenominator(){
        return this->denominator;
    }

    void Fraction::setNumerator(int num1){

        if(num1 != 0){
            this->numerator = num1;

            int gcd = Fraction::gcd(num1,this->denominator);

            this->numerator = this->numerator/gcd;
            this->denominator = this->denominator/gcd;
        }
        else{
            this->numerator = 0;
            this->denominator = 1;
        }

    }
    
    void Fraction::setDenominator(int num2){
        if(num2 == 0){
            throw std::invalid_argument("cant divide by 0");
        }
        this->denominator = num2;

        // checking if the fraction can be reduce
        int gcd = Fraction::gcd(this->numerator,num2);

        this->numerator = this->numerator/gcd;
        this->denominator = this->denominator/gcd;
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

    bool Fraction::operator== (float num) const{

        return *this == Fraction(num);
    }

    bool operator== (float num ,const Fraction& other_fraction){

        return Fraction(num) == other_fraction;
    }




    bool Fraction::operator> (const Fraction& other_fraction) const{

        return (this->numerator > other_fraction.numerator) && (this->denominator > other_fraction.denominator);
    }

    bool Fraction::operator> (float num) const{

        return *this > Fraction(num);
    }

    bool operator> (float num ,const Fraction& other_fraction){

        return Fraction(num) > other_fraction;
    }



    bool Fraction::operator< (const Fraction& other_fraction) const{

        return (this->numerator < other_fraction.numerator) && (this->denominator < other_fraction.denominator);
    }

    bool Fraction::operator< (float num) const{

        return *this < Fraction(num);
    }

    bool operator< (float num ,const Fraction& other_fraction){

        return Fraction(num) < other_fraction;
    }



    bool Fraction::operator>= (const Fraction& other_fraction) const{

        return (this->numerator >= other_fraction.numerator) && (this->denominator >= other_fraction.denominator);
    }

    bool Fraction::operator>= (float num) const{

        return *this >= Fraction(num);
    }

    bool operator>= (float num ,const Fraction& other_fraction){

        return Fraction(num) >= other_fraction;
    }



    bool Fraction::operator<= (const Fraction& other_fraction) const{

        return (this->numerator <= other_fraction.numerator) && (this->denominator <= other_fraction.denominator);
    }

    bool Fraction::operator<= (float num) const{

        return *this <= Fraction(num);
    }

    bool operator<= (float num ,const Fraction& other_fraction){

        return Fraction(num) <= other_fraction;
    }


    // postfix (n++)
    const Fraction Fraction::operator++ (int){

        Fraction cpy = *this;
        *this = *this +1;

        this->reduce();

        return cpy;
    }

    //prefix (++n)
    Fraction& Fraction::operator++ (){

        *this = *this + 1;

        this->reduce();

        return *this;
    }



    //postfix (n--)
    const Fraction Fraction::operator--(int){

        Fraction cpy = *this;
        *this = *this - 1;

        // int gcd = Fraction::gcd(this->numerator,this->denominator);
        // this->numerator = this->numerator/gcd;
        // this->denominator = this->denominator /gcd;

        this->reduce();

        return cpy;
    }

    //prefix (--n)
    Fraction& Fraction::operator--(){

        *this = *this - 1;

        this->reduce();

        return *this;
    }





    std::ostream& operator<< (std::ostream& output, const Fraction& fraction){
        output << fraction.numerator << "/" << fraction.denominator;
        return output;
    }

    std::istream& operator>>(std::istream& input, Fraction& fraction){

        int numerator;
        int denominator;
        char slash_in_input;

        input >> numerator;

        input >> slash_in_input;

        input >> denominator;

        if(slash_in_input == '/'  &&  denominator != 0){

            fraction.setNumerator(numerator);
            fraction.setDenominator(denominator);
        }
        else{
            throw std::runtime_error("Input isnt valid");
        }

        return input;
    }


}