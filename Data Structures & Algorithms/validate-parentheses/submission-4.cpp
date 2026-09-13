#include <iostream>
#include <stack>
#include <string>
class Solution {
public :
    bool isValid(const std::string& s) {
        std::stack<char> stk;
        size_t pointer = 0;

        while (!stk.empty() || pointer < s.size()) {
            if (pointer < s.size()) {
                char ch = s[pointer];

                if (ch == '(' || ch == '{' || ch == '[') {
                    stk.push(ch);
                    pointer++;
                } 
                else if (ch == ')' || ch == '}' || ch == ']') {
                    if (stk.empty()) {
                        return false;
                    }

                    char top = stk.top();
                    if ((ch == ')' && top == '(') ||
                        (ch == '}' && top == '{') ||
                        (ch == ']' && top == '[')) {
                        stk.pop();
                        pointer++;
                    } else {
                        return false;
                    }
                } else {
                    pointer++;
                }
            } else {

                return false;
            }
        }

        return true;
    }
}; 