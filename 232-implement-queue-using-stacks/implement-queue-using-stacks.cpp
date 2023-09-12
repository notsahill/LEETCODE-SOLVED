class MyQueue {
public:
    stack<int> s1,s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(s2.size()){
            int ele=s2.top();
            s1.push(ele);
            s2.pop();
        }
        s1.push(x);
    }
    
    int pop() {
        while(s1.size())
        {
            int ele=s1.top();
            s2.push(ele);
            s1.pop();
        }
        int ans=s2.top();
        s2.pop();
        return ans;
    }
    
    int peek() {
        while(s1.size())
        {
            int ele=s1.top();
            s2.push(ele);
            s1.pop();
        }
        int ans=s2.top();
        return ans;
    }
    
    bool empty() {
        return s1.empty()&&s2.empty();
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