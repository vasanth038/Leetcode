class Solution {
public:
    string digitSum(string s, int k) {

        string t = s;
        while (t.size() > k) {
            int n = t.size();
            int sum = 0;
            string cur = "";
            for (int i = 0; i < n; i++) {
                sum += (t[i] - '0');

                if ((i + 1) % k == 0) {
                    cur += to_string(sum);
                    sum = 0;
                }
            }

            if (n % k)
                cur += to_string(sum);

                t = cur;
        }

        return t;
    }
};