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
  int ret = 0;
  if (is_incorrect(A) || is_incorrect(B)) ret = 1;
  else if ((A->rows != B->rows) || (A->columns != B->columns))
    ret = 2;
  else
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
  return ret;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int ret = 0;
  if (is_incorrect(A) || is_incorrect(B)) ret = 1;
  else if ((A->rows != B->rows) || (A->columns != B->columns))
    ret = 2;
  else
    for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
      }
  return ret;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int ret = 0;
  if (is_incorrect(A)) ret = 1;
  else for (int i = 0; i < A->rows; i++)
    for (int j = 0; j < A->columns; j++) {
      result->matrix[i][j] = A->matrix[i][j] * number;
    }
  return ret;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int ret = 0;
  if (is_incorrect(A) || is_incorrect(B)) ret = 1;
  else if (A->rows != B->columns)
    ret = 2;
  else for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < B->columns; j++) {
        result->matrix[i][j] = 0;
        for (int k = 0; k < B->rows; k++)
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
      }
  return ret;
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int ret = 0;
  if (is_incorrect(A)) ret = 1;
  else if (A->rows != result->columns || A->columns != result->rows)
    ret = 2;
  else for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
  return ret;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int ret = 0;
  if (is_incorrect(A)) ret = 1;
  // else if (A->rows != result->columns || A->columns != result->rows) ret = 2;
  else for (int i = 0; i < A->rows; i++)
      for (int j = 0; j < A->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j];
      }
  return ret;
}

int s21_determinant(matrix_t *A, double *result) {
  int ret = 0;
  if (is_incorrect(A)) ret = 1;
  else if (A->rows != A->columns) ret = 2;
  else 
}

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {}

// helpers

int is_incorrect(matrix_t *M) {
  return (M && M->columns > 0 && M->rows > 0) ? 0 : 1;
}

void print_matrix(matrix_t M) {
  for (int i = 0; i < M.rows; i++) {
    for (int j = 0; j < M.columns; j++) printf("%lf ", M.matrix[i][j]);
    printf("\n");
  }
}

double get_minor(matrix_t *M, int row, int col) {
  matrix_t temp;
  s21_create_matrix(M->rows - 1, M->columns - 1, &temp);
  for (int r = 0, i = 0; r < M->rows && r != row; r++, i++)
    for (int c = 0, j = 0; c < M->columns && c != cols; c++, j++) 
      temp[i][j] = M[r][c];
  if (temp->rows == 2 && temp->columns == 2) 
  else (get_minor(M,))
}

int main() {
  matrix_t a = {0};
  s21_create_matrix(2, 3, &a);
  matrix_t result = {0};
  s21_create_matrix(3, 2, &result);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = i + j;
    }
  }
  print_matrix(a);
  s21_transpose(&a, &result);
  print_matrix(result);
  
  // matrix_t a = {0};
  // s21_create_matrix(2, 3, &a);
  // matrix_t b = {0};
  // s21_create_matrix(3, 2, &b);
  // matrix_t result = {0};
  // s21_create_matrix(2, 2, &result);
  // for (int i = 0; i < 2; i++) {
  //   for (int j = 0; j < 3; j++) {
  //     a.matrix[i][j] = i + j;
  //     b.matrix[j][i] = i + j;
  //   }
  // }
  // print_matrix(a);
  // print_matrix(b);
  // s21_mult_matrix(&a, &b, &result);
  // print_matrix(result);
}