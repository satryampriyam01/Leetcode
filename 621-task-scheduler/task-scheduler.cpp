class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        unordered_map<char,int> amp;

        int m=tasks.size();

        for(int i=0;i<m;i++)
        {
            amp[tasks[i]]++;
        }

        priority_queue<int> pq;

        for(auto i:amp)
        {
            pq.push(i.second);
        }

        int result=0;
        while(pq.size())
        {
            int slot=n+1;
            vector<int> v;
            int count=0;
            while(slot && pq.size())
            {
                int r=pq.top();
                pq.pop();

                if(r-1!=0)
                {
                    v.push_back(r-1);
                }
               
                count++;
                slot--;
                 cout<<count<<" "<<slot<<endl;
            }

            for(int i=0;i<v.size();i++)
            {
                pq.push(v[i]);
            }
            
            cout<<count<<endl;
            result+=count;
            if(!pq.size())
            {
                return result;
            }
            
            result+=slot;
        }


        return result;


        
    }
};