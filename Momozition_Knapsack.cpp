#include<bits/stdc++.h>
#include<iostream>
using namespace std;
int  static t[102][1001];
memset(t,-1,sizeof(t));
int Knapsack(int val[],int wt[],int w,int n)
{
	if(n==0||w==0)
	return 0;
	if(t[n][w]!=-1)
	return t[n][w];
	if(wt[n-1]<=w)
	return t[n][w]=max(val[n-1]+Knapsack(val,wt,w-wt[n-1],n-1),Knapsack(val,wt,w,n-1));
	else
	return t[n][w]=Knapsack(val,wt,w,n-1);
}
int main()
{
	int val[]={60,100,120};
	int wt[]={10,20,30};
	int w=50;
	int  n=sizeof(val)/sizeof(val[0]);
	
	cout<<Knapsack(val,wt,w,n)<<endl;
}
