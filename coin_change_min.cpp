#include<bits/stdc++.h>
using namespace std;
int subset(int a[],int sum,int n)
{
	int t[n+1][sum+1];
	int count=0;
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
		if(i==0)
			t[i][j]=INT_MAX-1;
				if(j==0)
			t[i][j]=0;
			
		}
	}
	
	for(int j=1; j<sum+1;j++)
	{
		if(j%a[0]==0)
		t[1][j]=j/a[0];
		else
		t[1][j]=INT_MAX-1;
	}
	
	for(int i=2;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			if(a[i-1]<=j)
			{
				t[i][j]=min(t[i][j-a[i-1]] +1, t[i-1][j]);
			}
			else
			{
				t[i][j]=t[i-1][j];
			}
		//	count++;
			
		}
	}
	return t[n][sum];
	
}
int main()
{
	int a[]={25,10,5};
	int sum=30;
	int n=sizeof(a)/sizeof(a[0]);
	cout<<subset(a,sum,n)<<endl;
	return 0;

}
