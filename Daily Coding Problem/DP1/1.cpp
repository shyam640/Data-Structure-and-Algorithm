#include<bits/stdc++.h>
using namespace std;
bool pairSum(vector<int> arr, int n, int k){
	// Method 1
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i] + arr[j] == k)	return true;
		}
	}
	return false;


	// Method 2
	map<int,bool> mp;
	for(int i=0;i<n;i++){
		mp[arr[i]] = true;
	}
	for(int i=0;i<n;i++){
		if(mp[k-arr[i]])	return true;
	}
	return false;
}
int main(){
	int n, k;
	cin>>n>>k;
	vector<int> arr(n);
	for(auto &val : arr)	cin>>val;
	if(pairSum(arr, n, k))		cout<<”YES”<<endl;
	else	cout<<”NO”<<endl;
	return 0;
}
