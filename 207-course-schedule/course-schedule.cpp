class Solution {
public:

int vst[2005];

    bool helper_dfsCycle(vector<vector<int>>& adj,int V)
    {

        if(vst[V]==1)
        {
            return 1;
        }

        if(vst[V]==-1)
        {
            return 0;
        }

        vst[V]=-1;

        for(int i=0;i<adj[V].size();i++)
        {
            if(!helper_dfsCycle(adj,adj[V][i]))
            {
                return 0;
            }
        }

        vst[V]=1;

        return 1;
    }


    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        int n=prerequisites.size();
        vector<vector<int>> adj(numCourses);
        memset(vst,0,sizeof(vst));

        for(int i=0;i<n;i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }



        for(int i=0;i<numCourses;i++)
        {
            if(!helper_dfsCycle(adj,i))
            {
                return 0;
            }
        }


return 1;

    }
};