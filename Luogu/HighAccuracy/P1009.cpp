/*
    阶乘之和
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int a[101]; //存储高精度数
int b[101];

void mul(int x)
{
    int g = 0; //进位
    for(int i=1;i <= 100;i++)
    {
        a[i] = a[i] * x + g;
        g = a[i] / 10;
        a[i] = a[i] % 10;
    }
}

void add() //两个高精度数相加
{
    int g  = 0;
    for(int i=1;i <= 100;i++)
    {
        b[i] = a[i] + b[i] + g;
        g = b[i] / 10;
        b[i] = b[i] % 10;
    }
}

int main()
{
    int n;
    cin>>n;
    for(int i=1;i <= 100;i++)
    {
        a[i] = 0;
        b[i] = 0;
    }
    b[1] = 1;
    a[1] = 1;
    for(int i=2;i <= n;i++)
    {
        mul(i);
        add();
    }
    for(int i=100;i >= 1;i--)
    {
        if(b[i] != 0)
            {
                for(int j=i;j >= 1;j--)
                    cout<<b[j];
                return 0;
            }  
    }
}