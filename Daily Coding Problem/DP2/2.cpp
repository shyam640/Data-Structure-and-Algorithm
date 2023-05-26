#include<bits/stdc++.h>
using namespace std;

vector<int> skippedProduct(vector<int> arr){
	// Method 1
	vector<int> ans;
	for(int i=0;i<arr.size();i++){
		int prod = 1;
		for(int j=i-1;j>=0;j--){
			prod = prod*arr[j];
		}
		for(int j=i+1;j<arr.size();j++){
			prod = prod*arr[j];
		}
		ans.push_back(prod);
	}
	return ans;
	
	// Method 2
	vector<int> ans;
	long long int prod = 1;
	for(auto val : arr)	prod*=val;
	for(auto val : arr)	ans.push_back(prod/val);
	return ans;

	// Method 3
	int n = arr.size();
	vector<int> left(n, 1), right(n, 1), ans(n);
	for(int i=1;i<n;i++){
		left[i]  = left[i-1]*arr[i-1];
	}
	for(int i=n-2;i>=0;i--){
		right[i] = right[i+1]*arr[i+1];
	}
	for(int i=0;i<n;i++){
		ans[i] = left[i]*right[i];
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	vector<int> arr(n);
	for(auto &val : arr)	cin>>val;
	vector<int> ans = skippedProduct(arr);
	for(auto val : ans)	cout<<val<<" ";
	cout<<endl;
	return 0;
}
