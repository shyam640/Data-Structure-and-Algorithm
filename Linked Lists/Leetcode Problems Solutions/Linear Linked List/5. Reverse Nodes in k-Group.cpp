// Question Link --> https://leetcode.com/problems/reverse-nodes-in-k-group/



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
    int lengthofLL(ListNode* head){
        int len=0;
        while(head!=NULL){
            len++;
            head= head->next;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* prevptr = NULL;
        ListNode* currptr = head;
        ListNode* nextptr;
        int count=0;
        int length = lengthofLL(head);
        
        while(currptr!=NULL and count<k){
            nextptr = currptr->next;
            currptr->next = prevptr;
            prevptr = currptr;
            currptr = nextptr;
            count++;
        }
        if(nextptr!=NULL and (length-count)>=k)
            head->next = reverseKGroup(nextptr,k);
        else{
            ListNode* temp = prevptr;
            while(temp->next!=NULL)
                temp = temp->next;
            while(nextptr!=NULL){
                temp->next = nextptr;
                temp = temp->next;
                nextptr = nextptr->next;
            }
            
        }
        return prevptr;
    }
};