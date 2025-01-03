class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s1;

        int n=nums.size();

        for(int i=0;i<n;i++)
        {
            if(s1.find(nums[i])!=s1.end())
            {
                return 1;
            }
            else
            {
                s1.insert(nums[i]);
            }
        }

        return 0;
    }
};