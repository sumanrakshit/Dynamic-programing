#include<bits/stdc++.h>
using namespace std;
int subset(int a[],int sum,int n)
{
	int t[n+1][sum+1];
	int count;
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
		if(i==0)
			t[i][j]=0;
				if(j==0)
			t[i][j]=1;
			
		}
	}
	
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			if(a[i-1]<=j)
			{
				t[i][j]=t[i-1][j-a[i-1]] + t[i-1][j];
			}
			else
			{
				t[i][j]=t[i-1][j];
			}
			count++;
			
		}
	}
	return t[n][sum];
	
}
int main()
{
	int a[]={10, 6, 4, 3, 5, 2};
	int sum=10;
	int n=sizeof(a)/sizeof(a[0]);
	cout<<subset(a,sum,n)<<endl;
	return 0;

}
