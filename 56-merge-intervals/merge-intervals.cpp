class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();

        if(n==0 || n==1)
        {
            return intervals;
        }

        sort(intervals.begin(),intervals.end());

        vector<vector<int>> result;
        result.push_back(intervals[0]);
        int k=1;

        for(int i=1;i<n;i++)
        {
            if(result[k-1][1]>=intervals[i][0])
            {
                result[k-1][0]=min(intervals[i][0],result[k-1][0]);
                result[k-1][1]=max(intervals[i][1],result[k-1][1]);
            }
            else
            {
                result.push_back(intervals[i]);
                k++;
            }
        }

        return result;
    }
};