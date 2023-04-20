/*
    快速幂||取余运算

    
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    long long int a,b,p;
    cin>>a>>b>>p;
    long long int base = a;  //a^0
    long long int t,x=b;
    long long int res=1;
    while(b > 0)
    {
        t = b % 2;
        b /= 2;
        if(t == 1)
        {
            res *= base % p;
            res %= p;
        }
        base *= base;
        base %= p;
    }
    cout<<a<<"^"<<x<<" mod "<<p<<"="<<res;

    return 0;
}