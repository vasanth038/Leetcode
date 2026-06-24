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
         vector<vector<int>>ans;
         if(root == NULL) return ans;
          queue<TreeNode*>q;
           q.push(root) ;
           int rev = 0 ;
           while(!q.empty()){
             int q_size = q.size() ;
             vector<int>level;
             for(int i = 0 ; i < q_size;i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left != NULL) q.push(curr->left) ;
                if(curr->right != NULL) q.push(curr->right);
                if(curr != NULL) level.push_back(curr->val);
             }
           if(rev%2 != 0){
            reverse(level.begin(),level.end());
           }
           ans.push_back(level);
           rev++;

           }
         return ans;
    }
};