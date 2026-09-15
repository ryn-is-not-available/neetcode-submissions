class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(string c : tokens) {
            if(c.size()==1 &&(c[0] == '+' || c[0]=='-' || c[0]=='/' || c[0]=='*')) {
                int op2=stk.top();
                stk.pop();
                int op1=stk.top();
                stk.pop();
                switch (c[0]) {
                    case '+':
                        stk.push(op1 + op2);
                        break;
                    case '-':
                        stk.push(op1 - op2);
                        break;
                    case '*':
                        stk.push(op1 * op2);
                        break;
                    case '/':
                        stk.push((int)(op1 / op2)); 
                        break;
                }

                continue;
            }
            stk.push(stoi(c));

        }
        return stk.top();
    }
};
