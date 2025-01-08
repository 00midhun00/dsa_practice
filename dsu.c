#include <stdio.h>
#include <stdlib.h>

// Define the node structure
struct node {
    struct node *rep;  // Pointer to the representative (head) of the set
    struct node *next; // Pointer to the next element in the set
    int data;          // The actual data value
} *heads[50], *tails[50];

static int countRoot = 0;

// Function to create a new set
void makeSet(int x) {
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->rep = new;    // The node is its own representative
    new->next = NULL;  // No next element
    new->data = x;     // Data is set to x

    heads[countRoot] = new;   // Add to heads array
    tails[countRoot++] = new; // Add to tails array and increment countRoot
}

// Function to find the representative of the set containing element a
struct node *find(int a) {
    for (int i = 0; i < countRoot; i++) {
        struct node *tmp = heads[i];
        while (tmp != NULL) {
            if (tmp->data == a) {
                return tmp->rep; // Return representative if found
            }
            tmp = tmp->next;
        }
    }
    return NULL; // Element not found
}

// Function to merge two sets
void unionSets(int a, int b) {
    struct node *rep1 = find(a);
    struct node *rep2 = find(b);

    if (rep1 == NULL || rep2 == NULL) {
        printf("\nElement not present in the DS\n");
        return;
    }

    if (rep1 != rep2) {
        int pos = -1;
        struct node *tail2 = NULL;

        // Locate the set containing rep2
        for (int j = 0; j < countRoot; j++) {
            if (heads[j] == rep2) {
                pos = j;
                tail2 = tails[j];
                break;
            }
        }

        // Remove rep2 from heads[] and tails[]
        if (pos != -1) {
            for (int i = pos; i < countRoot - 1; i++) {
                heads[i] = heads[i + 1];
                tails[i] = tails[i + 1];
            }
            countRoot--;
        }

        // Append rep2's list to rep1's list
        for (int j = 0; j < countRoot; j++) {
            if (heads[j] == rep1) {
                tails[j]->next = rep2;
                tails[j] = tail2;
                break;
            }
        }

        // Update representatives in rep2's list
        struct node *current = rep2;
        while (current != NULL) {
            current->rep = rep1;
            current = current->next;
        }
    }
}

// Function to check if an element exists in any set
int search(int x) {
    for (int i = 0; i < countRoot; i++) {
        struct node *tmp = heads[i];
        while (tmp != NULL) {
            if (tmp->data == x) {
                return 1; // Found
            }
            tmp = tmp->next;
        }
    }
    return 0; // Not found
}

// Main function to manage the menu
int main() {
    int choice, x, y;

    do {
        printf("\n========================================\n");
        printf("MENU\n");
        printf("1. Make Set\n");
        printf("2. Display Set Representatives\n");
        printf("3. Union\n");
        printf("4. Find Set\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("========================================\n");

        switch (choice) {
        case 1:
            printf("Enter new element: ");
            scanf("%d", &x);
            if (search(x)) {
                printf("Element already present in the disjoint set DS\n");
            } else {
                makeSet(x);
            }
            break;

        case 2:
            printf("Set Representatives: ");
            for (int i = 0; i < countRoot; i++) {
                printf("%d ", heads[i]->data);
            }
            printf("\n");
            break;

        case 3:
            printf("Enter first element: ");
            scanf("%d", &x);
            printf("Enter second element: ");
            scanf("%d", &y);
            unionSets(x, y);
            break;

        case 4:
            printf("Enter the element: ");
            scanf("%d", &x);
            struct node *rep = find(x);
            if (rep == NULL) {
                printf("Element not present in the DS\n");
            } else {
                printf("The representative of %d is %d\n", x, rep->data);
            }
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}
