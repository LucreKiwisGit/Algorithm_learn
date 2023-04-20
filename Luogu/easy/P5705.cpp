/*
    数字反转
*/
#include<stdio.h>
#include<stdlib.h>
#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

int main()
{
    string num;
    // num = "172.3";
    cin>>num;
    reverse(num.begin(), num.end());
    cout<<num;   
}