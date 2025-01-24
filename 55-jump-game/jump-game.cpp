class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int n=nums.size();
        int maxi=0;

        for(int i=0;i<=maxi;i++)
        {
            if(maxi>=n-1)
            {
                return 1;
            }

            maxi=max(maxi,nums[i]+i);
        }

        if(maxi>n-2)
        {
            return 1;
        }

        return 0;
    }
};