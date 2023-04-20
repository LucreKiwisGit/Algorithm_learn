/*	
	海港 
*/ 
#include<iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

typedef struct{
	int x;
	int last_time;
}gj;

vector<gj> t;
int v[100005];  //记录对应国籍的人最后一次出现的时间 

bool cmp(gj a,gj b)
{
	return a.last_time < b.last_time;
}

int binary_search(int left,int right,int v)
{
	if(right < left) return -1;
    int mid = (left + right) / 2;
	if(t[mid].last_time == v)
		return mid;
	else if(t[mid].last_time > v)
	{
		return binary_search(left, mid - 1,v); 
	}
	else{
		return binary_search(mid+1, right, v);
	}
}

int main()
{
	int n;
	cin>>n;
	memset(v,-1,sizeof(v)); 
	for(int i=1;i <= n;i++)
	{
		int t_i,k_i;
		cin>>t_i>>k_i;
		for(int j = 1;j <= k_i;j++)
		{
			int x;
			cin>>x;
			int pre_t = v[x]; //上一次国籍出现的时间 
			v[x] = t_i;
			
			//二分查找该国籍在t中的位置,并删除旧的记录 
            if(t_i - pre_t < 86400&&pre_t != -1)
            {   
                int p = binary_search(0, t.size()-1,pre_t);
                int len = t.size();
                while(p >= 0&&t[p].last_time == pre_t)
                {
                    p--;
                }
                p++;
                while(p < len&&t[p].last_time == pre_t)
                {
                    if(t[p].x == x)
                    {
                        break;
                    }
                    p++;
                }
                if(p != -1)
                    t.erase(t.begin()+p);//删掉以前的记录 
            }
			 
			// 把最新的记录存储到t的尾部，自动完成排序
			gj newgj;
			newgj.x = x;
			newgj.last_time = t_i;
            t.push_back(newgj);
		}
		int len = t.size();
		for(int k=0;k < len;k++)
		{
			if(t_i - t[k].last_time < 86400)
			{
				t.erase(t.begin(), t.begin() + k);
				break;
			}
		 } 
		cout<<t.size()<<endl;
        // cout<<t.capacity()<<endl;
	}
    return 0;
 } 