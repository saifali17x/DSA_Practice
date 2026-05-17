class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxPro = 0;
        int minPro = INT_MAX;
        int n = prices.size();

        for(int i=0; i<n; i++)
        {
            minPro = min(minPro, prices[i]);
            maxPro = max(maxPro, prices[i] - minPro);
        }
        return maxPro;
    }
};
