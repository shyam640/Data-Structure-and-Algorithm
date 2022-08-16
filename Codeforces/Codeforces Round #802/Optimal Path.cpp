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

lli getMinCost(vector<vector<lli>> arr,lli n,lli m){
   if (n < 0 || m < 0)
        return INT_MAX;
    else if (m == 0 && n == 0)
        return arr[n][m];
    else
        return arr[n][m] + min(getMinCost(arr, n - 1, m),getMinCost(arr, n, m - 1));
}

int main() {
   fast_io
   // Write your code here....
   lli t;
   cin>>t;
   while(t--){
      lli n,m;
      cin>>n>>m;
      // vector<vector<lli>> arr(n,vector<lli>(m));
      // for(lli i=0;i<n;i++){
      //    for(lli j=0;j<m;j++){
      //       arr[i][j] = (i)*m + j + 1;
      //    }
      // }
      // for(lli i=0;i<n;i++){
      //    for(lli j=0;j<m;j++){
      //       cout<<arr[i][j]<<" ";
      //    }
      //    cout<<endl;
      // }
      // lli ans = getMinCost(arr,n-1,m-1);
      // cout<<ans<<endl;
      cout<<((n*(n+1)/2*m) + (m*(m-1)/2))<<endl;
   }

   return 0;
}