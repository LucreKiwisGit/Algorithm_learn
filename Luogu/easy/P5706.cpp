/*
    再分肥宅水
*/
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main()
{
    float t;
    int n;
    scnaf("%f %d",&t,&n);
    printf("%.3f\n%d",t/n,2*n);
}