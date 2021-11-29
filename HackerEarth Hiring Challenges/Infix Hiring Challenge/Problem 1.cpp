// Maximum beauty subarray
// You are given an array A of size N.

// The beauty of a subarray is defined as the sum of all the elements of that subarray multiplied by any element present in that subarray.

// Task

// Determine the maximum beauty of all possible subarrays of array A.

// Notes

// An array B is a subarray of an array A if B can be obtained from A by deletion of several (possibly, zero or all) elements from the beginning and several (possibly, zero or all) elements from the end. For example, [1, 2], [4, 5, 6], [2, 3, 4] are valid subarrays of array [1, 2, 3, 4, 5, 6] and [2, 5, 6], [5, 4, 3] are invalid.
// 1-based indexing is followed.
// Example

// Assumptions

// T = 1
// N = 4
// arr = [5, 2, -2, -5]
// Approach

// There are two possible subarrays to get the maximum beauty out of all subarrays:
// [5, 2]: Sum of this subarray is 7 (5+2), and 7 can be multiplied with 5 or 2 to get 35 or 14. As 35>14, 35 is the answer.
// [-5, -2]: Sum of this subarray is -7 ((-5)+(-2)), and -7 can be multiplied with -5 or -2 to get 35 or 14. As 35>14, 35 is the answer.
// Hence, the answer is 35.
// Function description

// Complete the maxBeauty function provided in the editor. This function takes the following 2 parameters and returns the maximum beauty of all possible subarrays:

// N: Represents the length of the array
// A: Representing the array
// Input format

// Note: This is the input format that you must use to provide custom input (available above the Compile and Test button).

// The first line contains T denoting the number of test cases. T also specifies the number of times you have to run the maxBeauty function on a different set of inputs.
// For each test case:
// The first line contains one integer N denoting the size of the array.
// The second line contains N space-separated integers denoting elements of the array A.
// Output format

// For each test case in a new line, print the answer representing the maximum beauty of all possible subarrays of array A.

// Constraints

// 1≤T≤10

// 1≤N≤105

// −106≤Ai≤106

// Code snippets (also called starter code/boilerplate code) 

// This question has code snippets for C, CPP, Java, and Python.

// Sample input 1
// Copy
// 1
// 6
// 2 5 -2 4 -5 1
// Sample output 1
// Copy
// 45
// Explanation
// The first line contains the number of test cases, T = 1.

// Assumptions

// N = 6
// A = [2, 5, -2, 4, -5, 1]
// Approach

// The subarray from index 1 to index 4 has sum 9 (2+5+(-2)+4) and it can be multiplied with 2, 5, -2, or 4. So, multiplying 9 by 5 will be equal to 45 which is the maximum beauty of all subarrays.


#include<bits/stdc++.h>
using namespace std;

int main(){
   int t;
   cin>>t;
   while(t--){
      int n;
      cin>>n;
      vector<int> arr(n);
      for(int i=0;i<n;i++)
         cin>>arr[i];
      
      for(int i=0;i<n;i++){
         
      }
      cout<<ans<<endl;
   }
}