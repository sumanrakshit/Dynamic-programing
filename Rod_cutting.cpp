#include<bits/stdc++.h>
using namespace std;

int Knapsack(int val[],int wt[],int w,int n)
{
	int   t[n+1][w+1];
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<w+1;j++)
		{
			if(i==0||j==0)
			{
				t[i][j]=0;
			}
		}
	}
	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<w+1;j++)
		{
			if(wt[i-1]<=j)
			{
				
				t[i][j]=max(val[i-1]+t[i][j-wt[i-1]],t[i-1][j]);
			}
			else
			t[i][j]=t[i-1][j];
		}
	}
	return t[n][w];

	
}
int main()
{
	int price[]={1   ,5,   8,   9,  10,  17,  17,  20};
	int length[]={1,2,3,4,5,6,7,8};
	int w=8;
	int  n=sizeof(price)/sizeof(price[0]);
	
	cout<<Knapsack(price,length,w,n)<<endl;
}
