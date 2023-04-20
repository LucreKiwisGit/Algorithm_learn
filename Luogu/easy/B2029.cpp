/*
    大象喝水
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
using namespace std;
#define PI acos(-1)

int main()
{
    int h,r;
    cin>>h>>r;
    double V;
    V = h * PI * r * r;
    double num;
    num = 20000 / V;
    cout<<(int)num + 1;
    return 0;
}