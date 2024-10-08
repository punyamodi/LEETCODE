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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempa=headA;
        ListNode* tempb=headB;
        int c=0;
        while(headA!=headB){
            if(headB==NULL){
                headB=tempa;
                headA=headA->next;
            }
            else if(headA==NULL){
                headA=tempb;
                headB=headB->next;
            }
            else{
                headA=headA->next;
                headB=headB->next;
            }

        }
        return headA;
    }
    
};