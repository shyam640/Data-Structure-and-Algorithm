// You are given a positive integer N.

// You have to divide the number N into two numbers P1 and P2 such that:

// Each digit of N should belong to exactly one of P1 or one of P2 and this, in turn, would utilize every digit of the number N.
// Form the numbers P1 and P2 in a manner such that their sum is minimum.
// Task

// Determine the minimum possible sum of P1 and P2.

// Note: The order of occurrence of the digits in P1 and P2 may differ from the order of occurrence of the digits in N.

// Example
// Assumption

// N = 4325
// Approach

// P1 can be 25
// P2 can be 34
// The minimum sum of P1 and P2 is 59.
// Note there are other possibilities of P1 and P2 like (43, 25), (3, 245), (53, 24), etc. but their sum is not minimum.
// Thus the answer is 59.
// Function description

// Complete the function solve provided in the editor. This function takes the following parameter and returns the required answer:

// N: Represents the positive integer
// Input format
// Note: This is the input format that you must use to provide custom input (available above the Compile and Test button).

// The first line contains T denoting the number of test cases. T also specifies the number of times you have to run the solve function on a different set of inputs.
// For each test case:
// The first line contains an integer N.
// Output format
// For each test case, print the minimum possible sum of the two numbers P1 and P2.

// Constraints
// 1≤T≤10510≤N≤2×1018

// Code snippets (also called starter code/boilerplate code) 

// This question has code snippets for C, CPP, Java, and Python.

// Sample input 1
// Copy
// 24325867
// Sample output 1
// Copy
// 5975
// Explanation
// The first line contains the number of test cases, T = 2.

// The first test case

// This is the same as the example. Please refer to that.

// The second test case

// Given

// N = 867
// Approach

// P1 can be 68
// P2 can be 7
// Minimum sum of P1 and P2 is 75.

// Note there are other possibilities of P1 and P2 also like (6, 78), (6, 87), etc. but their sum is not minimum.

// Thus the answer is 75.



#include<bits/stdc++.h>
using namespace std;

int main(){
   int t;
   cin>>t;
   while(t--){
      long long int n;
      cin>>n;
      string p = to_string(n);
      sort(p.begin(),p.end());
      string p1="",p2="";
      for(int i=0;i<s.length();i++){
         if(i%2==0)
            p1 += p[i];
         else
            p2 += p[i];
      }
      cout<<stol(p1)+stol(p2)<<endl;
   }
}