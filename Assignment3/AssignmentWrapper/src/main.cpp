// AssignmentWrapper.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cstdio>
#include "Assignment3StudentImpl.h"
#include "Assignment3Tests.h"

int RunAssignment3()
{
    Assignment3_1StudentImpl testObject1;
    Assignment3_2StudentImpl testObject2;
    Assignment3_3StudentImpl testObject3;
    Assignment3_4StudentImpl testObject4;
    Assignment3_5StudentImpl testObject5;
    Assignment3_6StudentImpl testObject6;
    Assignment3_7StudentImpl testObject7;

    return RunAssignment3Tests(testObject1, testObject2, testObject3, testObject4, testObject5, testObject6, testObject7);
}

int main()
{
    int failedTestCount = RunAssignment3();
    if (failedTestCount)
        printf("Failed %d tests", failedTestCount);
    else
        printf("Passed all tests");

    return failedTestCount;
}
