#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
    public:
        bool hasCycle(ListNode *head) {
            if (head == nullptr) return false;

            ListNode *fast = head;
            ListNode *slow = head;

            while (fast->next != nullptr && fast->next->next != nullptr) {
                slow = slow->next;
                fast = fast->next->next;

                if (slow == fast) return true;
            }

            return false;
        }
};

int main() {
    ListNode *head = new ListNode(3);
    head->next = new ListNode(2);
    head->next->next = new ListNode(0);
    head->next->next->next = new ListNode(-4);
    head->next->next->next->next = head->next;

    Solution test;

    bool isCycle = test.hasCycle(head);
    cout << "isCycle = " << boolalpha << isCycle << endl;

    return 0;
}