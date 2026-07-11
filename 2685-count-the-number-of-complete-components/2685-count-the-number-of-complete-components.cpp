class Solution {
    private:
     void dfs(int node , vector<vector<int>>&graph ,int& nodes , int&eds , vector<int>&vis ){
           vis[node] = 1 ;
           nodes++;
           eds+=graph[node].size();
           for(int i = 0 ;i<graph[node].size();i++){
            if(vis[graph[node][i]] == 0) dfs(graph[node][i] , graph , nodes , eds , vis);
           }

     }
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
         vector<vector<int>>graph(n );
         for(auto e :  edges){
            graph[e[0]].push_back(e[1]);
             graph[e[1]].push_back(e[0]);
         }
         int ans = 0;
        vector<int>vis(n,0);
        for(int i = 0 ;i<n;i++){
            if(vis[i] == 1) continue;
 
              int nodes = 0;
              int eds = 0;

              dfs(i,graph , nodes , eds , vis );
              if(eds == (nodes*(nodes-1)) ) ans++;
        }
        return ans;
    }
};