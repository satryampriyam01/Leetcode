class Solution {
public:
    vector<vector<int>> findMissingRanges(vector<int>& nums, int lower, int upper) {
        
        int n=nums.size();
        vector<vector<int>> res;

        int current_lower=lower;
        int k=0;
        for(int i=0;i<n;i++)
        {
            if(current_lower<nums[i])
            { 
                cout<<i<<endl;
                cout<<current_lower<<" "<<nums[i]<<endl;
                res.push_back({current_lower,nums[i]-1});
            }
             current_lower=nums[i]+1;   
        }

        if(current_lower<=upper)
        {
            res.push_back({current_lower,upper});
        }

        return res;
    }
};