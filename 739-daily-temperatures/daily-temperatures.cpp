class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        int n=temperatures.size();
        vector<int> res(n);

        stack<int> stk;
        if(n<2)
        {
            return res;
        }

        stk.push(0);
        int k=0;
        for(int i=1;i<n;i++)
        {
            while(stk.size() && temperatures[i]>temperatures[stk.top()])
            {
                res[stk.top()]=i-stk.top();
                stk.pop();
            }

            stk.push(i);
        }

        return res;

    }
};