class Solution {
public:
    int countSubstrings(string s) {

        int n=s.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));


        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }

        int res=s.size();

        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
              {
                dp[i][i+1]=2;
                res++;
              }
        }


        for(int l=3;l<=n;l++)
        {
            for(int i=0;i<n-l+1;i++)
            {
                int se=i;
                int en=i+l-1;
                //cout<<dp[se+1][en-1]<<"Hello"<<s[se]<<"Y"<<s[en]<<endl;
                if(dp[se+1][en-1]!=0 && s[se]==s[en])
                {
                    dp[se][en]=1;
                    res++;
                }
            }

           // cout<<res<<endl;
        }

        return res;
        
    }
};