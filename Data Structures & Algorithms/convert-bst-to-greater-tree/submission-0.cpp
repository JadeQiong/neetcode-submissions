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
    int sum = 0;
    void getSum(TreeNode* root){
        if(!root){
            return;
        }
        sum += root->val;
        getSum(root->left);
        getSum(root->right);
    }
    int curTotal = 0;
    void dfs(TreeNode* root){
        if(!root) return;
        dfs(root->left);
        curTotal += root->val;
        root->val += (sum - curTotal);
        dfs(root->right);
    }
    TreeNode* convertBST(TreeNode* root) {
        getSum(root);
        dfs(root);
        return root;
    }
};