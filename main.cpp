#include <iostream>
#include <vector>

#include <bits/unique_ptr.h>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
        : val(0)
        , next(nullptr)
    {}
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {}
    ListNode(int x, ListNode *next)
        : val(x)
        , next(next)
    {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL)
        {
            return head;
        }

        if (head->next == NULL)
        {
            return head;
        }

        ListNode *currentNode  = head->next;
        ListNode *previousNode = head;
        previousNode->next     = NULL;

        while (currentNode != NULL)
        {
            ListNode *nextNode = currentNode->next;
            currentNode->next  = previousNode;

            if (nextNode == NULL)
            {
                break;
            }

            previousNode = currentNode;
            currentNode  = nextNode;
        }

        return currentNode;
    }

    ListNode *generateList(std::vector<int> v)
    {
        auto firstElement     = std::make_unique<ListNode>(v.at(0));
        ListNode *head        = firstElement.get();
        ListNode *currentNode = head;

        nodes.push_back(std::move(firstElement));

        for (size_t i = 1; i < v.size(); i++)
        {
            auto lastElement = std::make_unique<ListNode>(v.at(i));

            currentNode->next = lastElement.get();
            currentNode       = lastElement.get();

            nodes.push_back(std::move(lastElement));
        }
        return head;
    }

private:
    std::vector<std::unique_ptr<ListNode>> nodes;
};

int main()
{
    Solution sol;
    ListNode *list1 = sol.generateList({1, 2, 6, 3, 4, 5, 6});
    sol.reverseList(list1);

    std::cout << "Hello world!" << std::endl;
    return 0;
}
