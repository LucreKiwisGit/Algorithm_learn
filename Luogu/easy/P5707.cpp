/*
    上学迟到
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int main()
{
    int s,v;
    int min;
    cin>>s>>v;
    min = s / v;        //途中所需的走路时间
    if(s % v != 0) min++;
    min += 10;
    int hour;
    hour = min / 60;
    min = min % 60;
    if(hour < 8)
    {
        hour = 7 - hour;
        min = 60 - min;
        if(min == 60)
        {
            hour++;
            min = 0;
        }
        
    }
    else if(hour == 8 && min == 0)
    {
        hour = 0;
        min = 0;
    }
    else{
        hour = 23 - (hour - 8);
        min = 60 - min;
        if(min == 60)
        {
            hour++;
            min = 0;
        }
    }
    if(hour < 10)
        cout<<"0";
    cout<<hour<<":";
    if(min < 10)
        cout<<"0";
    cout<<min;
    return 0;
}