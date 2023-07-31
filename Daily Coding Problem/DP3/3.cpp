#include<bits/stdc++.h>
using namespace std;

class TreeNode {
	public:
		int data;
		TreeNode* left;
		TreeNode* right;
		TreeNode(int val){
			data = val;
			left = NULL;
			right = NULL;
		}
};

void serialize(TreeNode* root){
	if(!root){
		return;
	}
	serialize(root->left);
	cout<<root->data<<" ";
	serialize(root->right);
}

TreeNode* deserealize(vector<string> arr, int idx=0, int min = -1e9, int max = 1e9){
	if(idx==arr.size())	return NULL;
	int val = stoi(arr[idx]);
	if(val>max or val<min)	return NULL;
	TreeNode* root = new TreeNode(val);
	root->left = deserealize(arr, idx+1, min, val);
	root->right = deserealize(arr, idx+1, val, max);
	return root;
}

int main(){
	int n;
	cin>>n;
	vector<string> arr(n);
	for(auto &val : arr)	cin>>val;
	TreeNode* root = deserealize(arr);
	serialize(root);
	return 0;
}