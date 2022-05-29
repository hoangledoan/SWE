#include "point.h"
#include "geo_compare.h"

#include <cmath>
#include <iostream>
#include <cassert>

using namespace std;

double roundoff(double value)
{
    return round(value * 1000.0) / 1000.0;
}

void testCreatePointExpectTrue()
{
    Angle alpha;
    alpha.value = 30;
    double distance = 20;
    Point p3;
    p3 = createPoint(distance, alpha);
    assert(roundoff(p3.x) == 3.085);
    assert(roundoff(p3.y) == -19.761);
}

void testIsEqualExpectTrue()
{
    Point p1;
    p1.x = 5.25;
    p1.y = 7.75;

    Point p2;
    p2.x = 5.25;
    p2.y = 7.75;

    double epsilon = 0.00001;

    assert(isFuzzyEqual(p1, p2, epsilon));
}

void testDistanceToExpectTrue()
{
    Point p1;
    p1.x = 5.6;
    p1.y = 7.7;

    Point p2;
    p2.x = 24.3;
    p2.y = 35.2;

    assert(roundoff(distanceTo(p1, p2)) == 33.256);
}

void testGetLengthExpectTrue()
{
    Point point;
    point.x = 5.25;
    point.y = 7.75;

    assert(roundoff(getLength(point)) == 9.361);
}

void testSubtracPointsExpectTrue()
{
    Point p1;
    p1.x = 5;
    p1.y = 7;

    Point p2;
    p2.x = 6;
    p2.y = 8;

    Point point = subtractPoints(p1, p2);
    Point point_expected;
    point_expected.x = -1;
    point_expected.y = -1;

    assert(isFuzzyEqual(point, point_expected, 0.00001));
}

void testAddPointsExpectTrue()
{
    Point p1;
    p1.x = 4.25;
    p1.y = 6.47;

    Point p2;
    p2.x = 3.62;
    p2.y = 9.43;

    Point point = addPoints(p1, p2);
    Point point_expected;
    point_expected.x = 7.87;
    point_expected.y = 15.9;

    assert(isFuzzyEqual(point, point_expected, 0.00001));
}

void testMultiplyPointExpectTrue()
{
    Point point;
    point.x = 6.4;
    point.y = 23.6;

    Point point_x = multiplyPoint(point, 4.0);
    Point point_expected;
    point_expected.x = 25.6;
    point_expected.y = 94.4;
    assert(isFuzzyEqual(point_x, point_expected, 0.00001));
}

void testRotateExpectTrue()
{
    Point point;
    point.x = 10.2;
    point.y = 32.4;

    Angle angle;
    angle.value = 40;

    rotate(point, angle);

    assert(roundoff(point.x) == -30.944);
    assert(roundoff(point.y) == -14.009);
}

int main(int /*argc*/, char ** /*argv*/)
{
    testCreatePointExpectTrue();
    testIsEqualExpectTrue();
    testGetLengthExpectTrue();
    testDistanceToExpectTrue();
    testSubtracPointsExpectTrue();
    testAddPointsExpectTrue();
    testMultiplyPointExpectTrue();
    testRotateExpectTrue();
    return EXIT_SUCCESS;
}