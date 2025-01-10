class Solution {
public:
    string longestPalindrome(string s) {

        int n=s.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));

        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }

        int result_length=1;
        int se=0;

        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                se=i;
                result_length=2;
            }
        }


        for(int length=3;length<=n;length++)
        {
            for(int start=0;start<n-length+1;start++)
            {
                int en=start+length-1;
                if(dp[start+1][en-1]==1 && s[start]==s[en])
                {
                    //cout<<1<<endl;
                    dp[start][en]=1;
                    result_length=length;
                    se=start;
                }

            }
        }

        string str;
        for(int i=se;i<se+result_length;i++)
        {
            str+=s[i];
        }
        return str;
        
    }
};