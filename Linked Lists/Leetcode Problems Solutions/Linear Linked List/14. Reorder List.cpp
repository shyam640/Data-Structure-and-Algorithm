//Question Link - https://leetcode.com/problems/reorder-list/



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
    void reorderList(ListNode* head) {
        ListNode* temp = head;
        stack<ListNode*> st;
        int len=0;
        while(temp!=NULL){
            st.push(temp);
            temp = temp->next;
            len++;
        }
        temp = head;
        int i=0;
        while(i<len-1){
            ListNode* next = temp->next;
            temp->next = st.top();
            i++;
            st.pop();
            temp->next->next = next;
            temp = next;
            i++;
        }
        temp->next = NULL;
    }
};