class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        if(nums.size()<2)
        {
            return nums.size();
        }

        int result=2;

        for(int i=2;i<nums.size();i++)
        {
            if(nums[result-2]!=nums[i])
            {
                nums[result++]=nums[i];
            }
        }

        return result;
        
    }
};