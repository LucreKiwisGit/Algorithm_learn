/*
    液晶屏上，每个阿拉伯数字都是可以显示成 3×5的点阵的（其中 X 表示亮点，. 表示暗点）。现在给出数字位数（不超过 
    100)和一串数字，要求输出这些数字在显示屏上的效果。数字的显示方式如同样例输出，注意每个数字之间都有一列间隔。
    
    10
    0123456789
    XXX...X.XXX.XXX.X.X.XXX.XXX.XXX.XXX.XXX
    X.X...X...X...X.X.X.X...X.....X.X.X.X.X
    X.X...X.XXX.XXX.XXX.XXX.XXX...X.XXX.XXX
    X.X...X.X.....X...X...X.X.X...X.X.X...X
    XXX...X.XXX.XXX...X.XXX.XXX...X.XXX.XXX
*/
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;

char str[500][505];

bool fill_character(char number,int index)
{
    int start_index = (index - 1) * 4;
    switch (number)
    {
    case '0':
        str[0][start_index] = 'X';str[0][start_index + 1] = 'X';str[0][start_index + 2] = 'X';
        str[1][start_index] = 'X';str[1][start_index + 1] = '.';str[1][start_index + 2] = 'X';
        str[2][start_index] = 'X';str[2][start_index + 1] = '.';str[2][start_index + 2] = 'X';
        str[3][start_index] = 'X';str[3][start_index + 1] = '.';str[3][start_index + 2] = 'X';
        str[4][start_index] = 'X';str[4][start_index + 1] = 'X';str[4][start_index + 2] = 'X';
        break;
    case '1':
        str[0][start_index] = '.';str[0][start_index + 1] = '.';str[0][start_index + 2] = 'X';
        str[1][start_index] = '.';str[1][start_index + 1] = '.';str[1][start_index + 2] = 'X';
        str[2][start_index] = '.';str[2][start_index + 1] = '.';str[2][start_index + 2] = 'X';
        str[3][start_index] = '.';str[3][start_index + 1] = '.';str[3][start_index + 2] = 'X';
        str[4][start_index] = '.';str[4][start_index + 1] = '.';str[4][start_index + 2] = 'X';
        break;
    case '2':
        str[0][start_index] = 'X';str[0][start_index + 1] = 'X';str[0][start_index + 2] = 'X';
        str[1][start_index] = '.';str[1][start_index + 1] = '.';str[1][start_index + 2] = 'X';
        str[2][start_index] = 'X';str[2][start_index + 1] = 'X';str[2][start_index + 2] = 'X';
        str[3][start_index] = 'X';str[3][start_index + 1] = '.';str[3][start_index + 2] = '.';
        str[4][start_index] = 'X';str[4][start_index + 1] = 'X';str[4][start_index + 2] = 'X';
        break;
    case '3':
        str[0][start_index] = 'X';str[0][start_index + 1] = 'X';str[0][start_index + 2] = 'X';
        str[1][start_index] = '.';str[1][start_index + 1] = '.';str[1][start_index + 2] = 'X';
        str[2][start_index] = 'X';str[2][start_index + 1] = 'X';str[2][start_index + 2] = 'X';
        str[3][start_index] = '.';str[3][start_index + 1] = '.';str[3][start_index + 2] = 'X';
        str[4][start_index] = 'X';str[4][start_index + 1] = 'X';str[4][start_index + 2] = 'X';
        break;
    case '4':
        str[0][start_index] = 'X';str[0][start_index + 1] = '.';str[0][start_index + 2] = 'X';
        str[1][start_index] = 'X';str[1][start_index + 1] = '.';str[1][start_index + 2] = 'X';
        str[2][start_index] = 'X';str[2][start_index + 1] = 'X';str[2][start_index + 2] = 'X';
        str[3][start_index] = '.';str[3][start_index + 1] = '.';str[3][start_index + 2] = 'X';
        str[4][start_index] = '.';str[4][start_index + 1] = '.';str[4][start_index + 2] = 'X';
        break;
    case '5':
        str[0][start_index] = 'X';str[0][start_index + 1] = 'X';str[0][start_index + 2] = 'X';
        str[1][start_index] = 'X';str[1][start_index + 1] = '.';str[1][start_index + 2] = '.';
        str[2][start_index] = 'X';str[2][start_index + 1] = 'X';str[2][start_index + 2] = 'X';
        str[3][start_index] = '.';str[3][start_index + 1] = '.';str[3][start_index + 2] = 'X';
        str[4][start_index] = 'X';str[4][start_index + 1] = 'X';str[4][start_index + 2] = 'X';
        break;
    case '6':
        str[0][start_index] = 'X';str[0][start_index + 1] = 'X';str[0][start_index + 2] = 'X';
        str[1][start_index] = 'X';str[1][start_index + 1] = '.';str[1][start_index + 2] = '.';
        str[2][start_index] = 'X';str[2][start_index + 1] = 'X';str[2][start_index + 2] = 'X';
        str[3][start_index] = 'X';str[3][start_index + 1] = '.';str[3][start_index + 2] = 'X';
        str[4][start_index] = 'X';str[4][start_index + 1] = 'X';str[4][start_index + 2] = 'X';
        break;
    case '7':
        str[0][start_index] = 'X';str[0][start_index + 1] = 'X';str[0][start_index + 2] = 'X';
        str[1][start_index] = '.';str[1][start_index + 1] = '.';str[1][start_index + 2] = 'X';
        str[2][start_index] = '.';str[2][start_index + 1] = '.';str[2][start_index + 2] = 'X';
        str[3][start_index] = '.';str[3][start_index + 1] = '.';str[3][start_index + 2] = 'X';
        str[4][start_index] = '.';str[4][start_index + 1] = '.';str[4][start_index + 2] = 'X';
        break;
    case '8':
        str[0][start_index] = 'X';str[0][start_index + 1] = 'X';str[0][start_index + 2] = 'X';
        str[1][start_index] = 'X';str[1][start_index + 1] = '.';str[1][start_index + 2] = 'X';
        str[2][start_index] = 'X';str[2][start_index + 1] = 'X';str[2][start_index + 2] = 'X';
        str[3][start_index] = 'X';str[3][start_index + 1] = '.';str[3][start_index + 2] = 'X';
        str[4][start_index] = 'X';str[4][start_index + 1] = 'X';str[4][start_index + 2] = 'X';
        break;
    case '9':
        str[0][start_index] = 'X';str[0][start_index + 1] = 'X';str[0][start_index + 2] = 'X';
        str[1][start_index] = 'X';str[1][start_index + 1] = '.';str[1][start_index + 2] = 'X';
        str[2][start_index] = 'X';str[2][start_index + 1] = 'X';str[2][start_index + 2] = 'X';
        str[3][start_index] = '.';str[3][start_index + 1] = '.';str[3][start_index + 2] = 'X';
        str[4][start_index] = 'X';str[4][start_index + 1] = 'X';str[4][start_index + 2] = 'X';
        break;
    default:
        break;
    }
    str[0][start_index + 3] = '.';
    str[1][start_index + 3] = '.';
    str[2][start_index + 3] = '.';
    str[3][start_index + 3] = '.';
    str[4][start_index + 3] = '.';
    return true;
}

int main()
{
    int num_of_number;
    cin>>num_of_number;
    int i;
    char number[105];
    cin>>number;
    for(i=1;i <= num_of_number;i++)
    {   
        fill_character(number[i-1], i);
    }
    for(int row=0;row <= 4;row++)
    {
        for(int j=0;j < 4 * (i - 1) - 1;j++)
            cout<<str[row][j];
        cout<<endl;
    }
    return 0;
}