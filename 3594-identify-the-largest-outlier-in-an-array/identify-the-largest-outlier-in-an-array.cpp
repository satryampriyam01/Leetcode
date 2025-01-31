class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        
        unordered_map<int,int> amp;

        int n=nums.size();
        int sum=0;
        int result=INT_MIN;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            amp[nums[i]]++;
        }


        for(int i=0;i<n;i++)
        {
            sum-=nums[i];
            amp[nums[i]]--;

            if(sum%2==0 && amp[sum/2]>0)
            {
                //cout<<nums[i]<<" ";
                result=max(result,nums[i]);
            }
            sum+=nums[i];
            amp[nums[i]]++;
        }

        return result;
    }
};