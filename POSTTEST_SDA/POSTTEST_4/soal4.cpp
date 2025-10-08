#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void insertSorted(Node*& head, int d) {
    Node* n = new Node;
    n->data = d;
    if (head == NULL) {
        n->next = n;
        n->prev = n;
        head = n;
        return;
    }
    if (d < head->data) {
        Node* tail = head->prev;
        n->next = head;
        n->prev = tail;
        tail->next = n;
        head->prev = n;
        head = n;
        return;
    }
    Node* cur = head;
    while (cur->next != head && cur->next->data < d) cur = cur->next;
    Node* nxt = cur->next;
    cur->next = n;
    n->prev = cur;
    n->next = nxt;
    nxt->prev = n;
}

void print(Node* h) {
    if (h == NULL) {
        cout << "Kosong\n";
        return;
    }
    Node* c = h;
    do {
        cout << c->data << " ";
        c = c->next;
    } while (c != h);
    cout << endl;
}

int main() {
    Node* h = NULL;
    insertSorted(h, 30);
    insertSorted(h, 10);
    insertSorted(h, 40);
    insertSorted(h, 20);
    print(h);
    return 0;
}

