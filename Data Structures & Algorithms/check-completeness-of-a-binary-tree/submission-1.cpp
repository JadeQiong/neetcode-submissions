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
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int h = 0;
        while(!q.empty()){
           auto cur = q.front();
           q.pop();
           if(cur){
            q.push(cur->left);
            q.push(cur->right);
           } else {
            while(!q.empty()){
                if(q.front()) return false;
                q.pop();
            }
           }
        }
        return true;
    }
};