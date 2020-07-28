#include <stdio.h>
#include <stdlib.h>

// Like our location struct
struct list_container {
    struct node* head;
};

// Like our enemy struct
struct node {
    int data;
    struct node* next;
};

void print_list(struct list_container* container);
struct list_container* make_list(void);
void insert_at_end(struct list_container* container, int value);
struct node *new_node(int value);

int main(void) {
    struct list_container* list = make_list();
    insert_at_end(list, 100);
    insert_at_end(list, 150);
    insert_at_end(list, 200);
    print_list(list);

    return 0;
}

struct list_container* make_list(void) {
    struct list_container* new_container = malloc(sizeof(struct list_container));
    // The list is empty when we make it.
    new_container->head = NULL;
    return new_container;
}

// Like making a new enemy node
struct node *new_node(int value) {
    struct node* result = malloc(sizeof(struct node));
    // Set the initial value
    result->data = value;
    // The node is by itself and not in a list yet.
    result->next = NULL;
    return result;
}

void insert_at_end(struct list_container* container, int value) {
    // Make a new node with the value inside.
    struct node *my_node = new_node(value);

    // If the list is empty
    if (container->head == NULL) {

        // Sets the first value in the linked list
        // to the node we've just created.
        container->head = my_node;
    } else {

        // There are nodes, get to the last node in the list.
        struct node* current = container->head;

        // Change current until we are at the last node.
        while (current->next != NULL) {
            current = current->next;
        }

        // Now this must be true: current->next == NULL
        current->next = my_node;
        my_node->next = NULL;
    }
}

void print_list(struct list_container* container) {
    struct node* current = container->head;

    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}
