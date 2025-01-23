class Solution {
public:

    void helper_dfs(int i,int j,vector<vector<char>>& grid)
    {
        if(i<0 || j<0 || i>grid.size()-1 || j>grid[0].size()-1)
        {
            return ;
        }

        if(grid[i][j]=='1')
        {
            //visting nodes
            grid[i][j]='0';
            helper_dfs(i-1,j,grid);
            helper_dfs(i+1,j,grid);
            helper_dfs(i,j-1,grid);
            helper_dfs(i,j+1,grid);
            
        }

        return ;
    }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int result=0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]=='1')
                {
                    result++;
                    helper_dfs(i,j,grid);
                }
            }
        }

        return result;

    }
};