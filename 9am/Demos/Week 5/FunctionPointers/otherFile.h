#pragma once

typedef unsigned int uint;
typedef void(*thingFuncType)();
typedef int(*twoNumsFuncType)(int, int);

void thing();
int addNumbers(int a, int b);
int multiplyNumbers(int a, int b);

void runTwoNumsFunction(twoNumsFuncType funcPtr, int a, int b);