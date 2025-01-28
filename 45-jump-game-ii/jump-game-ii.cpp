class Solution {
public:
    int jump(vector<int>& nums) {

        int maxi=0;
        int current_maxi=0;
        int result=0;
        if(nums.size()==1)
        {
            return 0;
        }

        for(int i=0;i<nums.size();i++)
        {
            current_maxi=max(current_maxi,nums[i]+i);
            
            if(i==maxi)
            {
                result++;
                maxi=current_maxi;
                if(current_maxi>nums.size()-2)
                {
                    return result;
                }
            }

            if(i>maxi)
            {
                return -1;
            }
        }
        
        return result;
        
    }
};