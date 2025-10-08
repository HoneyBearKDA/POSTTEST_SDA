#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

void insertEnd(Node*& h, int d) {
    Node* n = new Node;
    n->data = d;
    if (h == NULL) {
        n->next = n;
        n->prev = n;
        h = n;
        return;
    }
    Node* t = h->prev;
    n->next = h;
    n->prev = t;
    t->next = n;
    h->prev = n;
}

void exchange(Node*& h) {
    if (h == NULL || h->next == h) return;
    Node* head = h;
    Node* tail = h->prev;
    if (head->next == tail) {
        h = tail;
        return;
    }
    Node* headNext = head->next;
    Node* tailPrev = tail->prev;
    tail->next = headNext;
    headNext->prev = tail;
    head->prev = tailPrev;
    tailPrev->next = head;
    tail->prev = head;
    head->next = tail;
    h = tail;
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
    insertEnd(h, 1);
    insertEnd(h, 2);
    insertEnd(h, 3);
    insertEnd(h, 4);
    insertEnd(h, 5);
    cout << "Sebelum: ";
    print(h);
    exchange(h);
    cout << "Sesudah: ";
    print(h);
    return 0;
}

