class Solution {
public:


int n;
vector<int> dir= {1,0,-1,0,1};


int helper_dfs(vector<vector<int>>& grid, int i,int j,int id)
{
    if(i<0 || j<0 || i>=n || j>=n || grid[i][j]!=1)
    {
        return 0;
    }

    grid[i][j]=id;
    int cnt=1;
    for(int d=0;d<4;d++)
    {
        cnt+=helper_dfs(grid,i+dir[d],j+dir[d+1],id);
    }
    return cnt;
}

    int largestIsland(vector<vector<int>>& grid) {
        
        n=grid.size();
        unordered_map<int,int> amp;

        int id=2;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    amp[id]=helper_dfs(grid,i,j,id);
                    id++;
                }
                
            }
        }



        int ans=0;
        for(auto i: amp)
        {
            ans=max(i.second,ans);
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    unordered_set<int> seen;
                    int cur=1;
                    for(int d=0;d<4;d++)
                    {
                        int ni=i+dir[d];
                        int nj=j+dir[d+1];
                        if(ni>-1 && nj>-1 && ni<n && nj<n)
                        {
                            int nid=grid[ni][nj];
                            if(nid>1 && !seen.count(nid))
                            {
                                cur+=amp[nid];
                                seen.insert(nid);
                            }
                        }
                    }
                    ans=max(ans,cur);
                }
            }
        }

        if(ans)
        {
            return ans;
        }
        return 1;
    }
};