/*****************************************  @its_shyam640  *********************************************/
#include<bits/stdc++.h>



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


#define               modulo(z)                  z%mod

template <typename T> T _gcd(T a, T b){if(a%b) return _gcd(b,a%b);return b;}
template <typename T> T _lcm(T a, T b){return (a*(b/_gcd(a,b)));}
template <typename T> T moduloPower(T base, T power){
   T res = 1;
   base = base%1000000007;
   if(base==0) return 0;
   while(power>0){
      if(power&1) res = ((res*base)%1000000007+1000000007)%1000000007;
      power = power>>1;
      base = ((base*base)%1000000007+1000000007)%1000000007;
   }
   return res%1000000007;
}
template<typename T> bool comparator(pair<T,T>& a, pair<T,T>& b){return (a.second<b.second);}


#define              fast_io                    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const long double pi = atan2(0, -1);


/***********************************   TIPS   *************************************

##   odd => n&1      even => !(n%1)

##   n<<1 => Multiply n with 2            n>>1 => Divide n with 2

##   swapping two numbers
      a ^= b;
      b ^= a;
      a ^= b;

## Total Number of digits => floor(log10(N)) + 1

## Check if number is power of 2 => n && (!(n&(n-1)))

## Check weather all elements are positive or not
   all_of(arr, arr+n, [](int x) { return x>0; }) ? true : false
   <=== OR ===>
   all_of(arr, arr+n, isPositive())






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


/*******************************       Usefull Functions          ***********************************/

/***** Check if all the characters are same **********/
bool all_Chars_Same(string s) {return (s.find_first_not_of(s[0]) == string::npos);}

/************ Check if number is prime or not   ****************/
bool isPrime(auto n){
   auto count = 0;
   for(auto idx=1;(idx*idx)<=n;idx++){
      if((idx*idx)==n){
         count++;
         continue;
      }
      if(n%idx==0)
         count+=2;
   }
   if(count==2)
      return true;
   return false;
}


/****************************** GENERATE PRIME FACTORS till 10^5  ********************/
vector<lli> primeFactors(500005);
void generateAllPrimeFactors(){
   for(lli idx=0;idx<500005;idx++){
      primeFactors[idx] = idx;
   }
   for(lli idx=2;idx<500005;idx+=2){
      primeFactors[idx] = 2;
   }
   for (lli idx=3; idx*idx<500005; idx++) {
      if (primeFactors[idx] == idx) {
         for (int j=idx*idx; j<500005; j+=idx)
               if (primeFactors[j]==j)
                  primeFactors[j] = idx;
      }
   }
}

/****************************** GENERATE Factorial till 10^5  ********************/
vlli factorials(500005,1);
void generateFactorials(){
   factorials[0] = 1;
   for(lli idx=1;idx<500005;idx++){
      factorials[idx] = (((((factorials[idx-1])+1000000007)%1000000007)*idx)+1000000007)%1000000007;
   }
}


/******** Getting GCD on subsegements ************/
// Like [0],[0,1],[0,2],[0,3]....,[0,n-1]

vector<map<lli,lli>> gcdOnSubsegments(vlli arr){
   vector<map<lli, lli>> sub_gcd(arr.size());
   /*
   Key is gcd,
   Value is the largest length such that gcd(a[i - len], ..., a[i]) equals to key.
   */
   sub_gcd[0][arr[0]] = 0;
   for(lli i = 1; i < arr.size(); i++){
      sub_gcd[i][arr[i]] = 0;
      for(auto it: sub_gcd[i - 1]){
         lli new_gcd = __gcd(it.first, arr[i]);
         sub_gcd[i][new_gcd] = max(sub_gcd[i][new_gcd], it.second + 1);
      }
   }
   return sub_gcd;
}

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

/****************************** SORT MAP BY VALUE **************************/
template <typename T> map<T,T> sortMapByValue(map<T,T> &mp){
   vector<pair<T,T>> arr;
   for(auto &it : mp)
      arr.pb(it);
   sort(arr.begin(),arr.end(),comparator);
   map<T,T> sortedMap;
   for(auto &it : arr)
      sortedMap.insert(it);
   return sortedMap;
}



int main() {
   fast_io
   // Write your code here....
   lli t;
   cin>>t;
   while(t--){
      lli n;
      cin>>n;
      vector<vector<string>> arr(3,vector<string>(n));
      map<string,int> mp;
      for(lli i=0;i<3;i++){
         for(int j=0;j<n;j++){
            cin>>arr[i][j];
            mp[arr[i][j]]++;
         }
      }
      // for(lli i=0;i<3;i++){
      //    for(int j=0;j<n;j++)
      //       cout<<arr[i][j]<<" ";
      //    cout<<endl;
      // }


      // Method 1 : TLE
      // vector<int> ans(3);

      // // 1st Row
      // for(lli i=0;i<n;i++){
      //    if(find(it(arr[1]),arr[0][i])==arr[1].end() and find(it(arr[2]),arr[0][i])==arr[2].end())
      //       ans[0]+=3;
      //    else if((find(it(arr[1]),arr[0][i])!=arr[1].end() and find(it(arr[2]),arr[0][i])==arr[2].end()) or (find(it(arr[1]),arr[0][i])==arr[1].end() and find(it(arr[2]),arr[0][i])!=arr[2].end()))
      //       ans[0]+=1;
      // }

      // // 2nd Row
      // for(lli i=0;i<n;i++){
      //    if(find(it(arr[0]),arr[1][i])==arr[0].end() and find(it(arr[2]),arr[1][i])==arr[2].end())
      //       ans[1]+=3;
      //    else if((find(it(arr[0]),arr[1][i])!=arr[0].end() and find(it(arr[2]),arr[1][i])==arr[2].end()) or (find(it(arr[0]),arr[1][i])==arr[0].end() and find(it(arr[2]),arr[1][i])!=arr[2].end()))
      //       ans[1]+=1;
      // }

      // // 3rd Row
      // for(lli i=0;i<n;i++){
      //    if(find(it(arr[0]),arr[2][i])==arr[0].end() and find(it(arr[1]),arr[2][i])==arr[1].end())
      //       ans[2]+=3;
      //    else if((find(it(arr[0]),arr[2][i])!=arr[0].end() and find(it(arr[1]),arr[2][i])==arr[1].end()) or (find(it(arr[0]),arr[2][i])==arr[0].end() and find(it(arr[1]),arr[2][i])!=arr[1].end()))
      //       ans[2]+=1;
      // }

      // for(lli i=0;i<ans.size();i++)
      //    cout<<ans[i]<<" ";
      // cout<<endl;


      // Method 2 : 
      vector<int> ans(3);
      for(lli i=0;i<3;i++){
         for(int j=0;j<n;j++){
            // cout<<mp[arr[i][j]]<<endl;
            if(mp[arr[i][j]]==1)
               ans[i]+=3;
            else if(mp[arr[i][j]]==2)
               ans[i]+=1;
         }
      }
      for(lli i=0;i<ans.size();i++)
         cout<<ans[i]<<" ";
      cout<<endl;
   }

   return 0;
}




/************ INTPUT *****************/




/************* OUTPUT *****************/
