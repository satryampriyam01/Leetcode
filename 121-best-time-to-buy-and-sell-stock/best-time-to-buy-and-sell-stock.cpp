class Solution {
public:
    int maxProfit(vector<int>& prices) {


        int res=0;
        int n=prices.size();
        if(n==0)
        {
            return 0;
        }

        int min_price=prices[0];

        for(int i=1;i<n;i++)
        {
            if(prices[i]<min_price)
            {
                min_price=prices[i];
            }
            else
            {
                res=max(res,prices[i]-min_price);
            }
        }

        return res;
        
    }
};