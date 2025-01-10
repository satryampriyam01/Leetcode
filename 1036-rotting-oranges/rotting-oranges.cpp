class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<pair<int,int>> que;

        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    que.push(make_pair(i,j));
                }
            }
        }

        int result=0;

        while(que.size())
        {
            int k=que.size();
            
            while(k--)
            {
                pair<int,int> p=que.front();
                que.pop();
                 int i=p.first;
                 int j=p.second;
                 //cout<<i<<" "<<j<<endl;
                //cout<<i+1<<" "<<j<<" "<<n<<" "<<grid[i+1][j]<<endl;
                if(i+1<n && grid[i+1][j]==1)
                {
                    grid[i+1][j]=2;
                    que.push(make_pair(i+1,j));
                }

                if(i-1>-1 && grid[i-1][j]==1)
                {
                   grid[i-1][j]=2;
                    que.push(make_pair(i-1,j)); 
                }

                if(j+1<m && grid[i][j+1]==1)
                {
                    grid[i][j+1]=2;
                    que.push(make_pair(i,j+1));
                }

                if(j-1>-1 && grid[i][j-1]==1)
                {
                    grid[i][j-1]=2;
                    que.push(make_pair(i,j-1)); 
                }
           
            }
            result++;
        }


    for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    return -1;
                }
            }
        }

if(result)   
{
    return result-1;
}
return result;


    }
};