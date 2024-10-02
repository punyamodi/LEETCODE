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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        vector<int> l;
        for(int i=0;i<n;i++){
            ListNode* itr = lists[i];
            while(itr != NULL){
                l.push_back(itr->val);
                itr = itr->next;
            }
        }
        if(n==0 || l.size()==0){
            return NULL;
        }
        sort(l.begin(),l.end());
        ListNode* head = new ListNode(l[0]);
        ListNode* it = head;
        for(int i=1;i<l.size();i++){
            ListNode* a = new ListNode(l[i]);
            it->next = a;
            it = it->next;
        }
        it->next = NULL;
        return head;
    }
};