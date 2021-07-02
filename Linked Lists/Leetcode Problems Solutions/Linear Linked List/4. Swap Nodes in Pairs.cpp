// Question Link --> https://leetcode.com/problems/swap-nodes-in-pairs/


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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL or head->next==NULL)
            return head;
        ListNode* temp = head;
        ListNode* prevptr = NULL;
        ListNode* currptr = head;
        ListNode* nextptr;
        int count=0;
        while(currptr!=NULL and count<2){
            nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
            count++;
        }
        if(nextptr!=NULL)
            head->next = swapPairs(nextptr);
        return prevptr;
    }
};