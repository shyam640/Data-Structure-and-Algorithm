#include<bits/stdc++.h>
using namespace std;

void sortArr(vector<int>& arr){
   for(int i=0;i<arr.size()-1;i++){
      for(int j=i+1;j<arr.size();j++){
         if(arr[j]<arr[i])
            swap(arr[i],arr[j]);
      }
   }
}

int main(){
   int n;
   cin>>n;
   vector<int> arr(n);
   for (int i=0;i<n;i++)
      cin>>arr[i];
   sortArr(arr);
   for(int i=0;i<n;i++)
      cout<<arr[i]<<" ";
}