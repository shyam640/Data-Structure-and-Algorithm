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

void getAnswer(string str1, string str2){
     for(lli idx=1;idx<=str1.length()-str2.length();idx++){
              //cout<<"A"<<endl;
            lli a =  str1[idx-1]-'0';
            lli b = str1[idx]-'0';
            if(str2[0] == '1' && (a == 1 || b == 1)){
                     str1[idx] = '1';

            }
            else if(str2[0] == '0' && (a == 0 || b == 0)){
                   str1[idx] = '0';

            }
     }

    lli temp1 = 0, k = 0;
     for(lli idx=str1.length()-str2.length();idx<str1.length();idx++){
      if(str1[idx]==str2[k]){
        temp1++;
      }
      k++;
     }

     if(temp1==str2.length()){
      cout<<"YES"<<endl;
     }
     else{
      cout<<"NO"<<endl;
     }

}

int main() {
   fast_io
   // Write your code here....
   lli t;
   cin>>t;
   while(t--){
      lli n,m;
      cin>>n>>m;
      string s1;
      cin>>s1;
      string s2;
      cin>>s2;
      getAnswer(s1,s2);
      // string temp1 = s1.substr(n-s2+1,n);
      // string temp2 = s1.substr(0,n-s2);
      // // cout<<temp1<<" "<<temp2<<endl;
      // if(s1.length()==s2.length())
      //    cout<<(s1==s2?"YES":"NO")<<endl;
      // else if(temp1!=s2.substr(1,s2.length()))
      //    cout<<"NO"<<endl;
      // else if(find(temp2.begin(),temp2.end(),s2[0])==temp2.end())
      //    cout<<"NO"<<endl;
      // else
      //    cout<<"YES"<<endl;
   }

   return 0;
}