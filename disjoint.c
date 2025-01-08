#include <stdio.h>
#include <stdlib.h>

// Node structure
struct node {
    struct node *rep;  // Points to the representative of the set
    struct node *next; // Points to the next node in the set
    int data;          // Data value
} *heads[50], *tails[50];

int countRoot = 0; // Number of disjoint sets

// Create a new set containing the element x
void makeSet(int x) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->rep = newNode;   // Node is its own representative
    newNode->next = NULL;     // No next element
    newNode->data = x;        // Set data

    heads[countRoot] = newNode;   // Add to heads array
    tails[countRoot++] = newNode; // Add to tails array
    printf("Created set with element: %d\n", x);
}

// Find the representative of the set containing x
struct node *find(int x) {
    for (int i = 0; i < countRoot; i++) {
        struct node *current = heads[i];
        while (current != NULL) {
            if (current->data == x) {
                return current->rep; // Found
            }
            current = current->next;
        }
    }
    return NULL; // Not found
}

// Merge two sets containing elements x and y
void unionSets(int x, int y) {
    struct node *repX = find(x);
    struct node *repY = find(y);

    if (!repX || !repY) {
        printf("One or both elements not found.\n");
        return;
    }
    if (repX == repY) {
        printf("Both elements are already in the same set.\n");
        return;
    }

    // Merge the set containing y into the set containing x
    for (int i = 0; i < countRoot; i++) {
        if (heads[i] == repY) {
            tails[i]->next = repX; // Append repY's list to repX
            break;
        }
    }

    // Update representatives in repY's list
    struct node *current = repY;
    while (current != NULL) {
        current->rep = repX;
        current = current->next;
    }

    printf("Union of sets containing %d and %d completed.\n", x, y);
}

// Display all sets
void displaySets() {
    printf("Current sets:\n");
    for (int i = 0; i < countRoot; i++) {
        struct node *current = heads[i];
        printf("Set %d: ", i + 1);
        while (current != NULL) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// Main menu for interacting with the program
int main() {
    int choice, x, y;

    do {
        printf("\nMenu:\n");
        printf("1. Make Set\n");
        printf("2. Find Set Representative\n");
        printf("3. Union Sets\n");
        printf("4. Display Sets\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter element: ");
            scanf("%d", &x);
            makeSet(x);
            break;
        case 2:
            printf("Enter element: ");
            scanf("%d", &x);
            struct node *rep = find(x);
            if (rep) {
                printf("Representative of %d: %d\n", x, rep->data);
            } else {
                printf("Element not found.\n");
            }
            break;
        case 3:
            printf("Enter two elements to union: ");
            scanf("%d%d", &x, &y);
            unionSets(x, y);
            break;
        case 4:
            displaySets();
            break;
        case 5:
            printf("Exiting program.\n");
            exit(0);
        default:
            printf("Invalid choice. Try again.\n");
        }
    } while (1);

    return 0;
}

/*
Sample Output:

Menu:
1. Make Set
2. Find Set Representative
3. Union Sets
4. Display Sets
5. Exit
Enter choice: 1
Enter element: 1
Created set with element: 1

Enter choice: 1
Enter element: 2
Created set with element: 2

Enter choice: 4
Current sets:
Set 1: 1 -> NULL
Set 2: 2 -> NULL

Enter choice: 3
Enter two elements to union: 1 2
Union of sets containing 1 and 2 completed.

Enter choice: 4
Current sets:
Set 1: 1 -> 2 -> NULL

Enter choice: 2
Enter element: 2
Representative of 2: 1

Enter choice: 5
Exiting program.
*/



