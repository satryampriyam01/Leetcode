class Solution {
public:
    string simplifyPath(string path) {

        int n=path.size();
        stack<string> stk;
        for(int i=0;i<n;i++)
        {
            if(path[i]=='/')
            {
                continue;
            }

            string temp;
            temp.clear();
            while(i<n && path[i]!='/')
            {
                temp+=path[i++];
            }

            if(temp==".")
            {
                continue;
            }
            else if(temp=="..")
            {
                if(stk.size())
                {
                stk.pop();
                }
            }
            else{
                reverse(temp.begin(),temp.end());
                stk.push(temp);
            }
        }

        string str;
        while(stk.size())
        {   
            str+=stk.top();
            str+='/';
            stk.pop();
        }
        reverse(str.begin(),str.end());
        if(str.size()==0)
        {
           str+='/'; 
        }

        return str;


    }
};