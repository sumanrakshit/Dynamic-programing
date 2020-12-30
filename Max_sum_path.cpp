#include <bits/stdc++.h> 
using namespace std; 
#define N 100 
  
// No of rows and columns 
int n, m; 
  
// Declaring the matrix of maximum 
// 100 rows and 100 columns 
int a[N][N]; 
  
// Variable visited is used to keep 
// track of all the visited positions 
// Variable dp is used to store 
// maximum sum till current position 
vector<vector<int> > dp(N, vector<int>(N)), 
    visited(N, vector<int>(N)); 
  
// For storing current sum 
int current_sum = 0; 
  
// For continuous update of 
// maximum sum required 
int total_sum = 0; 
  
// Function to Input the matrix of size n*m 
void inputMatrix() 
{ 
    n = 3; 
    m = 3; 
    a[0][0] = 500; 
    a[0][1] = 100; 
    a[0][2] = 230; 
    a[1][0] = 1000; 
    a[1][1] = 300; 
    a[1][2] = 100; 
    a[2][0] = 200; 
    a[2][1] = 1000; 
    a[2][2] = 200; 
} 
  
// Function to calculate maximum sum of path 
int maximum_sum_path(int i, int j) 
{ 
    // Checking boundary condition 
    if (i == n - 1 && j == m - 1) 
        return a[i][j]; 
  
    // Checking whether or not (i, j) is visited 
    if (visited[i][j]) 
        return dp[i][j]; 
  
    // Marking (i, j) is visited 
    visited[i][j] = 1; 
  
    // Updating the maximum sum till 
    // the current position in the dp 
    int& total_sum = dp[i][j]; 
  
    // Checking whether the position hasn't 
    // visited the last row or the last column. 
    // Making recursive call for all the possible 
    // moves from the current cell and then adding the 
    // maximum returned by the calls and updating it. 
    if (i < n - 1 & j < m - 1) { 
        int current_sum = max(maximum_sum_path(i, j + 1), 
                              max( 
                                  maximum_sum_path(i + 1, j + 1), 
                                  maximum_sum_path(i + 1, j))); 
        total_sum = a[i][j] + current_sum; 
    } 
  
    // Checking whether 
    // position has reached last row 
    else if (i == n - 1) 
        total_sum = a[i][j] 
                    + maximum_sum_path(i, j + 1); 
  
    // If the position is in the last column 
    else
        total_sum = a[i][j] 
                    + maximum_sum_path(i + 1, j); 
                    i++;
                    j++;
  
    // Returning the updated maximum value 
    return total_sum; 
} 
  
// Driver Code 
int main() 
{ 
    inputMatrix(); 
  
    // Calling the implemented function 
    int maximum_sum = maximum_sum_path(0, 0); 
  
    cout << maximum_sum; 
    return 0; 
} 
