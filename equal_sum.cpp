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
	int a[]={5,2,4,12};
	int n=sizeof(a)/sizeof(a[0]);
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
	}
	if(sum & 1)
	cout<<"No to found such subset"<<endl;
	else
	{
		if(issubset(a,sum/2,n)==true)
		cout<<"Yes found it";
		else
			cout<<"false"<<endl;
	}
	

	
}

