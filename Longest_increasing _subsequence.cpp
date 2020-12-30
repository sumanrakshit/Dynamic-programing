#include<bits/stdc++.h>
using namespace std;
int LCS( int x[],int y[],int n ,int m)
{
	int t[n+1][m+1];
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<m+1;j++)
		{
			if(i==0||j==0)
			t[i][j]= 0;
			
			 else if(x[i-1]==y[j-1])
		t[i][j]= 1+t[i-1][j-1];
			else
			t[i][j]= max(t[i][j-1],t[i-1][j]);
			
		}
	}
	
	return t[n][m];
}
int main()
{
	int x[]={ 12, 34, 1, 5, 40, 80 }; 
	int z[1001];
	
	int n=sizeof(x)/sizeof(x[0]);
	for(int i=0;i<n;i++)
    {
      z[i]=x[i];
	
	}	
	sort(x,x+n);
	int y[1001];
	for(int i=0;i<n;i++)
	{
		y[i]=x[i];
	}

int m=sizeof(y)/sizeof(y[0]);
	cout<<"Longest common subsequence:"<<LCS(z,y,n,m)<<endl;
	return 0;
}
