#include<algorithm>
#include<iostream>
#include<math.h>
using namespace std;

long long int n,x,y;

long long int to_gbs(long long int a,long long int b)
{
    long long int min_v = min(a,b);
    long long int max_v = max(a,b);
    // for(int i=1;;i++)
    // {
    //     if(min_v * i % max_v == 0)
    //         return min_v * i / x;
    // }
    // for(int i=sqrt(min_v);i>=1;i--)
    // {
    //     if(min_v % i ==0 && max_v % i == 0)
    //         return (max_v / i) * min_v / x;
    // }
    //辗转相除法
    long long int t = 1;
    long long int m = max_v;
    long long int n = min_v;
    while(t > 0) b            
    {
        t = m % n;
        if(t == 0)
            break;
        m = n;
        n = t;
    }
    return max_v * min_v / n / a;
}

int main()
{
    int t;
    cin>>t;
    for(int j=1;j <= t;j++)
    {
        cin>>n>>x>>y;
        long long int max_distance = (n - 1);
        long long int gbs = to_gbs(x,y);
        cout<<max_distance / gbs + 1;
    }
    return 0;
}