class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> amp;
        int result=0;
        int prefix_sum=0;
        amp[0]=1;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            prefix_sum+=nums[i];

            int remove_sum_prefix=prefix_sum-k;

            result+=amp[remove_sum_prefix];

            amp[prefix_sum]++;
            
        }

        return result;
        
    }
};