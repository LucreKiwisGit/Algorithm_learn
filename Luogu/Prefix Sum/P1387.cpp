/*
    最大正方形：

*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int s[n+1][m+1];
    for(int i=1;i <= n;i++)
        for(int j=1;j <= m;j++)
            cin>>s[i][j];

    //计算前缀和，preSum[i][j]表示以【0，0】、【i，j】对角的正方形内包含的所有元素和。
    int preSum[n+1][m+1];
    for(int i=0;i <= n;i++)
        for(int j=0;j <= m;j++)
            preSum[i][j] = 0;
    for(int i=1;i <= n;i++)
        for(int j=1;j <= m;j++)
            preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] - preSum[i-1][j-1] + s[i][j];
    
    //判断以【i,j】为右下角且边长为l的正方形是否存在
    int l = 2;
    while(l <= min(n,m))
    {
        bool isFind = false; //标识有无找到边长为l的正方形
        for(int i=l;i <= n;i++)
            for(int j=l;j <= m;j++){
                if(preSum[i][j] - preSum[i-l][j] - preSum[i][j-l] + preSum[i-l][j-l] == l * l)
                {
                    isFind = true;
                    break;
                }
            }
        if(!isFind){
            cout<<l-1;
            return 0;
        }
        l++;
    }
}