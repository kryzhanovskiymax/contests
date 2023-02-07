#include <string>
#include <stack>
#include <iostream>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;
        for (const auto& c : s) {
            if (c == '(') {
                st.push(c);
            } else if (c == '[') {
                st.push(c);
            } else if (c == '{') {
                st.push(c);
            } else if (c == ')') {
                if (st.empty()) {
                    return false;
                }
                if (st.top() != '(') {
                    return false;
                }

                st.pop();
            } else if (c == ']') {
                if (st.empty()) {
                    return false;
                }
                if (st.top() != '[') {
                    return false;
                }

                st.pop();
            } else if (c == '}') {
                if (st.empty()) {
                    return false;
                }
                if (st.top() != '{') {
                    return false;
                }

                st.pop();
            }
        }

        if (st.empty()) {
            return true;
        }

        return false;
    }
};

int main() {
    Solution s;

    std::cout << s.isValid("()") << std::endl;
    std::cout << s.isValid("(){}[]") << std::endl;
    std::cout << s.isValid("(]") << std::endl;
    std::cout << s.isValid("([)]") << std::endl;

    return 0;
}