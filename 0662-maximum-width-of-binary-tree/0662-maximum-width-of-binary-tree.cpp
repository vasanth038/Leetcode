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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        queue<pair<TreeNode*,long long>>q;
        q.push({root,0});
        int ans = 0;
        while(!q.empty()){
            int k = q.size();
              int minn = q.front().second;
               int first = -1;
               int last = -1;
             for(int i = 0;i<k;i++){
                 int id = q.front().second-minn;
                 TreeNode* node = q.front().first;
                 q.pop();
                 if(i == 0) first = id;
                 if(i == k-1) last = id;
                 if(node->left) q.push({node->left,1LL*2*id+1});
                 if(node->right) q.push({node->right,1LL*2*id+2});
             }
             ans = max(ans,last-first+1);
        }
        return ans;
    }
};