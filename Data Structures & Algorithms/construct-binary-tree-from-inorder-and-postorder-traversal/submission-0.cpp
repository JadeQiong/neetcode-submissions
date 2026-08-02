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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(postorder.empty() || inorder.empty()) return nullptr;
        TreeNode* root = new TreeNode(postorder.back());
        auto it = find(inorder.begin(), inorder.end(), postorder.back());
        int mid = distance(inorder.begin(), it);
        vector<int> leftInorder(inorder.begin(), inorder.begin() + mid);
        vector<int> rightInorder(inorder.begin()+mid+1, inorder.end());
        vector<int> leftPostOrder(postorder.begin(), postorder.begin()+mid);
        vector<int> rightPostOrder(postorder.begin()+mid, postorder.end()-1);
        root->left = buildTree(leftInorder, leftPostOrder);
        root->right = buildTree(rightInorder, rightPostOrder);
        return root;
    }
};