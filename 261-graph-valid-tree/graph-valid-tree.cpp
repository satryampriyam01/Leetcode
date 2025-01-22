class Solution {
public:

int vst[2005];

bool helper_dfsCycle(vector<vector<int>> &adj,int V, int prevV)
{
    
    if(vst[V]==1)
    {
        return 1;
    }

    vst[V]=1;

    for(int i=0;i<adj[V].size();i++)
    {
        int nxtV=adj[V][i];

        if(nxtV!=prevV && helper_dfsCycle(adj,nxtV,V))
        {
            return 1;
        }
    }

return 0;

}
    bool validTree(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(n);
        memset(vst,0,sizeof(vst));

        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][1]].push_back(edges[i][0]);
            adj[edges[i][0]].push_back(edges[i][1]);
        }

        if(helper_dfsCycle(adj,0,-1))
        {
            return 0;
        }

        for(int i=0;i<n;i++)
        {
            if(vst[i]==0)
            {
                return 0;
            }
        }

        return 1;

    }
};