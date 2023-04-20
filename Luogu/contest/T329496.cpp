#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
    int a1,p1,a2,p2;
    cin>>a1>>p1>>a2>>p2;
    bool winner_first;
    if(a1 != a2)
    {
        if(a1 > a2)
            winner_first = true;
        else
            winner_first = false;
    }
    else if(p1 != p2)
    {
        if(p1 < p2)
            winner_first = true;
        winner_first = false;
    }
    if(winner_first) cout<<"\"\\n\"";
    else cout<<"\"\\t\"";
    return 0;
}