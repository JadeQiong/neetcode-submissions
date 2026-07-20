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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        ListNode* cur = l1;
        while(cur){
            s1.push(cur->val);
            cur = cur->next;
        }
        cur = l2;
        while(cur){
            s2.push(cur->val);
            cur = cur->next;
        }
        int num = 0;
        ListNode* prev = nullptr;
        while(!s1.empty() || !s2.empty()){
            if(!s1.empty()){
                num += s1.top();
                s1.pop();
            }
            if(!s2.empty()){
                num += s2.top();
                s2.pop();
            }
            ListNode* tmp = new ListNode(num%10);
            tmp->next = prev;
            prev = tmp;
            num /= 10;
        }
        if(num){
            ListNode* tmp = new ListNode(num%10);
            tmp->next = prev;
            prev = tmp;
            
        }
        return prev;
    }
};