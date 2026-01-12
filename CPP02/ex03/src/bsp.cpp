#include "Point.h"

Fixed side_of_line(Point const a, Point const b, Point const p)
{
    Point ab = Point(b.getX() - a.getX(), b.getY() - a.getY());
    Point ap = Point(p.getX() - a.getX(), p.getY() - a.getY());

    return (ab.getX() * ap.getY() - ab.getY() * ap.getX());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    Fixed s1 = side_of_line(a, b, point);
    Fixed s2 = side_of_line(b, c, point);
    Fixed s3 = side_of_line(c, a, point);

    return (s1.getRawBits() != 0 && s2.getRawBits() != 0 && s3.getRawBits() != 0 &&
        ((s1.getRawBits() ^ s2.getRawBits()) >= 0) && ((s2.getRawBits() ^ s3.getRawBits()) >= 0));
}