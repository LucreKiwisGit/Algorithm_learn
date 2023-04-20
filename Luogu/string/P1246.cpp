/*
	编码 
*/
#include<iostream>
#include<algorithm>
#include<map>
// #include<string.h>
using namespace std;

map<string,int> mapEncode;
string s1;
int num = 0;
int l;
		
void dfs(int i)
{
	if(i == 0)
	{
		num++;
		mapEncode[s1] = num;
		return;
	}

	for(char c = l - i > 0 ? (s1[l- i - 1] + 1) : 'a';c <= 'z';c++)
	{
		s1[l - i] = c;
		dfs(i-1);
	}
}

void Encode()
{
	for(l=1;l <= 6;l++)
	{
        s1.clear();
        s1.resize(l);
		dfs(l);
	}
}

int main()
{
	Encode();
    string s;
	cin>>s;
    map<string,int>::iterator iter = mapEncode.find(s);
    if(iter != mapEncode.end())
    	cout<<mapEncode.find(s)->second;
    else cout<<0;
} 