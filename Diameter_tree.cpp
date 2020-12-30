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
	int temp=1+max(l,r);
	int ans=max(temp,1+l+r);
	res=max(res,ans);
	return temp;
}
int main()
{
	int res=INT_MIN;
	Node* root=newnode(1);
	root->left=newnode(2);
	root->right=newnode(3);
	root->left->left=newnode(4);
	root->left->right=newnode(5);
	root->right->left=newnode(6);
	solve(root,res);
	cout<< res-1;
}
