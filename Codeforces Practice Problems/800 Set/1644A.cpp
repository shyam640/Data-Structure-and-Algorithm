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


int main() {
   fast_io
   // Write your code here....
   lli t;
   cin>>t;
   while(t--){
      string s;
      cin>>s;
      int rKey=0,gKey=0,bKey=0;
      bool flag=0;
      for(int i=0;i<s.length();i++){
         if(s[i]=='r')
            rKey++;
         else if(s[i]=='g')
            gKey++;
         else if(s[i]=='b')
            bKey++;
         else if(s[i]=='R'){
            if(rKey==0){
               flag=1;
               break;
            }
            rKey--;
         }else if(s[i]=='G'){
            if(gKey==0){
               flag=1;
               break;
            }
            gKey--;
         }else if(s[i]=='B'){
            if(bKey==0){
               flag=1;
               break;
            }
            bKey--;
         }
      }
      if(flag)
         cout<<"NO"<<endl;
      else
         cout<<"YES"<<endl;
   }

   return 0;
}