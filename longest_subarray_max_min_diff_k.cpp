#include <bits/stdc++.h> 
#include<vector>
using namespace std; 
  
// Function to calculate longest 
// subarray with above condition 
int findLargestSubarray( 
    vector<int>& arr, 
    int N, int K) 
{ 
  
    // Sort the array 
    sort(arr.begin(), arr.end()); 
  
    int value1 = arr[0], value2 = 0; 
    int index1, index2, i, MAX; 
    index1 = index2 = 0; 
    i = 0, MAX = 0; 
  
    // Loop which will terminate 
    // when no further elements 
    // can be included in the subarray 
  
    while (index2 != N) { 
  
        // first value such that 
        // arr[index2] - arr[index1] > K 
        value2 = value1 + (K + 1); 
  
        // calculate its index using lower_bound 
        index2 = lower_bound(arr.begin(), 
                             arr.end(), value2) 
                 - arr.begin(); 
  
        // index2- index1 will give 
        // the accurate length 
        // of suarray then compare 
        // for MAX length and store 
        // in MAX variable 
        MAX = max(MAX, (index2 - index1)); 
  
        // change the index1 
        // to next greater element 
        // than previous one 
        // and recalculate the value1 
        index1 
            = lower_bound( 
                  arr.begin(), 
                  arr.end(), arr[index1] + 1) 
              - arr.begin(); 
        value1 = arr[index1]; 
    } 
  
    // finally return answer MAX 
    return MAX; 
} 
// Driver Code 
int main() 
{ 
    int N, K; 
    N = 18; 
    K = 5; 
    vector<int> arr{ 1, 1, 1, 2, 2, 
                     2, 2, 2, 3, 
                     3, 3, 6, 6, 7, 
                     7, 7, 7, 7 }; 
    cout << findLargestSubarray(arr, N, K); 
    return 0; 
} 
