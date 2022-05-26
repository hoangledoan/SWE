#include <cmath>
#include <iostream>
#include <cassert>
using namespace std;
struct Point
{
    double x{0.0};
    double y{0.0};
};

struct Line
{
    Point start;
    Point end;
};

struct Angle
{
    double value{0.0};
};

/* angle.cpp*/
double fixAngleRange(double angleValue)
{
    while (angleValue <= M_PI)
    {
        angleValue += 2 * M_PI;
    }

    angleValue -= 2 * M_PI * static_cast<unsigned int>(angleValue / (2 * M_PI));

    return angleValue > M_PI ? angleValue - 2 * M_PI : angleValue;
}

double getValueBetweenMinusPiAndPi(Angle angle)
{
    return fixAngleRange(angle.value);
}

/* compare.cpp*/
bool isFuzzyEqual1(double value1, double value2, double epsilon)
{
    return fabs(value1 - value2) < epsilon;
}

/*geo_comapre.cpp*/
bool isFuzzyEqual(Point one, Point two, double epsilon)
{
    return isFuzzyEqual1(one.x, two.x, epsilon) && isFuzzyEqual1(one.y, two.y, epsilon);
}

/* point.cpp*/
Point createPoint(double distance, Angle angle)
{
    return Point{distance * cos(getValueBetweenMinusPiAndPi(angle)),
                 distance * sin(getValueBetweenMinusPiAndPi(angle))};
}

double getLength(Point point)
{
    return sqrt(point.x * point.x + point.y * point.y);
}

Point addPoints(Point one, Point two)
{
    return Point{one.x + two.x, one.y + two.y};
}

Point subtractPoints(Point one, Point two)
{
    return Point{one.x - two.x, one.y - two.y};
}

double distanceTo(Point one, Point two)
{
    return getLength(subtractPoints(one, two));
}

Point multiplyPoint(Point point, double factor)
{
    return Point{point.x * factor, point.y * factor};
}

void rotate(Point &point, Angle angle)
{
    double angleValue = getValueBetweenMinusPiAndPi(angle);
    double xVal = point.x * cos(angleValue) - point.y * sin(angleValue);
    double yVal = point.x * sin(angleValue) + point.y * cos(angleValue);
    point.x = xVal;
    point.y = yVal;
}
/* note*/
Angle createAngle(Point start, Point end)
{
    Point positionDifference = subtractPoints(end, start);
    return Angle{fixAngleRange(atan2(positionDifference.y, positionDifference.x))};
}
/* line.cpp*/
Line createLine(Point start, Angle angle, double distance)
{
    return Line{start, addPoints(start, createPoint(distance, angle))};
}

Angle getDirection(Line line)
{
    return createAngle(line.start, line.end);
}

double roundoff(double value)
{
    return round(value * 1000.0) / 1000.0;
}

double getLengthl(Line line)
{
    return distanceTo(line.start, line.end);
}

void shiftParallel(Line &line, Point point)
{
    Point direction = subtractPoints(line.end, line.start);
    line.start = point;
    line.end = addPoints(line.start, direction);
}

/* point_test.cpp*/
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

/*line test*/
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
    testCreatePointExpectTrue();
    testIsEqualExpectTrue();
    testGetLengthExpectTrue();
    testDistanceToExpectTrue();
    testSubtracPointsExpectTrue();
    testAddPointsExpectTrue();
    testMultiplyPointExpectTrue();
    testRotateExpectTrue();
    testCreateLineExpectTrue();
    testGetDirectionExpectTrue();
    testGetLengthLineExpectTrue();
    testShiftParallelExpectTrue();
    return EXIT_SUCCESS;
}