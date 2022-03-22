#include<bits/stdc++.h>
using namespace std;
bool check(long long int n){
    long long int sum=0,prod=1;
    while(n){
        int rem = n%10;
        sum+=rem;
        prod*=rem;
        n/=10;
    }
    return prod%sum == 0;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int t;
    cin>>t;
    long long int c=1;
    while(t--){
        long long int a,b;
        cin>>a>>b;
        long long int ans=0;
        for(long long int i=a;i<=b;i++){
            if(check(i))
                ans++;
        }
        cout<<"Case #"<<c<<": "<<ans<<"\n";
        c++;
    }
}