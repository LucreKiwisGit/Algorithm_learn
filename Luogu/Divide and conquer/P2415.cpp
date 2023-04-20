/*
    子集和

        实际上，每个元素会出现2^n-1次；
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
    long long int sum = 0;
    long long int number,num;
    num = 0;
    while (cin>>number)
    {   
        num ++;
        sum += number;
    }
    
    sum *= pow(2, num - 1);
    cout<<sum;
    return 0;
}