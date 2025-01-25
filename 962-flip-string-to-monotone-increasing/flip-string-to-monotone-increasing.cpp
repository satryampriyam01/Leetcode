class Solution {
public:
    int minFlipsMonoIncr(string s) {
        

        int cnt_1=0;
        int cnt_flip=0;

        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1')
            {
                cnt_1++;
            }
            else
            {
                cnt_flip=min(cnt_flip+1,cnt_1);
            }
        }

        return cnt_flip;
    }
};