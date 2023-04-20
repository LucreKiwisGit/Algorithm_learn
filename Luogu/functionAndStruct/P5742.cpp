/*
    评等级
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<vector>
using namespace std;

typedef struct{
    string student_id;
    int grades1,grades2;
}student;

int main()
{
    vector<student> studens;
    int n;
    cin>>n;
    for(int i=1;i <= n;i++)
    {
        student a;
        cin>>a.student_id>>a.grades1>>a.grades2;
        if(a.grades1 * 7 + a.grades2 * 3 >= 800 && a.grades1 + a.grades2 > 140)
            cout<<"Excellent"<<endl;
        else cout<<"Not excellent"<<endl;
    }

    return 0;
}