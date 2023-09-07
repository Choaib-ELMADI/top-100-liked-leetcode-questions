#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x): val(x), next(NULL) {}
};

class Solution {
    public:
        ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
            if (!headA || !headB) return nullptr;
            if (headA == headB) return headA;

            ListNode *parcours1 = headA;
            while (parcours1 != nullptr) {
                ListNode *parcours2 = headB;
                
                while (parcours2 != nullptr) {
                    if (parcours1 == parcours2) return parcours1;
                    parcours2 = parcours2->next;
                }
                
                parcours1 = parcours1->next;
            }

            return nullptr;
        }
};

int main() {
    ListNode *inter = new ListNode(99);

    ListNode *headA = new ListNode(11);         //! 1
    headA->next = new ListNode(12);             //! 2
    headA->next->next = new ListNode(13);       //! 3
    headA->next->next->next = inter;            //! 4 <==
    inter->next = new ListNode(15);             //! 5
    inter->next->next = new ListNode(16);       //! 6
    
    ListNode *headB = new ListNode(21);         //! 1
    headB->next = new ListNode(22);             //! 2
    headB->next->next = inter;                  //! 3 <==

    Solution test;
    ListNode *intersection = test.getIntersectionNode(headA, headB);
    if (intersection) {
        cout << "Intersection node.val = " << intersection->val << endl;
    } else {
        cout << "No intersection node" << endl;
    }

    return 0;
}