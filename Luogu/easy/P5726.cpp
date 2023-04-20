/*
    打分
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    float score=0;
    float c;
    float best=-1,worst=11;
    for(int i =1;i <= n;i++)
    {
        cin>>c;
        if(best < c) best = c;
        if(worst > c) worst = c;
        score += c;
    }
    
    score -= (best + worst);
    printf("%.2f",score/(n-2));
    return 0;
}