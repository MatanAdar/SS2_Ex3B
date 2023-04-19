#include "Fraction.hpp"
#include <stdio.h>

using namespace std;

/// @brief 
namespace ariel{

    // Fraction::Fraction(){

    //     Fraction(this->numerator, this->denominator);
    // }

    Fraction::Fraction(int numerator, int denominator){
        this->numerator = numerator;
        this->denominator = denominator;
    }

    Fraction::Fraction(float num){

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
        this->denominator = num2;
    }

    

    Fraction Fraction::operator+ (Fraction& fraction){

        return Fraction(1,4);
    }

    float Fraction::operator+ (float num){

        return 1;
    }

    float operator+ (float num, Fraction& fraction){

        return 1;
    }



    Fraction Fraction::operator- (Fraction& fraction){

        return Fraction(1,2);
    }

    float Fraction::operator- (float num){

        return 1;
    }

    float operator- (float num, Fraction& fraction){

        return 1;
    }



    Fraction Fraction::operator* (Fraction& fraction){

        return Fraction(1,2);
    }

    float Fraction::operator* (float num){

        return 1;
    }

    float operator* (float num, Fraction& fraction){

        return 0;
    }

    

    Fraction Fraction::operator/ (Fraction& fraction){

        return Fraction(1,4);
    }

    float Fraction::operator/ (float num){

        return 1;
    }

    float operator/ (float num, Fraction& fraction){

        return 1;
    }



    bool Fraction::operator==(const Fraction& other_fraction) const{

        return false;
    }


    bool Fraction::operator> (const Fraction& other_fraction) const{

        return false;
    }


    bool Fraction::operator< (const Fraction& other_fraction) const{

        return false;
    }


    bool Fraction::operator>= (const Fraction& other_fraction) const{

        return false;
    }


    bool Fraction::operator<= (const Fraction& other_fraction) const{

        return false;
    }


    // postfix (n++)
    const Fraction Fraction::operator++ (int){

        return Fraction(1,1);
    }

    //prefix (++n)
    Fraction& Fraction::operator++ (){

        return *this;
    }



    //postfix (n--)
    const Fraction Fraction::operator--(int){

        return Fraction(1,1);
    }

    //prefix (--n)
    Fraction& Fraction::operator--(){

        return *this;
    }





    std::ostream& operator<< (std::ostream& output, const Fraction& fraction){
        return output;
    }

    std::istream& operator>>(std::istream& input, Fraction& fraction){
        return input;
    }


}