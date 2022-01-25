// - Level Order Traversal
// - Zig-Zag Order Traversal
// - Boundary Traversal
// - (Recursive and Iterative)
// - Inorder : left --> root --> right
// - Preorder : root --> left --> right
// - Postorder : left --> right --> root

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

// Level Order Traversal
vector<vector<int>> LevelOrderTraversal(TreeNode* root){
   vector<vector<int>> ans;
   if(root==NULL)
      return ans;
   queue<TreeNode*> q;
   q.push(root);
   while(!q.empty()){
      vector<int> level;
      for(int i=0;i<q.size();i++){
         TreeNode *temp = q.front();
         q.pop();
         if(root->left != NULL)  q.push(root->left);
         if(root->right != NULL)  q.push(root->right);
         level.push_back(root->val);
      }
      ans.push_back(level);
   }
   return ans;
}

// Zig-Zag Traversal
vector<vector<int>> zig_zagTraversal(TreeNode* root){
   vector<vector<int>> ans;
   if(root==NULL)
      return ans;
   queue<TreeNode*> q;
   q.push(root);
   bool flag=0;
   while(!q.empty()){
      vector<int> level;
      for(int i=0;i<q.size();i++){
         TreeNode *temp = q.front();
         q.pop();
         if(root->left != NULL)  q.push(root->left);
         if(root->right != NULL)  q.push(root->right);
         level.push_back(root->val);
      }
      if(!flag){
         ans.push_back(level);
         flag=!flag;
      }else{
         reverse(level.begin(),level.end());
         ans.push_back(level);
         flag=!flag;
      }
   }
   return ans;
}

// Boundary Traversal
void addLeftBoundary(TreeNode* root,vector<int>& ans){
   TreeNode* curr = root->left;
   while(curr){
      if(!isLeaf(curr))
         ans.push_back(curr->data);
      if(curr->left)
         curr = curr->left;
      else
         curr = curr->right;
   }
}

void addLeafNode(TreeNode* root,vector<int>& ans){
   if(isLeaf(root)){
      ans.push_back(root->data);
      return;
   }
   if(root->left)
      addLeafNode(root->left,ans);
   if(root->right)
      addLeafNode(root->right,ans);
}

void addRightBoundary(TreeNode* root,vector<int>& ans){
   TreeNode* curr = root->right;
   vector<int> temp;
   while(curr){
      if(!isLeaf(curr))
         temp.push_back(curr->data);
      if(curr->right)
         curr = curr->right;
      else
         curr = curr->left;
   }
   for(int i=temp.size()-1;i>=0;i--)
      ans.push_back(temp[i]);
}

vector<int> boundaryTraversal(TreeNode* root){
   vector<int> ans;
   if(root==NULL)
      return ans;
   if(!isLeaf(root))
      ans.push_back(root->data);
   addLeftBoundary(root,ans);
   addLeafNode(root,ans);
   addRightBoundary(root,ans);
   return ans;
}

// Vertical Traversal
vector<vector<int>> verticalTraversal(TreeNode* root){
   map<int,map<int,multiset<int>> nodes;
   queue<pair<TreeNode*,pair<int,int>> todo;
   todo.push({root,{0,0}});
   while(!todo.empty()){
      auto p = todo.first;
      todo.pop();
      TreeNode* node = p.first;
      int x = p.second.first , y = p.second.second;
      nodes[x][y].insert(node->val);
      if(node->left)
         todo.push({root->left,{x-1,y-1}});
      if(node->right)
         todo.push({root->right},{x+1,y+1});
   }
   vector<vector<int>> ans;
   for(auto p : nodes){
      vector<int> col;
      for(auto q : p.second){
         col.insert(col.end(),q.second.begin(),q.second.end());
      }
      ans.push_back(col);
   }
   return ans;
}

// Recursive Preorder , Inorder and Postorder
// T.C. = O(n)     S.C. = O(n)
void preOrderRecursive(TreeNode* root){
   if(root==NULL)
      return;
   cout<<root->data<<" ";
   preorder(root->left);
   preorder(root->right);
}

// T.C. = O(n)     S.C. = O(n)
void inOrderRecursive(TreeNode* root){
   if(root==NULL)
      return;
   inOrder(root->left);
   cout<<root->data<<" ";
   inOrder(root->right);
}

// T.C. = O(n)     S.C. = O(n)
void postOrderRecursive(TreeNode* root){
   if(root==NULL)
      return;
   postOrder(root->left);
   cout<<root->data<<" ";
   postOrder(root->right);
}

// Iterative Preorder , Inorder and Postorder
// T.C. = O(n)     S.C. = O(n)
vector<int> preOrderIterative(TreeNode* root){
   vector<int> preorder;
   if(root==NULL)
      return preorder;
   stack<TreeNode*> st;
   st.push(root);
   while(!st.empty()){
      root = st.top();
      st.pop();
      preorder.push_back(root->val);
      if(root->right!=NULL)
         st.push(root->right);
      if(root->left!=NULL)
         st.push(root->left);
   }
   return preorder;
}

// T.C. = O(n)     S.C. = O(n)
vector<int> inOrderIterative(TreeNode* root){
   stack<TreeNode*> st;
   TreeNode* node = root;
   vector<int> inorder;
   if(root==NULL)
      return inorder;
   while(true){
      if(node!=NULL){
         st.push(node);
         node = node->left;
      }else{
         if(st.empty())
            break;
         node = st.top();
         st.pop();
         inorder.push_back(node->val);
         node = node->right;
      }
   }
   return inorder;
}

// T.C. = O(n)     S.C. = O(n)
vector postOrderIterative(TreeNode* root){
   vector<int> postorder;
   stack<TreeNode*> s1,s2;
   s1.push(root);
   TreeNode* node;
   while(!s1.empty()){
      node = s1.top();
      s1.pop();
      s2.push(node);
      if(node->left)
         s1.push(node->left);
      if(node->right)
         s1.push(node->right);
   }
   while(!s2.empty()){
      postorder.push_back(s2.top());
      s2.pop();
   }
   return postorder;
}

int main(){
   struct TreeNode* root = new TreeNode(2);
   root->left = new TreeNode(1);
   root->right = new TreeNode(4);
   root->right->left = new TreeNode(3);
}