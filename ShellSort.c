#include <stdio.h>
#include <stdlib.h>

void ShellSort(int* a, int n);

int main(int argc, char *argv[]) {
    if(argc != 2)
        return 0;

    int n = atoi(argv[1]), i;
    int* a = malloc(sizeof(int) * n);

    for(i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }

    ShellSort(a, n);

    for(i = 0; i < n; ++i) {
        printf("%d ", a[i]);
    }

    return 0;
}

void ShellSort(int* a, int n) {
    int g, i, j, k, temp;
    for(g = n/2; g > 0; g /= 2) {
        for(i = g; i < n; ++i) {
            temp = a[i];
            for(j = i; i >= g && a[j-g] > temp; j -= g) {
                a[j] = a[j-g];
            }
            a[j] = temp;
        }
    }
}