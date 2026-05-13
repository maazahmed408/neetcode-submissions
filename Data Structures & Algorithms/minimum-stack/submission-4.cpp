class MinStack {
public:
    MinStack() {
        
    }
    stack <int> st;
    stack <int>minSt;
    void push(int val) {
    st.push(val);
    int m = minSt.empty() ? val : min(val, minSt.top());
    minSt.push(m);
}

void pop() {
    st.pop();
    minSt.pop();  // always pop both together
}

int top()    { return st.top(); }
int getMin() { return minSt.top(); }

};
