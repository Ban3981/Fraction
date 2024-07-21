#include "Fraction.h"
#include <cmath>

            namespace MathStuff
            {
                Fraction::Fraction(int x,int y) noexcept(false)
                {
                    if(y==0)
                        throwIfInvalidArgument();
                    numerator=x;
                    denominator=y;
                    correct();
                }


                Fraction::~Fraction() {}


                int Fraction::getNumerator() const noexcept
                {
                    return numerator;
                }


                int Fraction::getDenominator() const noexcept
                {
                    return denominator;
                }


                void Fraction::setNumerator(int x) noexcept
                {
                    numerator=x;
                    correct();
                }


                void Fraction::setDenominator(int x) noexcept(false)
                {
                    if(x==0)
                        throwIfInvalidArgument();
                    denominator=x;
                    correct();
                }


                std::ostream& operator<<(std::ostream& output,const Fraction& frac)
                {
                    output<<"("<<frac.numerator<<"/"<<frac.denominator<<")";
                    return output;
                }


                std::istream& operator>>(std::istream& input,Fraction& frac)
                {
                    std::cout<<"Enter values for fraction:";
                    int x,y;
                    input>>x>>y;
                    frac.setNumerator(x);
                    frac.setDenominator(y);
                    frac.correct();
                    return input;
                }


                Fraction Fraction::operator+(const Fraction& other) const noexcept
                {

                    return Fraction(numerator*other.denominator+other.numerator*denominator,denominator*other.denominator);
                }


                Fraction Fraction::operator-(const Fraction& other) const noexcept
                {

                    return Fraction(numerator*other.denominator-other.numerator*denominator,denominator*other.denominator);
                }


                Fraction Fraction::operator*(const Fraction& other) const noexcept
                {
                    return Fraction(numerator*other.numerator,denominator*other.denominator);
                }


                Fraction Fraction::operator/(const Fraction& other) const noexcept
                {
                    Fraction temp(numerator*other.denominator,denominator*other.numerator);
                    return temp;
                }


                bool Fraction::operator<(const Fraction& other) const noexcept
                {
                    return convertToDouble() < other.convertToDouble();
                }


                bool Fraction::operator>(const Fraction& other) const noexcept
                {
                    return convertToDouble()>other.convertToDouble();
                }


                bool Fraction::operator<=(const Fraction& other) const noexcept
                {
                    return convertToDouble()<=other.convertToDouble();
                }


                bool Fraction::operator>=(const Fraction& other) const noexcept
                {
                    return convertToDouble()>=other.convertToDouble();
                }


                bool Fraction::operator==(const Fraction& other) const noexcept
                {
                    return (numerator==other.numerator) && (denominator==other.denominator);
                }


                bool Fraction::operator!=(const Fraction& other) const noexcept
                {
                    return !(*this==other);
                }


                double Fraction::convertToDouble() const noexcept
                {
                    return static_cast<double>(numerator) / static_cast<double>(denominator);
                }


                int Fraction::greatestCommonDivisor(int x,int y) noexcept(false)
                {
                        if(x<y)
                            std::swap(x,y);

                        int i=2;
                        int res=1;
                        while(i<=y)
                        {
                            if(x%i==0 && y%i==0)
                            {
                                res*=i;
                                i=2;
                                x/=i;
                                y/=i;
                            }
                            else
                                ++i;
                        }
                        return res;
                }


                void Fraction::throwIfInvalidArgument() const noexcept(false)
                {
                    throw std::invalid_argument("Zero can't be denominator");
                }


                void Fraction::correct() noexcept(false)
                {
                    if((numerator<0 && denominator<0) || (numerator>0 && denominator<0))
                        numerator= -numerator,denominator= -denominator;

                    int x=std::abs(numerator);
                    int y=std::abs(denominator);
                    int temp=Fraction::greatestCommonDivisor(x,y);
                    if(temp!=1)
                        denominator/=temp,numerator/=temp;
                }
            }

