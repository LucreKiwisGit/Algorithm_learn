/*
    神奇的幻方
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;

int t[41][41];


int main()
{
    int n;
    cin>>n;
    for(int i=1;i <= n;i++)
        for(int j=1;j <= n;j++)
        {
            t[i][j] = -1;
        }
    int cur_x,cur_y;
    cur_x = 1;
    cur_y = n / 2 + 1;
    t[cur_x][cur_y] = 1;
    for(int i=2;i <= n*n;i++)
    {
        if(cur_x == 1 && cur_y != n)
        {
            cur_x = n;
            cur_y++;
            t[cur_x][cur_y] = i;
        }
        else if(cur_x != 1 && cur_y == n)
        {
            cur_x--;
            cur_y = 1;
            t[cur_x][cur_y] = i;
        }
        else if(cur_x == 1 && cur_y == n)
        {
            cur_x++;
            t[cur_x][cur_y] = i;
        }
        else{
            if(t[cur_x - 1][cur_y + 1] == -1)
            {
                cur_x--;
                cur_y++;
                t[cur_x][cur_y] = i;
            }
            else{
                cur_x++;
                t[cur_x][cur_y] = i;
            }
        }
    }
    for(int i=1;i <= n;i++)
    {
        for(int j=1;j <= n;j++)
        {
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}