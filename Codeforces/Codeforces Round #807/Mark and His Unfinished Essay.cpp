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
   while(t--){
      lli n,c,q;
      cin>>n>>c>>q;
      string s;
      cin>>s;
      vector<string> v;
      vector<vector<lli>> arr(c,vector<lli>(4));
      lli idx = s.length()-1,i=0;
      while(c--){
         lli l,r;
         cin>>l>>r;
         arr[i][0] = idx;
         arr[i][1] = idx+r-l;
         arr[i][2] = l-1;
         arr[i][3] = r-1;
         // arr.pb({idx,idx+r-l,l-1,r-1});
         idx+=(r-l+1);
         i++;
      }

      // for(lli i=0;i<arr.size();i++)
      //    cout<<arr[i][0]<<" "<<arr[i][1]<<" "<<arr[i][2]<<" "<<arr[i][3]<<endl;
      while(q--){
         lli k;
         cin>>k;
         k-=1;
         if(k<s.length())
            cout<<s[k]<<endl;
         else{
            for(lli i=0;i<arr.size();i++){
               if(k<0)
                  break;
               if(k<s.length()){
                  cout<<s[k]<<endl;
                  break;
               }
               // cout<<arr[i][2]<<" "<<arr[i][0]<<endl;
               if(arr[i][0]<=k and arr[i][1]>=k){
                  // cout<<arr[i][2]<<" "<<arr[i][0]<<" "<<k<<endl;
                  k -= (arr[i][2]-arr[i][0]);
               }
            }
         }
      }
   }

   return 0;
}


// (1 ≤ n ≤ 2⋅105, 1 ≤ c ≤ 40, and 1 ≤ q ≤ 104)
// 1 ≤ t ≤ 2⋅103