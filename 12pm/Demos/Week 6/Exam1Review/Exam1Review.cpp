// Exam1Review.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <time.h>

using namespace std;

typedef unsigned int uint;

typedef void(*fpTydeDef)(int*, int);

void printArray(int* nums, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << nums[i] << " ";
    }
    cout << endl;
//    nums[2] = 42;
}

void printMin(int* nums, int size)
{
    int min = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (nums[i] < min)
        {
            min = nums[i];
        }
    }
    cout << "Min: " << min << endl;
}

int* createArray()
{
    uint tmp = 5;
    int x[4] = { 6, 7, 8, 9 };
    return x;
}

void passByVal(uint param)
{
    param = 42;
}

void passByRef(uint& param)
{
    param = 42;
}

void passByPtr(uint* param)
{
    *param = 42;
}



int main()
{
    rand();
    srand(32);
    srand(time(NULL));

    uint a = 1;
    uint b = 2;
    uint c = 3;

    passByVal(a);
    passByRef(b);
    passByPtr(&c);

    std::cout << "a: " << a << std::endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;


    int n[4] = { 12, 56, 2, 9 }; // stack
    //int* n = createArray();

    //void(*fpVarName)(int*, int);

    fpTydeDef fpVarName;

    fpVarName = printArray;
    fpVarName = printMin;
    //printArray(n, 4);
    //printMin(n, 4);

    fpVarName(n, 4);

    for (int i = 0; i < 4; i++)
    {
        cout << n[i] << " ";
    }


}
