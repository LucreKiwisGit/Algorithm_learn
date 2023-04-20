/*
    质数口袋
*/
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<iostream>
using namespace std;

bool isPrime(int num)
{
    if(num == 2) return true;
    int l = sqrt(num);
    for(int i=2;i <= l;i++)
    {
        if(num % i == 0) return false;
    }
    return true;
}

int main()
{
    int L;
    cin>>L;
    int sum = 0;
    int num = 0;
    for(int i = 2;i <= L;i++)
    {
        if(sum + i > L) break;
        if(isPrime(i))
        {
            sum += i;
            num++;
            cout<<i<<endl;
        }
    }
    cout<<num;
}