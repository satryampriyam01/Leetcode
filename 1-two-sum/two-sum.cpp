class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        map<int,int> amp;
        amp.clear();

        vector<int> result;
        for(int i=0;i<nums.size();i++)
        {
            if(amp[target-nums[i]]!=0)
            {
                vector<int> result;
                result.push_back(amp[target-nums[i]]-1);
                result.push_back(i);
                return result;
            }
            else
            {
                amp[nums[i]]=i+1;
                //cout<<amp[nums[i]]<<" "<<i+1<<endl;
            }
        }
        
        return result;
    }
};