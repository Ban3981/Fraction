#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

        namespace MathStuff
        {
                class Fraction
                {
                    int numerator;
                    int denominator;

                public:
                    explicit Fraction(int=1,int=1) noexcept(false);
                    Fraction(const Fraction&) = default;
                    virtual ~Fraction();

                    int getNumerator() const noexcept;
                    int getDenominator() const noexcept;
                    void setNumerator(int) noexcept;
                    void setDenominator(int) noexcept(false);

                    friend std::ostream& operator<<(std::ostream&,const Fraction&);
                    friend std::istream& operator>>(std::istream&,Fraction&) noexcept(false);

                    Fraction operator+(const Fraction&) const noexcept;
                    Fraction operator-(const Fraction&) const noexcept;
                    Fraction operator*(const Fraction&) const noexcept;
                    Fraction operator/(const Fraction&) const noexcept;

                    bool operator<(const Fraction&) const noexcept;
                    bool operator>(const Fraction&) const noexcept;
                    bool operator<=(const Fraction&) const noexcept;
                    bool operator>=(const Fraction&) const noexcept;
                    bool operator==(const Fraction&) const noexcept;
                    bool operator!=(const Fraction&) const noexcept;

                    double convertToDouble() const noexcept;

                private:
                    static int greatestCommonDivisor(int,int) noexcept(false);
                    void correct() noexcept(false);
                    void throwIfInvalidArgument() const noexcept(false);
                };
        }


#endif // FRACTION_H
