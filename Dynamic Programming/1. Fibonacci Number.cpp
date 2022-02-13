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


template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}




void file_input_output(){
   ios_base::sync_with_stdio(0); 
   cin.tie(0); 
   cout.tie(0);
   #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
   #endif
}

int recursiveMethod(int n) {
   if(n<=1)
      return n;
   return recursiveMethod(n-1)+recursiveMethod(n-2);
}

void iterativeMethod(int n) {
   vector<int> fib;
   fib.push_back(0);
   fib.push_back(1);
   for(int i=2;i<=n;i++)
      fib.push_back(fib[i-1]+fib[i-2]);
   cout<<"N-th fibonacci number using Iterative Method is : " << fib[fib.size()-1] << endl;
}

void dynamicProgrammingMethod(int n,vector<int>& dp) {
   // Method 1 : Simple DP (Tabulation -> Bottom-Up approach)
   dp[0] = 0;
   dp[1] = 1;
   for(int i=2;i<=n;i++)
      dp[i] = dp[i-1]+dp[i-2];
   cout<<"N-th fibonacci number DP Method is : " << dp[n] << endl;

   // Method 2 : Simple DP (Memoization -> Top-Down approach)
   if(n<=1) return n;
   if(dp[n]!=-1)  return dp[n];
   dp[n] = dynamicProgrammingMethod(n-1,dp) + dynamicProgrammingMethod(n-1,dp);
   cout<<"N-th fibonacci number DP Method is : " << dp[n] << endl;

   // Method 3 : Space Optimizing
   int a=0,b=1,c;
   if(n==0)
      cout<<"N-th fibonacci number DP Optimized Method is : " << a << endl;
   for(int i=2;i<=n;i++){
      c = a + b;
      a = b;
      b = c;
   }
   cout<<"N-th fibonacci Number DP Optimized Method is : " << c << endl;
}

void formulaMethod(int n) {
   int fib = (pow((1+sqrt(5))/2,n) - pow((1-sqrt(5))/2,n)) / sqrt(5);
   cout<<"N-th fibonacci number using Formula Method is : "<< fib << endl;
}

void multiply(int F[2][2], int M[2][2]){
    int x = F[0][0] * M[0][0] +
            F[0][1] * M[1][0];
    int y = F[0][0] * M[0][1] +
            F[0][1] * M[1][1];
    int z = F[1][0] * M[0][0] +
            F[1][1] * M[1][0];
    int w = F[1][0] * M[0][1] +
            F[1][1] * M[1][1];
     
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}
 
void power(int F[2][2], int n){
    int i;
    int M[2][2] = { { 1, 1 }, { 1, 0 } };
    for(i = 2; i <= n; i++)
        multiply(F, M);
}

int matrixPowerMethod(int n) {
   int F[2][2] = { { 1, 1 }, { 1, 0 } };
   if (n == 0)
      return 0;
   power(F, n - 1);
   return F[0][0];
}

int main(int argc, char const *argv[]) {
   clock_t begin = clock();
   file_input_output();       // Taking file input and displaying output in output.txt
   // Write your code here....
   cout<<"Choose Method"<<endl;
   cout<<"1. Recursion O(N)"<<endl;
   cout<<"2. Iteration O(N)"<<endl;
   cout<<"3. Dynamic Programming O(N)"<<endl;
   cout<<"4. Using Formula O(1)"<<endl;
   cout<<"5. Using Matrix Power O(logN)"<<endl;
   
   int n;
   cout<<"Enter N-th number : ";
   cin>>n;
   cout<<"Enter Choice : ";
   int choice;
   cin>>choice;
   
   switch(choice){
      case 1 : {
                  int ans = recursiveMethod(n);
                  cout<<"N-th fibonacci number using Recursive Method is : " << ans <<endl;
                  break;
               }
      case 2 : {
                  iterativeMethod(n);
                  break;
               }
      case 3 : {
                  vector<int> dp(n+2,-1);
                  dynamicProgrammingMethod(n,dp);
                  break;
               }
      case 4 : {
                  formulaMethod(n);
                  break;
               }
      case 5 : {
                  int ans = matrixPowerMethod(n);
                  cout<<"N-th fibonacci number using Matrix Power is : " << ans <<endl;
                  break;
               }
      default :{
                  cout<<"Enter Valid Choice !!!!"<<endl;
                  break;
               }
   }

   #ifndef ONLINE_JUDGE 
   clock_t end = clock();
   cout<<"\n\nExecuted In: "<<double(end - begin) / CLOCKS_PER_SEC*1000<<" ms";
   #endif 
   return 0;
}