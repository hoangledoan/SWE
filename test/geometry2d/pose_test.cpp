#include "pose.h"
#include "angle.h"
#include "geo_compare.h"

#include <cassert>
#include <cstdlib>

// LMT_SEL_BEGIN
void testDistanceToExpectTrue() //1
{
    Pose one;
    one.position.x = 
    one.position.y =

    one.orientation.value =

    Pose two;
    two.position.x =
    two.position.y =

    two.orientation.value =
    
    double result = distanceTo(Pose one, Pose two);
    assert(result == LOL);
}

void testGetRelativeOrientationToExpectTrue() //2
{
    Pose source;
    source.position.x =
    source.position.y =

    source.orientation.value =

    Pose point;
    point.position.x =
    point.position.y =

    point.orientation.value =    
    
    Angle result = getRelativeOrientationTo(Pose source, Point point);
    assert(result == LOL);
}

void testIsEqualExpectTrue() //3
{
    Pose one;
    one.position.x =
    one.position.y =

    one.orientation.value =

    Pose two;
    two.position.x =
    two.position.y =

    two.orientation.value =
    
    bool result = isEqual(Pose one, Pose two);
    assert(result == LOL);
}

void testAddPosesExpectTrue() //4
{
    Pose one;
    one.position.x =
    one.position.y =

    one.orientation.value =

    Pose two;
    two.position.x =
    two.position.y =

    two.orientation.value =    
    Pose result = addPoses(Pose one, Pose two);
    assert(result == LOL);
}

void testSubtractPosesExpectTrue() //5
{
    Pose one;
    one.position.x =
    one.position.y =

    one.orientation.value =

    Pose two;
    two.position.x =
    two.position.y =

    two.orientation.value =   
    Pose result = subtractPoses(Pose one, Pose two);
    assert(result == LOL);
}

// LMT_SEL_END

int main(int /*argc*/, char** /*argv*/)
{
    // Run all test functions
    // LMT_SEL_BEGIN
    testDistanceToExpectTrue(); //1
    testGetRelativeOrientationToExpectTrue() //2
    testIsEqualExpectTrue() //3
    testAddPosesExpectTrue() //4
    testSubtractPosesExpectTrue() //5
    // LMT_SEL_END

    return EXIT_SUCCESS;
}