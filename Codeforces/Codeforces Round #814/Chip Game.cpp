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


// void solve() {
//   int n, k;
//   cin >> n >> k;


//   vector<int> no;

//   vector<int> a;
//   vector<int> b;
//   for (int i = 1; i <= n; i++) {
//     if (i % 4 == 0) {
//       b.pb(i);
//     }
//     else if ((i + k) % 4 == 0)
//       a.pb(i);
//     else
//       no.pb(i);
//   }

//   if (a.size() + b.size() != no.size()) {
//     cout << "NO" << endl;
//     debug("-1");
//     return ;
//   }

//   cout << "YES" << endl;
//   int pointer = 0;

//   for (int i = 0; i < a.size(); i++) {
//     cout << a[i] << " " << no[pointer++] << endl;
//   }
//   for (int i = 0; i < b.size(); i++) {
//     cout << no[pointer++] << " " << b[i] << endl;
//   }



// }

int main() {
   fast_io
   // Write your code here....
   lli t;
   cin>>t;
   while(t--){
      lli a,b;
      cin>>a>>b;
      if((a%2 and b%2) or (a%2==0 and b%2==0))
         cout<<"Tonya"<<endl;
      else
         cout<<"Burenka"<<endl;
   }

   return 0;
}