#include "pose.h"
#include "angle.h"
#include "geo_compare.h"

#include <cassert>
#include <cstdlib>

// LMT_SEL_BEGIN
void testIsFuzzyEqual1ExpectTrue() //1
{
    Point one;
    one.x = 4.25
    one.y = 3.5

    Point two;
    two.x = 4.25
    two.y = 3.5

    double epsilon = 0.00001
    
    bool result = isFuzzyEqual(Point one, Point two, double epsilon);
    assert(result == true);
}

void testIsFuzzyEqual2ExpectTrue() //2
{
    Angle one;
    one.value = 3.14

    Angle two;
    two.value = 3.14

    double epsilon = 0.00001
    
    bool result = isFuzzyEqual(Angle one, Angle two, double epsilon);
    assert(result == true);
}

void testIsFuzzyEqual3ExpectTrue() //3
{
    Pose one;
    one.position.x = 1.25
    one.position.y = 2.55

    one.orientation.value =

    Pose two;
    two.position.x = 1.25
    two.position.y = 2.55

    two.orientation.value =

    double epsilon = 0.00001
    
    bool result = isFuzzyEqual(Pose one, Pose two, double epsilon);
    assert(result == true);
}
// LMT_SEL_END

int main(int /*argc*/, char** /*argv*/)
{
    // Run all test functions
    // LMT_SEL_BEGIN
    testIsFuzzyEqual1ExpectTrue() //1
    testIsFuzzyEqual2ExpectTrue() //2
    testIsFuzzyEqual3ExpectTrue() //3
    // LMT_SEL_END

    return EXIT_SUCCESS;
}