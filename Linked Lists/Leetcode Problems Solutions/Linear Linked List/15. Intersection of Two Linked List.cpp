//Question Link - https://leetcode.com/problems/intersection-of-two-linked-lists/



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
    int lengthOfList(ListNode* head){
        int len = 0;
        ListNode* temp = head;
        while(temp!=NULL){
            temp = temp->next;
            len++;
        }
        return len;
    }
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = lengthOfList(headA);
        int l2 = lengthOfList(headB);
        ListNode* ptr1;
        ListNode* ptr2;
        int diff;
        if(l1<l2){
            ptr1 = headA;
            ptr2 = headB;
            diff = l2-l1;
        }else{
            ptr1 = headB;
            ptr2 = headA;
            diff = l1-l2;
        }
        while(diff-- and ptr2!=NULL){
            ptr2 = ptr2->next;
        }
        while(ptr1 and ptr2){
            if(ptr1 == ptr2)
                break;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        return ptr2;
    }
    
};