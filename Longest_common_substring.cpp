#include<bits/stdc++.h>
using namespace std;
int LCS( char x[],char y[],int n ,int m)
{
	int res=0;
	int t[n+1][m+1];
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<m+1;j++)
		{
			if(i==0||j==0)
			t[i][j]= 0;
			
			 else if(x[i-1]==y[j-1])
			 {
			 		t[i][j]= 1+t[i-1][j-1];
		res=max(res,t[i][j]);
			 }
	
			else
			t[i][j]=0;
			
		}
	}
	
	return res;
}
int main()
{
	char x[]="abcdgh";
	char y[]="abedfha";
	int n=strlen(x);
	int m=strlen(y);
	cout<<"Longest common subsequence:"<<LCS(x,y,n,m)<<endl;
	return 0;
}
