class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int n=nums.size();

        vector<int> result;
        unordered_map<int,int> amp;

        for(int i=0;i<n;i++)
        {
            if(amp[target-nums[i]]>0)
            {
                result.push_back(amp[target-nums[i]]-1);
                result.push_back(i);
                return result;
            }
            else
            {
                amp[nums[i]]=i+1;
            }
        }

        return result;


    }
};