#include<bits/stdc++.h>
using namespace std;
int solve(string s,int i,int j,bool istrue)
{
	int ans=0;
	if(i>j)
	return true;
	if(i==j)
	{
		if(istrue==true)
    return s[i]=='T';
   else
    return s[i]=='F';
	}
	
	for(int k=i+1;k<=j-1;k+=2)
	{
		int lt=solve(s,i,k-1,true);
		int lf=solve(s,i,k-1,false);
		int rt=solve(s,k+1,j,true);
		int rf=solve(s,k+1,j,false);
		if(s[k]=='&')
		{
			if(istrue==true)
			{
				ans=ans+lt*rt;
				
			}
			else
			ans=ans+lf*rt+rf*lt+lf*lf;
		}
		else if(s[k]=='|')
		{
			if(istrue==true)
			ans=ans+lf*rt+lt*rf+lt*rt;
			else
			{
				ans+=lf*rf;
			}
		}
		else if(s[k]=='^')
		{
			if(istrue==true)
			{
				ans+=lf*rt+rf*lt;
				
			}
			else
			ans+=lt*rt+rf*lf;
		}
	}
	return ans;
	
}
int main()
{
	string s="T|T&F^T";
	int i=0;
	int j=s.size()-1;
	cout<<solve(s,i,j,true)<<endl;
}
