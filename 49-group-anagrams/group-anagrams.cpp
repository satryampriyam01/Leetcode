class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> amp;

        int n=strs.size();

        for(int i=0;i<n;i++)
        {
            string str=strs[i];
            sort(str.begin(),str.end());
            amp[str].push_back(strs[i]);
        }

    vector<vector<string>> answer;
        for(auto i:amp)
        {
            vector<string> result=i.second;
            answer.push_back(result);
        }
        return answer;
    }
};