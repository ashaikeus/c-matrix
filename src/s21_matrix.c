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
  if ((A->rows != B->rows) || (A->columns != B->columns))
    ret = 0;
  else
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++) {
        if (A->matrix[i][j] - B->matrix[i][j] > S21_EPS) {
          ret = 0;
          break;
        }
      }
  return ret;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int ret = 1;
  if ((A->rows != B->rows) || (A->columns != B->columns))
    ret = 0;
  else
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
  return ret;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int ret = 1;
  if ((A->rows != B->rows) || (A->columns != B->columns))
    ret = 0;
  else
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
  return ret;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int ret = 1;
  for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  return ret;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {}

int s21_transpose(matrix_t *A, matrix_t *result) {}

int s21_calc_complements(matrix_t *A, matrix_t *result) {}

int s21_determinant(matrix_t *A, double *result) {}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {}

// helpers

void print_matrix(matrix_t M) {
  for (int i = 0; i < M.rows; i++) {
    for (int j = 0; j < M.columns; j++) printf("%lf ", M.matrix[i][j]);
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
  matrix_t result = {0};
  s21_create_matrix(2, 3, &result);
  s21_mult_number(&b, 3, &result);
  print_matrix(result);
}