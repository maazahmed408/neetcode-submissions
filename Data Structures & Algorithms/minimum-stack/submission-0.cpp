class MinStack {
public:
    stack<int> st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();  
    }
    
    int getMin() {
        vector<int> minList;
        int mini = st.top();
        while(!st.empty()){
            mini = min(mini, st.top());
            minList.push_back(st.top());
            st.pop();
        }
        for(int i = minList.size()-1; i>=0;--i){
            st.push(minList[i]);
        }
        return mini;
    }
};
