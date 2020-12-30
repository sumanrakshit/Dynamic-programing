#include<bits/stdc++.h>
using namespace std;
pair<int ,int> count_ht(char s,int N)
{
	pair<int ,int>p;
	if(s=='H')
	{
		p.first=floor(N/2.0);
		p.second=ceil(N/2.0);
	}
	else if(s=='T')
	{
			p.first=ceil(N/2.0);
		p.second=floor(N/2.0);
	}
	return p;
}
int main()
{
	  char C = 'H'; 
    int N = 5; 
      
    pair<int, int> p = count_ht(C, N); 
      
    cout << "Head = " << (p.first) << "\n"; 
    cout << "Tail = " << (p.second) << "\n";
}
