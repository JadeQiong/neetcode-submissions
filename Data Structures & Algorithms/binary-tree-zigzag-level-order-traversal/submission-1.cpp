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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        if(!root) return ans;
        q.push(root);
        int counter = 0;
        while(!q.empty()){
            vector<int> lvl;
            int siz = q.size();
            while(siz){
                auto cur = q.front(); q.pop();
                lvl.push_back(cur->val);
                if(cur->left) q.push(cur->left);
                if(cur->right) q.push(cur->right);
                siz--;
            }
            if(counter&1){
                reverse(lvl.begin(), lvl.end());
            }
            ans.push_back(lvl);
            counter++;
        }
        return ans;
    }
};