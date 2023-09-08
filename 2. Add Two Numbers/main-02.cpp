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
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            ListNode *newHead  = new ListNode();
            ListNode *node  = newHead;

            int remainder = 0;
            while (l1 || l2) {
                int sum = remainder;

                if (l1) {
                    sum += l1->val;
                    l1 = l1->next;
                }

                if (l2) {
                    sum += l2->val;
                    l2 = l2->next;
                }

                remainder = sum / 10;
                sum = sum % 10;

                node->next = new ListNode(sum);
                node = node->next;
            }

            if (remainder == 1) node->next = new ListNode(1);

            return newHead->next;
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
    ListNode *head1 = new ListNode(9);    //! 9999
    head1->next = new ListNode(9);
    head1->next->next = new ListNode(9);
    head1->next->next->next = new ListNode(9);

    ListNode *head2 = new ListNode(9);    //!  999 ==> 10998
    head2->next = new ListNode(9);
    head2->next->next = new ListNode(9);

    Solution test;

    printList(head1);
    printList(head2);
    printList(test.addTwoNumbers(head1, head2));

    return 0;
}