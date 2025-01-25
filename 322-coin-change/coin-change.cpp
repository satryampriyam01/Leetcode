class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        
        int n=coins.size();
        int m=amount;
        int dp[n+1][amount+1];

        for(int i=0;i<=n;i++)
        {
            dp[i][0]=0;
        }
        for(int j=0;j<=m;j++)
        {
            dp[0][j]=INT_MAX-1;
        }


        for(int i=1;i<n+1;i++)
        {
            for(int j=1;j<m+1;j++)
            {
                if(coins[i-1]<=j)
                {
                    dp[i][j]=dp[i-1][j];
                    dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }

        if(dp[n][m]==INT_MAX-1)
        {
            return -1;
        }
        return dp[n][m];
    }
};