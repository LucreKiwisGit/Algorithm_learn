/*
    三角形分类
*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
using namespace std;

bool is_triangle(int a, int b, int c)
{
    if(a >= b + c)
        return false;
    return true;  
}

bool is_rightangle(int a,int b, int c)
{
    if(a * a == b * b + c * c)
        return true;
    return false;
}

bool is_Acutetriangle(int a, int b,int c)
{
    if(a * a < b * b + c * c)
        return true;
    return false;
}

bool is_Isoscelestriangle(int a, int b,int c)
{
    if(a == b || b == c)
        return true;
    return false;
}

int main()
{
    int a, b, c;
    cin>>a>>b>>c;
    if(c >= b && c >= a)
    {
        int temp = a;
        a = c;
        c = temp;
    }
    if(b >= a && b >= c)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    if(!is_triangle(a, b, c))
    {
        cout<<"Not triangle"<<endl;
        return 0;
    }
    else{
        if(is_rightangle(a, b, c))
            cout<<"Right triangle"<<endl;
        else if(is_Acutetriangle(a, b, c))
            cout<<"Acute triangle"<<endl;
        else cout<<"Obtuse triangle"<<endl;

        if(is_Isoscelestriangle(a, b, c)){
            cout<<"Isosceles triangle"<<endl;
            if(a ==b && b == c)
            cout<<"Equilateral triangle";
        }    
    }

    return 0;
}