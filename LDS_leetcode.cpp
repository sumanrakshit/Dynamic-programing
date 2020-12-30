#include<bits/stdc++.h>
using namespace std;

vector<int> largestDivisibleSubset(vector<int>& nums) {
	int n=nums.size();
	vector<int> ans;
	if(n==0)
	return ans;
	int max=1;
	vector<int>t(n+1,1);
	sort(nums.begin(),nums.end());
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(nums[i]%nums[j]==0 && t[j]+1>t[i])
			{
				t[i]=t[j]+1;
				if(max<t[i])
				max=t[i];
			}
		}
	}
		for(int i=0;i<t.size();i++)
		{
			cout<<t[i];
		}
	int prev=-1;
	for(int i=n-1;i>=0;i--)
	{
		if(max=t[i] && prev%nums[i]==0 || prev==-1)
		{
			ans.push_back(nums[i]);
			max-=1;
			prev=nums[i];
		}
	}
 for(int i=0;i<ans.size();i++)
		{
			cout<<ans[i];
		}
	//return ans;
        
    }
    int main()
    {
    	vector<int> v;
    	for(int i=0;i<4;i++)
    	{
    		v.push_back(i);
		}
    	
    //	int n=v.size();
    	largestDivisibleSubset(v);
	}
