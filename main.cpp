#include <iostream>
#include <stack>

class MyQueue
{
private:
    std::stack<int> stack1;
    std::stack<int> stack2;

public:
    MyQueue() {}

    void push(int x) { stack1.push(x); }

    int pop()
    {
        if (stack1.size() == 1)
        {
            int result = stack1.top();
            stack1.pop();
            return result;
        }

        if (stack1.size() > 1)
        {
            swapStacks(stack1, stack2);

            int result = stack2.top();
            stack2.pop();

            swapStacks(stack2, stack1);

            return result;
        }
        return 0;
    }

    int peek()
    {
        if (stack1.size() == 1)
        {
            int result = stack1.top();
            return result;
        }

        if (stack1.size() > 1)
        {
            swapStacks(stack1, stack2);

            int result = stack2.top();

            swapStacks(stack2, stack1);

            return result;
        }
        return 0;
    }

    bool empty() { return stack1.empty(); }

    void swapStacks(std::stack<int> &first, std::stack<int> &second)
    {
        while (first.size() != 0)
        {
            int value = first.top();
            second.push(value);
            first.pop();
        }
    }
};

int main()
{
    std::cout << "Hello world!" << std::endl;
    return 0;
}
