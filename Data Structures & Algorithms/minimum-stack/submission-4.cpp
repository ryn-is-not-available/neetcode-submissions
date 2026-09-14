class MinStack {
private:
    stack<int> stk;
    stack<int> minStk;
    int size;
public:
    MinStack() {
        size=0;
    }
    
    void push(int val) {
        stk.push(val);
        size++;
        if(minStk.empty()){
            minStk.push(val);
        }else if(minStk.top()>=val) {
            minStk.push(val);
        }
    }
    
    void pop() {
        int value = stk.top();
        stk.pop();
        size--;
        if(value==minStk.top()){
            minStk.pop();
        }

    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};
