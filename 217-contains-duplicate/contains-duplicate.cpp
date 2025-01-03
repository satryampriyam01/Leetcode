class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int,int> amp;
        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            if(amp[nums[i]])
            {
                return 1;
            }
            amp[nums[i]]++;
        }

        return 0;
    }
};