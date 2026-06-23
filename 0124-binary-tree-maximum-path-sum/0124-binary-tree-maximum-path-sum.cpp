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
     int helper(TreeNode* node , int & maxi){
        if(node == nullptr) return 0;
        int left_sum = max(0 ,helper(node->left,maxi) );
        int right_sum = max(0 ,helper(node->right,maxi) );
        maxi = max(maxi , node->val+left_sum+right_sum);
        return node->val+max(right_sum ,left_sum ) ;

     }
public:
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        helper(root,maxi);
        return maxi ;
    }
};