class MyQueue {
public:
    // pop efficient method
    stack<int>st;
    stack<int>helper;
    MyQueue() {
        
    }
    
    void push(int x) { // O(n)
        // same as push at buttom
        if(st.size()==0) {
            st.push(x);
            return;
        }
        else {
            while(st.size()>0){
                helper.push(st.top());
                st.pop();
            }
            st.push(x);
            while(helper.size()>0){
                st.push(helper.top());
                helper.pop();
            }
        }
    }
    
    int pop() { // O(1)
        int x=st.top();
        st.pop();
        return x;
    }
    
    int peek() { // O(1)
        return st.top();
    }
    
    bool empty() {  // O(1)
       if(st.size()==0) return true;
       else return false; 
    }
};
    // push efficient method
    stack<int>st;
    stack<int>helper;
    // MyQueue() {
        
    // }
    
    void push(int x) { // O(1)
        st.push(x);
    }
    
    int pop() { // O(n)
        while(st.size()>0){
            helper.push(st.top());
            st.pop();
        }
        int x=helper.top();
        helper.pop();
        while(helper.size()>0){
            st.push(helper.top());
            helper.pop();
        }
        return x;
    }
    
    int peek() { // O(n)
        while(st.size()>0){
            helper.push(st.top());
            st.pop();
        }
        int x=helper.top();
        while(helper.size()>0){
            st.push(helper.top());
            helper.pop();
        }
        return x;
    }
    
    bool empty() {  // O(1)
       if(st.size()==0) return true;
       else return false; 
    }