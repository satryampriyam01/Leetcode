class Solution {
public:

    vector<int> prefix_sum;
    
    Solution(vector<int>& w) {
        
        int n=w.size();
        int prefix=0;

        for(int i=0;i<n;i++)
        {
            prefix+=w[i];
            prefix_sum.push_back(prefix);
        }
    }
    
    int pickIndex() {
        
        int wt= rand()%prefix_sum.back();
       
        int index=upper_bound(prefix_sum.begin(),prefix_sum.end(),wt)-prefix_sum.begin();
       
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */