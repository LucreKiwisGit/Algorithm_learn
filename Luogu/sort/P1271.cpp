/*
    选举学生会
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int vis[n+1];
    memset(vis, 0, sizeof(vis));
    for(int i=1;i <= m;i++)
    {
        int id;
        cin>>id;
        vis[id - 1]++;
    }
    for(int i=0;i < n;i++)
        for(int num=1;num <= vis[i];num++)
            cout<<i+1<<" ";
    return 0;
}
