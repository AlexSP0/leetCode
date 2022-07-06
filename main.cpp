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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL) return head;
        if(head->next == NULL) return head;

        ListNode *currentNode = head->next;
        ListNode *previousNode = head;
        ListNode *nextNode = currentNode->next;
        previousNode->next = NULL;
        currentNode->next = previousNode;
        if(nextNode == NULL) {
            return currentNode;
        }
        previousNode->next = NULL;
        currentNode->next = previousNode;
        while(nextNode != NULL) {
            previousNode = currentNode;
            currentNode = nextNode;
            nextNode = nextNode->next;

            currentNode->next = previousNode;
            if(nextNode == NULL) {
                currentNode->next = previousNode;
                return currentNode;
            }
        }
        return currentNode;
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
    ListNode *list2 = sol.reverseList(list1);
    std::cout << "Hello world!" << std::endl;
    return 0;
}
