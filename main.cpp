#include <iostream>
#include <stack>
#include <string>

class Solution
{
public:
    bool isValid(std::string s)
    {
        std::stack<char> st;
        for (char i : s)
        {
            if (i == '(' || i == '{' || i == '[')
            {
                st.push(i);
            }
            else if (i == ')' && st.size() && st.top() == '(')
            {
                st.pop();
            }
            else if (i == '}' && st.size() && st.top() == '{')
            {
                st.pop();
            }
            else if (i == ']' && st.size() && st.top() == '[')
            {
                st.pop();
            }
            else
            {
                return false;
            }
        }
        return st.empty();
    }
};

int main()
{
    std::cout << "Hello world!" << std::endl;
    return 0;
}
