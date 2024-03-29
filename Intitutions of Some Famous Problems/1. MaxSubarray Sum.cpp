// ********************************** Statement *********************************
// Given an array of n numbers, our task is to calculate the maximum subarray
// sum, i.e., the largest possible sum of a sequence of consecutive values in the
// array2. The problem is interesting when there may be negative values in the
// array. For example, in the array
// -1 2 4 -3 5 2 -5 2
// the following subarray produces the maximum sum 10:
// -1 |2 4 -3 5 2| -5 2
// We assume that an empty subarray is allowed, so the maximum subarray
// sum is always at least 0.


// ************************************ Algorithm 1 *********************************
// A straightforward way to solve the problem is to go through all possible subarrays,
// calculate the sum of values in each subarray and maintain the maximum sum.
// The following code implements this algorithm:

// int best = 0;
// for (int a = 0; a < n; a++) {
//    for (int b = a; b < n; b++) {
//       int sum = 0;
//       for (int k = a; k <= b; k++) {
//          sum += array[k];
//       }
//       best = max(best,sum);
//    }
// }
// cout << best << "\n";

// The variables a and b fix the first and last index of the subarray, and the
// sum of values is calculated to the variable sum. The variable best contains the
// maximum sum found during the search.
// The time complexity of the algorithm is O(n3), because it consists of three
// nested loops that go through the input.


// **************************** Algorithm 2 **************************************
// It is easy to make Algorithm 1 more efficient by removing one loop from it. This
// is possible by calculating the sum at the same time when the right end of the
// subarray moves. The result is the following code:

// int best = 0;
// for (int a = 0; a < n; a++) {
//    int sum = 0;
//    for (int b = a; b < n; b++) {
//       sum += array[b];
//       best = max(best,sum);
//    }
// }
// cout << best << "\n";

// After this change, the time complexity is O(n2).


// ***************************** Algorithm 3 ***************************************
// Surprisingly, it is possible to solve the problem in O(n) time3, which means that
// just one loop is enough. The idea is to calculate, for each array position, the
// maximum sum of a subarray that ends at that position. After this, the answer
// for the problem is the maximum of those sums.
// Consider the subproblem of finding the maximum-sum subarray that ends at
// position k. There are two possibilities:
// 1. The subarray only contains the element at position k.
// 2. The subarray consists of a subarray that ends at position k¡1, followed by
// the element at position k.
// In the latter case, since we want to find a subarray with maximum sum, the
// subarray that ends at position k¡1 should also have the maximum sum. Thus,
// we can solve the problem efficiently by calculating the maximum subarray sum
// for each ending position from left to right.
// The following code implements the algorithm:

// int best = 0, sum = 0;
// for (int k = 0; k < n; k++) {
//    sum = max(array[k],sum+array[k]);
//    best = max(best,sum);
// }
// cout << best << "\n";

// The algorithm only contains one loop that goes through the input, so the time
// complexity is O(n). This is also the best possible time complexity, because any
// algorithm for the problem has to examine all array elements at least once.


// ******************* FINAL CODE *************************
#include<bits/stdc++.h>
using namespace std;

void getMaxSubarraySum(vector<int> arr){
   // Method 1 : O(n^3)
   int best = 0;
   for (int a = 0; a < n; a++) {
      for (int b = a; b < n; b++) {
         int sum = 0;
         for (int k = a; k <= b; k++) {
            sum += arr[k];
         }
         best = max(best,sum);
      }
   }
   cout << best << "\n";


   // Method 2 : O(n^2)
   int best = 0;
   for (int a = 0; a < n; a++) {
      int sum = 0;
      for (int b = a; b < n; b++) {
         sum += arr[b];
         best = max(best,sum);
      }
   }
   cout << best << "\n";


   // Method 3 : O(n)
   int best = 0, sum = 0;
   for (int k = 0; k < n; k++) {
      sum = max(arr[k],sum+arr[k]);
      best = max(best,sum);
   }
   cout << best << "\n";

}

int main(){
   vector<int> arr = {-1,2,4,-3,5,2,-5,2};
   getMaxSubarraySum(arr);
}