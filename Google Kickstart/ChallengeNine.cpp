#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int t;
    cin>>t;
    long long int c=1;
    while(t--){
        long long int n;
        cin>>n;
        long long int temp = n;
        long long int sum=0;
        while(temp){
            int rem = temp%10;
            sum+=rem;
            temp/=10;
        }
        int num;
        if(sum%9==0)
            num=0;
        else
            num = 9 - sum%9;
        long long int i=0;
        string s = to_string(n);
        long long int val,final_ans=INT_MAX;
        while(i<s.length()){
            if(i==0 and num==0){
                i++;
                continue;
            }
            string ans = s.substr(0,i) + to_string(num) + s.substr(i);
            // cout<<ans<<endl;
            val = stoi(ans);
            if(val%9==0)
                final_ans = min(final_ans,val);
            i++;
        }
        string ans = s.substr(0,i) + to_string(num);
         val = stoi(ans);
         if(val%9==0 and final_ans!=n)
               final_ans = min(final_ans,val);
        cout<<"Case #"<<c<<": "<<final_ans<<"\n";
        c++;
    }
}

