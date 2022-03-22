#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int even=0,odd=0;
	    while(n){
	        int rem = n%10;
	        if(rem%2==0)
	            even++;
            n/=10;
	    }
	    if(even<=1)
	        cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
	}
	return 0;
}