
#include "Math.h"
#include<stdio.h>


int main()
{
    Math a;

    printf("%d\n", a.Add(22, 4));
    printf("%d\n", a.Add(2, 12, 33));
    printf("%f\n", a.Add(11.0, 2.0));
    printf("%f\n", a.Add(32.0, 11.0, 9.0));
    printf("%d\n", a.Mul(11, 2));
    printf("%d\n", a.Mul(3, 4, 5));
    printf("%f\n", a.Mul(2.0, 3.0));
    printf("%f\n", a.Mul(5.0, 2.0));
    printf("%d\n", a.Add(3, 11, 9, 8));
    printf("%s\n", a.Add("9887", "978"));
    return 0;
}
