// Question Link -> https://leetcode.com/problems/validate-binary-search-tree/


class Solution {
public:
    TreeNode* prev = NULL;
    bool isValidBST(TreeNode* root) {
        if(root==NULL)
            return true;
        bool temp = isValidBST(root->left);
        if(prev==NULL)
            prev = root;
        else if(prev->val >= root->val)
            return false;
        prev = root;
        return temp and isValidBST(root->right);
    }
};