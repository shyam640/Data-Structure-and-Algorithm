// Question Link --> https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/



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
    void deleteAtHead(ListNode* &ans){
        ListNode* todelete = ans;
        ans = ans->next;
        delete todelete;
    }
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        ListNode* ans = new ListNode(0,temp);
        ListNode* prev = ans;
        if(head==NULL or head->next==NULL)
            return head;
        while(temp!=NULL){
            if(temp->next!=NULL and temp->val == temp->next->val){
                while(temp->next!=NULL and temp->val == temp->next->val)
                    temp = temp->next;
                prev->next = temp->next;
            }else{
                prev = prev->next;
            }
            temp = temp->next;
        }
        deleteAtHead(ans);
        return ans;
    }
};