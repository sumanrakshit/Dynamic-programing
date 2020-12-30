#include<bits/stdc++.h>
using namespace std;
map<string,bool>mp;
bool solve(string a,string b)
{
	if(a.compare(b)==0)
	return true;
	if(a.length()<=1)
	return false;
	int n=a.length();
	if(n==0)
	return true;
	if(a.length()!=b.length())
	{
		return false;
	}
	string copy_a = a, copy_b = b; 
  
    sort(copy_a.begin(), copy_a.end()); 
    sort(copy_b.begin(), copy_b.end()); 
  
    if (copy_a != copy_b) { 
        return false; 
    } 
	bool flag=false;
	  
  string key = a;
  key.push_back(' ');
  key.append(b);
  if(mp.find(key)!=mp.end())
  {
  	return mp[key];
  }
  else
  {
  	
	for(int i=1;i<n;i++)
	{
		if((solve(a.substr(0,i),b.substr(n-i,i))==true && solve(a.substr(i,n-i),b.substr(0,n-i))==true) ||
		 (solve(a.substr(0,i),b.substr(0,i))==true && solve(a.substr(i,n-i),b.substr(i,n-i))==true))

      flag==true;
       break;
	}

	return  mp[key]=flag;
  }
}
int main()
{
	string a="coder";
	string b="ocder";
	if(a.length()!=b.length())
	return false;
  
  if(solve(a,b))
  cout<<"yes"<<endl;
  else
  cout<<"no"<<endl;
 
}
