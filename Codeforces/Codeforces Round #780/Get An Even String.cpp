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


template <typename T> T gcd(T a, T b){if(a%b) return gcd(b,a%b);return b;}
template <typename T> T lcm(T a, T b){return (a*(b/gcd(a,b)));}
#define              fast_io                    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
const long double pi = atan2(0, -1);


void fill(vector<vector<int>> &board,int x, int y){
   if ((x == 1 && y == 1))
            board[2 - 1][3 - 1] = 2;
        else if ((x == 1 && y == 8))
            board[2 - 1][6 - 1] = 2;
        else if (x == 8 && y == 1)
            board[7 - 1][3 - 1] = 2;
        else if (x == 8 && y == 8)
            board[7 - 1][6 - 1] = 2;
        else if (x == 1)
        {
            board[x + 2 - 1][y - 1 - 1] = 2;
            board[x + 2 - 1][y + 1 - 1] = 2;
        }
        else if (x == 8)
        {
            board[x - 2 - 1][y - 1 - 1] = 2;
            board[x - 2 - 1][y + 1 - 1] = 2;
        }
        else if (y == 1)
        {
            board[x - 1 - 1][y + 2 - 1] = 2;
            board[x + 1 - 1][y + 2 - 1] = 2;
        }
        else if (y == 8)
        {
            board[x - 1 - 1][y - 2 - 1] = 2;
            board[x + 1 - 1][y - 2 - 1] = 2;
        }
        else if (x == 2 && y == 2)
        {
            board[x - 1 - 1][y + 3 - 1] = 2;
            board[x + 2 - 1][y - 1 - 1] = 2;
        }
        else if (x == 2 && y == 7)
        {
            board[x - 1 - 1][y - 2 - 1] = 2;
            board[x + 3 - 1][y + 1 - 1] = 2;
        }
        else if (x == 7 && y == 2)
        {
            board[x + 1 - 1][y + 3 - 1] = 2;
            board[x - 2 - 1][y - 1 - 1] = 2;
        }
        else if (x == 7 && y == 7)
        {
            board[x + 1 - 1][y - 3 - 1] = 2;
            board[x - 2 - 1][y + 1 - 1] = 2;
        }
        else if (x == 2)
        {
            board[x - 1 - 1][y - 2 - 1] = 2;
            board[x + 1 - 1][y + 2 - 1] = 2;
        }
        else if (x == 7)
        {
            board[x - 1 - 1][y - 2 - 1] = 2;
            board[x + 1 - 1][y + 2 - 1] = 2;
        }
        else if (y == 2)
        {
            board[x - 2 - 1][y - 1 - 1] = 2;
            board[x + 2 - 1][y + 1 - 1] = 2;
        }
        else if (y == 7)
        {
            board[x - 2 - 1][y + 1 - 1] = 2;
            board[x + 2 - 1][y - 1 - 1] = 2;
        }
        else
        {
            board[x - 1 - 1][y - 2 - 1] = 2;
            board[x + 1 - 1][y + 2 - 1] = 2;
        }
}

int main() {
   fast_io
   // Write your code here...


   lli t;
    cin>>t;
    while(t--){
        lli x,y;
        cin>>x>>y;
        vector<vector<int>> board(n,vector<int>(n));
        board[x-1][y-1] = 1;
        fill(board,x,y);
        
        for(int i=0;i<8;i++){
            for(int j=0;j<8;j++){
                cout<<board[i][j];
            }
            cout<<endl;
        }
    }

   return 0;
}