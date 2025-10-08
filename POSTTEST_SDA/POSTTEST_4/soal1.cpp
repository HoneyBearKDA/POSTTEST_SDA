#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

void push(Node*& top, char data) {
    Node* n = new Node;
    n->data = data;
    n->next = top;
    top = n;
}

char pop(Node*& top) {
    if (top == NULL) return '\0';
    Node* t = top;
    char v = t->data;
    top = top->next;
    delete t;
    return v;
}

string reverseString(string s) {
    Node* top = NULL;
    for (int i = 0; i < s.size(); i++) push(top, s[i]);
    string res = "";
    char c;
    while ((c = pop(top)) != '\0') res += c;
    return res;
}

int main() {
    string teks = "Struktur Data";
    cout << "Teks asli: " << teks << endl;
    cout << "Teks terbalik: " << reverseString(teks) << endl;
    return 0;
}

