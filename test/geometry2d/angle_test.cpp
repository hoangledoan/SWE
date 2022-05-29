#include "angle.h"

#include <cmath>

#include "geo_compare.h"
#include "point.h"

#include <cassert>
#include <cstdlib>

// LMT_SEL_BEGIN
void testFixAngleRangeExpectTrue() //1
{
    double angleValue = 3 * M_PI;
    double result = fixAngleRange(angleValue);
    assert(result == M_PI);
}

void testConvertFromDegreeToRadiantExpectTrue() //2
{
    Angle angle;
    angle.value = 180;

    Angle result = convertFromDegreeToRadiant(double angle); 
    assert(result == M_PI);
}

void testGetHalfRotationExpectTrue() //3
{
    Angle result = getHalfRotation();
    assert(result == M_PI);
}

void testGetQuarterRotationExpectTrue() //4
{
    Angle result = getQuarterRotation();
    assert(result == M_PI_2);
}

void testGetFullRotationExpectTrue() //5
{
    Angle result = getFullRotation();
    assert(result == 0);
}

void testGetEighthRotationExpectTrue() //6
{
    Angle result = getEighthRotation();
    assert(result == M_PI_4);
}

void testGetValueBetweenMinusPiAndPiExpectTrue() //7 under construction
{
    Angle angle;
    angle.value = 3 * M_PI;
    double result = getValueBetweenMinusPiAndPi(Angle angle);
    assert(result == LOL);
}

void testGetValueBetweenZeroAndTwoPiExpectTrue() //8 under construction
{
    Angle angle;
    angle.value = 3 * M_PI;
    double result = getValueBetweenZeroAndTwoPi(Angle angle);
    assert(result == LOL);
}

void testMultiplyAngleExpectTrue() //9 under construction
{
    Angle angle;
    angle.value = 3 * M_PI;

    double factor = 
    Angle result = multiplyAngle(Angle angle, double factor);
    assert(result == LOL);
}

void testAddAnglesExpectTrue() //10 under construction
{
    Angle one;
    one.value = LOL;

    Angle two;
    two.value = 

    Angle result = addAngles(Angle one, Angle two);
    assert(result == LOL);
}

void testSubtractAnglesExpectTrue() //11 under construction
{
    Angle one;
    one.value = LOL;

    Angle two;
    two.value = 

    Angle result = subtractAngles(Angle one, Angle two);
    assert(result == LOL);
}

void testCreateAngleExpectTrue() //12 under construction
{
    Point start;
    start.x =  
    start.y =

    Point end;
    end.x = 
    end.y =

    Angle result = createAngle(Point start, Point end);
    assert(result == LOL);
}

void testIsEqualExpectTrue() //13 under construction
{
    Angle one;
    one.value = 

    Angle two;
    two.value =

    bool result = isEqual(Angle one, Angle two);
    assert(result == true);
}

void testIsObtuseExpectTrue() //14 under construction
{
    Angle angle;
    angle.value = 

    bool result = isObtuse(Angle angle);
    assert(result == true);
}

void testAbsExpectTrue() //15 under construction
{
    Angle angle;
    angle.value = 

    Angle result = abs(Angle angle);
    assert(result == LOL);
}

void testCreateAngleExpectTrue() //16 under construction
{
    Point source;
    source.x = 
    source.y =

    Point targetOne;
    targetOne.x = 
    targetOne.y =

    Point targetTwo;
    targetTwo.x = 
    targetTwo.y =

    Angle result = createAngle(Point source, Point targetOne, Point targetTwo);
    assert(result == LOL);
}
// LMT_SEL_END

int main(int /*argc*/, char** /*argv*/)
{
    // Run all test functions
    // LMT_SEL_BEGIN
    testFixAngleRangeExpectTrue(); //1
    testConvertFromDegreeToRadiantExpectTrue() //2
    testGetHalfRotationExpectTrue() //3
    testGetQuarterRotationExpectTrue() //4
    testGetFullRotationExpectTrue() //5
    testGetEighthRotationExpectTrue() //6
    testGetValueBetweenMinusPiAndPiExpectTrue() //7
    testGetValueBetweenZeroAndTwoPiExpectTrue() //8
    testMultiplyAngleExpectTrue() //9
    testAddAnglesExpectTrue() //10
    testSubtractAnglesExpectTrue() //11
    testCreateAngleExpectTrue() //12
    testIsEqualExpectTrue() //13
    testIsObtuseExpectTrue() //14
    testAbsExpectTrue() //15
    testCreateAngleExpectTrue() //16
    // LMT_SEL_END

    return EXIT_SUCCESS;
}