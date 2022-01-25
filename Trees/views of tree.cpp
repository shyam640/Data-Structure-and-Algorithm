// - Top View
// - Bottom View
// - Left/Right View

#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
   int data;
   struct TreeNode* left;
   struct TreeNode* right;
   TreeNode(int val){
      data = val;
      left = right = NULL;
   }
}

// Top View of Tree
// T.C. - O(n)    S.C. - O(n)
vector<int> topViewOfTree(TreeNode* root){
   vector<int> ans;
   if(root==NULL)
      return ans;
   map<int,int> mp;
   queue<pair<TreeNode*,int>> qp;
   qp.push({root,0});
   while(!qp.empty()){
      auto it = qp.front;
      qp.pop();
      TreeNode* node = it.first;
      int line = it.second;
      if(mp.find(line)==mp.end())
         mp[line] = node->val;
      if(node->left)
         qp.push({node->left,line-1});
      if(node->right)
         qp.push(node->right,line+1);
   }
   for(auto it : mp)
      ans.push_back(it.second);
   return ans;
}

// Bottom View of Tree
// T.C. - O(n)   S.C. - O(n)
vector<int> bottomViewOfTree(TreeNode* root){
   vector<int> ans;
   if(root==NULL)
      return ans;
   map<int,int> mp;
   queue<pair<TreeNode*,int>> qp;
   qp.push({root,0});
   while(!qp.empty()){
      auto it = qp.front;
      qp.pop();
      TreeNode* node = it.first;
      int line = it.second;
      mp[line] = node->val;
      if(node->left)
         qp.push({node->left,line-1});
      if(node->right)
         qp.push(node->right,line+1);
   }
   for(auto it : mp)
      ans.push_back(it.second);
   return ans;
}

int main(){
   struct TreeNode* root = new TreeNode(10);
   root->left = new TreeNode(20);
   root->right = new TreeNode(30);
   root->left->right = new TreeNode(50);
   root->right->right = new TreeNode(60);
   root->right->left = new TreeNode(40);
}