#include <iostream>
#include "Point.h"
#include "Fixed.h"

bool bsp(Point const a, Point const b, Point const c, Point const point);

void test(Point const& a, Point const& b, Point const& c, Point const& p, bool expected)
{
    bool result = bsp(a, b, c, p);

    std::cout << "Point (" 
              << p.getX() << ", " << p.getY() << ") -> "
              << (result ? "INSIDE" : "OUTSIDE");

    if (result == expected)
        std::cout << "  ✅";
    else
        std::cout << "  ❌  (EXPECTED " << (expected ? "INSIDE" : "OUTSIDE") << ")";

    std::cout << std::endl;
}

int main()
{
    Point a(Fixed(0), Fixed(0));
    Point b(Fixed(10), Fixed(0));
    Point c(Fixed(0), Fixed(10));

    std::cout << "\n--- BASIC INSIDE ---\n";
    test(a, b, c, Point(Fixed(1), Fixed(1)), true);
    test(a, b, c, Point(Fixed(2), Fixed(2)), true);
    test(a, b, c, Point(Fixed(3), Fixed(1)), true);

    std::cout << "\n--- OUTSIDE ---\n";
    test(a, b, c, Point(Fixed(10), Fixed(10)), false);
    test(a, b, c, Point(Fixed(-1), Fixed(1)), false);
    test(a, b, c, Point(Fixed(5), Fixed(6)), false);

    std::cout << "\n--- EDGE CASES (MUST BE FALSE) ---\n";
    test(a, b, c, Point(Fixed(0), Fixed(0)), false);
    test(a, b, c, Point(Fixed(10), Fixed(0)), false);
    test(a, b, c, Point(Fixed(0), Fixed(10)), false);
    test(a, b, c, Point(Fixed(5), Fixed(0)), false);
    test(a, b, c, Point(Fixed(0), Fixed(5)), false);
    test(a, b, c, Point(Fixed(5), Fixed(5)), false);

    std::cout << "\n--- CLOSE TO EDGE (PRECISION TEST) ---\n";
    test(a, b, c, Point(Fixed(5), Fixed(4.9f)), true);
    test(a, b, c, Point(Fixed(5), Fixed(5.1f)), false);

    std::cout << "\n--- REVERSED TRIANGLE (winding test) ---\n";
    Point ra(Fixed(0), Fixed(10));
    Point rb(Fixed(10), Fixed(0));
    Point rc(Fixed(0), Fixed(0));
    test(ra, rb, rc, Point(Fixed(1), Fixed(1)), true);
    test(ra, rb, rc, Point(Fixed(5), Fixed(5)), false);

    std::cout << "\n--- DIFFERENT SHAPE ---\n";
    Point t1(Fixed(1), Fixed(1));
    Point t2(Fixed(6), Fixed(2));
    Point t3(Fixed(3), Fixed(7));
    test(t1, t2, t3, Point(Fixed(3), Fixed(3)), true);
    test(t1, t2, t3, Point(Fixed(5), Fixed(5)), false);
    test(t1, t2, t3, Point(Fixed(3), Fixed(6)), true);
    test(t1, t2, t3, Point(Fixed(1), Fixed(6)), false);
    test(t1, t2, t3, Point(Fixed(4), Fixed(6)), false);
    test(t1, t2, t3, Point(Fixed(2), Fixed(6)), false);
    test(t1, t2, t3, Point(Fixed(1), Fixed(1)), false);
    test(t1, t2, t3, Point(Fixed(1.1f), Fixed(1.2f)), true);
    test(t1, t2, t3, Point(Fixed(1.9f), Fixed(1.2f)), true);
    test(t1, t2, t3, Point(Fixed(2.f), Fixed(1.2f)), false);
    test(t1, t2, t3, Point(Fixed(2.1f), Fixed(1.2f)), false);
}
