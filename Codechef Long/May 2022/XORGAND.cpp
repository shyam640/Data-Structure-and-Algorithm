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


template <typename T> T _gcd(T a, T b){if(a%b) return _gcd(b,a%b);return b;}
template <typename T> T _lcm(T a, T b){return (a*(b/_gcd(a,b)));}
#define              fast_io                    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const long double pi = atan2(0, -1);


// Usefull Functions
bool all_Chars_Same(string s) {return (s.find_first_not_of(s[0]) == string::npos);}


int main() {
   fast_io
   // Write your code here....
   lli t;
   cin>>t;
   while(t--){             // 100
      lli n;
      cin>>n;
      vlli arr(n);
      for(auto &val : arr)
         cin>>val;
      vector<vector<long long int>> dp(n+1,vector<long long int>(33));
      for(lli i=1;i<=n;i++){
         for(lli j=0;j<33;j++)
            dp[i][j] = dp[i-1][j];
         lli power = 32;
         if(arr[i-1]!=0)
            power = (int)log2(arr[i-1]);
         dp[i][power]++;
      }
      // for(lli i=0;i<dp.size();i++){
      //    for(lli j=0;j<dp[i].size();j++)
      //       cout<<dp[i][j]<<" ";
      //    cout<<endl;
      // }
      lli q;
      cin>>q;
      while(q--){          // 2.10^5
         lli l,r,x;
         cin>>l>>r>>x;
         lli ans = 0;

         // TIME LIMIT EXCEEDED WITH BELOW CODE
         // for(lli i=l-1;i<r;i++){       //2.10^5
         //    lli xr = arr[i]^x;
         //    lli nd = arr[i]&x;
         //    if(xr>nd)
         //       ans++;
         // }

         // OPTIMIZED CODE
         lli power = 32;
         lli count = 0;
         if(x!=0)
            power = (int)log2(x);
         count = dp[r][power] - dp[l-1][power];
         ans = (r-l+1)-count;
         cout<<ans<<endl;
      }
   }

   return 0;
}