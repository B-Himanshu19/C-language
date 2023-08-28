#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;
node *create() {
    node *p;
    int x;
    printf("Enter data (-1 for no data): ");
    scanf("%d", &x);
    if (x == -1)
        return NULL;
    p = (node*)malloc(sizeof(node));
    p->data = x;
    printf("Enter left child of %d:\n", x);
    p->left = create();
    printf("Enter right child of %d:\n", x);
    p->right = create();
    return p;
}
void preorder(node *t) {
    if (t != NULL) {
        printf("%d ", t->data);
        preorder(t->left);
        preorder(t->right);
    }
}
void inorder(node *t) {
    if (t != NULL) {
        inorder(t->left);
        printf("%d ", t->data);
        inorder(t->right);
    }
}
void postorder(node *t) {
    if (t != NULL) {
        postorder(t->left);
        postorder(t->right);
        printf("%d ", t->data);
    }
}
int height(node *t) {
    if (t == NULL)
        return 0;
    int leftHeight = height(t->left);
    int rightHeight = height(t->right);
    return (leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1);
}
int main() {
    node *root;
    root = create();
    printf("\nThe preorder traversal of the tree is: ");
    preorder(root);
    printf("\n\nThe inorder traversal of the tree is: ");
    inorder(root);
    printf("\n\nThe postorder traversal of the tree is: ");
    postorder(root);
    printf("\n\nThe height of the tree is: %d\n", height(root));
    return 0;
}
