class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        priority_queue<int,vector<int>,greater<int>> pq_min;

        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(pq_min.size()<k)
            {
                pq_min.push(nums[i]);
            }
            else if(pq_min.top()<nums[i])
            {
                pq_min.push(nums[i]);
                if(pq_min.size()>k)
                {
                    pq_min.pop();
                }
            }
        }

        if(pq_min.size())
        {
            return pq_min.top();
        }
        return -1;

    }
};