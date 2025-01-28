class Solution {
public:


void helper(vector<int> &nums,vector<int> &v,vector<vector<int>> &result)
{
    result.push_back(v);

    for(int i=0;i<nums.size();i++)
    {
        v.push_back(nums[i]);
        vector<int> subvector(nums.begin()+ i+1, nums.end());
        helper(subvector,v,result);
        v.pop_back();
    }
}


    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        vector<vector<int>> result;

        helper(nums,v,result);

        return result;
    }
};