#include<algorithm>
#include<iostream>
using namespace std;

long long int n,x,y;

long long int to_gbs(long long int a,long long int b)
{
    long long int min_v = min(a,b);
    long long int max_v = max(a,b);
    for(int i=1;;i++)
    {
        if(min_v * i % max_v == 0)
            return min_v * i;
    }
}

int main()
{
    cin>>n>>x>>y;
    long long int max_distance = (n - 1) * x;
    long long int gbs = to_gbs(x,y);
    cout<<max_distance / gbs + 1;
    return 0;
}