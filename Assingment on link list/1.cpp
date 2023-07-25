#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtMid(struct Node** head_ref, int x) {
    // Get a new node
    Node* newNode = (Node*)malloc(sizeof(Node));
  
    // inserting the required data
    newNode->data = x;
    newNode->next = NULL;

    struct Node* ptr = *head_ref;
    int len = 0;

    // Calculate the length of the linked list
    // i.e., the number of nodes
    while (ptr != NULL) {
        len++;
        ptr = ptr->next;
    }

    // 'count' the number of nodes after which
    // the new node is to be inserted
    int count = ((len % 2) == 0) ? (len / 2) : (len + 1) / 2;
    ptr = *head_ref;

    // 'ptr' points to the node after which 
    // the new node is to be inserted
    while (count-- > 1)
        ptr = ptr->next;

    // Insert the 'newNode' and adjust the
    // required links
    newNode->next = ptr->next;
    ptr->next = newNode;

    return *head_ref;
}


void printLinkedList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* head = NULL;
    
    // Create the linked list {10, 20, 30, 40, 50, 60}
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node4 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node5 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node6 = (struct Node*)malloc(sizeof(struct Node));
    
    node1->data = 10;
    node1->next = node2;
    
    node2->data = 20;
    node2->next = node3;
    
    node3->data = 30;
    node3->next = node4;
    
    node4->data = 40;
    node4->next = node5;
    
    node5->data = 50;
    node5->next = node6;
    
    node6->data = 60;
    node6->next = NULL;

    head = node1;
    
    printf("Linked List before insertion: ");
    printLinkedList(head);
    
    // Insert 500 at the middle of the linked list
    insertAtMid(&head, 500);
    
    printf("Linked List after insertion: ");
    printLinkedList(head);

    // Free allocated memory
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
    
    return 0;
}
