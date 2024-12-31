class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {


        int n=nums.size();
        unordered_map<int,int> amp;

        for(int i=0;i<n;i++)
        {
            amp[nums[i]]++;
        }

        priority_queue<pair<int,int>> pq;
        
        for(auto i: amp)
        {
            int num=i.first;
            int r=i.second;
            pq.push(make_pair(i.second,i.first));
        }


        vector<int> res;

        while(k--)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }


        return res;

        
    }
};