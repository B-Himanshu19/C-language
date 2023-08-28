#include <stdio.h>
#include <stdlib.h>
struct node {
    int x, p;
    struct node* next;
};
struct node* create() {
    struct node* first = NULL;
    struct node* temp = NULL;
    int ch;
    do {
        struct node* nn = (struct node*)malloc(sizeof(struct node));
        printf("Enter Data: ");
        scanf("%d%d", &nn->x, &nn->p);
        if (first == NULL) first = temp = nn;
        else temp->next = nn, temp = nn;
        temp->next = NULL;
        printf("Continue? 0/1 ");
        scanf("%d", &ch);
    } while (ch != 0);
    return first;
}
void display(struct node* o) {
    if (!o) printf("Empty");
    else for (struct node* temp = o; temp; temp = temp->next) {
        printf(" %dx^%d%s", temp->x, temp->p, temp->next ? " +" : "");
    }
    printf(" = 0");
}
void multiply(struct node* a, struct node* b) {
    struct node* result = NULL;
    for (struct node* tempA = a; tempA; tempA = tempA->next) {
        for (struct node* tempB = b; tempB; tempB = tempB->next) {
            struct node* nn = (struct node*)malloc(sizeof(struct node));
            nn->x = tempA->x * tempB->x;
            nn->p = tempA->p + tempB->p;
            if (!result) result = nn;
            else {
                struct node* tempResult = result;
                while (tempResult->next) tempResult = tempResult->next;
                tempResult->next = nn;
            }
            nn->next = NULL;
        }
    }
    display(result);
}
int main() {
    int x;
    struct node* a = NULL;
    struct node* b = NULL;
    do {
        printf("\nChoice\n1. Create A\n2. Create B\n3. Display A\n4. Display B\n5. Multiply\n0. Exit\n");
        scanf("%d", &x);
        switch (x) {
            case 1: a = create(); break;
            case 2: b = create(); break;
            case 3: display(a); break;
            case 4: display(b); break;
            case 5: multiply(a, b); break;
        }
    } while (x);
    return 0;
}
