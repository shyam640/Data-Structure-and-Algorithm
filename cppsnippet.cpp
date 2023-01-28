#include<bits/stdc++.h>

// ++++++++++++++++++++++++++++++++++++++++++++  @its_shyam640 ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/********************    Codeforces Header Files    *************************************/

// #include <atcoder/convolution>       
// // Convolution of two arrays is defined as C[i + j] = ∑(a[i] * b[j]) for every i and j
// using namespace atcoder;



using namespace std;

#define               li                        long int
#define               lf                        long float
#define               ld                        long double
#define               lli                       long long int
#define               llf                       long long float
#define               lld                       long long double
#define               usig                      unsigned
#define               sig                       signed
#define               def_mod                   1000000007
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
#define               rit(var)                  var.rbegin(),var.rend()
#define               loop(i,st,end)            for(auto i=st;i<=end;i++)
#define               loop_rev(i,st,end)        for(auto i=end;i>=st;i--)
#define               mid(left,right)           (left+(right-left)/2)
#define               print_arr(arr,st,end)     for(auto var = st;var<=end;var++)  cout<<arr[var]<<" "; cout<<endl;

#define               what_is(x)                 cerr << #x << " is " << x << endl;
#define               fast_io                    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

template <typename T> T _gcd(T a, T b){if(a%b) return _gcd(b,a%b);return b;}
template <typename T> T _lcm(T a, T b){return (a*(b/_gcd(a,b)));}
template <typename T, typename... Args> auto sum(T a, Args... args) { return a + sum(args...); }
template<typename T> bool comparator(pair<T,T>& a, pair<T,T>& b){return (a.second<b.second);}
bool all_Chars_Same(string s) {return (s.find_first_not_of(s[0]) == string::npos);}


const long double pi = atan2(0, -1);


/***********************************   TIPS   *************************************

##   odd => n&1      even => !(n%1)

##   n<<1 => Multiply n with 2            n>>1 => Divide n with 2

##   swapping two numbers
      a ^= b;
      b ^= a;
      a ^= b;

##   ASCII Numbers
     48-57 -> 0-9
     65-90 -> A-Z
     97-122 -> a-z

## Total Number of digits => floor(log10(N)) + 1

## Check if number is power of 2 => n && (!(n&(n-1)))

## Check weather all elements are positive or not
   all_of(arr, arr+n, [](int x) { return x>0; }) ? true : false
   <=== OR ===>
   all_of(arr, arr+n, isPositive())

## Built in functions
   what_is(__builtin_ffs(4))        # Returns position of first set bit
   what_is(__builtin_clz(7))        # Returns 32 - no. of set bits
   what_is(__builtin_popcount(6))   # Returns number of ones(or setbits) in number

## Raw strings   string r_str = R"(Hello\tWorld\n)";    Output : Hello\tWorld\n

## Binary Representation of a number
   void show_binary(int n) {
      for (int i = 0; i < 20; ++i) {
         cout << !!(n & (1 << i));
      }
      cout << "\n";
   }
   Instead, one can simply write

   cout << bitset<20>(n) << "\n";
Also, if you want to print an octal or a hexadecimal representation of a number, 
you can simply write cout << oct << n << "\n" and cout << hex << n << "\n", 
respectively.  To return back to normal decimal, use cout << dec


## Minimum and Maximum element of array
   vector<int> x = {1, 2, 3, 4};
   auto it = minmax_element(all(x));
   cout << *it.first << ' ' << *it.second << endl;


## 







*/

/******************************************** USEFUL STL FUNCTIONS ****************************

# accumulate(first_iterator, last_iterator, initial value of sum) – Does the summation of vector elements

# lower_bound(first_iterator, last_iterator, x) – returns an iterator pointing to the first element in the range [first,last) which has a value not less than ‘x’.

# upper_bound(first_iterator, last_iterator, x) – returns an iterator pointing to the first element in the range [first,last) which has a value greater than ‘x’. 

# partition(beg, end, condition) :- This function is used to partition the elements on basis of condition mentioned in its arguments.

# is_partitioned(beg, end, condition) :- This function returns boolean true if container is partitioned else returns false.

# stable_partition(beg, end, condition) :- This function is used to partition the elements on basis of condition mentioned in its arguments in such a way that the relative order of the elements is preserved..

# partition_point(beg, end, condition) :- This function returns an iterator pointing to the partition point of container i.e. the first element in the partitioned range [beg,end) for which condition is not true. The container should already be partitioned for this function to work.

# sort(v.begin(),v.end(),greater<int>()) :- Sorting array in decreasing order

# partial_sort(start,partition_point,end) :- Sort array in range [start,partition_point]





*/


/************************************** CODEFORCES TRICKS ******************************************

## If given like 1<= a <= b <= 10^5...... ab <= 10^5     then its actually  a<=400



*/


/*##############################       Usefull Functions          ###################################*/

/**************************** Check if number is prime or not   ********************************/
bool isPrime(lli n){auto count = 0;for(auto idx=1;(idx*idx)<=n;idx++){if((idx*idx)==n){count++;continue;}if(n%idx==0)count+=2;}if(count==2)return true;return false;}


/****************************** GENERATE PRIME FACTORS  ********************************/
map<lli,lli> primeFactors(lli n){ map<lli,lli> factors; while (n % 2 == 0) { factors[2]++; n = n/2; } for (int i = 3; i <= sqrt(n); i = i + 2) { while (n % i == 0) { factors[i]++; n = n/i; } } if (n > 2) factors[n]++; return factors; }

/****************************** GENERATE Factorial  *******************************/
string stringFactorial(lli n){ if (n>1000){ cout << " Integer Overflow"<< endl; return ""; } lli counter; unsigned long long int sum = 0; if (n == 0) return "1"; for (counter=1;counter<=n;counter++) sum = sum + log(counter); string result = to_string(round(exp(sum))); return result; }

lli moduloFactorial(lli n, lli p){if (n >= p) return 0; lli result = 1; for (lli i = 1; i <= n; i++) result = (result * i) % p; return result;}


/****************************** Generate Testcases **************************/
void generateTestcase(vlli &arr, lli pivot){ generate(arr.begin(), arr.end(), [&pivot]{ return (rand() % pivot); });}

/****************************** SORT MAP BY VALUE **************************/
void sortMapByValue(map<string, int>& M) { multimap<int, string> MM; for (auto& it : M) { MM.insert({ it.second, it.first }); } for (auto& it : MM) { cout << it.second << ' ' << it.first << endl; } }


/******** Getting GCD on subsegements ************/
// Like [0],[0,1],[0,2],[0,3]....,[0,n-1]

vector<map<lli,lli>> gcdOnSubsegments(vlli arr){ vector<map<lli, lli>> sub_gcd(arr.size()); /* Key is gcd, Value is the largest length such that gcd(a[i - len], ..., a[i]) equals to key. */ sub_gcd[0][arr[0]] = 0; for(lli i = 1; i < arr.size(); i++){ sub_gcd[i][arr[i]] = 0; for(auto it: sub_gcd[i - 1]){ lli new_gcd = __gcd(it.first, arr[i]); sub_gcd[i][new_gcd] = max(sub_gcd[i][new_gcd], it.second + 1); } } return sub_gcd; }

/********************  CREATE BINARY TREE *********************/
struct TreeNode{
    int data;
    TreeNode* left, * right;
};

TreeNode* newNode(int data){
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

TreeNode* createTreeFromLOT(auto arr,lli i, lli n){
   TreeNode *root = nullptr;
   if (i < n){
      root = newNode(arr[i]);
      root->left = createTreeFromLOT(arr,2 * i + 1, n);
      root->right = createTreeFromLOT(arr,2 * i + 2, n);
   }
   return root;
}

void displayTree(TreeNode* root){
   if (root != NULL){
      displayTree(root->left);
      cout << root->data<<" -> ";
      displayTree(root->right);
   }
}




void file_input_output(){
   ios_base::sync_with_stdio(0); 
   cin.tie(0); 
   cout.tie(0);
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   #endif
}

int main(int argc, char const *argv[]) {
   clock_t begin = clock();
   file_input_output();       // Taking file input and displaying output in output.txt
   // Write your code here....
   


   #ifndef ONLINE_JUDGE 
   clock_t end = clock();
   cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
   #endif 
   return 0;
}




/************ INTPUT *****************/




/************* OUTPUT *****************/
