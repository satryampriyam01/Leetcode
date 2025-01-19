class Solution {
public:
    int characterReplacement(string s, int k) {

        int n=s.size();

        unordered_map<char,int> amp;

        int res=0;

        int se=0;

        int maxi=0;


        for(int i=0;i<n;i++)
        {
            amp[s[i]]++;

            int r=amp[s[i]];
            
            res=max(res,amp[s[i]]);

            while((i-se+1)-res>k)
            {
                amp[s[se]]--;
                se++;
            }

            maxi=max(maxi,i-se+1);

            
        }

        return maxi;
        
    }
};