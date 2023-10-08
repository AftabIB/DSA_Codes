class MyStack {
private:
queue<int> q1;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
        for(int i=0;i<q1.size()-1;i++)
        {
            int a = q1.front();
            q1.pop();
            q1.push(a);
        }
    }
    
    int pop() {
        if(q1.empty())
            return -1;
        int a = q1.front();
        q1.pop();
        return a;
    }
    
    int top() {
        if(q1.empty())
            return -1;
        else
            return q1.front();
    }
    
    bool empty() {
        return q1.size() == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */