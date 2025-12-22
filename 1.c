#include <stdio.h>
#include <stdlib.h>
#define MAX_TERMS 101 


typedef struct {
    int row;    
    int col;   
    int value;  
} term;

void createSparseMatrix(int rows, int cols, int denseMatrix[rows][cols], term sparseMatrix[]);
void printSparseMatrix(term sparseMatrix[]);

int main() {
    int rows = 4;
    int cols = 5;
    
    int matrix[4][5] = {
        {0, 0, 0, 0, 9},
        {0, 5, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {7, 0, 0, 2, 0}
    };

    term sparse[MAX_TERMS];

    printf("--- Normal (Dense) Matris ---\n");
    for(int i=0; i<rows; i++) {
        for(int j=0; j<cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    createSparseMatrix(rows, cols, matrix, sparse);

  
    printSparseMatrix(sparse);

    return 0;
}

void createSparseMatrix(int rows, int cols, int denseMatrix[rows][cols], term sparseMatrix[]) {
    int i, j;
    int currentTerm = 1;

    
    sparseMatrix[0].row = rows;
    sparseMatrix[0].col = cols;
    

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (denseMatrix[i][j] != 0) {
                sparseMatrix[currentTerm].row = i;
                sparseMatrix[currentTerm].col = j;
                sparseMatrix[currentTerm].value = denseMatrix[i][j];
                currentTerm++;
            }
        }
    }
    

    sparseMatrix[0].value = currentTerm - 1;
}

void printSparseMatrix(term sparseMatrix[]) {
    int totalElements = sparseMatrix[0].value;
    
    printf("\n--- Sparse Matrix (Coordinate List) ---\n");
    printf("Row\tCol\tValue\n");
    printf("---------------------\n");
    

    
    for (int i = 1; i <= totalElements; i++) {
        printf("%d\t%d\t%d\n", sparseMatrix[i].row, sparseMatrix[i].col, sparseMatrix[i].value);
    }
}