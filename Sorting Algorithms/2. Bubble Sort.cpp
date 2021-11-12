#include<bits/stdc++.h>
using namespace std;

void sortArr(vector<int>& arr){
   int counter=1;
   while(counter<arr.size()){
      for(int i=0;i<arr.size()-counter;i++){
         if(arr[i]>arr[i+1])
            swap(arr[i],arr[i+1]);
      }
      counter++;
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