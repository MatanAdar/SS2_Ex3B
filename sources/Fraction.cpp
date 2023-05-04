#include "Fraction.hpp"
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <stdexcept>
#include <cmath>

using namespace std;


namespace ariel{

    Fraction::Fraction() : numerator(0) , denominator(1){

    }

    // Fraction::Fraction(int numerator) : numerator(numerator), denominator(1){}


    Fraction::Fraction(int n, int d) : numerator(n),denominator(d){
        if(d == 0){
            throw std::invalid_argument("Cant divide by 0");
        }

        this->reduce();

    }

    Fraction::Fraction(float num) : numerator(int(num*1000)) , denominator(1000){

        this->reduce();
        
    }

    // // copy constructor
    // Fraction::Fraction(const Fraction& other) : numerator(other.numerator) , denominator(other.denominator){

    // }

    // Fraction::Fraction(Fraction&& other) noexcept {
    //     // move other's data to this object
    // }

    // Fraction& Fraction::operator=(Fraction&& other) noexcept {
    //     if (this != &other) {
    //         // move other's data to this object
    //     }
    //     return *this;
    // }


    // Fraction& Fraction::operator=(const Fraction& other) {
    //     if (this != &other) {
    //         // copy other's data to this object
    //     }
    //     return *this;
    // }



    int Fraction::gcd(int nume, int den) {
        if (den == 0) {
            return nume;
        }
        return gcd(den, nume % den);
    }


    void Fraction::reduce(){
        if (this->denominator < 0) {
            this->numerator = -1*((this->getNumerator()));
            this->denominator = -1*((this->getDenominator()));
        }
        int gcd = this->gcd( abs(this->getNumerator()) , abs(this->getDenominator()) );
        this->numerator = this->getNumerator() / gcd;
        this->denominator = this->getDenominator() / gcd;
    }


    int Fraction::getNumerator() const{
        return this->numerator;
    }

    int Fraction::getDenominator() const{
        return this->denominator;
    }

    // void Fraction::setNumerator(int num1){

    //     if(num1 != 0){
    //         this->numerator = num1;

    //         int gcd = Fraction::gcd(num1,this->denominator);

    //         this->numerator = this->numerator/gcd;
    //         this->denominator = this->denominator/gcd;
    //     }
    //     else{
    //         this->numerator = 0;
    //         this->denominator = 1;
    //     }

    // }
    
    // void Fraction::setDenominator(int num2){
    //     if(num2 == 0){
    //         throw std::invalid_argument("cant divide by 0");
    //     }
    //     if(num2 < 0){
    //         this->numerator = (-1*(this->numerator));
    //         this->denominator = (-1*(this->denominator));

    //     }
    //     this->denominator = num2;

    //     // checking if the fraction can be reduce
    //     int gcd = Fraction::gcd(this->numerator,num2);

    //     this->numerator = this->numerator/gcd;
    //     this->denominator = this->denominator/gcd;
    // }


    void Fraction::check_Overflow(long numerator,long denominator) const{

        if(numerator > INT_MAX || numerator < INT_MIN){
            throw std::overflow_error("Numerator are larger then max int or smaller then min int");
        }
        else if(denominator > INT_MAX || denominator < INT_MIN){
            throw std::overflow_error("Denominator are larger then max int or smaller then min int");
        }
        else{
            return;
        }
    }


    

    Fraction Fraction::operator+(const Fraction &other_fraction) const{

        long new_n1 = (long)(this->getNumerator() * other_fraction.getDenominator()) + (other_fraction.getNumerator() * this->getDenominator());    
        long new_d1 = (long)(this->getDenominator() * other_fraction.getDenominator());

        check_Overflow(new_n1 , new_d1);

        int new_n = (int)(new_n1);
        int new_d = (int)(new_d1);
           
        return Fraction(new_n,new_d);
    }

    Fraction Fraction::operator+ (float num){

        Fraction temp(num*1000,1000);

        return *this + temp;
    }

    Fraction operator+(float num, const Fraction &fraction)
    {

        int num_as_fraction = num*1000;
        int den_as_fraction = 1000;

        return Fraction(num_as_fraction,den_as_fraction) + fraction;
    }



    Fraction Fraction::operator- (const Fraction& fraction) const{

        long new_n1 = (long)(this->getNumerator() * fraction.getDenominator()) - (long)(fraction.getNumerator() * this->getDenominator());    
        long new_d1 = (long)(this->getDenominator() * fraction.getDenominator());

       check_Overflow(new_n1 , new_d1);

        int new_n = (int)(new_n1);
        int new_d = (int)(new_d1);

        return Fraction(new_n,new_d);
    }

    Fraction Fraction::operator- (float num){

        Fraction temp(num*1000, 1000);

        return *this - temp;
    }

    Fraction operator- (float num, const Fraction& fraction){

        int num_as_fraction = num*1000;
        int den_as_fraction = 1000;

        return Fraction(num_as_fraction,den_as_fraction) - fraction;
    }



    Fraction Fraction::operator* (const Fraction& fraction) const{

        long new_n1 = ((long)this->getNumerator() * (long)fraction.getNumerator());    
        long new_d1 = ((long)this->getDenominator() * (long)fraction.getDenominator());

        check_Overflow(new_n1 , new_d1);

        int new_n = (int)(new_n1);    
        int new_d = (int)(new_d1);

        return Fraction(new_n,new_d);
    }

    Fraction Fraction::operator* (float num){

         // perform the float to fraction
        Fraction temp(num*1000 , 1000);

        return *this * temp;
    }

    Fraction operator* (float num, const Fraction& fraction){

        int num_as_fraction = num*1000;
        int den_as_fraction = 1000;

        return Fraction(num_as_fraction,den_as_fraction) * fraction;
    }



    Fraction Fraction::operator/ (const Fraction& fraction) const{

        if(fraction.numerator == 0){
            throw std::runtime_error("Cant denominator be 0");
        }
        
        long new_n1 = ((long)this->getNumerator() * fraction.getDenominator());
        long new_d1 = ((long)this->getDenominator() * fraction.getNumerator());

        check_Overflow(new_n1 , new_d1);

        int new_n = (int)(new_n1);
        int new_d = (int)(new_d1);

        return Fraction(new_n,new_d);
    }

    Fraction Fraction::operator/ (float num){

        if(num == 0){
            throw std::runtime_error("Cant denominator be 0");
        }

       // perform the float to fraction
        Fraction temp(num*1000 , 1000);

        return *this / temp;
    }

    Fraction operator/ (float num, const Fraction& fraction){

        int num_as_fraction = num*1000;
        int den_as_fraction = 1000;

        return Fraction(num_as_fraction,den_as_fraction) / fraction;
    }




    bool Fraction::operator== (const Fraction& other_fraction) const{
        
        if(this->numerator == other_fraction.numerator && this->denominator == other_fraction.denominator){
            return true;
        }

        float thousand = 1000.0;
        int fl1 = (int)(((float)this->numerator / (float)this->denominator) * thousand);
        int fl2 = (int)(((float)other_fraction.numerator / (float)other_fraction.denominator) * thousand);

        return fl1 == fl2;

        }

    bool Fraction::operator== (float num){

        return *this == Fraction(num);
    }

    bool operator== (float num ,const Fraction& other_fraction){

        return Fraction(num) == other_fraction;
    }





    bool Fraction::operator> (const Fraction& other_fraction) const{
        
        if(this->denominator == other_fraction.denominator){
            return this->numerator > other_fraction.numerator;
        }
        else{
            // get the numes of each one of the fraction to be with common denominator
            int new_this_nume = this->numerator * other_fraction.denominator;
            int new_other_nume = other_fraction.numerator * this->denominator;

            // checking the numerators after common denominator
            return new_this_nume > new_other_nume;
        }

    }

    bool Fraction::operator> (float num){

        return *this > Fraction(num);
    }

    bool operator>(float num, const Fraction &other_fraction)
    {

        return Fraction(num) > other_fraction;
    }



    bool Fraction::operator< (const Fraction& other_fraction) const{

        if(this->denominator == other_fraction.denominator){
            return this->numerator < other_fraction.numerator;
        }
        else{
            // get the numes of each one of the fraction to be with common denominator
            int new_this_nume = this->numerator * other_fraction.denominator;
            int new_other_nume = other_fraction.numerator * this->denominator;

            // checking the numerators after common denominator
            return new_this_nume < new_other_nume;
        }

    }

    bool Fraction::operator< (float num){

        return *this < Fraction(num);
    }

    bool operator< (float num ,const Fraction& other_fraction){

        return Fraction(num) < other_fraction;
    }




    bool Fraction::operator>= (const Fraction& other_fraction) const{

        if(this->denominator == other_fraction.denominator){
            return  this->numerator >= other_fraction.numerator;
        }
        else{
            // get the numes of each one of the fraction to be with common denominator
            int new_this_nume = this->numerator * other_fraction.denominator;
            int new_other_nume = other_fraction.numerator * this->denominator;

            // checking the numerators after common denominator
            return new_this_nume >= new_other_nume;
        }

    }

    bool Fraction::operator>= (float num){

        return *this >= Fraction(num);
    }

    bool operator>= (float num ,const Fraction& other_fraction){

        return Fraction(num) >= other_fraction;
    }




    bool Fraction::operator<= (const Fraction& other_fraction) const{

        if(this->denominator == other_fraction.denominator){
            return this->numerator <= other_fraction.numerator;
        }
        else{ 
            // get the numes of each one of the fraction to be with common denominator
            int new_this_nume = this->numerator * other_fraction.denominator;
            int new_other_nume = other_fraction.numerator * this->denominator;

            // checking the numerators after common denominator
            return new_this_nume <= new_other_nume;
        }   

    }

    bool Fraction::operator<= (float num){

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
        
        if((input >> numerator >> denominator) && denominator != 0){

            fraction = Fraction(numerator,denominator);
        }
        else{
            throw std::runtime_error("Input isnt valid");
        }

        return input;
    }

    //destructor
    // Fraction::~Fraction(){}

}