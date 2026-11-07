class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {

        priority_queue<vector<long long >, vector<vector<long long>>, greater<vector<long long >>>
            busy, free;

        for (int s = 0; s < servers.size(); s++) {
            free.push({servers[s], s});
        }

        int n = tasks.size();
        vector<int> ans(n);
         long long time = 0;
        for (int i = 0; i < n; i++) {
               time = max(time,(long long ) i ) ;

            while (!busy.empty() && busy.top()[0] <= i) {
                auto top = busy.top();
                busy.pop();
                free.push({top[1], top[2]});
            }
            if (free.empty()) {

                time = busy.top()[0];

                while (!busy.empty() && busy.top()[0] <= time) {
                    auto top = busy.top();
                    busy.pop();
                    free.push({top[1], top[2]});
                }
            }

            auto f = free.top();
            free.pop();
            ans[i] = f[1];
            busy.push({time + tasks[i], f[0], f[1]});
        }

        return ans;
    }
};