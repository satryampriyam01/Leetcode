class Solution {
public:

bool helper(string s,int start,int end)
{
       
        while(start<end)
        {
            if(s[start++]!=s[end--])
            {
                return 0;
            }
        }

        return 1;
}

    bool validPalindrome(string s) {

        int r=0;

        int start=0;
        int end=s.size()-1;

        while(start<end)
        {
            if(s[start]!=s[end])
            {
            
                bool left=helper(s,start+1,end);
                bool right=helper(s,start,end-1);

                if(left ||  right)
                {
                    return 1;
                } 
                else
                {
                    return 0;
                }
            }
            start++;
            end--;
        }

        return 1;
    }
};