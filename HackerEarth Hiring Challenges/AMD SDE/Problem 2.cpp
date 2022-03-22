// The playground
// You are playing in a playground in form of a 2D matrix of size N x M.

// Initially, the playground contains just an outer boundary. There are some walls given in an array A of size Q. You construct these walls in the playground.

// Task

// Determine how many different regions the playground gets divided into.

// Notes 

// The walls will be given as input x1, y1, x2, y2. where (x1, y1) and (x2, y2) are adjacent cells of the matrix and the wall needs to be constructed on the side common to both these adjacent cells. Formally,
// If x1 = x2, then | y1-y2 | = 1, and this will account for a left wall or right wall.
// If y1 = y2, then | x1-x2 | = 1, and this will account for a top wall or bottom wall.
// The boundary walls are assumed to be connected initially, they are not given in input. Thus, a matrix of size NxM has a total of 1 region initially (without any walls built).
// A region is connected to another region if there is any path between the two without any walls.
// Example 

// Assumptions

// T=1 
// N = 2
// M = 2
// Q = 2
// A = { [1 1 2 1], [2 2 1 2]}
// Approach

// Without any walls, the playground looks like


// After adding walls (Red Line represents walls)


// Hence, the total regions are 2.
// Function description

// Complete the function playground provided in the editor. This function takes the following 4 parameters and returns the required answer:

// N: Represents the rows of the 2D matrix
// M: Represents the columns of the 2D matrix
// Q: Represents the size of vector A
// A: Represents the walls to be constructed. Each wall is in the form of a vector with four values x1, y1, x2, y2.
// Input format

// Note: This is the input format that you must use to provide custom input (available above the Compile and Test button).

// The first line contains T denoting the number of test cases. T also specifies the number of times you have to run the playground function on a different set of inputs.
// For each test case:
// The first line contains three space-separated integers N, M, and Q.
// Q lines follow, each denoting the wall to be constructed. Each wall contains four space-separated integers as input x1, y1, x2, y2 denoting there is a wall between cell (x1, y1) and (x2, y2).
// Output format

// For each test case in a new line, print the total number of regions the playground gets divided into.

// Constraints 

// 1≤T≤105

// 1≤N≤2×105

// 1≤M≤2×105

// 1≤Q≤2×105

// Sum of N x M across all test cases is ≤2×105

// 1≤A[i][0],A[i][2]≤N

// 1≤A[i][1],A[i][3]≤M

// Code snippets (also called starter code/boilerplate code)

// This question has code snippets for C, CPP, Java, and Python.

// Sample input
// 1
// 3 3 4
// 1 1 2 1
// 3 1 2 1
// 2 3 2 2
// 2 1 2 2
// Sample output
// 2
// Explanation
// The first line contains the number of test cases, T = 1.

// First test case

// Given

// N = 3
// M = 3
// Q = 4
// A = {[ 1 1 2 1 ] , [ 3 1 2 1 ] , [ 2 3 2 2 ], [ 2 1 2 2]} 
// Approach

// The 1st wall, 2nd wall, and the 4th wall forms a closed region in the matrix not connected to any other region. So, there are 2 regions.
// So the output is 2.