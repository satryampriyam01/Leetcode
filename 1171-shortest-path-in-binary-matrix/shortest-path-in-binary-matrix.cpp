class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        int n=grid.size();
        int m=grid[0].size();

        if(grid[0][0]==1)
        {
            return -1;
        }

        queue<pair<int,int>> que;
     //   unordered_map<pair<int,int>,int> amp;

        que.push(make_pair(0,0));
        int k=1;

        while(que.size())
        {
            int r=que.size();

            while(r--)
            {
                pair<int,int> p=que.front();
                que.pop();
                int i=p.first;
                int j=p.second;
                cout<<i<<" "<<j<<endl;
                if(i==n-1 && j==m-1)
                {
                    return k;
                }

                //1
                if(j+1<m && grid[i][j+1]==0 )
                {
                    grid[i][j+1]=1;
                    que.emplace(make_pair(i,j+1));
                }

                //2
                if(i+1<n && j+1<m && grid[i+1][j+1]==0)
                {
                    grid[i+1][j+1]=1;
                    que.emplace(make_pair(i+1,j+1));
                }

                //3
                if(i+1<n && grid[i+1][j]==0)
                {
                    grid[i+1][j]=1;
                    que.emplace(make_pair(i+1,j));
                }

                //4
                if(i+1<n && j-1>-1 && grid[i+1][j-1]==0)
                {
                    grid[i+1][j-1]=1;
                    que.emplace(make_pair(i+1,j-1));
                }

                //5
                if(j-1>=0 && grid[i][j-1]==0)
                {
                    grid[i][j-1]=1;
                    que.emplace(make_pair(i,j-1));
                }

                //6
                if(i-1>=0 && j-1>=0 && grid[i-1][j-1]==0)
                {
                    grid[i-1][j-1]=1;
                    que.emplace(make_pair(i-1,j-1));
                }

                //7
                if(i-1>-1 && grid[i-1][j]==0)
                {
                    grid[i-1][j]=1;
                    que.emplace(make_pair(i-1,j));
                }


                //8
                if(i-1>-1 && j+1<m && grid[i-1][j+1]==0)
                {
                    grid[i-1][j+1]=1;
                    que.emplace(make_pair(i-1,j+1));
                }
            }
            k++;
            cout<<k<<endl;
        }



        return -1;



        
    }
};