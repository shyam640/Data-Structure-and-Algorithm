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

lli getUnique(vlli arr,lli st,lli end){
    set<lli> sett;
    for(lli i=st;i<=end;i++){
        sett.insert(arr[i]);
    }
    return sett.size();
}

bool isSorted(vlli arr){
    for(lli i=1;i<arr.size();i++){
        if(arr[i-1]>arr[i])
            return false;
    }
    return true;
}

int main() {
    fast_io;
    lli t;
    cin>>t;
    while(t--){
        lli n;
        cin>>n;
        vlli arr(n);
        for(auto &val : arr){
            cin>>val;
        }
        // set<lli> st;
        // for(lli i=0;i<n-1;i++)
        //     st.insert(arr[i]);
        // cout<<st.size()<<endl;
        lli count = 0;
        lli i = 0;
        if(isSorted(arr))
            cout<<0<<endl;
        else{
            for(i=arr.size()-1;i>0;i--){
            
            if(find(arr.begin(),arr.begin()+i-1,arr[i]) != arr.begin()+i-1)
                break;
            if(arr[i-1]>arr[i])
                break;
        }
        lli distincts = getUnique(arr,0,i-1);
        // cout<<"distincts = " << distincts<<endl;
        cout<<distincts<<endl;
        }
        
    }
    
    return 0;
}

// 11 12 9 8 8 8 9