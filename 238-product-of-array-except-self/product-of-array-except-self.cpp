class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> left(n);
        //vector<int> right(n);

        left[0]=1;
        for(int i=1;i<n;i++)
        {
            left[i]=nums[i-1]*left[i-1];
        }

        int right=1;

        for(int i=n-2;i>-1;i--)
        {
            right=right*nums[i+1];
            left[i]*=right;
        }


        // for(int i=0;i<n;i++)
        // {
        //     nums[i]=left[i]*right[i];
        // }

        return left;
    }
};