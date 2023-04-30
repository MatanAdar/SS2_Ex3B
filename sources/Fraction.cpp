#include "Fraction.hpp"
#include <stdio.h>
#include <iostream>
#include <algorithm>

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

    

    Fraction Fraction::operator+ (const Fraction& fraction) const{
        
        int new_n = (this->getNumerator() * fraction.getDenominator()) + (fraction.getNumerator() * this->getDenominator());    
        int new_d = (this->getDenominator() * fraction.getDenominator());

        int gcd = __gcd(new_n,new_d);

        new_n = new_n/gcd;
        new_d = new_d/gcd;
           
        return Fraction(new_n,new_d);
    }

    Fraction operator+ (const Fraction& fraction ,const float num){

        Fraction temp(num*1000,1000);

        //Fraction result = fraction + temp;

        // int new_n = (this->getNumerator() * den_as_fraction) + (num_as_fraction * this->getDenominator());
        // int new_d = this->getDenominator() * den_as_fraction;

        // int gcd = __gcd(new_n,new_d);

        // new_n = new_n/gcd;
        // new_d = new_d/gcd;

        return fraction + temp;
    }

    const Fraction operator+(const float num, const Fraction &fraction)
    {

        int num_as_fraction = num*1000;
        int den_as_fraction = 1000;

        return Fraction(num_as_fraction,den_as_fraction) + fraction;
    }



    Fraction Fraction::operator- (const Fraction& fraction) const{

        int new_n = (this->getNumerator() * fraction.getDenominator()) - (fraction.getNumerator() * this->getDenominator());    
        int new_d = (this->getDenominator() * fraction.getDenominator());

        int gcd = __gcd(new_n,new_d);

        new_n = new_n/gcd;
        new_d = new_d/gcd;

        return Fraction(new_n,new_d);
    }

    Fraction operator- (const Fraction& fraction ,const float num){

        Fraction temp(num*1000, 1000);

        // int new_n = (this->getNumerator() * den_as_fraction) - (num_as_fraction * this->getDenominator());
        // int new_d = this->getDenominator() * den_as_fraction;

        // int gcd = __gcd(new_n,new_d);

        // new_n = new_n/gcd;
        // new_d = new_d/gcd;

        return fraction - temp;
    }

    // const Fraction operator-(float num, const Fraction &fraction)
    // {
    //     return Fraction();
    // }

    const Fraction operator- (const float num, const Fraction& fraction){

        int num_as_fraction = num*1000;
        int den_as_fraction = 1000;

        return Fraction(num_as_fraction,den_as_fraction) - fraction;
    }



    Fraction Fraction::operator* (const Fraction& fraction) const{

        int new_n = (this->getNumerator() * fraction.getNumerator());    
        int new_d = (this->getDenominator() * fraction.getDenominator());

        int gcd = __gcd(new_n,new_d);

        new_n = new_n/gcd;
        new_d = new_d/gcd;

        return Fraction(new_n,new_d);
    }

    Fraction operator* (const Fraction& fraction , const float num){

         // perform the float to fraction
        Fraction temp(num*1000 , 1000);

        // int new_n = (this->getNumerator() * num_as_fraction);    
        // int new_d = (this->getDenominator() * den_as_fraction);

        // int gcd = __gcd(new_n,new_d);

        // new_n = new_n/gcd;
        // new_d = new_d/gcd;

        return fraction * temp;
    }

    Fraction operator* (const float num, const Fraction& fraction){

        int num_as_fraction = num*1000;
        int den_as_fraction = 1000;

        return Fraction(num_as_fraction,den_as_fraction) * fraction;
    }



    Fraction Fraction::operator/ (const Fraction& fraction) const{

        if(fraction.numerator == 0){
            throw std::runtime_error("Cant denominator be 0");
        }
        
        int new_n = (this->getNumerator() * fraction.getDenominator());
        int new_d = (this->getDenominator() * fraction.getNumerator());

        int gcd = __gcd(new_n,new_d);

        new_n = new_n/gcd;
        new_d = new_d/gcd;

        return Fraction(new_n,new_d);
    }

    Fraction operator/ (const Fraction& fraction , const float num){

       // perform the float to fraction
        Fraction temp(num*1000 , 1000);

        // int new_n = (this->getNumerator() * den_as_fraction);    
        // int new_d = (this->getDenominator() * num_as_fraction);

        // int gcd = __gcd(new_n,new_d);

        // new_n = new_n/gcd;
        // new_d = new_d/gcd;

        return fraction / temp;
    }

    Fraction operator/ (const float num, const Fraction& fraction){

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

    bool operator== (const Fraction& fraction , const float num){

        return fraction == Fraction(num);
    }

    bool operator== (const float num ,const Fraction& other_fraction){

        return Fraction(num) == other_fraction;
    }





    bool Fraction::operator> (const Fraction& other_fraction) const{
        
        if(this->denominator == other_fraction.denominator){
            return this->numerator > other_fraction.numerator;
        }
        else{
            // ???????????????
            int comman_d = this->denominator*other_fraction.denominator;
            int new_this_nume = this->numerator * other_fraction.denominator;
            int new_other_nume = other_fraction.numerator * this->denominator;
           
            return new_this_nume > new_other_nume;
        }

    }

    bool operator> (const Fraction& fraction , float num){

        return fraction > Fraction(num);
    }

    bool operator> (float num ,const Fraction& other_fraction){

        return Fraction(num) > other_fraction;
    }




    bool Fraction::operator< (const Fraction& other_fraction) const{

        if(this->denominator == other_fraction.denominator){
            return this->numerator < other_fraction.numerator;
        }
        else{
            // ????????????????
            int comman_d = this->denominator*other_fraction.denominator;
            int new_this_nume = this->numerator * other_fraction.denominator;
            int new_other_nume = other_fraction.numerator * this->denominator;
           
            return new_this_nume < new_other_nume;
        }

    }

    bool operator< (const Fraction& fraction , float num){

        return fraction < Fraction(num);
    }

    bool operator< (float num ,const Fraction& other_fraction){

        return Fraction(num) < other_fraction;
    }




    bool Fraction::operator>= (const Fraction& other_fraction) const{

        if(this->denominator == other_fraction.denominator){
            return  this->numerator >= other_fraction.numerator;
        }
        else{
            // ????????????????????
            int comman_d = this->denominator*other_fraction.denominator;
            int new_this_nume = this->numerator * other_fraction.denominator;
            int new_other_nume = other_fraction.numerator * this->denominator;
           
            return new_this_nume >= new_other_nume;
        }

    }

    bool operator>= (const Fraction& fraction , float num){

        return fraction >= Fraction(num);
    }

    bool operator>= (float num ,const Fraction& other_fraction){

        return Fraction(num) >= other_fraction;
    }




    bool Fraction::operator<= (const Fraction& other_fraction) const{

        if(this->denominator == other_fraction.denominator){
            return this->numerator <= other_fraction.numerator;
        }
        else{ 
            // ??????????????????? new numerators after common ground
            int comman_d = this->denominator*other_fraction.denominator;
            int new_this_nume = this->numerator * other_fraction.denominator;
            int new_other_nume = other_fraction.numerator * this->denominator;
           
            return new_this_nume <= new_other_nume;
        }   

    }

    bool operator<= (const Fraction& fraction , float num){

        return fraction <= Fraction(num);
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
        // char separator_in_input;

        // input >> numerator >> denominator ;

        // if(separator_in_input == ','  &&  denominator != 0){
            
        //     fraction = Fraction(numerator,denominator);
        //     // fraction.setNumerator(numerator);
        //     // fraction.setDenominator(denominator);
        // }
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