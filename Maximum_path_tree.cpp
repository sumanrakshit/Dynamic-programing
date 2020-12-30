#include<bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node* left;
	Node* right;
};
Node* newnode(int data)
{
	Node* root=new Node();
	root->data=data;
	root->left=root->right=NULL;
	return(root);
}
int solve(Node* root,int& res)
{
	if(root==NULL)
	return 0;
	int l=solve(root->left,res);
	int r=solve(root->right,res);
	int temp=max(root->data+max(l,r),root->data);
	int ans=max(temp,root->data+l+r);
	res=max(res,ans);
	return temp;
}
int main()
{
	int res=INT_MIN;
	Node* root=newnode(-10);
	root->left=newnode(9);
	root->right=newnode(20);
	root->right->left=newnode(15);
	root->right->right=newnode(7);
	//root->right->left=newnode(6);
	solve(root,res);//leetcode any noode to any node
	cout<< res;
}
