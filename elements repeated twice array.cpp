#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
void findDuplicates(int arr[], int n) {
    int hash[MAX_SIZE] = {0}; 

    printf("Elements repeated twice: ");
    for (int i = 0; i < n; i++) {
        hash[arr[i]]++; 
        if (hash[arr[i]] == 2) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0 || n > MAX_SIZE) {
        printf("Invalid number of elements\n");
        return 1;
    }

    int arr[MAX_SIZE];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findDuplicates(arr, n);

    return 0;
}

