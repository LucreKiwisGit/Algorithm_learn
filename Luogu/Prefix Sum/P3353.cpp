/*
    在你窗外闪耀的星星
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;

int main()
{
    int num_star,width;
    cin>>num_star>>width;
    int pos[num_star + 1];
    int bri[num_star + 1];
    int pos_bri[100005];
    int prefix[100005];
    int max_pos=0;
    int max_sum_bri = 0;
    memset(pos_bri,0,sizeof(pos_bri));
    memset(prefix,0,sizeof(prefix));
    for(int i=1;i <= num_star;i++)
    {   

        cin>>pos[i]>>bri[i];
        pos_bri[pos[i]] += bri[i];
        max_pos = max_pos > pos[i] ? max_pos : pos[i];
    }
    for(int i=1;i <= max_pos;i++)
    {
        prefix[i] = pos_bri[i] + prefix[i-1];
        if(i < width) max_sum_bri = prefix[i]; 
        if(i >= width){
            int temp = prefix[i] - prefix[i-width];
            max_sum_bri = max_sum_bri > temp ? max_sum_bri : temp;
        }
    }
    
    cout<<max_sum_bri;

    return 0;

}