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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        map<int,int>mpp;
        queue<TreeNode*>q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int k = q.size();
            mpp[level] = q.front()->val;
            while(k--){
                TreeNode* node = q.front();
                q.pop();
                if(node->right) q.push(node->right);
                if(node->left) q.push(node->left);
            }
            level++;
        }
        vector<int>ans;
        for(auto & it : mpp){
            ans.push_back(it.second);
        }
      return ans;
    }
};