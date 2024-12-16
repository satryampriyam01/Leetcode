class Solution {
public:
unordered_map<int,vector<int>> amp;
    Solution(vector<int>& nums) {
        
        for(int i=0;i<nums.size();i++)
        {
            amp[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
       
        vector<int> v=amp[target];
        int index=rand()%v.size();
        return v[index];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */