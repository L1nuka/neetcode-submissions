class MinStack {
public:
    stack<int> con; // Actual values
    stack<int> mStack; // minimums
    int m = INT_MAX;

    MinStack() {
        
    }
    
    void push(int val) {
        con.push(val);
        if (val <= m){
            mStack.push(m);
            m = val;
        }
    }
    
    void pop() {
        if (con.top() == m){
            m = mStack.top();
            mStack.pop();
        }
        con.pop();
    }
    
    int top() {
        return con.top();
    }
    
    int getMin() {
        return m;
    }
};
