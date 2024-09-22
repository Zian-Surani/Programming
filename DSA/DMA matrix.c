#include <stdio.h>
#include <stdlib.h>

// Function to allocate memory for a matrix
int* allocateMatrix(int rows, int cols) {
    int* matrix = (int*) malloc(rows * cols * sizeof(int));
    return matrix;
}

// Function to deallocate memory for a matrix
void freemat(int* matrix) {
    free(matrix);
}

// Function to multiply two matrices
void multiplyMatrices(int* matrixA, int* matrixB, int* matrixC, int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            matrixC[i * colsB + j] = 0;
            for (int k = 0; k < colsA; k++) {
                matrixC[i * colsB + j] += matrixA[i * colsA + k] * matrixB[k * colsB + j];
            }
        }
    }
}

// Function to print a matrix
void printMatrix(int* matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i * cols + j]);
        }
        printf("\n");
    }
}

int main() {
    int rowsA, colsA, rowsB, colsB;

    // Get dimensions of matrices A and B
    printf("Enter number of rows for matrix A: ");
    scanf("%d", &rowsA);
    printf("Enter number of columns for matrix A: ");
    scanf("%d", &colsA);
    printf("Enter number of rows for matrix B: ");
    scanf("%d", &rowsB);
    printf("Enter number of columns for matrix B: ");
    scanf("%d", &colsB);

    // Check if matrices can be multiplied
    if (colsA != rowsB) {
        printf("Matrices cannot be multiplied.\n");
        return 1;
    }

    // Allocate memory for matrices A, B, and C
    int* matrixA = allocateMatrix(rowsA, colsA);
    int* matrixB = allocateMatrix(rowsB, colsB);
    int* matrixC = allocateMatrix(rowsA, colsB);

    // Initialize matrices A and B
    printf("Enter elements of matrix A:\n");
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            scanf("%d", &matrixA[i * colsA + j]);
        }
    }
    printf("Enter elements of matrix B:\n");
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            scanf("%d", &matrixB[i * colsB + j]);
        }
    }

    // Multiply matrices A and B
    multiplyMatrices(matrixA, matrixB, matrixC, rowsA, colsA, colsB);

    
    printf("Matrix A:\n");// Print result matrix
    printMatrix(matrixA, rowsA, colsA);
    printf("Matrix B:\n");
    printMatrix(matrixB, rowsB, colsB);
    printf("Matrix C (A * B):\n");
    printMatrix(matrixC, rowsA, colsB);

    // free matrix memory
    freemat(matrixA);
    freemat(matrixB);
    freemat(matrixC);

    return 0;
}