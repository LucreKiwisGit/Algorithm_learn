#include<iostream>
#include<string.h>
using namespace std;

//公式：(n-2)*(∑xiyi)+(∑xi)*(∑yi) 
int main() {
    int n, m;
    cin >> n >> m;
    long long number[n+1];
    int color[n+1];

    long long sum_i_num[2*m+1];
    long long sum_num[2*m+1];
    long long sum_i[2*m+1];
    int count[2*m+1];
    for (int i = 1; i <= n; i++) {
    //cin >> number[i];
    scanf("%lld",&number[i]) ;
    }
    memset(sum_num,0,sizeof(sum_num));
    memset(sum_i,0,sizeof(sum_i));
    memset(sum_i_num,0,sizeof(sum_i_num));
    memset(count,0,sizeof(count));
    for (long long i = 1; i <= n; i++) {
    //cin >> color[i];
    scanf("%d", &color[i]);
    int idx=color[i]*2-i%2;
    
    sum_i_num[idx]=(sum_i_num[idx]+(number[i]*i)%10007)%10007; 
    sum_num[idx]=(sum_num[idx]+number[i])%10007;
    sum_i[idx]=(sum_i[idx]+i)%10007;
    count[idx]++;
    }
    
    // for(int i=1;i<=2*m;i++){
    //  cout<<count[i]<<":";
    //  for(int j=0;j<20;j++){
    //   cout<<arr[i][j]<<" ";
    //  }
    //  cout<<"\n";
    // }
    
    int res = 0;
    for (int i = 1; i <= 2*m;i++) {
        if(count[i] >= 2)
            res=((res+(sum_i_num[i]*(count[i]-2))%10007)%10007+(sum_i[i]*sum_num[i])%10007)%10007;
    }
    cout << res;
    return 0;
}