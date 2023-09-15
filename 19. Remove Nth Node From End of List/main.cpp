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
        ListNode* removeNthFromEnd(ListNode* head, int n) {
            ListNode *first = head;
            ListNode *second = head;

            int i=0;
            while (i<n) {
                if (!first->next) {
                    return head->next;
                }
                first = first->next;
                ++i;
            }

            while (first->next) {
                first = first->next;
                second = second->next;
            }

            ListNode *newNext = second->next->next;
            second->next = newNext;

            return head;
        }
};

void printList(ListNode *);

int main() {
    Solution test;

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    printList(head);
    printList(test.removeNthFromEnd(head, 5));

    return 0;
}

void printList(ListNode *head) {
    ListNode *curr = head;
    while (curr) {
        cout << curr->val;
        if (curr->next) cout << " - ";
        curr = curr->next;
    }
    cout << endl;
}