class Solution {
public:
//int vst[1001][1001];
void helper(vector<vector<int>>& grid,int i,int j,int &res)
{
    if(i<0 || j<0 || i>grid.size()-1 || j>grid[0].size()-1 || grid[i][j]==0)
    {
       // || vst[i][j]==1 
        return;
    }
    grid[i][j]=0;
    //vst[i][j]=1;
    res+=1;
    helper(grid,i+1,j,res);
    helper(grid,i-1,j,res);
    helper(grid,i,j+1,res);
    helper(grid,i,j-1,res);
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
             int maxi=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                
                if(grid[i][j]==1)
                {
                    //|| vst[i][j]==1 
                    int res=0;
                    helper(grid,i,j,res);
                    maxi=max(maxi,res);
                }
            }
        }

        return maxi;
    }
};