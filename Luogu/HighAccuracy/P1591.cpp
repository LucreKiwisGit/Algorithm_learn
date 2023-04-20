/*
    阶乘数码
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;

int number[10001]; //用于存储阶乘结果

void mul(int x)
{
    int d = 0;
    for(int i=1;i <= 10000;i++)
    {
        d = number[i] * x + d;
        number[i] = d % 10;
        d = d / 10;
    }
}

void factorial(int n)
{
    memset(number, 0, sizeof(number));
    number[1] = 1;
    for(int x=1;x <= n;x++)
    {
        mul(x);
    }
}

int main()
{
    int t;
    cin>>t;
    for(int i=1;i <= t;i++)
    {
        int n,a;
        cin>>n>>a;
        factorial(n);
        int num = 0;
        bool start = false;
        for(int i=10000;i >= 1;i--)
        {
            if(number[i] != 0)//找到最高位
            {
                for(int j=i;j >= 1;j--)
                {
                    if(number[j] == a) num++;
                }
                cout<<num<<endl;
                break;
            }
        }
    }
    return 0;
}