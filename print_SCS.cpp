#include<bits/stdc++.h>
using namespace std;
string SCS( string x,string y,int n ,int m)
{
	int t[n+1][m+1];
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<m+1;j++)
		{
			if(i==0)
			t[i][j]= j;
		else if(j==0)
			t[i][j]=i;
			
			 else if(x[i-1]==y[j-1])
		t[i][j]= 1 + t[i-1][j-1];
			else
			t[i][j]= 1 + min(t[i][j-1],t[i-1][j]);
			
		}
	}
	
  
	string s;
	int i=n;
	int j=m;
		while(i>0 && j>0)
	{
		if(x[i-1]==y[j-1])
		{
			s.push_back(x[i-1]);
			i--;
			j--;
			
		}
	
		
			 	else if(t[i][j-1]<t[i-1][j])
			{
				s.push_back(y[j-1]);
				j--;
				
			}
			else
			{
				s.push_back(x[i-1]);
				i--;
				index--;
			}
		
}
while(i>0)

{
	s.push_back(x[i-1]);
	i--;
		
}
		while(j>0)
		{
			s.push_back(y[j-1]);
			j--;
		
		}
				reverse(s.begin(),s.end());
            	cout<<s.size()<<endl;
		return s;
		
	
}
int main()
{
	string x="abcdgh";
	string y="abedfha";
	int n=x.size();
	int m=y.size();
cout<<	SCS(x,y,n,m);


	return 0;
}
