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
// lli moduloFactorial(lli n){ if(n>=mod) return 0;   lli res = 1;   for(lli i=1;i<=n;i++){ res = (res*i)%mod; }   return res; }
// lli nCr(lli n,lli r){
//    lli num = 1;
//    for(lli i=n;i>r;i--)
//       num = (num*i)%mod;
//    return ((num/moduloFactorial(num-r))%mod);
// }



lli getBinomialCoefficient(lli n, lli k){
   lli res = 1;
   if (k > n - k)
      k = n - k;
   for (lli i = 0; i < k; ++i){
      res = (res*(n-i))%100000000000007;
      res = (res/(i + 1))%100000000000007;
   }
   return res%1000000007;
}


void getPascalValues(lli n,lli l,lli r){
   lli t = l+n;
   t = t/2;
   while(l<=r){
      // cout<<binomialCoeff(n,3)<<endl;
      lli ans = getBinomialCoefficient(n,t);
      cout<<ans<<" ";
      t++;
      if(l<r)
         cout<<"0 ";
      l+=2;
   }
   cout<<endl;
}


int main() {
   fast_io
   // Write your code here....
   int t;
   cin>>t;
   while(t--){
      lli n,l,r;
      cin>>n>>l>>r;

      // First Method - Gives Runtime Error !!
      // vlli arr;
      // lli c = 1;
      // for(lli i=1;i<=n+1;i++){
      //    arr.pb(c);
      //    // cout<<c<<" ";
      //    if(i!=n+1)
      //    //    cout<<"0"<<" ";
      //       arr.pb(0);
      //    c = c*(n+1-i)/i;
      // }
      // // cout<<endl;
      // print_arr(arr,lli,l+n,r+n);
      // print_arr(arr,lli,l+arr.size()/2,r+arr.size()/2);

      // Second Method - Using Modulo
      getPascalValues(n,l,r);
   }

   return 0;
}