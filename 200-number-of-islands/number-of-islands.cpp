class Solution {
public:


void helperDFS(vector<vector<char>>& grid, int i,int j)
{
    if(i<0 || j<0 || i>grid.size()-1 || j>grid[0].size()-1)
    {
        return ;
    }

    if(grid[i][j]=='1')
    {
        grid[i][j]=0;
        helperDFS(grid,i+1,j);
        helperDFS(grid,i-1,j);
        helperDFS(grid,i,j-1);
        helperDFS(grid,i,j+1);
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
                    helperDFS(grid,i,j);
                }
            }
        }
        return result;
    }
};