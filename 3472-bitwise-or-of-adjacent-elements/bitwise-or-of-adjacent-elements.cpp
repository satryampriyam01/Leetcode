class Solution {
public:
    vector<int> orArray(vector<int>& nums) {
        
        vector<int> result;

        for(int i=0;i<nums.size()-1;i++)
        {
            int k=nums[i]|nums[i+1];
            result.push_back(k);
        }

        return result;
    }
};