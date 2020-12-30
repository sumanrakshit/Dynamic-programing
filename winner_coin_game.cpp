 /*A and B are playing a game. At the beginning there are n coins. Given two more numbers x and y.
 In each move a player can pick x or y or l coins. A always starts the game. The player who picks the last coin wins the game.
For a given value of n, find whether A will win the game or not if both are playing optimally.*/

#include <bits/stdc++.h> 
using namespace std; 
  

bool findWinner(int x, int y, int n) 
{ 
 
    int dp[n + 1]; 
  
   
    dp[0] = false; 
    dp[1] = true; 
  
   
    for (int i = 2; i <= n; i++) { 
  
      
        if (i - 1 >= 0 && !dp[i - 1]) 
            dp[i] = true; 
        else if (i - x >= 0 && !dp[i - x]) 
            dp[i] = true; 
        else if (i - y >= 0 && !dp[i - y]) 
            dp[i] = true; 
  
        // Else A loses game. 
        else
            dp[i] = false; 
    } 
  
    return dp[n]; 
} 
  

int main() 
{ 
    int x = 3, y = 4, n = 5; 
    if (findWinner(x, y, n)) 
        cout << 'A'; 
    else
        cout << 'B'; 
  
    return 0; 
} 
