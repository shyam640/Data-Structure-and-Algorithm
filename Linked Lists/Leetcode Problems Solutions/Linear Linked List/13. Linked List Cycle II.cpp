//Question Link - https://leetcode.com/problems/linked-list-cycle-ii/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* start = head;
        while(fast!=NULL and fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast==slow){
                while(slow!=start){
                    slow=slow->next;
                    start = start->next;
                }
                return start;
            }
        }
        return NULL;
    }
};