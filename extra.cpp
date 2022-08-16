#include<bits/stdc++.h>
using namespace std;

vector<vector<long long int>> storePosition(vector<char> arr){
    vector<vector<long long int>> stored(26);
    for(long long int i=0;i<arr.size();i++){
         if(arr[i]!='\0')
            stored[arr[i]-'a'].push_back(i);
    }
    return stored;
}

bool no_duplicate(vector<vector<long long int>> arr,long long int l,long long int r){
    for(long long int i=0;i<26;i++){
        auto first = lower_bound(arr[i].begin(),arr[i].end(),l-1);
        if(first != arr[i].end() and *first<r){
            first++;
            if(first != arr[i].end() and *first < r)
                return false;
        }
    }
    return true;
}

long long int goodString (long long int N, long long int Q, string S, vector<long long int> arr, vector<vector<long long int> > ranges) {
    vector<char> ch(S.length()+1);
    for(long long int i=0;i<N;i++)
        ch[i] = S[i];
    long long int i=0;
    long long int count=0;
    for(i=0;i<N;i++){
        // vector<vector<char>> stored = storePosition(ans[i]);
        ch[arr[i]-1] = '\0';
        bool flag=1;
        for(long long int j=0;j<Q;j++){
            if(!no_duplicate(storePosition(ch), ranges[j][0], ranges[j][1])){
                flag=0;
                break;
            }
        }
        count++;
        if(flag){
            if(i==0)    count--;
            break;
        }
    }

    return count;
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);
    long long int T;
    cin >> T;
    for(long long int t_i = 0; t_i < T; t_i++)
    {
        long long int N;
        cin >> N;
        long long int Q;
        cin >> Q;
        string S;
        cin >> S;
        vector<long long int> arr(N);
        for(long long int i_arr = 0; i_arr < N; i_arr++)
        {
        	cin >> arr[i_arr];
        }
        vector<vector<long long int> > ranges(Q, vector<long long int>(2));
        for (long long int i_ranges = 0; i_ranges < Q; i_ranges++)
        {
        	for(long long int j_ranges = 0; j_ranges < 2; j_ranges++)
        	{
        		cin >> ranges[i_ranges][j_ranges];
        	}
        }

        long long int out_;
        out_ = goodString(N, Q, S, arr, ranges);
        cout << out_;
        cout << "\n";
    }
}


