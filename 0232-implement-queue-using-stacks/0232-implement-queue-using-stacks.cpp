class MyQueue {
public:
    stack<int> st1;
    MyQueue() {
        
    }
    //making push operation costly
    
    void push(int x) {
        if(st1.size()==0){
            st1.push(x);
            return;
        }
        int top=st1.top();
        st1.pop();
        push(x);
        st1.push(top);
    }
    
    int pop() {
        if(st1.size()==0)return -1;
        int k=st1.top();
        st1.pop();
        return k;
    }
    
    int peek() {
        if(st1.size()==0)return -1;
        
        return st1.top();
    }
    
    bool empty() {
        return st1.size()==false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */