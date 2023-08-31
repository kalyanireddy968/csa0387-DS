#include <stdio.h>
#define MAX_SIZE 10

void inputMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }
}

void displayMatrix(int mat[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

void subtractMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
}

void multiplyMatrices(int mat1[MAX_SIZE][MAX_SIZE], int mat2[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

int main() {
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows and columns of matrix 1: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter the number of rows and columns of matrix 2: ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1 != rows2) {
        printf("Matrix multiplication is not possible!\n");
        return 1;
    }

    int matrix1[MAX_SIZE][MAX_SIZE], matrix2[MAX_SIZE][MAX_SIZE], result[MAX_SIZE][MAX_SIZE];

    printf("For matrix 1:\n");
    inputMatrix(matrix1, rows1, cols1);

    printf("For matrix 2:\n");
    inputMatrix(matrix2, rows2, cols2);

    printf("Choose operation:\n");
    printf("1. Add matrices\n");
    printf("2. Subtract matrices\n");
    printf("3. Multiply matrices\n");
    printf("4. Exit\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            if (rows1 != rows2 || cols1 != cols2) {
                printf("Matrix addition is not possible!\n");
                return 1;
            }
            addMatrices(matrix1, matrix2, result, rows1, cols1);
            displayMatrix(result, rows1, cols1);
            break;
        case 2:
            if (rows1 != rows2 || cols1 != cols2) {
                printf("Matrix subtraction is not possible!\n");
                return 1;
            }
            subtractMatrices(matrix1, matrix2, result, rows1, cols1);
            displayMatrix(result, rows1, cols1);
            break;
        case 3:
            multiplyMatrices(matrix1, matrix2, result, rows1, cols1, cols2);
            displayMatrix(result, rows1, cols2);
            break;
        case 4:
            printf("Exiting the program.\n");
            return 0;
        default:
            printf("Invalid choice!\n");
            return 1;
    }

    return 0;
}

