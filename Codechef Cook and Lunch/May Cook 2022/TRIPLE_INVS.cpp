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


bool only_inc(vlli arr){
   lli inc=1;
   for(lli i=1;i<arr.size();i++){
      if(arr[i]>arr[i-1])
         inc++;
   }
   return inc==arr.size();
}


bool only_dec(vlli arr){
   lli dec=1;
   for(lli i=1;i<arr.size();i++){
      if(arr[i]<arr[i-1])
         dec++;
   }
   return dec==arr.size();
}

bool palindrome(vlli arr){
   lli st=0,end=arr.size()-1;
   while(st<=end){
      if(arr[st]!=arr[end])
         return false;
      st++;
      end--;
   }
   return true;
}


int main() {
   fast_io
   // Write your code here....
   lli t;
   cin>>t;
   while(t--){
      lli n;
      cin>>n;
      vlli arr(n);
      for(auto &val : arr)
         cin>>val;
      if(only_inc(arr) or only_dec(arr))
         cout<<"NO"<<endl;
      else if(n%2!=0 and palindrome(arr))
         cout<<"NO"<<endl;
      else
         cout<<"YES"<<endl;
   }

   return 0;
}