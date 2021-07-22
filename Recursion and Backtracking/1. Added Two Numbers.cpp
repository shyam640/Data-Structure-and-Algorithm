// Question Link --> https://leetcode.com/problems/add-two-numbers/



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
    void deleteHead(ListNode* &head){
        ListNode* todelete = head;
        head = head->next;
        delete todelete;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = new ListNode();
        ListNode* sumNode = ans;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        int carry=0;
        while(temp1!=NULL or temp2!=NULL){
            int a = (temp1!=NULL)?temp1->val:0;
            int b = (temp2!=NULL)?temp2->val:0;
            int sum = carry + a + b;
            carry = sum/10;
            sumNode->next = new ListNode(sum%10);
            sumNode = sumNode->next;
            if(temp1!=NULL) temp1 = temp1->next;
            if(temp2!=NULL) temp2 = temp2->next;
        }
        if(carry>0)
            sumNode->next = new ListNode(carry);
        deleteHead(ans);
        return ans;
    }
};