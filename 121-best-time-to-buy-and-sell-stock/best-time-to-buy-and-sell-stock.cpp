class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n=prices.size();
        if(n==0)
        {
            return 0;
        }

        int min_price=prices[0];
        int profit=0;

        for(int i=1;i<n;i++)
        {
            if(min_price>prices[i])
            {
                min_price=prices[i];
            }
            else
            {
                profit=max(profit,prices[i]-min_price);
            }
        }

        return profit;
        
    }
};