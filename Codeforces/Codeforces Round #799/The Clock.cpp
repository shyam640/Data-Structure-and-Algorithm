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

string getTimes(string &s,lli x){
   lli minutes = ((s[0]-'0')*10 + s[1]-'0')*60 + ((s[3]-'0')*10 + s[4]-'0');
   minutes += x;
   lli hour = (minutes/60)%24;
   lli min = minutes%60;
   string time = "";
   if(hour<10)
      time+=("0"+to_string(hour)+":");
   else
      time+=(to_string(hour)+":");
   if(min<10)
      time+=("0"+to_string(min));
   else
      time+=(to_string(min));
   s = time;
   return s;
}

int main() {
   fast_io
   // Write your code here....
   lli t;
   cin>>t;
   while(t--){
      string s;
      lli x;
      cin>>s>>x;
      lli ans=0;
      
      vector<string> times;
      while(1){
         string time = getTimes(s,x);
         if(find(times.begin(),times.end(),time)!=times.end())
            break;
         times.pb(time);
         // cout<<time<<endl;
         if(time[0]==time[4] and time[1]==time[3])
            ans++;
      }
      cout<<ans<<endl;
   }

   return 0;
}