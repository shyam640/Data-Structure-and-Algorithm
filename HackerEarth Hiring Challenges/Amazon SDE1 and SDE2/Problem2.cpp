// You are given an array A containing N integers. You are also given an integer K. An array is good if A[i] ≤ A[i + K], i = 1, 2, 3, .. , N - K.

// In one operation, you can choose any element and convert it to an arbitrary integer.

// Task

// Determine the minimum number of operations to make the array good.

// Note: Assume 1-based indexing

// Example

// AssumptionsInl

// T = 1
// N = 4
// A = [2, 4, 1, 3]
// K = 2
// Approach

// You convert A[3] to 2 and A[2] to 3, so A becomes [2, 3, 2, 3]. Easy to observe that A[1] ≤ A[3] and A[2] ≤ A[4].
// Therefore, the minimum required operations are 2.
// Function description

// Complete the minOperations function provided in the editor. This function takes the following 3 parameters and returns an integer denoting the minimum number of operations to make the array good:

// N: Represents the integer N
// A: Represents the integer array A
// K: Represents the integer K
// Input format

// Note: This is the input format that you must use to provide custom input (available above the Compile and Test button).

// The first line contains a single integer T, which denotes the number of test cases. T also specifies the number of times you have to run the minOperations function on a different set of inputs.
// For each test case:
// The first line contains an integer N denoting the length of the array.
// The second line contains N space-separated integers denoting array A.
// The third line contains an integer K.
// Output format

// For each test case in a new line, print the minimum number of operations to make the array good. 

// Constraints

// 1≤T≤203≤N≤2×1052≤K≤N−10≤Ai≤105

// Code snippets (also called starter code/boilerplate code) 

// This question has code snippets for C, CPP, Java, and Python.

// Sample input 1
// Copy
// 242 4 1 3251 2 0 1 23
// Sample output 1
// Copy
// 20
// Explanation
// The first line contains the number of test cases, T = 2.

// The first test case

// The first test case is the same as the example. Please refer to that.

// The second test case

// Assumptions

// T = 1
// N = 5
// A = [1, 2, 0, 1, 2]
// K = 3
// Approach

// It is easy to observe that A[1] ≤  A[4] and A[2] ≤  A[5]. Therefore, the array is already good.
// Therefore, the minimum required operations are 0.



