#include <bits/stdc++.h> 
using namespace std; 
  
// Function to return the maximum marks 
// by considering topics which can be 
// completed in the given time duration 
int MaximumMarks(int marksarr[], int timearr[],  
                             int h, int n, int p) 
{ 
    int no_of_topics = n + 1; 
    int total_time = h + 1; 
  
    int T[no_of_topics][total_time]; 
  
    // Initialization 
  
    // If we are given 0 time 
    // then nothing can be done 
    // So all values are 0 
    for (int i = 0; i < no_of_topics; i++) { 
        T[i][0] = 0; 
    } 
  
    // If we are given 0 topics 
    // then the time required 
    // will be 0 for sure 
    for (int j = 0; j < total_time; j++) { 
        T[0][j] = 0; 
    } 
  
    // Calculating the maximum marks 
    // that can be achieved under 
    // the given time constraints 
    for (int i = 1; i < no_of_topics; i++) { 
  
        for (int j = 1; j < total_time; j++) { 
  
            // If time taken to read that topic 
            // is more than the time left now at 
            // position j then do no read that topic 
            if (j < timearr[i]) { 
  
                T[i][j] = T[i - 1][j]; 
            } 
            else { 
  
                /*Two cases arise: 
                1) Considering current topic 
                2) Ignoring current topic 
                We are finding maximum of (current topic weightage  
                + topics which can be done in leftover time  
                - current topic time)  
                and ignoring current topic weightage sum 
                */
                T[i][j] = max(marksarr[i] 
                                  + T[i - 1][j - timearr[i]], 
                              T[i - 1][j]); 
            } 
        } 
    } 
  
    // Moving upwards in table from bottom right 
    // to calculate the total time taken to 
    // read the topics which can be done in 
    // given time and have highest weightage sum 
    int i = no_of_topics - 1, j = total_time - 1; 
  
    int sum = 0; 
  
    while (i > 0 && j > 0) { 
  
        // It means we have not considered 
        // reading this topic for 
        // max weightage sum 
        if (T[i][j] == T[i - 1][j]) { 
  
            i--; 
        } 
        else { 
  
            // Adding the topic time 
            sum += timearr[i]; 
  
            // Evaluating the left over time after 
            // considering this current topic 
            j -= timearr[i]; 
  
            // One topic completed 
            i--; 
        } 
    } 
  
    // It contains the maximum weightage sum 
    // formed by considering the topics 
    int marks = T[no_of_topics - 1][total_time - 1]; 
  
    // Condition when exam cannot be passed 
    if (marks < p) 
        return -1; 
  
    // Return the marks that 
    // can be obtained after 
    // passing the exam 
    return sum; 
} 
  
// Driver code 
int main() 
{ 
    // Number of topics, hours left 
    // and the passing marks 
    int n = 4, h = 10, p = 10; 
  
    // n+1 is taken for simplicity in loops 
    // Array will be indexed starting from 1 
    int marksarr[n + 1] = { 0, 6, 4, 2, 8 }; 
    int timearr[n + 1] = { 0, 4, 6, 2, 7 }; 
  
    cout << MaximumMarks(marksarr, timearr, h, n, p); 
  
    return 0; 
} 
