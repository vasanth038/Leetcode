class Solution {
public:
    vector<int> busiestServers(int k, vector<int>& arrival, vector<int>& load) {

        priority_queue<vector<long long>, vector<vector<long long>>, greater<vector<long long>>>
            busy;

        priority_queue<int, vector<int>, greater<int>> free;

        for (int i = 0; i < k; i++) {
            free.push(i);
        }

        vector<int> cnt(k, 0);
   
        for (int i = 0; i < arrival.size(); i++) {
              
               int time = arrival[i];
            while (!busy.empty() && busy.top()[0] <= time) {
                auto id = busy.top()[1];
                busy.pop();
                free.push(i+((id-i)%k+k)%k);
            }

             if(free.empty()) continue;
                int id = free.top()%k;
                 free.pop();
                cnt[id]++;
                busy.push({(long long) time + load[i], id});
            
        }

        int maxi = *max_element(cnt.begin(), cnt.end());

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            if (cnt[i] == maxi)
                ans.push_back(i);
        }

        return ans;
    }
};