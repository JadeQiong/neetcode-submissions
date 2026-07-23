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
    pair<bool, bool> dfs(TreeNode* node, TreeNode* p, TreeNode* q){
      if(!node || lca ) return {false, false};
      auto left = dfs(node->left, p, q);
      auto right = dfs(node->right, p, q);
    bool foundP = node == p || left.first || right.first;
    bool foundQ = node == q || left.second || right.second;
    if(foundP && foundQ && !lca){
        lca = node;
    }
      return {foundP, foundQ};
    }
};