/*
    歌唱比赛
    
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int maxSumvalue = 0;
    for(int i=1;i <= n; i++)
    {   
        int value;
        int sumValue=0;
        int max_value=0,min_value=10;
        for(int j=1; j <= m;j++)
        {
            cin>>value;
            max_value = max(max_value, value);
            min_value = min(min_value, value);
            sumValue += value;
        }
        sumValue -= max_value;
        sumValue -= min_value;
        maxSumvalue = max(maxSumvalue, sumValue);
    }
    float maxAverageValue = float(maxSumvalue) / (m - 2);
    printf("%.2f",maxAverageValue);
    return 0;
}