class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        
        int n=rooms.size();
        int m=rooms[0].size();
        queue<pair<int,int>> que;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                    if(rooms[i][j]==0)
                    {
                        que.push(make_pair(i,j));
                    }
            }
        }


        int res=0;

        while(que.size())
        {
            int k=que.size();
            res++;

            while(k--)
            {
                int i=que.front().first;
                int j=que.front().second;

                que.pop();

                //cout<<i<<" "<<j<<endl;
         
                if(i+1<n && rooms[i+1][j]==2147483647)
                {
                    cout<<i+1<<" "<<j<<endl;
                    rooms[i+1][j]=min(res,rooms[i+1][j]);
                    que.push(make_pair(i+1,j));
                }

                 if(i-1>-1 && rooms[i-1][j]==2147483647)
                {
                    cout<<i-1<<" "<<j<<endl;
                    rooms[i-1][j]=min(res,rooms[i-1][j]);
                    que.push(make_pair(i-1,j));
                }
                

                 if(j+1<m && rooms[i][j+1]==2147483647)
                {
                    cout<<i<<" "<<j+1<<endl;
                    rooms[i][j+1]=min(res,rooms[i][j+1]);
                    que.push(make_pair(i,j+1));
                }
                

                 if(j-1>-1 && rooms[i][j-1]==2147483647)
                {
                    cout<<i<<" "<<j-1<<endl;
                    rooms[i][j-1]=min(res,rooms[i][j-1]);
                    que.push(make_pair(i,j-1));
                }
                
cout<<endl;
            }

            
        }



    }
};