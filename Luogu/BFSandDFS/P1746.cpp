/*
	搜索
	
	P1746 离开中山路 
*/ 
#include<iostream>
#include<string.h>
#include<queue> 
#include<algorithm>
using namespace std;

typedef struct{
	int x,y;
	int step;
}Node;

int dx[5] = {0, 0, 1, -1};
int dy[5] = {1, -1, 0, 0};

int n;
bool map_s[1005][1005];
int x1,y1,x2,y2;
queue<Node> q;

bool vis[1005][1005]; //标记是否已经来过 

int bfs()
{
	Node next_node, cur;
	int next_x,next_y;	
	
	while(!q.empty()) 
	{
		cur = q.front();
		q.pop();
		for(int k=0;k < 4;k++)
		{
			next_x = cur.x + dx[k];
			next_y = cur.y + dy[k];
			if(next_x >= 1&&next_x <= n&&next_y >=1&&next_y <= n)
			{
				if(map_s[next_x][next_y]||vis[next_x][next_y])
					continue;
				if(next_x == x2&&next_y == y2)
				{
					cout<<cur.step + 1;
					return 0;
				}
				next_node.x = next_x;
				next_node.y = next_y;
				next_node.step = cur.step + 1;
				q.push(next_node);
				vis[next_x][next_y] = true;
			}
		}
	}
}
 
int  main()
{
	cin>>n;
	memset(map_s,false,sizeof(map_s));
	memset(vis,false,sizeof(vis)); 
	string s;
	for(int i=1;i <= n;i++)
	{
		cin>>s;
		for(int j=0;j <= n-1;j++)
		{
			if(s[j] == '0')
				map_s[i][j+1] = 0;
			else map_s[i][j+1] = 1; 
		}
	}
	cin>>x1>>y1>>x2>>y2; 
	
	Node begin;
	begin.x = x1;
	begin.y = y1;
	begin.step = 0;
	
	q.push(begin);
	
	bfs();
	
}