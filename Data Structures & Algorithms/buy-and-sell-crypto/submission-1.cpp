class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int r = 0;
        int l = 0;

        int i = 0;

        int maxprofit = 0;


        while(i<prices.size()){

            if(prices[i]<=prices[l])
                l = i;
            else
                r = i;

            int profit = r>=l ? prices[r]-prices[l] : 0;
            maxprofit = max(maxprofit,profit);

            i++;

        }

        return maxprofit;
    }
};
