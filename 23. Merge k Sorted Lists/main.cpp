#include <iostream>
#include <vector>
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
        ListNode *mergeKLists(vector<ListNode *>& lists) {
            int k = lists.size();
            if (k == 0) return nullptr;
            if (k == 1) return lists[0];

            while (k > 1) {
                for (int i=0; i<k/2; ++i) {
                    lists[i] = mergeTwo(lists[i], lists[k - 1 - i]);
                }
                k = (k + 1) / 2;
            }

            return lists[0];
        }

        ListNode *mergeTwo(ListNode *head1, ListNode *head2) {
            if (!head1) return head2;
            if (!head2) return head1;

            ListNode *head = head1;
            if (head1->val > head2->val) {
                head = head2;
                head2 = head2->next;
            } else {
                head1 = head1->next;
            }

            ListNode *curr = head;
            while (head1 && head2) {
                if (head1->val > head2->val) {
                    curr->next = head2;
                    head2 = head2->next;
                } else {
                    curr->next = head1;
                    head1 = head1->next;
                }
                curr = curr->next;
            }

            if (!head1) curr->next = head2;
            else curr->next = head1;

            return head;
        }
};

void printList(ListNode *);

int main() {
    ListNode *node13 = new ListNode(5);       //=> List 1
    ListNode *node12 = new ListNode(4, node13);
    ListNode *head1 = new ListNode(1, node12);

    ListNode *node23 = new ListNode(4);       //=> List 2
    ListNode *node22 = new ListNode(3, node23);
    ListNode *head2 = new ListNode(1, node22);

    ListNode *node32 = new ListNode(6);       //=> List 3
    ListNode *head3 = new ListNode(2, node32);

    ListNode *node42 = new ListNode(9);       //=> List 4
    ListNode *head4 = new ListNode(7, node42);

    vector<ListNode *> v = {head1, head2, head3, head4};
    Solution test;
    ListNode *head = test.mergeKLists(v);
    printList(head);

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