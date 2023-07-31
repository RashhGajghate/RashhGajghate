#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, M;

    // Get user input for N
    printf("Enter the number of rows (0 < N <= 3): ");
    scanf("%d", &N);

    // Validate the input for N
    if (N <= 0 || N > 3) {
        printf("Invalid input for N. Exiting the program.\n");
        return 0;
    }

    // Get user input for M
    printf("Enter the number of columns (0 < M <= 3): ");
    scanf("%d", &M);

    // Validate the input for M
    if (M <= 0 || M > 3) {
        printf("Invalid input for M. Exiting the program.\n");
        return 0;
    }

    // Allocate memory for the matrix
    int** matrix = (int* )malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        matrix[i] = (int*)malloc(M * sizeof(int));
    }

    // Get user input for matrix elements
    printf("Enter the elements of the matrix:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Print the matrix
    printf("The matrix is:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
