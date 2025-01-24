class Solution {
public:
    string reorganizeString(string s) {

        priority_queue<pair<int,char>> pq;
        int n=s.size();
        unordered_map<char,int> amp;
        for(int i=0;i<n;i++)
        {
            amp[s[i]]++;
        }

        for(auto i:amp)
        {
            pq.push(make_pair(i.second,i.first));
        }

        string str;
        str.clear();

        char prev_ch=pq.top().second;
        int prev_r=pq.top().first-1;
        str+=prev_ch;
        pq.pop();

        while(pq.size())
        {
            char ch=pq.top().second;
            int r=pq.top().first-1;
            str+=ch;
            pq.pop();

            if(prev_r!=0)
            {
                
                pq.push(make_pair(prev_r,prev_ch));
            }


            prev_ch=ch;
            prev_r=r;

            
        }

        cout<<prev_r<<endl;

        if(prev_r>0)
        {
            return "";
        }
       // return str+=prev_ch;

        return str;

    }
};