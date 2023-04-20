/*
    高精度除法
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;

int a[5001];
int d[5001];

void div(int b)
{
    long long int d = 0;
    bool start = false;
    for(int i=5001;i >= 1;i--)
    {
        if(a[i] > 0)
        {
            for(int j=i;j >= 1;j--)
            {
                d = d + a[j];
                if(d / b != 0) start = true;
                if(start)
                    cout<<d / b;
                d = d % b;
                d *= 10;
            }
            break;
        }
    }
}

int main()
{
    int b;
    char s[5001];
    cin>>s>>b;
    for(int i=1;i <= 5001;i++)
    {
        a[i] = 0;
        d[i] = 0;
    }
    if(strlen(s) == 1&&s[0] == '0')
    {
        cout<<"0";
        return 0;
    }
    for(int i=strlen(s);i >= 1;i--)
        a[i] = (int)(s[strlen(s) - i] - '0');
    div(b);
    return 0;
}