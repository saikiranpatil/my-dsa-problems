class MyQueue {
public:
    stack<int> stk;
    MyQueue() {
        
    }
    
    void push(int x) {
        stack<int> tmp;
        while(!stk.empty()){
            int num = stk.top();
            tmp.push(num);
            stk.pop();
        }
        stk.push(x);
        while(!tmp.empty()){
            int num = tmp.top();
            stk.push(num);
            tmp.pop();
        }
    }
    
    int pop() {
        int ans = stk.top();
        stk.pop();
        return ans;
    }
    
    int peek() {
        return stk.top();
    }
    
    bool empty() {
        return stk.empty();
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