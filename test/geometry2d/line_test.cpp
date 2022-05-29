#include "line.h"

#include <cmath>
#include <iostream>
#include <cassert>

using namespace std;

double roundoff(double value)
{
    return round(value * 1000.0) / 1000.0;
}

void testCreateLineExpectTrue()
{
    Point point;
    point.x = 4.5;
    point.y = 6.5;

    Angle angle;
    angle.value = 30;

    double distance = 12.5;

    Point point2;
    point2.x = 6.428;
    point2.y = -5.850;

    Line line = createLine(point, angle, distance);

    Line line_expect;
    line_expect.start = point;
    line_expect.end = point2;

    assert(isFuzzyEqual(line.end, line_expect.end, 0.001));
}

void testGetDirectionExpectTrue()
{
    Point p1;
    p1.x = 3.5;
    p1.y = 6.7;

    Angle angle;
    angle.value = 56;

    double distance = 15;
    Line line = createLine(p1, angle, distance);

    Angle direction = getDirection(line);
    assert(roundoff(direction.value) == -0.549);
}

void testGetLengthLineExpectTrue()
{
    Point p1;
    p1.x = 5.25;
    p1.y = 7.75;

    Point p2;
    p2.x = 8.94;
    p2.y = 12.37;

    Line line;
    line.start = p1;
    line.end = p2;

    assert(roundoff(getLengthl(line)) == 5.913);
}

void testShiftParallelExpectTrue()
{
    Point p1;
    p1.x = 12.52;
    p1.y = 3.67;

    Point p2;
    p2.x = 8.12;
    p2.y = 12.63;

    Line line;
    line.start = p1;
    line.end = p2;

    Point point;
    point.x = 6.98;
    point.y = 7.54;

    shiftParallel(line, point);

    assert(line.end.x == 2.58);
    assert(line.end.y == 16.5);
}

int main(int /*argc*/, char ** /*argv*/)
{
    testCreateLineExpectTrue();
    testGetDirectionExpectTrue();
    testGetLengthLineExpectTrue();
    testShiftParallelExpectTrue();
    return EXIT_SUCCESS;
}