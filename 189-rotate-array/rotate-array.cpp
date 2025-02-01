class Solution {
public:
    void rotate(vector<int>& nums, int k) {

         int n=nums.size();
         k=k%n;

         reverse(nums.begin(),nums.end());

         int start=0;
         int end=k-1;

         while(start<end)
         {
            swap(nums[start++],nums[end--]);
         }

         start=k;
         end=n-1;
         while(start<end)
         {
            swap(nums[start++],nums[end--]);
         }

    }
};