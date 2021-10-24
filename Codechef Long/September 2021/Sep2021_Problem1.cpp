#include<bits/stdc++.h>
using namespace std;

int main(){
   int t;
   cin>>t;
   while(t--){
      int a,b,c,d,e;
      cin>>a>>b>>c>>d>>e;
      if(((a+b)<=d or (a+c)<=d or (b+c)<=d) and (a<=e or b<=e or c<=e))
         cout<<"YES"<<endl;
      else
         cout<<"NO"<<endl;
   }
   return 0;
}