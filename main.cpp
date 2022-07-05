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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL) { return list2; }
        if(list2 == NULL) { return list1; }
        ListNode *result = new ListNode(0);
        ListNode *currentNode = result;
        while(list1 != NULL && list2 != NULL) {
            if(list1->val <= list2->val) {
                currentNode->next = list1;
                list1 = list1 -> next;
                currentNode = currentNode->next;
            } else {
                currentNode->next = list2;
                list2 = list2 -> next;
                currentNode = currentNode->next;
            }
        }
        currentNode->next = list1 != NULL? list1 : list2;
        return result->next;
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
    ListNode *list1 = sol.generateList({1,2,4});
    ListNode *list2 = sol.generateList({1,3,4});
    ListNode *list3 = sol.mergeTwoLists(list1, list2);
    std::cout << "Hello world!" << std::endl;
    return 0;
}
