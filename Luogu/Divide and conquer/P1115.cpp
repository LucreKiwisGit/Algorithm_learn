/*
    最大子段和
*/
#include<stdlib.h>
#include<stdio.h>
#include<iostream>

using namespace std;

int main()
{
    int list_len;  //列表长度
    cin>>list_len;
    int list[list_len+1];
    for(int i=1;i <= list_len;i++)
        cin>>list[i];
    int dp[list_len];   //dp[i]代表以list[i]结尾的最大子段和
    dp[0] = 0;
    int maxSum = -10000;
    for(int i=1;i <= list_len;i++)
    {
        dp[i] = dp[i-1] + list[i] > list[i] ? dp[i-1] + list[i] : list[i];
        maxSum = maxSum > dp[i] ? maxSum : dp[i];
    }
    
    cout<<maxSum;
    return 0;
}