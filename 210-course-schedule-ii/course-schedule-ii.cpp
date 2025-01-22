class Solution {
public:

vector<int> result;
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
            return -1;
        }

    }

    vst[V]=1;
    result.push_back(V);
    return 1;
}

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        memset(vst,0,sizeof(vst));
        vector<vector<int>> adj(numCourses);

        int n=prerequisites.size();

        for(int i=0;i<n;i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }


        for(int i=0;i<numCourses;i++)
        {
            if(!helper_dfsCycle(adj,i))
            {
                vector<int> result;
                return result;
            }

        }

    reverse(result.begin(),result.end());
    return result;
    }
};