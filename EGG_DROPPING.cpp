#include<bits/stdc++.h>
using namespace std;
int solve(int e,int f)
{
	if(e==1)
	return f;
	if(f==0||f==1)
	return f;
	int mn=INT_MAX;
	for(int k=1;k<=f;k++)
	{
		int temp=1+max(solve(e-1,k-1),solve(e,f-k));
		mn=min(temp,mn);
	}
	return mn;
}
int main()
{
	int e=2;
	int f=10;
	cout<<"minimum number of attemptin worst case:"<<"-> "<< solve(e,f)<<endl;
}
