class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        
        priority_queue<int> pq;

        for(int i=1;i<nums.size();i++)
        {
            int r=nums[i];
            int rem=nums[i]-nums[i-1]-1;
            if(k<=rem)
            {
                return nums[i-1]+k;
            }
            else
            {
                k-=rem;
            }
        }

        
            return nums[nums.size()-1]+k;
        
    }
};