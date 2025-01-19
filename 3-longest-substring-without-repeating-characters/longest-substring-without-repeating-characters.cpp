class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.size();
        int start=0;
        int res=0;
        unordered_map<char,int> amp;
        for(int i=0;i<n;i++)
        {
            if(amp[s[i]]==0)
            {
                amp[s[i]]=i+1;
            }
            else
            {
                start=max(start,amp[s[i]]);
                amp[s[i]]=i+1;
                
            }

            res=max(res,i+1-start);
        }

        return res;
    }
};