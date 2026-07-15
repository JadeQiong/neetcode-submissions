/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*> stk;
        TreeNode* node1 = nullptr;
        TreeNode* node2 = nullptr;
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        while(!stk.empty() || cur){
            while(cur){
                stk.push(cur);
                cur = cur->left;
            }
            cur = stk.top();
            stk.pop();
            if(prev && prev->val >= cur->val){
                node2 = cur;
                if(!node1){
                    node1 = prev;
                } else break;
            }
            prev = cur;
            cur = cur->right;
        }
        swap(node1->val, node2->val);
    }
};