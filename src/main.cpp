
#include        <iostream>

#include        "../header/BigInt.hpp"

int     main()
{
        const BigInt    a(42);
        BigInt  b(2100), c(1), d("4000000000000000000000000000000000000000000000000000000"), e(d);
        BigInt  f;

        std::cout << "a = " << a << std::endl;
        std::cout << "b = " << b << std::endl;
        std::cout << "c = " << c << std::endl;
        std::cout << "d = " << d << std::endl;
        std::cout << "e = " << e << std::endl;

        f = d + b;
        std::cout << "d + b = " << f << std::endl;

        std::cout << "(d < a) = " << (d < a) << std::endl;
        std::cout << "(d <= a) = " << (d <= a) << std::endl;
        std::cout << "(d > a) = " << (d > a) << std::endl;
        std::cout << "(d >= a) = " << (d >= a) << std::endl;
        std::cout << "(d == a) = " << (d == a) << std::endl;
        std::cout << "(d != a) = " << (d != a) << std::endl;

        return 0;
}