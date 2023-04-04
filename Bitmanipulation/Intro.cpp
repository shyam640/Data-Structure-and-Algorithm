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

int main(){
   cout<<clearBit(5,0)<<endl;
}

