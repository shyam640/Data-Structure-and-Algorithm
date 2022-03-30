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
      lli n;
      cin>>n;
      vlli arr1(n);
      for(lli i=0;i<n;i++)
         cin>>arr1[i];
      vlli arr2(n);
      for(lli i=0;i<n;i++)
         cin>>arr2[i];
      vector<vlli> plan(n);
      for(lli i=0;i<n;i++){
         plan[arr2[i]].push_back(arr1[i]);
      }
      vector<double> dp(n+1,0);
      lli sum=0;
      multiset<lli> s;
      for(lli i=1;i<n+1;i++){
         for(auto &j : plan[i-1])
            s.insert(j);
         // for(auto it=s.begin();it!=s.end();it++)
         //    cout<<*it<<" ";
         cout<<endl;
         if(s.size()){
            auto it = s.end();
            it--;
            sum+=*it;
            s.erase(it);
         }else
            break;
      }
      // print_arr(dp,double,0,n+1);
      // double ans = *max_element(dp.begin(),dp.end());
         // cout<<fixed<<setprecision(6)<<ans<<endl;
      cout<<fixed<<setprecision(6)<<sum<<endl;
   }

   return 0;
}