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
    int ans = 0;
    void dfs(TreeNode* node, int cur){
        if(!node) return;
        if(!node->left && !node->right){
            cur*=10;
            cur+=node->val;
            //cout << cur << endl;
            ans += cur;
            return;
        }
        cur *= 10;
        dfs(node->left, cur+node->val);
        dfs(node->right, cur+node->val);
    }
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};