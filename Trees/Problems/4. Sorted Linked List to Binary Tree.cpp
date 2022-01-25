// Question Link -> https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/


class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return new TreeNode(head->val);
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* mid = NULL;
        while(slow and fast != NULL and fast->next!=NULL){
            mid = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(mid->next->val);
        ListNode* temp = mid->next->next;
        mid->next = NULL;
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(temp);
        return root;
            
    }
};