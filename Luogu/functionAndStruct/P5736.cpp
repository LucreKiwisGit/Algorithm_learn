/*
    输入n个不大于10^5的正整数。要求全部储存在数组中，去除掉不是质数的数字，依次输出剩余的质数。
*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<cmath>
using namespace std;

bool is_prime(int num)
{
    if(num == 1) return false;
    for(int i=2;i <= sqrt(num);i++)
    {
        if(num % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    int number;
    for(int i=1;i <= n;i++)
    {
        cin>>number;
        if(is_prime(number))
            cout<<number<<" ";
    }
    return 0;
}