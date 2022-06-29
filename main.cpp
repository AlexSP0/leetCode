#include <array>
#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* buildList(std::vector<int> &arr, int pos) {
        ListNode *head = new ListNode(arr[0]);;
        ListNode *currentNode = head;

        for(int i = 1; i < arr.size(); i++) {
            ListNode* newNode = new ListNode(arr[i]);
            currentNode->next = newNode;
            currentNode = newNode;
        }
        ListNode *cycleNode = head;
        for(int j = 0; j < (pos-1); j++ ) {
            cycleNode = cycleNode->next;
        }
        currentNode->next = cycleNode;
        return head;
    }
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        if(head->next == NULL && head == NULL) { return false;}
        ListNode *fP = head;
        ListNode *sP = head;
        while(fP->next != NULL && fP->next->next != NULL) {
            sP = sP -> next;
            fP = fP -> next -> next;
            if(sP == fP) { return true;}
        }
        return false;
    }
};

int main()
{
    std::vector<int> arr = {1,2,3};
    Solution sol;
    ListNode  *n = sol.buildList(arr, -1);
    std::cout << sol.hasCycle(n) << std::endl;
    return 0;
}
