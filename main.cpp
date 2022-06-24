#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) { return head; }
        ListNode *currentNode = head;
        ListNode *previousNode = NULL;
        while(currentNode) {
            if(currentNode == head && currentNode->val == val) {
                head = currentNode->next;
                currentNode = head;
            } else if (currentNode->val == val) {
                previousNode->next = currentNode->next;
                delete currentNode;
                currentNode = previousNode->next;
            } else {
                previousNode = currentNode;
                currentNode = currentNode->next;
            }
        }
        return head;
    }

    ListNode* generateList(std::vector<int> v) {
        ListNode *head = new ListNode(v.at(0));
        ListNode *currentNode = head;
        for(int i = 1; i < v.size(); i++) {
            ListNode *newNode = new ListNode(v.at(i));
            currentNode->next = newNode;
            currentNode = newNode;
        }
        return head;
    }
};
int main()
{
    Solution sol;
    ListNode *list1 = sol.generateList({1,2,6,3,4,5,6});
    ListNode *list2 = sol.removeElements(list1, 6);
    std::cout << "Hello world!" << std::endl;
    return 0;
}
