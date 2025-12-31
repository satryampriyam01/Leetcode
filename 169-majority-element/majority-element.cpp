class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        int majorElement=nums[0];
        int result=0;

        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==majorElement)
            {
                result++;
            }
            else
            {
                result--;
                if(result==0)
                {
                    majorElement=nums[i];
                    result+=1;
                }
            }
        }

        return majorElement;
    }
};