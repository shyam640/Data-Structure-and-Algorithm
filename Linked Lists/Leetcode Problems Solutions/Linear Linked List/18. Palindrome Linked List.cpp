//Question Link - https://leetcode.com/problems/palindrome-linked-list/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head==NULL or head->next==NULL)
            return true;
        stack<int> st;
        ListNode* temp1 = head;
        ListNode* temp2 = head;
        while(temp1!=NULL){
            st.push(temp1->val);
            temp1 = temp1->next;
        }
        while(temp2!=NULL and !st.empty()){
            if(st.top()!=temp2->val) 
                return false;
            st.pop();
            temp2 = temp2->next;
        }
        return true;
    }
};