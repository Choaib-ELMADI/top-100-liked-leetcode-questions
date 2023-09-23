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
            ListNode *dummy = new ListNode(0);
            dummy->next = head;
            ListNode *curr = dummy;

            while (curr->next && curr->next->next) {
                ListNode *first = curr->next;
                ListNode *second = curr->next->next;

                first->next = second->next;
                second->next = first;

                curr->next = second;
                curr = first;
            }

            return dummy->next;
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