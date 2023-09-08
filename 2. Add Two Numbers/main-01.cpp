/*
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    !!!                                          !!!
    !!!      Code not working as expected        !!!
    !!!                                          !!!
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

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
            ListNode *curr1 = l1;
            ListNode *curr2 = l2;
            ListNode *node  = new ListNode();
            ListNode *newHead  = node;

            while (curr1 || curr2) {
                ListNode *nextNode = new ListNode();

                if (curr1 && curr2) {
                    if (curr1->val + curr2->val >= 10) {
                        node->val += ((curr1->val + curr2->val) % 10);
                        nextNode->val = ((curr1->val + curr2->val) / 10);
                    } else {
                        node->val += curr1->val + curr2->val;
                    }

                    curr1 = curr1->next;
                    curr2 = curr2->next;
                } else if (curr1 && !curr2) {
                    node->val = curr1->val;
                    curr1 = curr1->next;
                } else {
                    node->val = curr2->val;
                    curr2 = curr2->next;
                }

                node->next = nextNode;
                node = node->next;
            }

            return newHead;
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