// * FULL BINARY TREE - Have 0 or 2 nodes
// * COMPLETE BINARY TREE - All Levels are completely filled except the last level and the last level has all nodes as left as possible
// * PERFECT BINARY TREE - All leaf nodes at same level
// * BALANCED BINARY TREE - Maximum Height of tree is log(N)
// * DEGENERATE TREE - All left or all right only.


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

int main(){
   struct TreeNode* root = new TreeNode(1);
   root->left = new TreeNode(2);
   root->left->right = new TreeNode(4);
}