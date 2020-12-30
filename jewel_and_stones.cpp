#include<bits,stdc++.h>
using namespace std;
int solve(string j,string s)
{
	unordered_map<char,int>mp;
	for(int i=0;j[i]!='\0';++i)
	++mp[j[i]];
	int count++;
	for(int i=0;s[i]!='\0';i++)
	{
		if(mp.find(s[i])!=mp.end())
		count++;
	}
	return count;
}
