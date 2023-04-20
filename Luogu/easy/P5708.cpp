/*
    三角形面积
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
using namespace std;

int main()
{
    float a,b,c;
    scanf("%f %f %f",&a, &b, &c);
    double p;
    p = (a + b + c) / 2;
    double s;
    s = p * (p - a) * (p - b) * (p - c);
    s = sqrt(s);
    printf("%.1f", s);
    return 0;
}