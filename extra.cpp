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
#define               vlli                      vector<long long int> 
#define               vllf                      vector<long long float>
#define               vlld                      vector<long long double>

#define               pf                        push_front
#define               pb                        push_back
#define               ob                        pop_back
#define               of                        pop_front


#define               it(var)                   var.begin(),var.end()
#define               rit(var)                  var.rbegin(),var.rend()
#define               mid(left,right)           (left+(right-left)/2)
#define               fast_io                   ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define               _print(x)                 cerr << #x << " = " << x << endl;

template <typename T> T _gcd(T a, T b){if(a%b) return _gcd(b,a%b);return b;}
template <typename T> T _lcm(T a, T b){return (a*(b/_gcd(a,b)));}
template <typename T, typename... Args> auto sum(T a, Args... args) { return a + sum(args...); }
template<typename T> bool comparator(pair<T,T>& a, pair<T,T>& b){return (a.second<b.second);}
bool all_Chars_Same(string s) {return (s.find_first_not_of(s[0]) == string::npos);}


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


/*###########################################       Usefull Functions          #############################################*/

/**************************** Check if number is prime or not   ********************************/
bool isPrime(lli n){auto count = 0;for(auto idx=1;(idx*idx)<=n;idx++){if((idx*idx)==n){count++;continue;}if(n%idx==0)count+=2;}if(count==2)return true;return false;}

lli inv(lli i){if(i==1) return 1;return (def_mod-((def_mod/i)*inv(def_mod%i))%def_mod)%def_mod;}

/****************************** GENERATE PRIME FACTORS  ********************************/
map<lli,lli> primeFactors(lli n){ map<lli,lli> factors; while (n % 2 == 0) { factors[2]++; n = n/2; } for (int i = 3; i <= sqrt(n); i = i + 2) { while (n % i == 0) { factors[i]++; n = n/i; } } if (n > 2) factors[n]++; return factors; }

/****************************** GENERATE Factorial  *******************************/
string stringFactorial(lli n){ if (n>1000){ cout << " Integer Overflow"<< endl; return ""; } lli counter; unsigned long long int sum = 0; if (n == 0) return "1"; for (counter=1;counter<=n;counter++) sum = sum + log(counter); string result = to_string(round(exp(sum))); return result; }

lli moduloFactorial(lli n, lli p){if (n >= p) return 0; lli result = 1; for (lli i = 1; i <= n; i++) result = (result * i) % p; return result;}


/****************************** Generate Testcases **************************/
void genTestArr(auto &arr, auto pivot){ generate(arr.begin(), arr.end(), [&pivot]{ return (rand() % pivot); });}


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
	freopen("error.txt", "w", stderr);
	#endif
}

/* $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ SNIPPET ENDED $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$*/

int getClosest(int val1, int val2, int target){
if (target - val1 >= val2 - target)	return val2;
else	return val1;
}

int bin_search(vlli arr, int target){
	int n = arr.size();
	if (target <= arr[0])	return arr[0];
	if (target >= arr[n - 1])	return arr[n - 1];

	int i = 0, j = n, mid = 0;
	while (i < j) {
		mid = (i + j) / 2;

		if (arr[mid] == target)
			return arr[mid];

		if (target < arr[mid]) {
			if (mid > 0 && target > arr[mid - 1])
					return getClosest(arr[mid - 1], arr[mid], target);
			j = mid;
		}
		else {
			if (mid < n - 1 && target < arr[mid + 1])
					return getClosest(arr[mid],arr[mid + 1], target);
			i = mid + 1;
		}
	}

	return arr[mid];
}

// int fun(vlli arr, int key, int low, int high) {
// 	int max_limit = high;
// 	while(low<high) {
// 		int mid = low +(high-low)/2.0;
// 		if(arr[mid]<key) {
// 			low = mid + 1;
// 		}else high = mid;
// 	}

// 	return arr[high];
// }

int main(int argc, char const *argv[]) {
	clock_t begin = clock();
	Debug d;
	fast_io
	// file_input_output();       // Taking file input and displaying output in output.txt
	// Write your code here....
	lli t;
	cin>>t;
	while(t--){
		lli n, m;
		cin>>n>>m;
		vlli slopes;
		lli k;
		for(lli i=0;i<n;i++){
			cin>>k;
			slopes.push_back(k);
		}
		sort(it(slopes));
		lli a, b, c;
		for(lli i=0;i<m;i++){
			cin>>a>>b>>c;
			// lli close = bin_search(slopes, b);
			// lli close = fun(slopes, b, 0, slopes.size()-1);
			// _print(close);
			auto l_close = lower_bound(slopes.begin(), slopes.end(), b);
			auto u_close = upper_bound(slopes.begin(), slopes.end(), b);
			_print(*l_close);
			_print(*u_close);
			lli mn = min(b-*l_close, *u_close-b);
			lli p = pow(mn, 2);
			if(p - 4*a*c >= 0){
				cout<<"NO"<<endl;
			}else{
				cout<<"YES"<<endl;
				cout<<mn<<endl;
			}
		}
		cout<<endl;
	}



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
