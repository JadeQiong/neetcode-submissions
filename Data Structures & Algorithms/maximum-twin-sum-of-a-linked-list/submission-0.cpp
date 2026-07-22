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
    int pairSum(ListNode* head) {
        ListNode* head2 = head;
        ListNode* cur = head;
        ListNode* prev = nullptr;
        while(head2){
            prev = cur;
            cur = cur->next;
            head2 = head2->next;
            if(head2)
            head2 = head2->next;
        }
        prev->next = nullptr;
        cout << " first half's tail " << prev->val << endl;
        cout << "half's val " << cur->val << endl;
        ListNode* newHead = cur;
        // reverse the first half
        cur = head;

        while(cur){
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        int ans = 0;
        cur = prev;
        // ListNode* tmp = prev;
        // while(tmp){
        //     cout << tmp->val << " ";
        //     tmp = tmp->next;
        // }
        // cout << endl;
        while(newHead){
            cout << newHead->val << " + " << cur->val << endl;
            ans = max(ans, newHead->val + cur->val);
            newHead = newHead->next;
            cur = cur->next;
        }
        return ans;
        
    }
};