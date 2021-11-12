#include<bits/stdc++.h>
using namespace std;

void sortArr(vector<int>& arr){
   
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