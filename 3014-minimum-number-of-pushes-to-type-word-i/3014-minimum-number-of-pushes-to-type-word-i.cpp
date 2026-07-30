class Solution {
public:
    int minimumPushes(string word) {
        int n = word.size();
        int b = n/8;
        int rem = n%8;
        int ans = 4*(b+b*b);
        ans+=(rem*(b+1));
        return ans;
        
    }
};