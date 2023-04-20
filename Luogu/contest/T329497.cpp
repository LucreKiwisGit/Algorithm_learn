#include<iostream>
using namespace std;

int main()
{
    string s;
    cin>>s;
    int num[11];
    for(int i=0;i <= 9;i++)
        num[i] = 0;
    int len = s.size();
    int t;
    for(int i=0;i < len;i++)
    {
        t = s[i] - '0';
        num[t]++;
    }
    int sum = 0;
    sum += num[2];
    sum += num[6];
    sum += num[9];
    sum += num[0];
    sum += 2 * num[8];
    cout<<sum;
    return 0;
}