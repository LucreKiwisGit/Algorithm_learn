/*
	Meteor Shower S
	
	深度搜索、广度搜索 
	
*/
#include<iostream>
#include<queue> 
#include<string.h>
using namespace std;
#define INF 9999999

int M;
int meteor[305][305];		//-1表示没有陨石波及，否则则为时间t波及 
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

typedef struct{
	int time_spend; //花费的时间 
	int x,y;	//位置坐标 
}Node;

int bfs()
{
	if(meteor[0][0] == INF)
		return 0;
	queue<Node> q;
	Node start;
	start.x = 0;
	start.y = 0;
	start.time_spend = 0;
	q.push(start);
	
	while(!q.empty())
	{
		Node cur = q.front();
		q.pop();
		Node next;
		for(int k=0;k < 4;k++)
		{
			int x = cur.x;
			int y = cur.y;
			x += dx[k];
			y += dy[k];
			if(x >= 0 && x <= 300 && y >= 0 &&y <= 300)
			{
				if(meteor[x][y] == INF)
					return cur.time_spend + 1;
				if(meteor[x][y] > cur.time_spend + 1)
				{
					next.time_spend = cur.time_spend + 1;
					next.x = x;
					next.y = y;
					q.push(next);
				}
			 } 
		}
	}
	return -1;
}


int main()
{
	cin>>M;
	for(int i=0;i <= 300;i++)
		for(int j=0;j <= 300;j++)
			meteor[i][j] = INF;
	for(int i=1;i <= M;i++)
	{
		int x,y,t;
		cin>>x>>y>>t;
		meteor[x][y] = min(t, meteor[x][y]);
		for(int k=0;k < 4;k++)
		{
			x += dx[k];
			y += dy[k];
			if(x >= 0 && x <= 300 && y >= 0&&y <= 300)
			{
				meteor[x][y] = min(t, meteor[x][y]);
			 } 
			x -= dx[k];
			y -= dy[k];
		}
	 } 
	
	cout<<bfs();
}