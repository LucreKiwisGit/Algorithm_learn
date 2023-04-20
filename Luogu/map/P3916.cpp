/*
    P3916 图的遍历

    反向建边
*/
#include<iostream>
#include<vector>
#include<string.h>
#include<queue>
using namespace std;

int n,m;
vector<int> re_edges[100005]; //反向图
bool vis[100005];
int num = 0;
int A[100005];

void bfs(int k)
{
    queue<int> q;
    if(vis[k] == true)
        return;
    q.push(k);
    vis[k] = true;
    A[k] = k;
    num++;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        int len = re_edges[cur].size();
        for(int i=0;i < len;i++)
        {
            if(vis[re_edges[cur][i]] == false)
            {
                vis[re_edges[cur][i]] = true;
                A[re_edges[cur][i]] = k;
                q.push(re_edges[cur][i]);
                num++;
            }
        }
    }
}

int main()
{
    cin>>n>>m;

    int v1,v2;
    for(int i=1;i <= m;i++)
    {
        cin>>v1>>v2;
        re_edges[v2].push_back(v1);
    }

    memset(vis,false,sizeof(vis));
    
    for(int i=n;num < n;i--)
        bfs(i);
    for(int i=1;i <= n;i++)
        cout<<A[i]<<" ";
    return 0;
}