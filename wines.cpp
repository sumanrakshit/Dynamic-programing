#include<bits/stdc++.h>
using namespace std;
int solve(int a[],int n)
{
	int l=0;
	int r=n-1;
	int res=0;
	for(int i=1;i<=n;i++)
	{
		if(a[l]*i+a[r]*(i+1)>a[r]*i+a[l]*(i+1))
		{
		
			res +=a[l]*i+a[r]*(i+1);
				l++;
		}
		else if(a[l]*i+a[r]*(i+1)<a[r]*i+a[l]*(i+1))
		{
			
			res +=a[r]*i+a[l]*(i+1);
			r--;
		}
		else
		{
		
			res +=a[l]*i+a[r]*(i+1);
				l++;
		}
		if(l==r)
		res +=a[l]*i;
	}
	return res;
}
int main()
{
	int a[]={2 ,4, 6, 2, 5};
	int n=sizeof(a[0])/sizeof(a);
	cout<<solve(a,n);
}
