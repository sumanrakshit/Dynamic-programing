#include<bits/stdc++.h>
using namespace std;
int t[1001][1001];
int solve(int e,int f)
{
	if(e==1)
	return f;
	if(f==0||f==1)
	return f;
	int mn=INT_MAX;
	int low,high;
	for(int k=1;k<=f;k++)
	{
		if(t[e-1][k-1]!=-1)
		{
			low=t[e-1][k-1];
		}
		 
		else
		{
			low=solve(e-1,k-1);
			t[e-1][k-1]=low;
		}
		if(t[e][f-k]!=-1)
		{
			high=t[e][f-k];
		}
		else
		{
			high=solve(e,f-k);
			t[e][f-k]=high;
		}
		
		int temp=1+max(low,high);
		mn=min(temp,mn);
	}
	return t[e][f]= mn;
}
int main()
{
	int e=2;
	int f=10;
	memset(t,-1,sizeof(t));
	cout<<"minimum number of attemptin worst case:"<<"-> "<< solve(e,f)<<endl;
}
