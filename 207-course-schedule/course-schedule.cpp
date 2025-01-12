class Solution {
public:
int vst[2005];

bool helper_dfsCycle(vector<vector<int>> &adj,int v)
{
    if(vst[v]==1)
    {
        return 1;
    }
    if(vst[v]==-1)
    {
        return 0;
    }

    vst[v]=-1;
    
    for(int i=0;i<adj[v].size();i++)
    {
        if( !helper_dfsCycle(adj,adj[v][i]))
        {
            return 0;
        }
    }

    vst[v]=1;
    return 1;


}


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {


        memset(vst,0,sizeof(vst));
        int n=numCourses;

        vector<vector<int>> adj(n);

        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }


        for(int i=0;i<n;i++)
        {
            if(!vst[i])
            {
                if(!helper_dfsCycle(adj,i))
                {
                    return 0;
                }
            }
        }

        return 1;

        
    }
};