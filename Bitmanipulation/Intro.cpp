#include<bits/stdc++.h>
using namespace std;

int getBit(int n, int pos){
   return (n & (1<<pos))!=0;
}

int setBit(int n, int pos){
   return (n | (1<<pos));
}

int clearBit(int n, int pos){
   return (n & ~(1<<pos));
}

int updateBit(int n, int pos, int bit){
   int mask = (n & ~(1<<pos));
   int clear_bit = n & mask;
   int set_bit = bit<<pos;
   return (clear_bit | set_bit);
}

pair<int,int> twoUnique(int arr[], int n){
   int xr = 0;
   for(int i=0;i<n;i++) xr ^= arr[i];

   int store_xr = xr ,set_bit = 0, set_bit_pos = 0;
   while(set_bit != 1){
      set_bit = (xr & 1);
      set_bit_pos++;
      xr = xr >> 1;
   }

   int newXr = 0;
   for(int i=0;i<n;i++){
      if(getBit(arr[i], set_bit_pos-1))
         newXr = newXr ^ arr[i];
   }

   int firstVal = newXr;
   int secVal = newXr ^ store_xr;
   return make_pair(firstVal, secVal);
}

int uniqueBetweenThreeFreq(int arr[], int n){
   int bit_set[64] = {0};
   for(int i=0;i<n;i++){
      int val = arr[i];
      int pos = 0;
      while(val){
         bit_set[pos]+=(val&1);
         pos++;
         val = val>>1;
      }
   }

   int ans = 0;
   for(int i=0;i<64;i++)
      if(bit_set[i]%3) ans += (pow(2, i));
   return ans;
}


int main(){
   // cout<<updateBit(5,1,1)<<endl;

   // int arr[] = {1, 2, 3, 4, 5, 4, 7, 1, 2, 3};
   // pair<int,int> ans = twoUnique(arr, 10);
   // cout<<ans.first<<" "<<ans.second<<endl;

   int arr[] = {1, 3, 2, 3, 1, 3, 2, 2, 1, 4, 4, 4, 5};
   cout<<uniqueBetweenThreeFreq(arr, 13)<<endl;
}

