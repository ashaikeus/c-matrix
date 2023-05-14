#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
    int status = 0;

    result->rows = rows;
    result->columns = columns;
    result->matrix = calloc(rows, sizeof(double *));

    for (int i = 0; i < rows; i++) {
        result->matrix[i] = calloc(columns, sizeof(double));
    }

    return status;
}

void s21_remove_matrix(matrix_t *A) {
    for (int i = 0; i < A->rows; i++) {
        free(A->matrix[i]);
    }
    free(A->matrix);

    A->rows = 0;
    A->columns = 0;
    A->matrix = NULL;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
    int ret = 1;
    if ((A->rows != B->rows) || (A->columns != B->columns)) ret = 0;
    else for (int i = 0; i < A->rows; i++) for (int j = 0; j < A->columns; j++) {
        if (A->matrix[i][j] - B->matrix[i][j] > S21_EPS) {
            ret = 0;
            break;
        }
    }
    return ret;
}

// helpers

int empty_check(matrix_t M) {
    int result = 1;
    for (int i = 0; i < M.rows; i++) for (int j = 0; j < M.columns; j++) if (M.matrix[i][j]) {
        result = 0;
        break;
    }
    return result;
}

void print_matrix(matrix_t M) {
    for (int i = 0; i < M.rows; i++) {
        for (int j = 0; j < M.columns; j++) printf("%Lf ", M.matrix[i][j]);
        printf("\n");
    }
}

int main() {
    matrix_t a = {0};
    s21_create_matrix(2, 3, &a);
    matrix_t b = {0};
    s21_create_matrix(2, 3, &b);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            a.matrix[i][j] = 2;
            b.matrix[i][j] = 3;
        }
    }
    printf("%d, %d - ", a.rows, a.columns);
    print_matrix(a);
    printf("%d, %d - ", b.rows, b.columns);
    print_matrix(b);
}