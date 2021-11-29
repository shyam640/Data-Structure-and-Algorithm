// You are given a grid of size NxN where each element of the grid is represented by the equation 
// grid(i, j)=(i+j)^2+10^5(j−i) where i and j represent the corresponding row and column of the grid.

// Task

// Determine the kth smallest element in the grid.

// Note: Assume 1-based indexing.

// Example

// Assumptions

// N = 2
// k = 1

// Approach

// The value of elements in grid is:
// grid(1, 1) = 4
// grid(1, 2) = 100009
// grid(2, 1) = -99991
// grid(2, 2) = 16
// kth smallest element is -99991.
// Function description

// Complete the solve function provided in the editor. This function takes the following 2 parameters and returns the required answer:

// N: Represents the dimension of grid
// k: Represents the value of k
// Input format

// Note: This is the input format that you must use to provide custom input (available above the Compile and Test button).

// The first line contains a single integer T, which denotes the number of test cases. T also specifies the number of times you have to run the solve function on a different set of inputs
// For each test case:
// The first line contains two space-separated integers N and k.
// Output format

// For each test case in a new line, print the kth smallest element.

// Testcase 1 :-
// 2
// 1 1
// 2 3
// Output :-
// 4
// 16

// Explanation
// The first line contains the number of test cases, T = 2.

// For the first test case

// Given

// N = 1
// k = 1
// Approach

// The value of elements in the grid is:
// grid(1, 1) = 4
// The kth smallest element is 4.
// For the second test case

// Given

// N = 2
// k = 1
// Approach

// The value of elements in the grid is:
// grid(1, 1) = 4
// grid(1, 2) = 100009
// grid(2, 1) = -99991
// grid(2, 2) = 16
// The kth smallest elements is 16.


#include<bits/stdc++.h>
using namespace std;

long long int getElement(vector<vector<long long int>>& grid,long int n,long long int k){
   auto cmp = [&](pair<int,int> a,pair<int,int> b){
      return grid[a.first][a.second] > grid[b.first][b.second];
   };

   priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
   for(int i=0; i<n; i++){
      pq.push({i,0});
   }
   
   

   for(int i=1; i<k; i++){
      auto p = pq.top();
      pq.pop();
      
      if(p.second+1 < n) pq.push({p.first,p.second + 1});
   }

   // for(int i=0;i<pq.size();i++)
   //    cout<<pq.top().first<<" "<<pq.top().second<<endl;

   return grid[pq.top().first][pq.top().second];
}

int main(){
   int t;
   cin>>t;
   while(t--){
      long int n;
      long long int k;
      cin>>n>>k;
      vector<vector<long long int>> grid(n,vector<long long int>(n,0));
      for(int i=0;i<n;i++){
         for(int j=0;j<n;j++){
            grid[i][j] = ((i+1+j+1)*(i+1+j+1)) + (10*10*10*10*10*(j-i));
         }
      }
      for(int i=0;i<n;i++)
         sort(grid[i].begin(),grid[i].end());
      sort(grid.begin(),grid.end());
      
      long long int ans = getElement(grid,n,k);
      cout<<ans<<endl;
   }
}