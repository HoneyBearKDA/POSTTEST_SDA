#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
};

void enqueue(Node*& front, Node*& rear, string d) {
    Node* n = new Node;
    n->data = d;
    n->next = NULL;
    if (front == NULL) {
        front = n;
        rear = n;
    } else {
        rear->next = n;
        rear = n;
    }
}

string dequeue(Node*& front, Node*& rear) {
    if (front == NULL) return "";
    Node* t = front;
    string d = t->data;
    front = front->next;
    if (front == NULL) rear = NULL;
    delete t;
    return d;
}

int main() {
    Node* f = NULL;
    Node* r = NULL;
    enqueue(f, r, "Document1.pdf");
    enqueue(f, r, "Report.docx");
    enqueue(f, r, "Presentation.pptx");
    cout << "Memproses dokumen:" << endl;
    while (f != NULL) cout << dequeue(f, r) << endl;
    return 0;
}

