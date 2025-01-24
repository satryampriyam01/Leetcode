class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        int result_length=0;

        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
            result_length=1;
        }

        int start=0;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                result_length=2;
                start=i;
            }
        }


        for(int length=3;length<n+1;length++)
        {
            for(int se=0;se<n-length+1;se++)
            {
                int en=se+length-1;

                if(dp[se+1][en-1] && s[se]==s[en])
                {
                        dp[se][en]=1;    
                        result_length=length;
                        start=se;
                    
                }
            }
        }

        string str;
        //cout<<start<<" "<<result_length<<endl;
        for(int i=start;i<start+result_length;i++)
        {
            str+=s[i];
        }

        return str;
    
    }
};