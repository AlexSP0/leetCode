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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        if(head->next == NULL) return head;
        ListNode *currentNode = head;
        ListNode *nextNode = head->next;
        while(currentNode->next != NULL) {
            while(nextNode != NULL && currentNode->val == nextNode->val) {
                nextNode=nextNode->next;
            }
            if(nextNode == NULL) {
                currentNode->next = NULL;
                break;
            }
            currentNode->next = nextNode;
            currentNode = nextNode;
            nextNode = nextNode->next;
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
    ListNode *list1 = sol.generateList({1,1,2,2});
    ListNode *list2 = sol.deleteDuplicates(list1);
    std::cout << "Hello world!" << std::endl;
    return 0;
}

