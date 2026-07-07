class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minelement = prices[0];
        int mxsum = 0;
        for(int i = 0 ; i < prices.size();i++){
            minelement = min(minelement,prices[i]);
            mxsum = max(mxsum,prices[i]-minelement);
        }
        return mxsum;
    }
};