#include<bits/stdc++.h>

using namespace std;

#define               li                        long int
#define               lf                        long float
#define               ld                        long double
#define               lli                       long long int
#define               llf                       long long float
#define               lld                       long long double
#define               usig                      unsigned
#define               sig                       signed
#define               mod                       1000000007
#define               infi                      1e18
#define               neg_infi                  -1e18
#define               endl                      "\n"
#define               vi                        vector<int>
#define               vc                        vector<char>
#define               vs                        vector<string>
#define               vli                       vector<long int> 
#define               vlf                       vector<long float>
#define               vld                       vector<long double>
#define               vlli                      vector<long long int> 
#define               vllf                      vector<long long float>
#define               vlld                      vector<long long double>

#define               pf                        push_front
#define               pb                        push_back
#define               ob                        pop_back
#define               of                        pop_front
#define               pq                        priority_queue
#define               ump                       unordered_map


#define               it(var)                   var.begin(),var.end()
#define               loop(type,var,st,end)     for(type var=st;var<end;var++)
#define               loop_rev(type,var,st,end) for(type var=st;var<end;var++)
#define               mid(left,right)           (left+(right-left)/2)
#define               print_arr(arr,type,st,end) for(type var = st;var<=end;var++)  cout<<arr[var]<<" "; cout<<endl;


template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
#define              fast_io                    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const long double pi = atan2(0, -1);


bool checkSeq(string s,string a){
   lli st=0;
   for(lli i=0;i<s.length() and st<a.length();i++){
         if(s[i]==a[st])
            st++;
      }
      // cout<<st<<endl;
      if(st==a.length())
         return true;
      return false;
}

int main() {
   fast_io
   // Write your code here....
   lli t;
   cin>>t;
   while(t--){
      lli n,m;
      cin>>n>>m;
      string s,a;
      cin>>s>>a;
      bool flag=0;
      string ans="";
      char choice[] = {'a','b','c','d','e'};
      for(int i=0;i<5;i++){
         lli st=0;
         ans="";
         for(lli j=0;j<s.length();j++){
            if(s[j]=='?')
               ans+=choice[i];
            else
               ans+=s[j];
            if(ans[ans.length()-1]==a[st] and st<a.length())
               st++;
         }
         if(st!=a.length()){
            cout<<ans<<endl;
            flag=1;
            break;
         }
      }
      if(!flag)
         cout<<"-1"<<endl;
   }

   return 0;
}