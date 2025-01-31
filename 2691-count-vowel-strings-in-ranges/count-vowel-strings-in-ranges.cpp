class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        

        int n=words.size();
        vector<int> prefix_sum(n);
        unordered_set<char> s1;
        s1.insert('a');
        s1.insert('e');
        s1.insert('i');
        s1.insert('o');
        s1.insert('u');
        int res=0;
        for(int i=0;i<n;i++)
        {
            string str=words[i];
            if(s1.find(str[0])!=s1.end() && s1.find(str[str.size()-1])!=s1.end())
            {
                res++;
            }
           // cout<<res<<endl;

            prefix_sum[i]=res;
            
        }

        vector<int> result;
        for(int i=0;i<queries.size();i++)
        {
            int res=prefix_sum[queries[i][1]];

            if(queries[i][0]>0)
            {
                res-=prefix_sum[queries[i][0]-1];
            }
            result.push_back(res);
        }

        return result;
    }
};