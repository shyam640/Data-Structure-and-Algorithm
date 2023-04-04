/*

Problem 1 :

Find the Evil Monsters
Problem Description
Given an array A of N elements representing the monsters and an array B of Q elements representing the heros.

The i-th type of monster is represented by A[i][0], A[i][1] and A[i][2] which means a monster of the i-th type is present at each integer co-ordinate from A[i][0] to A[i][1] and having a strength of A[i][2].

The i-th type of hero is represented by B[i][0] and B[i][1] which means a hero of strength B[i][1] will appear at the integer point B[i][0] after i seconds. When the i-th hero appears it will destroy each and every monster present at B[i][0] and having a strength less than B[i][1].

For each i you have to determine the number of monsters left after the i-th hero has completed their task.



Problem Constraints
1 <= N <= 105
1 <= Q <= 105
1 <= A[i][0] <= A[i][1] <= 105
1 <= B[i][0] <= 105
1 <= A[i][2] <= 109
1 <= B[i][1] <= 109


Input Format
The first argument is an array A.
The second argument is an array B.


Output Format
Return a list of integers.


Example Input
Sample Input 1 -
N = 3
A = [ [ 1, 3, 7 ], [ 2, 5, 4 ], [ 4, 8, 6 ] ]
Q = 2
B = [ [ 3, 5 ], [ 5, 8 ] ]
Sample Input 2 -
N = 4
A = [ [ 2, 5, 8 ], [ 5, 8, 6 ], [ 3, 6, 9 ], [ 7, 10, 10 ] ]
Q = 3
B = [ [ 2, 7 ], [ 7, 9 ], [ 7, 11 ] ]


Example Output
Sample Output 1 -
[ 11, 9 ]
Sample Output 2 -
[ 16, 15, 14 ]


Example Explanation
Explanation 1 -
Intially there are 12 monsters in total. The first hero will destroy the monster of 2nd type present at co-ordinate
5 having a strength of 4. After the first operation there are 11 monsters left. The second hero will destroy the monster of 2nd type present at 
co-ordinate 5 having a strength of 4 and the monster of 3rd type present at co-ordinate 5 having a strength of 6.
Explanation 2 -
Intially there are 16 monsters in total. The first hero will not destroy even a single monster. The second hero will 
destroy the monster of 2nd type present at co-ordinate 7 having a strength of 6. The third hero will destroy the monster of
4th type present at co-ordinate 7 having a strength of 10.


*/





/*

Problem 2 : 
Minimize Travel Tax
Problem Description
There are A cities connected by A-1 bi-directional roads such that all the cities are connected.
Roads are given by array 2D array B where ith road connects B[i][0] city to B[i][1].
You go on C trips where on the i-th trip you travel from C[i][0] city to C[i][1] city. All the trips are independent of each other.
You have to pay a tax on D[i] on entering or leaving the i-th city. If you pay the tax while entering then you don't need to pay at the time of leaving.

You can choose some non-adjacent cities and make their tax half.

What can be the minimum sum of taxes you pay for all the C trips? Since the answer can be large, return the remainder after dividing it by 109+7.


Problem Constraints
2 <= A <= 105
1 <= B[i][0], B[i][1] <= A
1 <= C <= 105
1 <= C[i][0], C[i][1] <= A
C[i][0] ≠ C[i][1]
1 <= D[i] <= 105
D = A and D[i] % 2 = 0


Input Format
First argument is an integer A
Second argument is a 2D array B
Third argument is a 2D array C
Fourth argument is an array D


Output Format
Return an integer


Example Input
Input 1:

 A = 3
 B = [ [1, 2]
       [1, 3] ] 
 C = [ [1, 3]
       [3, 2] ]
 D = [2, 2, 8] 
Input 2:

 A = 3
 B = [ [1, 2]
       [2, 3] ] 
 C = [ [1, 3]
       [1, 2] ]
 D = [2, 4, 2] 


Example Output
Output 1:

 13
Output 1:

 10


Example Explanation
Explanation 1:

 Given Tree:
    1
  /   \
 3     2

 For trip 1, from 1 to 3: you will have to pay taxes at cities 1 and 3.
 For trip 2, from 3 to 2: you will have to pay taxes at cities 1, 2 and 3.
 You can reduce the taxes at citites 2 and 3.
 Then the net tax will be 2×2 + 1×1 + 4×2 = 13
 So, the ans is 13.
Explanation 2:

 Given Tree:
     1
      \
       2
      /
     3 
 For trip 1, from 1 to 3: you will have to pay taxes at cities 1, 2 and 3.
 For trip 2, from 1 to 2: you will have to pay taxes at cities 1 and 2.
 You can reduce the taxes at city 2.
 Then the net tax will be 2×2 + 2×2 + 2×1 = 10
 So, the ans is 10.





*/






/*


Expected Path Length - III

Problem Description
You have A natural number from 1 to A, each occuring exactly once. Now, you choose any of the A (each number being equally likely) numbers and do the following procedures:

1. Initialize a variable step = 0.
2. Let X be the current number you have.
3. Randomly choose any divisor of X (each divisor being equally likely). Let it be Y, now replace X by X / Y. Also, increment step by 1.
4. If X is not equal to 1, repeat from 2nd step.

Let expected value of step be represented in the form of a irreducible fraction x/y. Return xy-1 mod (109 + 7), where y-1 is the modulo multiplicative inverse of y modulo (109 + 7).

NOTE: You only have to consider positive values of Y.


Problem Constraints
1 <= A <= 105


Input Format
First argument A, is an integer.


Output Format
Return a single integer.


Example Input
Input 1:
A = 1
Input 2:
A = 2


Example Output
Output 1:
0
Output 2:
1


Example Explanation
For Input 1:
The only possible X we can choose is 1. 
For X = 1, step = 0. 
Therefore, expected path length = 0.
For Input 2:
Different possible sequences of steps are: 
[1], [2, 1], [2, 2, 1], [2, 2, 2, 1], .......
with their correspoding value of step as: 0, 1, 2, 3, .....
It is found that the expected value is 1.




*/





/*

Three Subarrays

Problem Description
You are given an array A of N integers. You will have to pick 3 subarrays from the array l1, l2 and l3. The subarray l1 must be a prefix and l3 must be a suffux. The minimum length of each of these subarrays must be 1. An element of the array cannot be present in more than 1 of these subarrays.

Find the maximum sum of all the elements in each of these three subarrays. Since the sum can be large , return the positive remainder after dividing the sum with 109 + 7.


Problem Constraints
3 <= N <= 105
-109 <= A[i] <= 109


Input Format
First argument A is an array of integer.


Output Format
Return an integer


Example Input
Input 1:
A = [2, -3, -1, 4]
Input 2:
A = [-6, -2, 1, -4, 5, 2] 


Example Output
Output 1:
5 
Output 2:
2


Example Explanation
For Input 1:
l1 = [2] , l2 = [-1] , l3 = [4]
The sum is 5.
For Input 2:
l1 = [-6] , l2 = [1] , l3 = [5, 2]
The sum is 2.




*/