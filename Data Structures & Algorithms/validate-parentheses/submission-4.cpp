#include <stack>

class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 1)
            return false;
        stack<char> brackets;
        string left = "([{";
        string right = ")]}";
        int ptr = 0;
        for (auto& c : s){
            if (left.find(c) != -1)
                brackets.push(c);
            else{
                if (right[0] == c)
                    ptr = 0;
                else if (right[1] == c)
                    ptr = 1;
                else if (right[2] == c)
                    ptr = 2;
                
                if (!brackets.empty() && left[ptr] == brackets.top()){
                    brackets.pop();
                    continue;
                }
                else
                    return false;
            }
        }
        return (brackets.empty()) ? true : false;
    }
};
