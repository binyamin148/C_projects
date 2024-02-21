#include "rational.hpp"

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

Rational::Rational(int num, int denom) : numerator(num), denominator(denom) {}
void Rational::reduce()
{
    int divisor = gcd(numerator, denominator);
    numerator /= divisor;
    denominator /= divisor;
}
Rational Rational::invert() const
{
    return Rational(denominator, numerator);
}
Rational Rational::operator+(const Rational &other) const
{
    return Rational(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
}
Rational Rational::operator-(const Rational &other) const
{
    return Rational(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
}
Rational Rational::operator*(const Rational &other) const
{
    return Rational(numerator * other.numerator, denominator * other.denominator);
}
Rational Rational::operator/(const Rational &other) const
{
    return Rational(numerator * other.denominator, denominator * other.numerator);
}
bool Rational::operator==(const Rational &other) const
{
    return numerator == other.numerator && denominator == other.denominator;
}
bool Rational::operator!=(const Rational &other) const
{
    return !(*this == other);
}
bool Rational::operator<(const Rational &other) const
{
    return numerator * other.denominator < other.numerator * denominator;
}
bool Rational::operator>(const Rational &other) const
{
    return numerator * other.denominator > other.numerator * denominator;
}
bool Rational::operator<=(const Rational &other) const
{
    return !(*this > other);
}
bool Rational::operator>=(const Rational &other) const
{
    return numerator * other.denominator >= other.numerator * denominator;
}
Rational &Rational::operator+=(const Rational &other)
{
    numerator = numerator * other.denominator + other.numerator * denominator;
    denominator *= other.denominator;
    reduce();
    return *this;
}

Rational &Rational::operator-=(const Rational &other)
{
    numerator = numerator * other.denominator - other.numerator * denominator;
    denominator *= other.denominator;
    reduce();
    return *this;
}

Rational &Rational::operator*=(const Rational &other)
{
    numerator *= other.numerator;
    denominator *= other.denominator;
    reduce();
    return *this;
}

Rational &Rational::operator/=(const Rational &other)
{
    numerator *= other.denominator;
    denominator *= other.numerator;
    reduce();
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Rational &rational)
{
    os << rational.numerator << "/" << rational.denominator;
    return os;
}