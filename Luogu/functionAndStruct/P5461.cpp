/*
    赦免战俘
*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
using namespace std;

bool vis[2050][2050];
int n;

void dfs(int width,int start_row,int start_col)
{
    if(width == 0)
        return;
    //赦免左上角的方阵中的作弊者
    for(int i=start_row;i < start_row + width;i++)
    {
        for(int j=start_col;j < start_col + width;j++)
            vis[i][j] = 0;
    }

    dfs(width / 2, start_row, start_col + width);
    dfs(width / 2, start_row + width, start_col);
    dfs(width / 2, start_row + width, start_col + width);
}

int main()
{
    cin>>n;
    memset(vis,1,sizeof(vis));
    int width = 2 << (n - 1);
    dfs(width / 2, 0, 0);
    for(int i = 0;i < width;i++)
    {
        for(int j = 0;j < width;j++)
        {
            cout<<vis[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}