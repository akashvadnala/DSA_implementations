class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    MinStack() {
       
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            st.push(val);
            return;
        }
        int min=st.top();
        st.push(val);
        if(val<=min) st.push(val);
        else st.push(min);
        return;
    }
    
    void pop() {
        st.pop();
        st.pop();
        return;
    }
    
    int top() {
        int min=st.top();
        st.pop();
        int val=st.top();
        st.push(min);
        return val;
    }
    
    int getMin() {
        return st.top();
    }
};