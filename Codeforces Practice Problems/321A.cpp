#include<bits/stdc++.h>
using namespace std;
int main(){
   int t;
   cin>>t;
   int ans=0;
   while(t--){
      int a,b,c;
      cin>>a>>b>>c;
      if((a==1 and b==1) or (a==1 and c==1) or (b==1 and c==1))
         ans++;
   }
   cout<<ans<<endl;
}