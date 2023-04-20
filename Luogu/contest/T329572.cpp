#include<iostream>
#include<stdio.h>
using namespace std;

int winner[20];

int main()
{
    int p_id=1,q_id=2;
    int p,q;
    string s;
    for(int i=1;i <= 8;i++)
    {
        scanf("%d-%d",&p,&q);
        if(p > q) winner[i] = p_id;
        else winner[i] = q_id;
        p_id += 2;
        q_id += 2;
    }
    for(int i=9;i <= 15;i++)
    {
        p_id = winner[16 - ((16 - i) * 2 + 1)];
        q_id = winner[16 - ((16 - i) * 2)];
        scanf("%d-%d",&p,&q);
        if(p > q) winner[i] = p_id;
        else winner[i] = q_id;
    }
    char final_winner = (char)('A' + winner[15] - 1);
    cout<<final_winner;
    return 0;
}