// *************************************   Generate string   ***********************************************


// You are given a string S of length N. You are also given a string P of length M. You want to generate string P using the letters of the string S.
// For that, you start at any index i on the string S, write that letter at the current index i, and perform the following operation any number of times:

// You move to one place, either left or right, if that exists, and write the letter from the new position after the last written letter.
// You move to any position with the same letter as the current one and do not write anything.
// The time taken to move from position a to position b is |a - b| where (x equals (a-b), and |x| represents the absolute value of x).

// Task

// Determine the minimum time to generate the string P or print -1 if that's not possible.

// Note: Assume 1-based indexing.

// Example

// Assumptions

// N = 7
// M = 5
// S = ankoobx
// P = boook
// Approach

// You can start with index 6. Write S[6], i.e., write 'b'. This step takes 0 units of time.
// You can perform the operation of moving one place to the left, i.e., move to index 5. Write S[5], i.e., write 'o'. This step takes 1 unit of time.
// You can perform the operation of moving one place to the left, i.e., move to index 4. Write S[4], i.e. write 'o'. This step takes 1 unit of time.
// You can perform the operation of moving one place to the right, i.e., move to index 5. Write S[5], i.e., write 'o'. This step takes 1 unit of time.
// You can move to index 4 as it contains the same letter as index 5 and writes nothing. This step takes 1 unit of time.
// You can move to one place left, i.e., move to index 3 and write S[3] on paper, i.e., write 'k'. This step takes 1 unit of time. 
// Thus, the answer is 5.
// Function description

// Complete the function solve provided in the editor. This function takes the following 4 parameters and returns the minimum time to generate the string or -1 if that's not possible:

// N: Represents the length of string S
// M: Represents the length of string P​​
// S: Represents the string S
// P: Represents the string P


// Input format


// The first line contains T denoting the number of test cases. T also specifies the number of times you have to run the solve function on a different input set.
// For each test case:
// The first line contains integers N and M.
// The second line contains N lowercase letters denoting the string S.
// The third line contains M lowercase letters denoting the string P.

// Output format

// For each test case in a new line, print the minimum possible time to generate the string P, or −1 if that is not possible.

// Constraints

// 1 ≤ T ≤ 10
// 1 ≤ N , M ≤ 200


// Sample input
// 2
// 8 7
// rracecar
// carrace
// 3 3
// abc
// acd

// Sample output
// 7
// -1
// Explanation
// The first line contains the number of the test cases, T = 2.

// For the first test case

// Given

// N = 8
// M = 7
// S = "rracecar"
// P = "carrace"
// Approach

// You can start with index 4. Write S[4] on the paper, i.e., write 'c'.
// You can perform the operation of moving one place to the left, i.e., move to index 3. Write S[3] on the paper, i.e., write 'a'. This step takes 1 unit of time.
// You can perform the operation of moving one place to the left, i.e., move to index 2. Write S[2] on the paper, i.e., write 'r'. This step takes 1 unit of time.
// You can perform the operation of moving one place to the left, i.e., move to index 1. Write S[1] on the paper, i.e., write 'r'. This step takes 1 unit of time.
// You can move to index 2 as it contains the same letter as index 1 and writes nothing. This step takes 1 unit of time.
// You can perform the operation of moving one place to the right, i.e., move to index 3. Write S[3] on the paper, i.e., write 'a'. This step takes 1 unit of time.
// You can perform the operation of moving one place to the right, i.e., move to index 4. Write S[4] on the paper, i.e., write 'c'. This step takes 1 unit of time.
// You can perform the operation of moving one place to the right, i.e., move to index 5. Write S[5] on the paper, i.e., write 'e'. This step takes 1 unit of time.
// Thus, the answer is 7.
// For the second test case

// Given

// N = 3
// M = 3
// S = abc
// P = acd
// Approach

// It is impossible to generate string P from the given string S.
// Therefore the answer is -1.

// Sample input 1
// 220 
// 6gwbgylyriromococqauqgyrocq17 
// 5tttgugqeiqsystzgttgqst

// Sample output 1
// 13
// 11

// Sample input 2
// 44 
// 1wayww7 
// 2lelrcbrlr14 
// 4nhunwvwwiewxsxnwwx

// Sample output 2
// 0
// 1
// 8
// 24



// ***********************************   SOLUTION   ************************************************