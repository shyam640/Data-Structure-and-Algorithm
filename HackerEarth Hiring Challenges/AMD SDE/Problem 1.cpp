// Re-sort
// You are given a permutation A of 1 to N with only even lengthed slopes. A slope is defined as a consecutively decreasing subarray.

// Note: A subarray containing a single element is also considered a slope of length 1. For example, the sequence [5, 1, 4, 6, 2, 3] has 2 slopes of length 2, i.e., [5, 1] and [6, 2], and 2 slopes of length 1, i.e., [4] and [3].

// Consider the following algorithm to sort the permutation:

// re-sort(sequence A):
//     while(A is not sorted in non decreasing order):
//         partition A into minimum number of consecutive slopes
//         for each slope with length > 1:
//             reverse(slope)
// Task

// Determine the total number of times reverse() is called when the sequence A is passed to re-sort()

// Note: An array b is a subarray of an array a if b can be obtained from a by deletion of several (possibly, zero, or all) elements from the beginning and several (possibly, zero, or all) elements from the end. In particular, an array is a subarray of itself.

// Example

// Assumptions

// N = 2
// A = [2, 1]
// Approach

// The given sequence has only 1 slope initially of length 2.
// When it is passed to re-sort(), the slope [2, 1] is reversed.
// Now the sequence becomes [1, 2].
// Hence, the output is 1 as reverse() is called only 1 time.

// Function description

// Complete the reverseCount function provided in the editor. This function takes the following 2 parameters and returns the number of times reverse function would be called in re-sort():

// N: Represents an integer denoting the length of the permutation
// A: Represents an array of integers denoting the permutation
// Input format

// Note: This is the input format that you must use to provide custom input (available above the Compile and Test button).

// The first line contains a single integer T which denotes the number of test cases. T also denotes the number of times you have to run the reverseCount function on a different set of inputs.
// For each test case:
// The first line contains a single integer N denoting the length of the permutation.
// The second line contains N space-separated integers denoting the permutation.
// Output format

// For each test case, print only one integer in a single line representing the number of times reverse() is called.

// Constraints

// 1≤T≤10

// 2≤N≤105

// 1≤Ai≤N

// N is even.

// Code snippets (also called starter code/boilerplate code)

// This question has code snippets for C, CPP, Java, and Python.

// Sample input
// 143 1 4 2
// Sample output
// 3
// Explanation
// The first line contains the number of test cases, T = 1.

// The first test case

// Given

// N = 4, A = [3, 1, 4, 2]
// Approach

// The given sequence has 2 slopes initially of length 2 each.
// When it is passed to re-sort(), the slopes [3, 1] and [4, 2] are reversed.
// Now the sequence becomes [1, 3, 2, 4]
// In this sequence, there is one slope with length > 1, i.e., [3, 2]. Now, this is also reversed.
// The sequence becomes [1, 2, 3, 4].
// Hence, the output is 3 as reverse() is called 3 times.



#include<bits/stdc++.h>
using namespace std;

bool isSorted(vector<int> arr){
   for(int i=1;i<arr.size();i++){
      if(arr[i]<arr[i-1])
         return false;
   }
   return true;
}

int main(){
   int t;
   while(t--){
      int n;
      cin>>n;
      vector<int> arr(n);
      for(int i=0;i<n;i++)
         cin>>arr[i];
      long long int ans=0;
      vector<int> temp = arr;
      next_permutation(arr.begin(),arr.end());
      while(arr!=temp){
         for(int i=0;i<arr.size();i++)
            cout<<arr[i]<<" ";
         cout<<endl;
         if(isSorted(arr))
            break;
         ans++;
         next_permutation(arr.begin(),arr.end());
      }
      cout<<ans<<endl;
      return 0;
   }
}

