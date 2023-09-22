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
        ListNode* reverseList(ListNode* head) {
            //================================================================//
            //>==> First Method:

            ListNode *prev = nullptr;
            ListNode *curr = head;
            ListNode *next = nullptr;

            while (curr != nullptr) {
                next = curr->next;
                curr->next = prev;

                prev = curr;
                curr = next;
            }

            head = prev;
            return head;

            //================================================================//
            //>==> Second Method:

            /*
            if (!head || !head->next)
                return head;

            ListNode *node = reverseList(head->next);

            head->next->next = head;
            head->next = nullptr;

            return node;
            */
        }
};

void printList(ListNode *head) {
    ListNode *parcours = head;

    while (parcours != nullptr) {
        cout << parcours->val;
        if (parcours->next != nullptr) cout << " - ";
        parcours = parcours->next;
    }
    cout << endl;
}

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);

    printList(head);

    Solution test;
    ListNode *newHead = test.reverseList(head);

    printList(newHead);

    return 0;
}