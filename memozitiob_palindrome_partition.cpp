#include<bits/stdc++.h>
using namespace std;
int t[10001][1001];
 bool ispalindrome(string s,int i,int j)
{
	if(i==j)
	return true;
	if(i>j)
	return true;
	while(i<j)
	{
		if(s[i]!=s[j])
		return false;
	i++;
	j--;	
	
	}

	return true;
 /*	if(s==string(s.rbegin(),s.rend()))
      return true;
    else
         return false;*/
}
int solve(string s,int i,int j)
{
	if(i>=j)
	return 0;
	if(ispalindrome(s,i,j)==true)
	return 0;
	if(t[i][j]!=-1)
	return t[i][j];
	int mn=INT_MAX;
	for(int k=i;k<=j-1;k++)
	{
		int temp=1+solve(s,i,k)+solve(s,k+1,j);
			if(temp<mn)
	{
		mn=temp;
	}
	}
return t[i][j]= mn;
}
int main()
{
	string s="suman";
	int n=s.size();
	memset(t,-1,sizeof(t));
	cout<<"minimum cost :"<<solve(s,0,n-1)<<endl;//valid i=0 and j=n-1;
}

