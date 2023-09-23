#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

class Solution {
    public:
        ListNode* swapPairs(ListNode* head) {
            if (!head) return nullptr;
            if (!head->next) return head;

            ListNode *first = head->next;
            ListNode *second = head;

            int temp = first->val;
            first->val = second->val;
            second->val = temp;

            while (first->next && first->next->next) {
                first = first->next->next;
                second = second->next->next;

                temp = first->val;
                first->val = second->val;
                second->val = temp;
            }

            return head;
        }
};

void printList(ListNode *head) {
    ListNode *curr = head;
    while (curr) {
        cout << curr->val;
        if (curr->next) {
            cout << " - ";
        }
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    ListNode *fifth = new ListNode(5);
    ListNode *fourth = new ListNode(4, fifth);
    ListNode *third = new ListNode(3, fourth);
    ListNode *second = new ListNode(2, third);
    ListNode *head = new ListNode(1, second);

    Solution test;
    printList(test.swapPairs(head));

    return 0;
}