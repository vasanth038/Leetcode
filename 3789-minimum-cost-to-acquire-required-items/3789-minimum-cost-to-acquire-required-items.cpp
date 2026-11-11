class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1,
                          int need2) {

        long long pair_cost = min(need1, need2) ;
         pair_cost*= 1LL*min(cost1 + cost2, costBoth);

        long long rem = 1LL*(need1 - min(need1, need2)) * min(cost1, costBoth) ;
        rem+= 1LL*(need2 - min(need1, need2)) * min(cost2, costBoth) ;

        return pair_cost + rem;
    }
};