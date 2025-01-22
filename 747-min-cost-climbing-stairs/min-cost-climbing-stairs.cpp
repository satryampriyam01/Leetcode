class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n=cost.size();
        vector<int> dp(n+1);
        if(n<2)
        {
            return cost[0];
        }

       // cost[1]=min(cost[0],cost[1]);

        for(int i=2;i<n;i++)
        {
            //cout<<cost[i-2]<<" "<<cost[i]<<" Cost "<<cost[i-1]<<endl;
            cost[i]=min(cost[i-2]+cost[i],cost[i]+cost[i-1]);
            

        }

        return min(cost[n-2],cost[n-1]);
        
    }
};