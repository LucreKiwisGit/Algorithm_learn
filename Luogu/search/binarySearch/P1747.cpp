/*
    好奇怪的游戏

    ·广度搜索
*/
#include<iostream>
#include<queue>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;

typedef struct{
    int x;
    int y;
}Position;

int vis[21][21];
//十二个方向移动的位移
int dx[12] = {-2, -2, -1, 1, 2, 2, -2, -2, -1, 1, 2, 2};
int dy[12] = {-1, -2, -2, -2, -2, -1, 1, 2, 2, 2, 2, 1};

bool InPlate(Position pos)
{
    if(pos.x >= 1 && pos.y >= 1 && pos.x <= 20 && pos.y <=20)
        if(vis[pos.x - 1][pos.y - 1] == -1)
            return true;
    return false;
}

int bfs(Position pos)
{
    memset(vis, -1, sizeof(vis));
    queue<Position> q;
    q.push(pos);
    vis[pos.x - 1][pos.y - 1] = 0;
    while(!q.empty())
    {
        Position cur = q.front();
        q.pop();
        Position next;
        for(int i=0;i < 12;i++)
        {
            next.x = cur.x + dx[i];
            next.y = cur.y + dy[i];
            if(InPlate(next))
            {
                vis[next.x - 1][next.y - 1] = vis[cur.x - 1][cur.y - 1] + 1;
                q.push(next);
            }
            if(next.x == 1&&next.y == 1)
                return vis[0][0];
        }
    }
    return -1;
}

int main()
{
    Position white_horse,black_horse;
    cin>>black_horse.x>>black_horse.y;
    cin>>white_horse.x>>white_horse.y;
    cout<<bfs(black_horse)<<endl;
    cout<<bfs(white_horse);
}