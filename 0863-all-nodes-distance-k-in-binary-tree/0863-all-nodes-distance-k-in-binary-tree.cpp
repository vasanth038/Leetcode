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
          void helper(TreeNode* node,   map<TreeNode*,TreeNode*>&mpp){
             if(!node) return;
             if(node->left) {
                mpp[node->left] = node;
             }
             if(node->right){
                 mpp[node->right] = node;
             }
              helper(node->left,mpp);
             helper(node->right,mpp);

          }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        map<TreeNode*,TreeNode*>mpp;
        map<TreeNode* , bool>vis;
         helper(root,mpp);
         int dis = 0;
         queue<TreeNode*>q;
         q.push(target);
         vis[target] = true;
         while(!q.empty() && dis < k ){
              int size = q.size();
              for(int i = 0;i<size;i++){
                TreeNode* node = q.front();
                q.pop();
                if(mpp.find(node) != mpp.end() && !vis.count(mpp[node])) {
                    q.push(mpp[node]);
                    vis[mpp[node]] = true;
                }
                 if(node->left && !vis.count(node->left) ) {
                    q.push(node->left);
                    vis[node->left]=true;
                 }
                 if(node->right && !vis.count(node->right)) {
                    q.push(node->right);
                    vis[node->right] = true;
                 }
              }
              dis++;
         }
         vector<int>ans;
         while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
           ans.push_back(node->val);
         }
         return ans;

    }
};