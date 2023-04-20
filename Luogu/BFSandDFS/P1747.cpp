/*
    好奇怪的游戏
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<queue>
using namespace std;
#define INFINITY 99999

int move[12][2] = {
    {-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1},
    {-2, 2}, {2, 2}, {2, -2}, {-2, -2}
}

typedef struct{
    int x;
    int y;
    int r;
    bool opearator<(const Node& a) const{
        return r > a.r;
    }
}Node;

int d[21][21];  //记录（i，j)到（1，1）的最短步数
int bestw1;
int bestw2;

int main()
{
    cin>>x1>>y1>>x2>>y2;

    //初始化
    for(int i=1;i <= 20;i++)
        for(int j=1;j <= 20;j++)
            d[i][j] = INFINITY;
    d[1][1] = 0;

    //利用分支限界来搜索节点,优先队列式分支限界
    //优先级定义为的d[i,j] + ||pos.x - i|| + ||pos.y - j||
    priority_queue<Node> q;


    Node cur;
    cur.x = 1;
    cur.y = 1;
    cur.r = abs(x1 - 1) + abs(y1 - 1);
    q.push(cur);
    while(!q.empty())
    {
        cur = q.top();
        q.pop();

        //generate node
        for(int i=0;i < 12;i++)
        {
            int new_x = cur.x + move[i][0];
            int new_y = cur.y + move[i][1];
            if(new_x > 0 && new_y > 0)
         }
    }

}