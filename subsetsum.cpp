#include<bits/stdc++.h>
using namespace std;
bool issubset(int a[],int sum,int n)
{
	bool t[n+1][sum+1];
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			if(i==0)
			t[i][j]=false;
				if(j==0)
			t[i][j]=true;
			
		}
	}
	
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			if(a[i-1]<=j)
			{
				t[i][j]=t[i-1][j-a[i-1]] || t[i-1][j];
			}
			else
			t[i][j]=t[i-1][j];
		}
	}
	return t[n][sum];
	
}
int main()
{
	int a[]={3, 34, 4, 12, 5, 2};
	int sum=166;
	int n=sizeof(a)/sizeof(a[0]);
	if(issubset(a,sum,n)==true)
	{
		cout<<"YES"<<endl;
	}
	
	else
	{
			cout<<"NO"<<endl;
	}

}
