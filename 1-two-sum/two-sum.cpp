class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> amp;
        int n=nums.size();
        vector<int> result;

        for(int i=0;i<n;i++)
        {
            if(amp[target-nums[i]]==0)
            {
                amp[nums[i]]=i+1;
            }
            else
            {
                result.push_back(i);
                result.push_back(amp[target-nums[i]]-1);
            }

        }
            return result;
    }
};