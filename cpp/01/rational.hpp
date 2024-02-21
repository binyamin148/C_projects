#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>

class Rational
{
private:
    int numerator;
    int denominator;

public:
    Rational(int num, int denom);
    void reduce();
    Rational invert() const;
    Rational operator+(const Rational &other) const;
    Rational operator-(const Rational &other) const;
    Rational operator*(const Rational &other) const;
    Rational operator/(const Rational &other) const;
    bool operator==(const Rational &other) const;
    bool operator!=(const Rational &other) const;
    bool operator>(const Rational &other) const;
    bool operator<(const Rational &other) const;
    bool operator>=(const Rational &other) const;
    bool operator<=(const Rational &other) const;
    Rational &operator+=(const Rational &other);
    Rational &operator-=(const Rational &other);
    Rational &operator*=(const Rational &other);
    Rational &operator/=(const Rational &other);
    friend std::ostream &operator<<(std::ostream &os, const Rational &rational);
};

#endif