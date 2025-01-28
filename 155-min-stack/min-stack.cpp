class MinStack {
public:
long long current_min=0;
    stack<long long> stk;
    MinStack() {
    //stk.clear();
    }
    
    void push(int val) {
        if(stk.size()==0)
        {
            stk.push(val);
            current_min=val;
        }
        else if(val<current_min)
        {
            long long num=2*(long long)val-current_min;
            stk.push(num);
            current_min=val;
        }
        else
        {
            stk.push(val);
        }
    }
    
    void pop() {
        if(stk.top()<=current_min)
        {
            current_min=2*current_min-stk.top();
            stk.pop();
        }
        else
        {
            if(stk.size())
            stk.pop();
        }
    }
    
    int top() {
       if(stk.top()<current_min)
       {
        return current_min;
       } 
       else
       {
        return stk.top();
       }
       return -1;
    }
    
    int getMin() {
        return current_min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */