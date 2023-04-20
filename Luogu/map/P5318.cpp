/*
    P5318 查找文献

    图的遍历
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<string.h>
using namespace std;

vector<int> arcNode[100010];
int n,m;
bool vis[100010];

void addEdge(int a,int b)
{
    arcNode[a].push_back(b);
    return ;
}

void dfs(int cur)
{
    cout<<cur<<" ";
    int len = arcNode[cur].size();
    for(int i=0;i < len;i++)
    {
        if(vis[arcNode[cur][i]] == true)
            continue;
        vis[arcNode[cur][i]] = true;
        dfs(arcNode[cur][i]);
    }
    return ;
}

void bfs()
{
    queue<int> q;
    memset(vis,false,sizeof(vis));

    q.push(1);
    vis[1] = true;

    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        cout<<cur<<" ";

        int len = arcNode[cur].size();
        for(int i=0;i < len;i++)
        {
            if(vis[arcNode[cur][i]] == true)
                continue;
            q.push(arcNode[cur][i]);
            vis[arcNode[cur][i]] = true;
        }
    }
    return ;
}

int main()
{
    cin>>n>>m;
    int a,b;
    for(int i=1;i <= m;i++)
    {
        cin>>a>>b;
        addEdge(a,b);
    }
    for(int i=1;i <= n;i++)
    {
        sort(arcNode[i].begin(),arcNode[i].end());
    }

    memset(vis,false,sizeof(vis));
    vis[1] = true;
    dfs(1);
    cout<<endl;
    bfs();
    return 0;
}