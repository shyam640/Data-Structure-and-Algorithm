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


int main() {
   fast_io
   // Write your code here....
   long long int t;
   cin>>t;
   while(t--){
      string s;
      cin>>s;
      s.erase(unique(s.begin(),s.end()),s.end());
      if(s.length()==1)
         cout<<s[0]<<endl;
      else if(s.length()==2){
         if((s[0]=='>' and s[1]=='=') or (s[0]=='=' and s[1]=='>'))
            cout<<'>'<<endl;
         else if((s[0]=='<' and s[1]=='=') or (s[0]=='=' and s[1]=='<'))
            cout<<'<'<<endl;
      }else{
         cout<<"?"<<endl;
      }
   }
   return 0;
}