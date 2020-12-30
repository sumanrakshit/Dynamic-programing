#include<bits/stdc++.h>
using namespace std;
int solve(int a[],int i,int j)
{
	if(i>=j)
	return 0;
	int mn=INT_MIN;
	for(int k=i;k<=j-1;k++)
	{
		int temp=solve(a,i,k)+solve(a,k+1,j)+a[i-1]*a[k]*a[j];
			if(temp>mn)
	{
		mn=temp;
	}
	}
return mn;
}
int main()
{
	int  a[]={1,3,1,5,8,1};
	int n=sizeof(a)/sizeof(a[0]);
	cout<<"minimum cost :"<<solve(a,1,n-1)<<endl;//valid i=1 and j=n-1;
}

