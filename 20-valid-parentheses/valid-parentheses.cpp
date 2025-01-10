class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<char> stk;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='[' || s[i]=='(' || s[i]=='{')
            {
                stk.push(s[i]);
            }
            else
            {
                if((stk.size()) && ((stk.top()=='(' && s[i]==')') || (stk.top()=='[' && s[i]==']') || (stk.top()=='{' && s[i]=='}')))
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
            }
            
        }

        if(!stk.size())
        {
        return true;
        }
        else
        {
            return false;
        }
    }
};