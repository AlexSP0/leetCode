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
                st.push(i + 2 + ((-1) * (i == 40)));
            }
            else
            {
                if (st.size() && st.top() == i)
                {
                    st.pop();
                    continue;
                }
                return false;
            }
        }

        return st.empty();
    }
};

int main()
{
    Solution solution;

    std::cout << "Is valid: " << (solution.isValid("({})[](()") ? "Yes" : "No") << std::endl;

    return 0;
}
