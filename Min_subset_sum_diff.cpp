 #include<bits/stdc++.h>
using namespace std;
int issubset(int a[],int sum,int n)
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
	 vector<int> v;
for(int j=0;j<(sum+1)/2;j++)
{
	if(t[n][j]==true)
	{
		v.push_back(j);
	}
}

int mn=INT_MAX;
for(int i=0;i<v.size();i++)

	mn= min(mn,sum-(2*v[i]));
	//cout<<mn<<endl;

  return mn;//don't understand why this happen?...its clear;
//cout<<mn<<endl;

	
}
int main()
{
	int a[]={1, 2,111};
	int sum=0;
	int n=sizeof(a)/sizeof(a[0]);
	for(int i=0;i<n;i++)
	{
		sum+=a[i];
	}
  cout<< issubset(a,sum,n);

}
