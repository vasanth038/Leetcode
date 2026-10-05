class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if (n > m ) return findMedianSortedArrays(nums2, nums1);

        int l = 0;
        int r = n;

        while (l <= r) {

            int m1 = l + (r - l) / 2;
            int m2 = (n + m + 1) / 2 - m1;
             
              int l1 =  m1 == 0 ? INT_MIN : nums1[m1-1];
              int l2 =  m2 == 0 ? INT_MIN : nums2[m2-1];
              int r1 = m1 == n ? INT_MAX : nums1[m1];
              int r2 = m2 == m ? INT_MAX : nums2[m2];
              
            if (l1 <= r2 && l2 <=  r1) {

                double p1 = max(l1, l2);
                double p2 = min(r1, r2);

                if ((m + n) % 2 == 0) {
                    return (double)(p1 + p2) / 2.0;
                } else
                    return p1;
            }

            if (l1 > r2)
                r = m1 - 1;
            else
                l = m1 + 1;
        }

        return 0.0;
    }
};