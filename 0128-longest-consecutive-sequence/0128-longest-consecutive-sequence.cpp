class Solution {
public:
    int longestConsecutive(vector<int>& a) {

        unordered_set<int> st;

        for (auto x : a) st.insert(x);

        int len = 0;

        for (auto x : st) {
            if (st.find(x - 1) == st.end()) {
                int cnt = 1;
                while (st.find(x+1) != st.end()) {
                    cnt+=1;
                    x+=1;
                }
                 len = max(len, cnt);
            }

           
        }

        return len;
    }
};