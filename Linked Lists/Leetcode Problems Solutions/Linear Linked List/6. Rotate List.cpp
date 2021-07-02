// Question Link --> https://leetcode.com/problems/rotate-list/


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
    int length_of_LinkedList(ListNode* head){
        int len = 0;
        while(head!=NULL){
            head = head->next;
            len++;
        }
        return len;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        int len = length_of_LinkedList(head);
        if(head==NULL or head->next==NULL or k==0 or k%len==0)
            return head;
        while(k>len)
            k%=len;
        k=len-k;
        ListNode* temp = head;
        int count=1;
        while(count<k and temp!=NULL){
            temp = temp->next;
            count++;
        }
        ListNode* restList = temp;
        while(temp->next!=NULL)
            temp = temp->next;
        temp->next = head;
        head  = restList->next;
        restList->next = NULL;
        return head;
    }
};