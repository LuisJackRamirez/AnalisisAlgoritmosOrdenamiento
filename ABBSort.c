/*
    Titulo: Ordenamiento con Árbol binario de búsqueda
    Descripción: Implemntación de un árbol binario de búsqueda con rotaciones, su
    recorrido inOrder para devolver los elementos ordenados.
    Fecha: 26/10/2020
    Version: 1.6.1
    Autor: Luis Fernando Reséndiz Chávez
*/

/*********************************************************
        BIBLIOTECAS UTILIZADAS
*********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

/*********************************************************
        ESTRUCTURA DEL ÁRBOL BINARIO DE BÚSQUEDA
*********************************************************/

typedef struct node {
    int value; // Valor del nodo.
    struct node* left; // Apuntador a un hijo izquierdo.
    struct node* right; // Apuntador a un hijo derecho.
    int height; // Altura del nodo respecto al árbol.
} node;

/*********************************************************
        PROTOTIPOS DE FUNCIONES
*********************************************************/

int max(int a, int b);
int height(node *root);
int getBalance(node* root);
node* createNode(int value);
node* rightRotation(node* root);
node* leftRotation(node* root);
node* insert(node* root, int value);
void inOrder(node* root);

/*********************************************************
        VARIABLES GLOBALES
*********************************************************/

int sorted = 0; // Posición desde donde empezar a guardar los números ordenados.
int* a; // Apuntador de tipo entero para recibir los números.

/*********************************************************
        FUNCIÓN PRINCIPAL DEL PROGRAMA
*********************************************************/

int main(int argc, char *argv[]) {
    // Si no se da un tamaño del problema al ejecutar, finaliza.
    if(argc != 2)
        return 0;

    // Variables para medir el tiempo del algoritmo.
    double utime0, stime0, wtime0,utime1, stime1, wtime1;

    // Se recibe la n (tamaño del problema).
    int n = atoi(argv[1]);
    // Se le asigna memoria al apuntador "a", para n números.
    a = malloc(sizeof(int) * n);

    // Variable iterativa.
    int i;

    // Inicialización del árbol.
    node* ABBSort = NULL;

    for(i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    // Incio del algoritmo, comenzamos a contar el tiempo.
    uswtime(&utime0, &stime0, &wtime0);
    

    for(i = 0; i < n; ++i) {
        ABBSort = insert(ABBSort, a[i]);
    }

    inOrder(ABBSort);

    // Fin del algoritmo, dejamos de medir el tiempo
    uswtime(&utime1, &stime1, &wtime1);

    //Cálculo del tiempo de ejecución del programa
    printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));


    return 0;
}

/*********************************************************
        IMPLEMENTACIÓN DE FUNCIONES
*********************************************************/

// max(int, int) -> int
// Recibe dos numeros enteros y devuelve el mayor de ellos.
int max(int a, int b) {
    return (a > b) ? a : b;
}

// height(node*) -> int
// Recibe una apuntador a una estructura nodo y devuelve su altura respecto al árbol.
int height(node *root) {
    return (root == NULL) ? 0 : root -> height;
}

// createNode(int) -> node*
// Recive un número entero y devuleve un apuntador a una estrcutura nodo con dicho valor.
node* createNode(int value) {
    node* root =(node*) malloc(sizeof(node));

    root -> value = value;
    root -> left = NULL;
    root -> right = NULL;
    root -> height = 1;

    return root;
}

// rightRotation(node*) -> node*
// Recibe un apuntador a una estructura nodo, rota su subarbol a la derecha para balancearlo y retorna la nueva raiz
node* rightRotation(node* root) {
    node* next = root -> left;
    node* temp = next -> right;

    next -> right = root;
    root -> left = temp;

    root -> height = max(height(root -> left), height(root -> right)) + 1;
    next -> height = max(height(next -> left), height(next -> right)) + 1;

    return next;
}

// leftRotation(node*) -> node*
// Recibe un apuntador a una estructura nodo, rota su subarbol a la izquierda para balancearlo y retorna la nueva raiz
node* leftRotation(node* root) {
    node* next = root -> right;
    node* temp = next -> left;

    next -> left = root;
    root -> right = temp;

    root -> height = max(height(root -> left), height(root -> right)) + 1;
    next -> height = max(height(next -> left), height(next -> right)) + 1;

    return next;
}

// getbalance(node*) -> int
// Recibe un apuntador a una estructura nodo y devuelve du factor de balance, sirve para
// ver hacia que lado queda balanceado el árbol
int getBalance(node* root) {
    return (root == NULL) ? 0 : height(root -> left) - height(root -> right);
}

// insert(node*, int) -> node*
// Recibe un apuntador a una estructura nodo que representa la raiz del arbol, tambien
// recibe un número entero y lo inserta en el árbol creando un nuevo nodo, devuelve el árbol
// con el nuevo numero insertado.
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

// inOrder(root*) -> void
// Realiza el recorrido inOrder (hijo izquierdo, raiz, hijo derecho) de un árbol binario.
// Almacena los valores ya ordenados de cada nodo en el arreglo incial (variable global).
void inOrder(node* root) {
    if(root != NULL) {
        inOrder(root -> left);
        a[sorted++] = root -> value;
        inOrder(root -> right);
    }
}