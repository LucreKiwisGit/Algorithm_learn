/*
    统计单词数
*/

#include<string>
#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
#include<iostream>
using namespace std;


int main()
{
    string s1,s2;
    int times_match = 0;
    int first_match = -1;
    getline(cin,s1);
    getline(cin,s2);
    s2 += ' ';
    s2 = ' ' + s2;
    transform(s1.begin(),s1.end(),s1.begin(),::tolower);
    transform(s2.begin(),s2.end(),s2.begin(),::tolower);
    int str_len = s1.size();
    int str_len2 = s2.size();
    for(int i=0;i < s2.size();i++)
    {
        if(s2[i] != ' ')
        {
            int j = 0;
            for(;j < str_len;j++)
            {
                if(s1[j] != s2[i])
                    break;
                i++;
            }
            if(j == str_len&&s2[i]==' '&&s2[i - str_len - 1]==' ')
            {
                if(first_match == -1)
                    first_match = i - str_len - 1;
                times_match++;
            }
        }
    }
    if(first_match == -1)
        cout<<-1;
    else
        cout<<times_match<<" "<<first_match;
    return 0;
}
