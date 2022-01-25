// ********************************   Simple path   *********************************************


// You are given the following:

// A tree of n nodes numbered from 1 to n and n - 1 edges
// An array C of length n
// The element Ci for each (1≤i≤n) represents the value associated with the ith node.

// Now, let's call a simple path good if the frequency of the value of any one of the nodes in the path is at least half of the length of the path round to the next greatest integer (i.e. taking ceil of half of the length of the path). The length of a path from node A to node B is the number of nodes you encounter in that unique path while going from A to B.

// Task

// Determine the count of the total good path starting from node 1.

// Notes

// 1-based indexing is followed.
// In graph theory, a simple path is a path in a graph that does not have repeating vertices
// A tree is an undirected graph in which any two vertices are connected by exactly one path, or can also be called a connected acyclic undirected graph.
// Example

// Assumptions

// n = 4
// C = [1, 2, 1, 2]
// Tree with edges as follow:


// Approach

// All paths starting from node 1:

// Ci value in the path from 1 to 1 is {1} and the frequency of C1 satisfies the given condition so it is a good path.
// Ci values in the path from 1 to 2 are {1, 2} and the frequency of C1 satisfies the given condition so it is a good path.
// Ci values in the path from 1 to 3 are {1, 2, 1} and the frequency of C1 satisfies the given condition so it is a good path.
// Ci values in the path from 1 to 4 are {1, 2, 1, 2}  and the frequency of C1 satisfies the given condition so it is a good path.
// Hence, the final answer will be 4.

// Function description

// Complete the solve function provided in the editor. This function takes the following 3 parameters and returns an integer:

// n: Represents the number of nodes in a tree
// C: Represents an array denoting the node values
// edges: Represents a 2D array of edges
// Input format

// Note: This is the input format that you must use to provide custom input (available above the Compile and Test button)

// The first line contains an integer T denoting the number of test cases. T also denotes the number of times you have to run the solve function on a different set of inputs.
// For each test case:
// The first line contains an integer n denoting the number of nodes.
// The second line contains n space-separated integers representing the node values.
// The Next n - 1 line contains two space-separated integers representing an edge between the nodes.  
// Output format

// For each test case in a new line, print the answer representing the total count of good paths starting from node 1. 

// Constraints

// 1 ≤ T ≤ 10
// 1 ≤ n ≤ 105
// 1 ≤ Ci ≤ 105


// Sample input
// 2
// 5
// 1 2 3 4 5
// 1 2
// 2 3
// 1 4
// 2 5
// 4
// 1 2 1 2
// 1 2
// Sample output
// 3
// 4


// Explanation
// The first line contains the number of test cases, T = 2.

// The first test case

// Given

// n = 5
// C = [1, 2, 3, 4, 5]
// Tree:


// Approach

// All paths starting from node1:

// Ci value in the path from 1 to 1 is {1} and the frequency of C1 satisfies the given condition so it is a good path.
// Ci values in the path from 1 to 2 are {1, 2}  and the frequency of C1 satisfies the given condition so it is a good path.
// Ci values in the path from 1 to 3 are {1, 2, 3} since no Ci satisfies the given condition so it is not a good path.
// Ci values in the path from 1 to 4 are {1, 4}  and the frequency of C1 satisfies the given condition so it is a good path.
// Ci values in the path from 1 to 5 are {1, 2, 5} since no Ci satisfies the given condition so it is not a good path. 
// Hence, the final answer is 3.



// The second test case

// Sample input 1
// 11088 78 46 95 84 98 55 3 68 4210 25 76 13 68 51 27 2
// Sample output 1
// 3


// Sample input 2
// 11034 48 8 72 67 90 15 85 7 901 49 51 57 16 12 87 8



// ***************************************   SOLUTION   *******************************************************


#include<bits/stdc++.h>
