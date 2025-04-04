class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n=nums.size();
        if(n==0)
        {
            return 0;
        }
        sort(nums.begin(),nums.end());
        
        int result=0;
        int r=1;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]+1==nums[i+1])
            {
              r++;
            }
            else if(nums[i]==nums[i+1])
            {
                continue;
            }
            else
            {
                result=max(result,r);
                r=1;
            }
        }

        result=max(result,r);

        return result;
    }
};