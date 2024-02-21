#include "rational.hpp"

int main()
{
    Rational a(1, 4);
    Rational b(1, 2);

    Rational c = a + b;
    Rational d = a - b;
    Rational e = a * b;
    Rational f = a / b;
    bool equal = a == b;
    bool not_equal = a != b;
    Rational inverted = a.invert();

    std::cout << "a + b = " << c << std::endl;
    std::cout << "a - b = " << d << std::endl;
    std::cout << "a * b = " << e << std::endl;
    std::cout << "a / b = " << f << std::endl;
    std::cout << "a == b: " << equal << std::endl;
    std::cout << "a != b: " << not_equal << std::endl;
    std::cout << "Inverted a: " << inverted << std::endl;

    a += b;
    bool greater = a > b;
    bool greater_equal = a >= b;
    bool less = a < b;
    bool less_equal = a <= b;

    std::cout << "a += b: " << a << std::endl;
    std::cout << "a > b: " << greater << std::endl;
    std::cout << "a >= b: " << greater_equal << std::endl;
    std::cout << "a < b: " << less << std::endl;
    std::cout << "a <= b: " << less_equal << std::endl;

    return 0;
}
