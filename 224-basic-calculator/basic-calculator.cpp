class Solution {
public:
    int calculate(string s) {
        
        int n=s.size();
        stack<int> stk;
        int sign=1;
        int result=0;
        int num=0;
        for(int i=0;i<n;i++)
        {
            if(isdigit(s[i]))
            {
                num=num*10+(s[i]-'0');
            }
            else if(s[i]=='(')
            {
                stk.push(result);
                stk.push(sign);
                result=0;
                sign=1;
            }
            else if(s[i]=='+')
            {
                result+=sign*num;
                sign=1;
                num=0;
            }
            else if(s[i]=='-')
            {
                result+=sign*num;
                sign=-1;
                num=0;
            }
            else if(s[i]==')')
            {
                result+=sign*num;
                result*=stk.top();
                stk.pop();
                result+=stk.top();
                stk.pop();
                num=0;
            }

        }

        return result+=sign*num;
    }
};