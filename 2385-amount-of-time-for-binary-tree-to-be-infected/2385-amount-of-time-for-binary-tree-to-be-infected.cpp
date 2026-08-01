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
          TreeNode* findNode(TreeNode* node,int start){
                if(!node) return NULL;
               if(node->val == start)  return node;
               TreeNode* left = findNode(node->left,start);
               TreeNode* right =  findNode(node->right,start);
               if(left == NULL) return right;
               if(right == NULL) return left;
               return node;
          }
          void findParent(TreeNode* node, map<TreeNode* , TreeNode*>&mpp){
            if(!node) return;
            if(node->left){
                mpp[node->left] = node;
            }
            if(node->right){
                mpp[node->right] = node;
            }
            findParent(node->left,mpp);
            findParent(node->right,mpp);
          }

public:
    int amountOfTime(TreeNode* root, int start) {
        TreeNode* target = findNode(root,start);
        map<TreeNode* , TreeNode*>mpp;
          findParent(root,mpp);
        int time = -1 ;
         map<TreeNode*,int>vis;
         vis[target]++;
          queue<TreeNode*>q;
          q.push(target);
          while(!q.empty()){
             int size = q.size();
             for(int i = 0;i<size;i++){
                 TreeNode* node = q.front();
                 q.pop();
                 if(mpp.find(node) != mpp.end() && !vis.count(mpp[node])){
                    q.push(mpp[node]);
                    vis[mpp[node]]++;
                 }
                 if(node->left && !vis.count(node->left)){
                    q.push(node->left);
                    vis[node->left]++;
                 }
                 if(node->right && !vis.count(node->right)){
                    q.push(node->right);
                    vis[node->right]++;
                 }
             }
             time++;
          }

        return time;
        
    }
};