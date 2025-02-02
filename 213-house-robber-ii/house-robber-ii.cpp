class Solution {
public:
    int rob_sol(vector<int>& nums, int start, int end) {
        int n = end - start + 1;
        if (n == 0) return 0;
        if (n == 1) return nums[start];
        
        vector<int> dp(n, 0);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);
        
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[start + i]);
        }
        
        return dp[n - 1];
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        
        // Case 1: Rob from house 0 to n-2
        int case1 = rob_sol(nums, 0, n - 2);
        
        // Case 2: Rob from house 1 to n-1
        int case2 = rob_sol(nums, 1, n - 1);
        
        // Return the maximum of both cases
        return max(case1, case2);
    }
};