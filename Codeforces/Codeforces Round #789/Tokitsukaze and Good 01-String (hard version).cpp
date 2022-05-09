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
      lli n;
      cin>>n;
      string s;
      cin>>s;
      lli count=1,ans=0;
      vlli countArr;
      // set<lli> st;
      lli oneC=0,zeroC=0;
      (s[0]=='0')?zeroC++:oneC++;
      for(lli i=1;i<n;i++){
         if(s[i]=='0')
            zeroC++;
         else
            oneC++;
         if(s[i]==s[i-1])
            count++;
         else{
            countArr.pb(count);
            // st.insert(countArr[countArr.size()-1]);
            count=1;
         }
      }
      countArr.pb(count);
      count=1;
      for(lli i=1;i<n;i++){
         if(s[i]==s[i-1])
            count++;
         else{
            if(count%2!=0){
               ans++;
               i++;
            }
            count=1;
         }
      }
      // print_arr(countArr,lli,0,countArr.size()-1);
      if(all_of(countArr.begin(),countArr.end(),[](lli val) { return !(val%2); })){
         cout<<"0 "<<countArr.size()<<endl;
      }else{
         // print_arr(countArr,lli,0,countArr.size()-1);
         // cout<<min(ans,n)<<" "<<oneC<<" "<<zeroC<<endl;
         // for(auto it : st)
         //    cout<<it<<" ";
         // cout<<endl;
         if(min(ans,n)==zeroC or min(ans,n)==oneC)
            cout<<min(ans,n)<<" 1"<<endl;
         else
            cout<<min(ans,n)<<" 2"<<endl;
      }
   }

   return 0;
}