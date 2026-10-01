class Solution {
public:
    void nextPermutation(vector<int>& a) {

        int n = (int) a.size();
        int i = n - 2;

        while (i >= 0 && a[i] >= a[i + 1]) i--;
         int p = i;
        sort(a.begin()+i+1, a.end());
        while (i < n && p >= 0 ) {
            if (a[i] > a[p]) {
                swap(a[i], a[p]);
                break;
            }
            i++;
        }
    }
};