//#pragma once

// official way to write an include guard in a header file
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
int addNums(int a, int b);
#endif

// if I do this more than once, VS grays out the one that won’t be run
// happening in preprocessing - so per source file
#ifndef FUNCTIONS_H
#define FUNCTIONS_H
int addNums(int a, int b);
#endif
