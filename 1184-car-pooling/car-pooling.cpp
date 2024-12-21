class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
       
        priority_queue<pair<int,int>> pq;
        unordered_map<long long,priority_queue<int>> amp;
        int n=trips.size();
        int current_size=0;
      
        for(int i=0;i<n;i++)
        {
             vector<int> v=trips[i];
             
             int size=v[0];
             int trip_start=v[1];
             int trip_end=v[2]; 
             pq.push(make_pair(-1*trip_start,-1*trip_end));
             long long res=10000000*(long long)trip_start+10000*trip_end;
             amp[res].push(size);
        }

        priority_queue<pair<int,int>> pq2;


        while(pq.size())
        {
            pair<int,int> p=pq.top();
        
            int start_trip=pq.top().first*-1;
            int end_trip=pq.top().second*-1;
            long long res=10000000*(long long)start_trip+10000*end_trip;
            int size=amp[res].top();
            amp[res].pop();
            cout<<res<<endl;
            current_size+=size;
            pq.pop();
               
                while(pq2.size() && -1*pq2.top().first<=start_trip)
                {
                    current_size-=pq2.top().second;
                    pq2.pop();
                }

                pq2.push(make_pair(end_trip*-1,size));
            

            cout<<current_size<<" "<<capacity<<endl;
            if(current_size>capacity)
            {
                return 0;
            }


        }

        return 1;

    }
};