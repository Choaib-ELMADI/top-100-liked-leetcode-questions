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

            ListNode *slow = head;
            ListNode *fast = head;
            stack<int> s;

            while (fast && fast->next) {
                s.push(slow->val);
                slow = slow->next;
                fast = fast->next->next;
            }

            if (fast) {
                slow = slow->next;
            }

            while (slow) {
                int val = s.top();
                s.pop();
                if (val != slow->val) {
                    return false;
                }
                slow = slow->next;
            }

            return true;
        }
};

int main() {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(1);

    Solution test;
    bool isPalindrome = test.isPalindrome(head);
    cout << boolalpha << "isPalindrome = " << isPalindrome << endl;

    return 0;
}