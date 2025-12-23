class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        
        stack<int> stk;
        int j=0;
        for(int i=0;i<pushed.size();i++)
        {
                stk.push(pushed[i]);
                while(stk.size() && popped[j]==stk.top() && j<popped.size() )
                {
                    stk.pop();
                    j++;
                }
        }

        if(stk.size()==0)
        {
            return 1;
        }
        cout<<stk.size();
        return 0;
    }
};