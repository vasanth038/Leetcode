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
     int helper(TreeNode* node,int &dai){
        if(!node) return 0;
        int left = helper(node->left,dai);
        int right = helper(node->right,dai);
        dai = max(dai,left+right+1);
        return max(left,right)+1;
     }
public:
    int diameterOfBinaryTree(TreeNode* root) {
       int dai = 0;
       if(!root)   return dai;
       helper(root,dai);
       return dai-1;
    }
};