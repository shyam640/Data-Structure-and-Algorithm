#include<bits/stdc++.h>
using namespace std;

int main(){
   int t;
   cin>>t;
   while(t--){
      int n,a,b;
      cin>>n>>a>>b;
      string s;
      cin>>s;
      int ones=0,zeros=0;
      for(int i=0;i<s.length();i++)
         (s[i]=='0')?zeros++:ones++;
      cout<<(a*zeros + b*ones)<<endl;
   }
   return 0;
}