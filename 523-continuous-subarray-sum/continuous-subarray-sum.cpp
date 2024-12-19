class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        int n=nums.size();  
        unordered_map<int,int> amp;
        amp[0]=-1;
        int r=0;
        for(int i=0;i<n;i++)
        {
            r+=nums[i];
            r=r%k;

            if(amp.find(r)!=amp.end())
            {
                if(i-amp[r]>1)
                {
                    return 1;
                }
            }
            else
            {
                amp[r]=i;
            }
        }

        return 0;
    }
};