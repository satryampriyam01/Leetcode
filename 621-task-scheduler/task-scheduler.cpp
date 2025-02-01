class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char,int> amp;

        for(int i=0;i<tasks.size();i++)
        {
            amp[tasks[i]]++;
        }

        priority_queue<int> pq;

        for(auto i:amp)
        {
            pq.emplace(i.second);
        }

    int result=0;
        while(pq.size())
        {

            int slot=n+1;
            int count=0;
            vector<int> v;


            while(slot && pq.size())
            {
                int r=pq.top();
                pq.pop();

                count++;
                slot--;
                if(r-1!=0)
                {
                    v.push_back(r-1);
                }
            }

            for(auto i:v)
            {
                pq.emplace(i);
            }

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