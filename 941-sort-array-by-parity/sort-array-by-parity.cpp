class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int se=0;
        int en=0;
        int n=nums.size();
        while(en<n)
        {
            if(nums[en]%2==0)
            {
                swap(nums[se],nums[en]);
                se++;
                en++;
            }
            else
            {
                en++;
            }
        }
        return nums;
    }
};