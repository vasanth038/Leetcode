class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        
        int n = nums.size(); 
         if(n <= 2 ) return n;
        int p =   32 - __builtin_clz(n)-1 ;
        return   2 << p ;

    }
};