#pragma once
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

class Math
{
public:
    ///Math(char* a, char* b);
    static int Add(int, int);
    static int Add(int, int, int);
    static double Add(double, double);
    static double Add(double, double, double);
    static int Mul(int, int);
    static int Mul(int, int, int);
    static double Mul(double, double);
    static double Mul(double, double, double);
    static int Add(int count, ...); // sums up a list of integers
    static char* Add(const char*, const char*);
};
