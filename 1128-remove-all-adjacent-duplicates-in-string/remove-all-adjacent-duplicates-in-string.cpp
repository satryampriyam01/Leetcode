class Solution {
public:
    string removeDuplicates(string s) {
        
        stack <char>stk;

        for(int i=0;i<s.size();i++)
        {
            
            if(stk.size() && s[i]==stk.top())
            {
                stk.pop();
            }
            else
            {
                stk.push(s[i]);
            }

        }


        string str;

        while(stk.size())
        {
            str+=stk.top();
            stk.pop();
        }
        reverse(str.begin(),str.end());

        return str;
    }
};