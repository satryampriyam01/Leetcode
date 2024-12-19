class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        int n=nums.size();  
        unordered_map<int,int> amp;
        amp[0]=-1;
        int r=0;
        for(int i=0;i<n;i++)
        {
            r+=nums[i];
            nums[i]=r%k;

            if(amp.find(nums[i])!=amp.end())
            {
                if(i-amp[nums[i]]>1)
                {
                    return 1;
                }
            }
            else
            {
                amp[nums[i]]=i;
            }
        }

        return 0;
    }
};