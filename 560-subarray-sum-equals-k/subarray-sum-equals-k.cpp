class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        unordered_map<int,int> amp;
        amp[0]=1;
        int prefix_sum=0;
        int result=0;

        for(int i=0;i<nums.size();i++)
        {
            prefix_sum+=nums[i];
            int required_prefix=prefix_sum-k;
            result+=amp[required_prefix];
            amp[prefix_sum]++;

        }

        return result;
    }
};