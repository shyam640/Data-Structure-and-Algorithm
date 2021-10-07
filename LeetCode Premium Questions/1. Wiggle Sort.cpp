// Companies -> Google

// Question :-

// Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....

// For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].


// Solution :-

#include<bits/stdc++.h>
using namespace std;

void waveSort(vector<int>& arr){
   sort(arr.begin(),arr.end());
   for(int i=1;i<arr.size()-1;i+=2)
      swap(arr[i],arr[i+1]);
}

int main(){
   int t;
   cin>>t;
   while(t--){
      int n;
      cin>>n;
      vector<int> arr(n);
      for(int i=0;i<n;i++)
         cin>>arr[i];
      waveSort(arr);
      for(int i=0;i<arr.size();i++)
         cout<<arr[i]<<" ";
   }
}