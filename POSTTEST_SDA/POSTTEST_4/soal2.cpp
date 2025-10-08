#include <iostream>
#include <string>
using namespace std;

struct Node {
    char data;
    Node* next;
};

void push(Node*& top, char d) {
    Node* n = new Node;
    n->data = d;
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

bool match(char o, char c) {
    return (o == '(' && c == ')') || (o == '{' && c == '}') || (o == '[' && c == ']');
}

bool balanced(string s) {
    Node* top = NULL;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') push(top, s[i]);
        else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (top == NULL) return false;
            char x = pop(top);
            if (!match(x, s[i])) return false;
        }
    }
    return top == NULL;
}

int main() {
    string a = "{[()]}";
    string b = "{[(])}";
    cout << a << " -> " << (balanced(a) ? "Seimbang" : "Tidak Seimbang") << endl;
    cout << b << " -> " << (balanced(b) ? "Seimbang" : "Tidak Seimbang") << endl;
    return 0;
}

