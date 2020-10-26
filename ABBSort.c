#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
    int height;
} node;

int max(int a, int b);
int height(node *root);
int getBalance(node* root);
node* createNode(int value);
node* rightRotation(node* root);
node* leftRotation(node* root);
node* insert(node* root, int value);
void inOrder(node* root);

int sorted = 0;
int* a;

int main(int argc, char *argv[]) {
    if(argc != 2)
        return 0;

    double utime0, stime0, wtime0,utime1, stime1, wtime1;

    int n = atoi(argv[1]);
    a = malloc(sizeof(int) * n);

    int value, i;
    node* ABBSort = NULL;

    // algorithm begin
    uswtime(&utime0, &stime0, &wtime0);

    for(i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        ABBSort = insert(ABBSort, a[i]);
    }

    inOrder(ABBSort);

    // algorithm end
    uswtime(&utime1, &stime1, &wtime1);
    //Cálculo del tiempo de ejecución del programa
    printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));


    return 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int height(node *root) {
    return (root == NULL) ? 0 : root -> height;
}

node* createNode(int value) {
    node* root =(node*) malloc(sizeof(node));

    root -> value = value;
    root -> left = NULL;
    root -> right = NULL;
    root -> height = 1;

    return root;
}

node* rightRotation(node* root) {
    node* next = root -> left;
    node* temp = next -> right;

    next -> right = root;
    root -> left = temp;

    root -> height = max(height(root -> left), height(root -> right)) + 1;
    next -> height = max(height(next -> left), height(next -> right)) + 1;

    return next;
}

node* leftRotation(node* root) {
    node* next = root -> right;
    node* temp = next -> left;

    next -> left = root;
    root -> right = temp;

    root -> height = max(height(root -> left), height(root -> right)) + 1;
    next -> height = max(height(next -> left), height(next -> right)) + 1;

    return next;
}

int getBalance(node* root) {
    return (root == NULL) ? 0 : height(root -> left) - height(root -> right);
}

node* insert(node* root, int value) {
    if(root == NULL) {
        return createNode(value);
    }

    if(value < root -> value) {
        root -> left = insert(root -> left, value);
    } else if(value > root -> value) {
        root -> right = insert(root -> right, value);
    } else {
        return root;
    }

    root -> height = max(height(root -> left), height(root -> right)) + 1;

    int balance = getBalance(root);

    if(balance > 1 && value < root -> left -> value) {
        return rightRotation(root);
    }

    if(balance < -1 && value > root -> right -> value) {
        return leftRotation(root);
    }

    if(balance > 1 && value > root -> left -> value) {
        root -> left = leftRotation(root -> left);
        return rightRotation(root);
    }

    if(balance < -1 && value < root -> right -> value) {
        root -> right = rightRotation(root -> right);
        return leftRotation(root);
    }

    return root;
}

void inOrder(node* root) {
    if(root != NULL) {
        inOrder(root -> left);
        a[sorted++] = root -> value;
        inOrder(root -> right);
    }
}