#include <stdio.h>
#include <stdlib.h>

// Simple singly linked list node for practice problem
typedef struct Node {
    int value;
    struct Node *next;
} Node;

Node* new_node(int v) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->value = v;
    n->next = NULL;
    return n;
}

// Reverse a singly linked list iteratively in O(n) time and O(1) extra space
Node* reverse_list(Node* head) {
    Node *prev = NULL, *curr = head;
    while (curr) {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void print_list(Node* head) {
    for (Node* n = head; n; n = n->next) {
        printf("%d%s", n->value, n->next ? " -> " : "\n");
    }
}

int main(void) {
    // Example: 1 -> 2 -> 3 -> NULL becomes 3 -> 2 -> 1 -> NULL
    Node* head = new_node(1);
    head->next = new_node(2);
    head->next->next = new_node(3);

    print_list(head);
    head = reverse_list(head);
    print_list(head);

    // cleanup
    while (head) {
        Node* tmp = head->next;
        free(head);
        head = tmp;
    }
    return 0;
}
