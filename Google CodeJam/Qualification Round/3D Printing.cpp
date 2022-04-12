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
   lli test=1;
   while(t--){
      vector<vector<lli>> colors(3,vector<lli>(4));
      for(lli i=0;i<3;i++){
         for(lli j=0;j<4;j++)
            cin>>colors[i][j];
      }
      lli cyan = min(colors[0][0],min(colors[1][0],colors[2][0]));
      lli magenta = min(colors[0][1],min(colors[1][1],colors[2][1]));
      lli yellow = min(colors[0][2],min(colors[1][2],colors[2][2]));
      lli black = min(colors[0][3],min(colors[1][3],colors[2][3]));
      lli total = cyan+magenta+yellow+black;
      vector<lli> availableColors = {cyan,magenta,yellow,black};
      // cout<<cyan<<" "<<magenta<<" "<<yellow<<" "<<black<<endl;
      cout<<"Case #"<<test<<": ";
      if(total==1000000){
         cout<<cyan<<" "<<magenta<<" "<<yellow<<" "<<black<<endl;
      }else if(total>1000000){
         lli sum=0,i=0;
         while(i<4){
            sum+=availableColors[i];
            // cout<<"sum=" <<sum<<endl;
            if(sum>1000000){
               break;
            }else{
               cout<<availableColors[i]<<" ";
            }
            i++;
         }
         sum-=availableColors[i];
         cout<<1000000-sum<<" ";
         for(int j=i+1;j<4;j++)
            cout<<"0 ";
         cout<<endl;
      }else{
         cout<<"IMPOSSIBLE"<<endl;
      }
      test++;
   }
   return 0;
}