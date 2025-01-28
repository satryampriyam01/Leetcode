class Solution {
public:
    void sortColors(vector<int>& nums) {
        
        int se=0;
        int en=nums.size()-1;
        int i=0;

        while(i<=en)
        {
            if(nums[i]==0)
            {
                swap(nums[se++],nums[i++]);
            }
            else if(nums[i]==2)
            {
                swap(nums[en--],nums[i]);
            }
            else
            {
                i++;
            }
        }

        return ;
    }
};