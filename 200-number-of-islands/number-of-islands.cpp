class Solution {
public:


void helper_dfs(vector<vector<char>>& grid,int i,int j)
{
    if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size())
    {
        return ;
    }

    if(grid[i][j]=='1')
    {
        grid[i][j]='0';
        helper_dfs(grid,i-1,j);
        helper_dfs(grid,i,j+1);
        helper_dfs(grid,i+1,j);
        helper_dfs(grid,i,j-1);
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
                    helper_dfs(grid,i,j);
                }
            }
        }


        return result;
    }
};