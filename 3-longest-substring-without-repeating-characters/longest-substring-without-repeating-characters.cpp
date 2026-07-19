class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        int n=s.size();
        unordered_map<char,int> amp;
        int res=0;
        int start=0;
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

            res=max(res,i-start+1);
        }

        return res;

        
    }
};