#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n,k;
	    cin>>n>>k;
	    vector<int> arr(n);
	    for(int i=0;i<n;i++)
	        cin>>arr[i];
        sort(arr.begin(),arr.end());
        int i=0,ans=0;
        if(n==1){
            if(arr[0]<=k)
                ans++;
            else if(round(arr[0]/2) <= k)
                ans++;
        }else{
            for(i=0;i<n;i++){
                if(k>=arr[i]){
                    k-=arr[i];
                    ans++;
                }
            }
            if(i<n){
                int last = round(arr[i]/2);
                if(last<=k)
                    ans++;
            }
        }
        cout<<ans<<endl;
	}
	return 0;
}
