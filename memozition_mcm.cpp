#include<bits/stdc++.h>
using namespace std;
int t[1001][1001];
int solve(int a[],int i,int j)
{
	if(i>=j)
	return 0;
    if(t[i][j]!=-1)
	return t[i][j];
		int mn=INT_MAX;
	for(int k=i;k<=j-1;k++)
	{
		int temp=solve(a,i,k)+solve(a,k+1,j)+a[i-1]*a[k]*a[j];
			if(temp<mn)
	{
		mn=temp;
	}
	}
return t[i][j]= mn;
}
int main()
{
	int  a[]={1,2,3,4,3};
	memset(t,-1,sizeof(t));
	int n=sizeof(a)/sizeof(a[0]);
	cout<<"minimum cost :"<<solve(a,1,n-1)<<endl;//valid i=1 and j=n-1;
}

