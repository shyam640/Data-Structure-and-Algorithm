//Question Link - https://leetcode.com/problems/reverse-linked-list-ii/



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
private:
        bool stop;
        ListNode* back;
    public:
        void recurseReverse(ListNode* right,int m,int n){
            if(n==1)
                return;
            right = right->next;
            if(m>1)
                back = back->next;
            recurseReverse(right,m-1,n-1);
            if(back==right || right->next == back)
                stop = true;
            if(!stop){
                int t = back->val;
                back->val = right->val;
                right->val = t;
                back = back->next;
            }
        }
        ListNode* reverseBetween(ListNode* head, int left, int right) { 
            back = head;
            stop = false;
            recurseReverse(head,left,right);
            return head;
        }
};