// Question Link --> https://leetcode.com/problems/remove-nth-node-from-end-of-list/


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
    int lenOfLinkedList(ListNode* head){
        int l=0;
        while(head!=NULL){
            l++;
            head = head->next;
        }
        return l;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = lenOfLinkedList(head);
        int t = len-n-1;
        if(head==NULL)
            return head;
        if(head->next==NULL or (len-n)==0){
            // cout<<t<<endl;
            ListNode* todelete =  head;
            head = head->next;
            delete todelete;
            return head;
        }
        if(head->next->next==NULL){
            ListNode* todelete;
            if(n==1){
                todelete = head->next->next;
                head->next = NULL;
            }else if(n==2){
                todelete = head;
                head = head->next;
            }
            delete todelete;
            return head;
        }
        ListNode* temp = head;
        while(t-- and temp!=NULL){
            temp = temp->next;
        }
        ListNode* todelete = temp->next;
        temp->next = temp->next->next;
        delete todelete;
        return head;
    }
};