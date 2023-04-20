/*
    方块转换：Transformations
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

char ori[11][11];
char tar[11][11];
int n;

bool transform_turn90(char ori[][11]=ori)
{
    /*
        顺时针转九十度。
        ori[i][j] --> tar[j][n - 1 -i]
    */
    for(int i=0;i < n;i++)
    {
        for(int j=0;j < n;j++)
        {
            if(ori[i][j] != tar[j][n - 1 - i])
                return false;
        }
    }    
    return true;
}

bool transform_turn180(char ori[][11]=ori)
{
    /*
        顺时针转一百八十度。
        ori[i][j] --> tar[n - 1 - i][n - 1 - j]
    */
    for(int i=0;i < n;i++)
    {
        for(int j=0;j < n;j++)
        {
            if(ori[i][j] != tar[n - i - 1][n - j - 1])
                return false;
        }
    }    
    return true;
}

bool transform_turn270(char ori[][11]=ori)
{
    /*
        顺时针转二百七十度。
        ori[i][j] --> tar[n - 1 - j][i]
    */
    for(int i=0;i < n;i++)
    {
        for(int j=0;j < n;j++)
        {
            if(ori[i][j] != tar[n - 1 - j][i])
                return false;
        }
    }    
    return true;
}

bool transform_flip(char ori[][11]=ori)
{
    /*
        水平翻转
        ori[i][j] --> tar[n - 1 -i][j]
    */
   for(int i=0;i < n;i++)
    {
        for(int j=0;j < n;j++)
        {
            if(ori[i][j] != tar[i][n - 1 - j])
                return false;
        }
    }    
    return true;
}

bool transform_combiantion()
{
    /*
        先进行水平翻转,再进行顺时针旋转。
    */
    char ori_temp[11][11];
    for(int i=0;i < n;i++)
    {
        for(int j=0;j < n;j++)
        {
            ori_temp[i][j] = ori[i][n - 1 - j];
        }
    }    
    if(transform_turn90(ori_temp) || transform_turn180(ori_temp) || transform_turn180(ori_temp))
        return true;
    return false;
}

bool is_equal()
{
    /*
        是同样的矩阵。
    */
    for(int i=0;i < n;i++)
    {
        for(int j=0;j < n;j++)
        {
            if(ori[i][j] != tar[i][j])
                return false;
        }
    }    
    return true;
}

int main()
{
    cin>>n;
    //initial two matrix
    for(int i=0;i < n;i++)
    {
        for(int j=0;j < n;j++)
        {
            cin>>ori[i][j];
        }
    }
    for(int i=0;i < n;i++)
    {
        for(int j=0;j < n;j++)
        {
            cin>>tar[i][j];
        }
    }
    //对比七种转换方式
    if(transform_turn90())
        cout<<1;
    else if(transform_turn180())
        cout<<2;
    else if(transform_turn270())
        cout<<3;
    else if(transform_flip())
        cout<<4;
    else if(transform_combiantion())
        cout<<5;
    else if(is_equal())
        cout<<6;
    else cout<<7;
}