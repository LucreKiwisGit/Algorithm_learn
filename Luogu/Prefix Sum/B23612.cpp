/*
    求区间和。
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

int main()
{
    int n;  //数列长度
    cin>>n;
    int number[n+1];    //数列
    int prefix[n+1];    //前缀和
    prefix[0] = 0;
    for(int i=1;i <=n;i++)
    {
        cin>>number[i];
        prefix[i] = number[i] + prefix[i-1];
    }
    
    int m; //区间个数
    cin>>m;
    int left,right;
    for(int i=1;i <= m;i++)
    {
        cin>>left>>right;
        int sum = prefix[right] - prefix[left-1];
        cout<<sum<<endl;   
    }
    return 0;
}