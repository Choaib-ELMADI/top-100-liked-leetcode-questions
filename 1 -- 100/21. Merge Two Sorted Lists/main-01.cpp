#include <iostream>
using namespace std;

struct Node {
    Node(): val(0), next(nullptr) {}
    Node(int x): val(x), next(nullptr) {}
    Node(int x, Node *next): val(x), next(next) {}

    int val;
    Node *next;
};

void printList(Node *);
Node *mergeTwoLists(Node *, Node *);

int main() {
    //!First List
    Node *second1 = new Node(7);
    Node *head1 = new Node(4, second1);
    printList(head1);
    cout << endl;

    //!Second List
    Node *third2 = new Node(8);
    Node *second2 = new Node(3, third2);
    Node *head2 = new Node(1, second2);
    printList(head2);
    cout << endl;

    Node *head3 = mergeTwoLists(head1, head2);
    printList(head3);

    return 0;
}

void printList(Node *e) {
    while (e != NULL) {
        cout << e->val;
        if (e->next != NULL) cout << " - ";
        e = e->next;
    }
    cout << endl;
}

Node *mergeTwoLists(Node *list1, Node *list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;

    Node *head = list1;
    if (list1->val > list2->val) {
        head = list2;
        list2 = list2->next;
    } else {
        list1 = list1->next;
    }

    Node *curr = head;
    while (list1 != NULL && list2 != NULL) {
        if (list1->val > list2->val) {
            curr->next = list2;
            list2 = list2->next;
        } else {
            curr->next = list1;
            list1 = list1->next;
        }
        curr = curr->next;
    }
    if (list1 == NULL) curr->next = list2;
    else curr->next = list1;

    return head;
}