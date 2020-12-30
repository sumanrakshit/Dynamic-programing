#include<bits/stdc++.h>
using namespace std;
int max_win(int n)
{
	 int t[n];
	 t[0]=1;
	 t[1]=2;
	 int i=2;
	 do{
	 	t[i]=t[i-1]+t[i-2];
	 	
	 }while(t[i++]<=n);
	 return (i-2);//for extra loop occurs
}
int main()
{
	int n=10;
	cout<<"Number of win match of the winner of the game " <<max_win(n)<<endl;
	return 0;
}
