#include <stdio.h>

#define MAX 10 // Define a maximum size for the 2D arrays

// Function to take matrix input from the user
void inputMatrix(int matrix[MAX][MAX], int *rows, int *cols, char name) {
    printf("\n--- Input for Matrix %c ---\n", name);
    printf("Enter number of rows (max %d): ", MAX);
    scanf("%d", rows);
    printf("Enter number of columns (max %d): ", MAX);
    scanf("%d", cols);

    printf("Enter the elements row by row:\n");
    for (int i = 0; i < *rows; i++) {
        for (int j = 0; j < *cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function for Matrix Addition
void addMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Function for Matrix Multiplication
void multiplyMatrices(int mat1[MAX][MAX], int mat2[MAX][MAX], int result[MAX][MAX], int r1, int c1, int r2, int c2) {
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            result[i][j] = 0; // Initialize element to 0
            for (int k = 0; k < c1; k++) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// Function to Transpose a Matrix
void transposeMatrix(int matrix[MAX][MAX], int result[MAX][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[j][i] = matrix[i][j]; // Swap rows and columns
        }
    }
}

int main() {
    int matrixA[MAX][MAX], matrixB[MAX][MAX], resultMatrix[MAX][MAX];
    int r1, c1, r2, c2;

    // Get user input for both matrices
    inputMatrix(matrixA, &r1, &c1, 'A');
    inputMatrix(matrixB, &r2, &c2, 'B');

    printf("\n--- Matrix A ---\n");
    printMatrix(matrixA, r1, c1);
    
    printf("\n--- Matrix B ---\n");
    printMatrix(matrixB, r2, c2);

    // 1. Matrix Addition (Requires identical dimensions)
    printf("\n--- Addition (A + B) ---\n");
    if (r1 == r2 && c1 == c2) {
        addMatrices(matrixA, matrixB, resultMatrix, r1, c1);
        printMatrix(resultMatrix, r1, c1);
    } else {
        printf("Error: Matrices must have the exact same dimensions for addition.\n");
    }

    // 2. Matrix Multiplication (Requires Cols of A == Rows of B)
    printf("\n--- Multiplication (A * B) ---\n");
    if (c1 == r2) {
        multiplyMatrices(matrixA, matrixB, resultMatrix, r1, c1, r2, c2);
        printMatrix(resultMatrix, r1, c2); // Result dimensions are r1 x c2
    } else {
        printf("Error: Number of columns in Matrix A must equal the number of rows in Matrix B.\n");
    }

    // 3. Matrix Transpose (We will just transpose Matrix A as an example)
    printf("\n--- Transpose of Matrix A ---\n");
    transposeMatrix(matrixA, resultMatrix, r1, c1);
    printMatrix(resultMatrix, c1, r1); // Dimensions are swapped

    return 0;
}