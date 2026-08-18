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
    void insert(ListNode* dummyHead, ListNode* n){
        ListNode* node = new ListNode(n->val);
        // cout << " inserting " << node->val << endl;
        ListNode* cur = dummyHead;
        ListNode* prev = dummyHead;
        while(cur && cur->val <= node->val){
            prev = cur;
            cur = cur->next;
        }

        node->next = prev->next;
        prev->next = node;
    }

    ListNode* insertionSortList(ListNode* head) {
        ListNode* dummyHead = new ListNode(-5001);
        while(head){
            insert(dummyHead, head);
            head = head->next;
        }
        return dummyHead->next;
    }
};