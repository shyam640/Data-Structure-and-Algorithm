// Question Link --> https://leetcode.com/problems/merge-two-sorted-lists


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
    void deleteAtHead(ListNode* &head){
        ListNode* todelete = head;
        head = head->next;
        delete todelete;
    }
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* temp = ans;
        while(l1!=NULL and l2!=NULL){
            if(l1->val>l2->val){
                ListNode* a = new ListNode(l2->val);
                if(temp==NULL){
                    temp = a;
                }
                while(temp->next!=NULL){
                    temp = temp->next;
                }
                temp->next = a;
                l2 = l2->next;
            }else{
                ListNode* b = new ListNode(l1->val);
                if(temp==NULL){
                    temp = b;
                }
                while(temp->next!=NULL){
                    temp = temp->next;
                }
                temp->next = b;
                l1 = l1->next;
            }
            temp = temp->next;
        }
        while(l1!=NULL){
            ListNode* c = new ListNode(l1->val);
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = c;
            l1 = l1->next;
        }
        while(l2!=NULL){
            ListNode* d = new ListNode(l2->val);
            while(temp->next!=NULL){
                temp = temp->next;
            }
            temp->next = d;
            l2 = l2->next;
        }
        deleteAtHead(ans);
        return ans;
    }
};