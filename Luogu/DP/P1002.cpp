/*
    过河卒：
        由于卒子只能向右或者向左走，因此dp[i][j] = dp[i-1][j] + dp[i][j-1];
        这里的dp[i][j]代表从[0,0]出发到[i,j]的路径个数。
*/
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Position
{
    int col;
    int row;
};

int vec[25][25];
int dp[25][25];
Position target;
Position horse;
int n,m;

bool isInPosition(int row, int col)
{
    if(row < 0 || row > n || col < 0 || col > m)
        return false;
    return true;
}

int main()
{
    cin>>target.row>>target.col>>horse.row>>horse.col;
    int n = target.row;
    int m = target.col;

    //初始化格子
    for(int i=0;i <= n;i++)
        for(int j=0;j <= m;j++)
        {
            vec[i][j] = -1;
            dp[i][j] = 0;
        }
    // 标记马能达到的位置
    int row = horse.row + 1;
    int col = horse.col + 2;
    if(isInPosition(row, col))  vec[row][col] = 0;
    row = horse.row + 1;
    col = horse.col - 2;
    if(isInPosition(row, col))  vec[row][col] = 0;
    row = horse.row - 1;
    col = horse.col + 2;
    if(isInPosition(row, col))  vec[row][col] = 0;
    row = horse.row - 1;
    col = horse.col - 2;
    if(isInPosition(row, col))  vec[row][col] = 0;
    row = horse.row + 2;
    col = horse.col + 1;
    if(isInPosition(row, col))  vec[row][col] = 0;
    row = horse.row + 2;
    col = horse.col - 1;
    if(isInPosition(row, col))  vec[row][col] = 0;
    row = horse.row - 2;
    col = horse.col + 1;
    if(isInPosition(row, col))  vec[row][col] = 0;
    row = horse.row - 2;
    col = horse.col - 1;
    if(isInPosition(row, col))  vec[row][col] = 0;

    dp[0][0] = 1;

    for(int i=0;i <= n;i++)
        for(int j=0;j <= m;j++)
        {
            if(vec[i][j] == -1){
                int min = 9999;
                if(i > 0)  min = dp[i-1][j];
                if(j > 0)  min = dp[i][j-1] < min ? dp[i][j-1] : min;
                if(min < 9999) dp[i][j] = min + 1;
            }
        }

}