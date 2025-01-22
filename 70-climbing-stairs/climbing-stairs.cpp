class Solution {
public:
    int climbStairs(int n) {

        if(n<4)
        {
            return n;
        }


        vector<int> dp(n+1);

        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        dp[3]=3;

        for(int i=4;i<n+1;i++)
        {
            dp[i]=dp[i-1]+dp[i-2];
        }

        return dp[n];
        
    }
};