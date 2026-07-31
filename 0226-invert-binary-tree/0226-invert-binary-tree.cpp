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
    private:
       void helper(TreeNode* node){
        if(!node) return;
         TreeNode* right = node->right;
          node->right = node->left;
         node->left = right;
        helper(node->left);
        helper(node->right);
       }
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;

        helper(root);
        return root;
    }
};