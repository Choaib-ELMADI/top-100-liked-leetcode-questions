/*
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    !!!                                   !!!
    !!!     This works only for list      !!!
    !!!         with even number          !!!
    !!!             of nodes              !!!
    !!!                                   !!!
    !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
*/

#include <iostream>
#include <stack>
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
        bool isPalindrome(ListNode* head) {
            if (!head || !head->next) return true;

            stack<ListNode *> s;
            s.push(head);
            ListNode *curr = head->next;

            while (curr != nullptr) {
                ListNode *top = s.top();

                if (top->val != curr->val) {
                    s.push(curr);
                } else {
                    s.pop();
                }

                curr = curr->next;
            }

            return s.empty();
        }
};

int main() {
    ListNode *head = new ListNode(0);
    head->next = new ListNode(0);
    head->next->next = new ListNode(1);

    Solution test;
    bool isPalindrome = test.isPalindrome(head);
    cout << boolalpha << "isPalindrome = " << isPalindrome << endl;

    return 0;
}