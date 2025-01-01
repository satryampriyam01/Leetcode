class Solution {
public:
    string mergeAlternately(string word1, string word2) {


        int n=word1.size();
        int m=word2.size();

        int i=0;
        int j=0;
        string str;
        str.clear();
        int flag=1;

        while(i<n || j<m)
        {
            if(flag && i<n)
            {
                str+=word1[i++];
            }
            else if(!flag && j<m)
            {
                str+=word2[j++];
            }
            flag^=1;
        }

        return str;
        
    }
};