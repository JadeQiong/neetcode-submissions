/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        lca = nullptr;
        dfs(root, p, q);
        return lca;
    }
private:
    TreeNode* lca;
    pair<bool, bool> dfs(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root || lca) return {false, false};
        auto left = dfs(root->left, p, q);
        auto right = dfs(root->right, p, q);
        bool foundP = left.first || right.first || root == p;
        bool foundQ = left.second || right.second || root == q;
        if(foundP && foundQ && !lca){
            lca = root;
        }
        return {foundP, foundQ};
    }
};