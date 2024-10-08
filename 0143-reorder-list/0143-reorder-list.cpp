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
    void reorderList(ListNode* head) {
        vector<int> v;
        int len = 0, i;
        ListNode* temp = head;

        while (temp != NULL) {
            v.push_back(temp->val);
            temp = temp->next;
            len++;
        }

        vector<int> a; 
        for (i = 0; i < len / 2; i++) {
            a.push_back(v[i]);              
            a.push_back(v[len - i - 1]);    
        }
        if (len % 2 != 0) {
            a.push_back(v[i]);
        }

        temp = head;
        for (int i = 0; i < len; i++) {
            temp->val = a[i];
            temp = temp->next;
        }
    }
};
