#include<stdio.h>
#include<stdlib.h>
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
} node;
node* insert(node* root, int data) {
    if (root == NULL) {
        node* newNode = (node*)malloc(sizeof(node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}
node* createBST() {
    node* root = NULL;
    int data;
    printf("Enter data for nodes (-1 to exit): ");
    while (1) {
        scanf("%d", &data);
        if (data == -1) {
            break;
        }
        root = insert(root, data);
    }
    return root;
}
void preorder(node* t) {
    if (t != NULL) {
        printf("%d ", t->data);
        preorder(t->left);
        preorder(t->right);
    }
}
void inorder(node* t) {
    if (t != NULL) {
        inorder(t->left);
        printf("%d ", t->data);
        inorder(t->right);
    }
}
void postorder(node* t) {
    if (t != NULL) {
        postorder(t->left);
        postorder(t->right);
        printf("%d ", t->data);
    }
}
int height(node* t) {
    if (t == NULL)
        return 0;
    int leftHeight = height(t->left);
    int rightHeight = height(t->right);
    return (leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1);
}
int main() {
    node* root = createBST();
    printf("\nThe preorder traversal of the tree is: ");
    preorder(root);
    printf("\n\nThe inorder traversal of the tree is: ");
    inorder(root);
    printf("\n\nThe postorder traversal of the tree is: ");
    postorder(root);
    printf("\n\nThe height of the tree is: %d\n", height(root));
    return 0;
}
