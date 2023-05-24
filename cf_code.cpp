#include<bits/stdc++.h>

// ++++++++++++++++++++++++++++++++++++++++++++  @its_shyam640 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

using namespace std;

#define               li                        long int
#define               lf                        long float
#define               ld                        long double
#define               lli                       long long int
#define               llf                       long long float
#define               lld                       long long double
#define               endl                      "\n"
#define               vlli                      vector<long long int> 
#define               it(var)                   var.begin(),var.end()
#define               rit(var)                  var.rbegin(),var.rend()
#define               mid(left,right)           (left+(right-left)/2)
#define               fast_io                   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define               _print(x)                 cerr << #x << " = " << x << endl;

template <typename T> T _gcd(T a, T b){if(a%b) return _gcd(b,a%b);return b;}
template <typename T> T _lcm(T a, T b){return (a*(b/_gcd(a,b)));}
template <typename T, typename... Args> auto sum(T a, Args... args) { return a + sum(args...); }
template<typename T> bool comparator(pair<T,T>& a, pair<T,T>& b){return (a.second<b.second);}


const long double pi = atan2(0, -1);
string pi100 = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";


class Debug{
   public:
      void dbg(auto var) {cerr << var;}

      // pair print
      template <class T, class V> 
      void dbg(pair <T, V> p) {cerr<< "pair = {"; dbg(p.first); cerr << ","; dbg(p.second); cerr << "}" << endl;}

      // vector print
      template <class T> 
      void dbg(vector <T> v) {cerr << "array = { "; for (T i : v) {dbg(i); cerr << " ";} cerr << "}" << endl;}

      // print set
      template <class T> 
      void dbg(set <T> v) {cerr << "set = [ "; for (T i : v) {dbg(i); cerr << " ";} cerr << "]" << endl;}
      
      // print map
      template <class T, class V> 
      void dbg(map <T, V> v) {cerr << "map = [ \n"; for (auto i : v) {dbg(i); cerr << endl;} cerr << "]" << endl;}
      
      // print unordered_map
      template <class T, class V> 
      void dbg(unordered_map <T, V> v) {cerr << "ump = [ "; for (auto i : v) {dbg(i); cerr << " ";} cerr << "]" << endl;}
      
      // print multiset
      template <class T> 
      void dbg(multiset <T> v) {cerr << "multiset = [ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]" << endl;}
};


/****************************** Generate Testcases **************************/
void genTestArr(auto &arr, auto pivot){ generate(arr.begin(), arr.end(), [&pivot]{ return (rand() % pivot); });}


void file_input_output(){
   ios_base::sync_with_stdio(0); 
   cin.tie(0); 
   cout.tie(0);
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   freopen("error.txt", "w", stderr);
   #endif
}

/* $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ SNIPPET ENDED $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/




int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    Debug d;
    fast_io
    // file_input_output();       // Taking file input and displaying output in output.txt
    // Write your code here....
    
    
    
    #ifndef ONLINE_JUDGE 
    clock_t end = clock();
    cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms"<<endl;
    cout<<"Date : "<<__DATE__<< endl;
    cout<<"Time : "<<__TIME__<< endl;
    #endif 
    return 0;
}





/************ INTPUT *****************/




/************* OUTPUT *****************/

