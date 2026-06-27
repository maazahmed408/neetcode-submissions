class MinStack {
public:
    MinStack() {
        
    }

    stack<int> st;
    stack<int> minSt;
    
    void push(int val) {
        st.push(val);
        if((!minSt.empty() && minSt.top() > val) || minSt.empty()){
            minSt.push(val);
        }else{
            minSt.push(minSt.top());
        }
    }
    
    void pop() {
        if(!st.empty()){
            st.pop();
            minSt.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};
