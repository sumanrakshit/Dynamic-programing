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
	int a[]={1,1,1,1,1};
	int k=3;
 int sum=0;
	int n=sizeof(a)/sizeof(a[0]);
	for(int i=0;i<n;i++)
	{
	sum+=a[i];	
	}
	 int sum_s1=(k+sum)/2;
	cout<<subset(a,sum_s1,n)<<endl;
	return 0;

}
