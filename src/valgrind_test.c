#include "s21_matrix.h"

int create() {
  int res = 0;
  matrix_t m = {0};
  for (int k = 0; k < 50; k++) {
    int rows = k, cols = k;
    s21_create_matrix(rows, cols, &m);
    s21_remove_matrix(&m);
  }
}

int compare_1() {  // +
  matrix_t a = {0};
  s21_create_matrix(2, 2, &a);
  matrix_t b = {0};
  s21_create_matrix(2, 2, &b);
  s21_eq_matrix(&a, &b);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}

int compare_2() {  // - bc size
  matrix_t a = {0};
  s21_create_matrix(2, 3, &a);
  matrix_t b = {0};
  s21_create_matrix(2, 2, &b);
  s21_eq_matrix(&a, &b);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}

int compare_3() {  // - bc values
  matrix_t a = {0};
  s21_create_matrix(2, 3, &a);
  matrix_t b = {0};
  s21_create_matrix(2, 3, &b);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = 2;
      b.matrix[i][j] = 3;
    }
  s21_eq_matrix(&a, &b);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
}

int sum_1() {
  int res = 0;
  matrix_t a = {0};
  s21_create_matrix(2, 3, &a);
  matrix_t b = {0};
  s21_create_matrix(2, 3, &b);
  matrix_t result = {0};
  s21_create_matrix(2, 3, &result);
  matrix_t true_result = {0};
  s21_create_matrix(2, 3, &true_result);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = 2.13243422;
      b.matrix[i][j] = 3.3431413598;
      true_result.matrix[i][j] = 2.13243422 + 3.3431413598;
    }
  s21_sum_matrix(&a, &b, &result);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
  s21_remove_matrix(&true_result);
}

int sum_2() {
  int res = 0;
  matrix_t a = {0};
  s21_create_matrix(2, 2, &a);
  matrix_t b = {0};
  s21_create_matrix(2, 3, &b);
  matrix_t result = {0};
  s21_create_matrix(2, 3, &result);
  s21_sum_matrix(&a, &b, &result);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
}

int sum_3() {
  int res = 0;
  matrix_t a = {0};
  s21_create_matrix(2, 3, &a);
  matrix_t b = {0};
  s21_create_matrix(2, 3, &b);
  matrix_t result = {0};
  s21_create_matrix(2, 3, &result);
  matrix_t true_result = {0};
  s21_create_matrix(2, 3, &true_result);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = i + j;
      b.matrix[i][j] = j * 2 + i;
      true_result.matrix[i][j] = i + j + j * 2 + i;
    }
  s21_sum_matrix(&a, &b, &result);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
  s21_remove_matrix(&true_result);
}

int sum_4() {
  int res = 0;
  matrix_t result = {0};
  s21_create_matrix(2, 3, &result);
  s21_sum_matrix(NULL, NULL, &result);
  s21_remove_matrix(&result);
}

int sub_1() {
  int res = 0;
  matrix_t a = {0};
  s21_create_matrix(2, 3, &a);
  matrix_t b = {0};
  s21_create_matrix(2, 3, &b);
  matrix_t result = {0};
  s21_create_matrix(2, 3, &result);
  matrix_t true_result = {0};
  s21_create_matrix(2, 3, &true_result);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = 2.13243422;
      b.matrix[i][j] = 3.3431413598;
      true_result.matrix[i][j] = 2.13243422 - 3.3431413598;
    }
  s21_sub_matrix(&a, &b, &result);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
  s21_remove_matrix(&true_result);
}

int sub_2() {
  int res = 0;
  matrix_t a = {0};
  s21_create_matrix(2, 2, &a);
  matrix_t b = {0};
  s21_create_matrix(2, 3, &b);
  matrix_t result = {0};
  s21_create_matrix(2, 3, &result);
  s21_sub_matrix(&a, &b, &result);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
}

int sub_3() {
  int res = 0;
  matrix_t a = {0};
  s21_create_matrix(2, 3, &a);
  matrix_t b = {0};
  s21_create_matrix(2, 3, &b);
  matrix_t result = {0};
  s21_create_matrix(2, 3, &result);
  matrix_t true_result = {0};
  s21_create_matrix(2, 3, &true_result);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = i + j;
      b.matrix[i][j] = j * 2 + i;
      true_result.matrix[i][j] = i + j - j * 2 - i;
    }
  s21_sub_matrix(&a, &b, &result);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
  s21_remove_matrix(&true_result);
}

int sub_4() {
  int res = 0;
  matrix_t result = {0};
  s21_create_matrix(2, 3, &result);
  s21_sub_matrix(NULL, NULL, &result);
  s21_remove_matrix(&result);
}

int mul_num_1() {
  int res = 0;
  matrix_t a = {0};
  s21_create_matrix(2, 3, &a);
  matrix_t result = {0};
  s21_create_matrix(2, 3, &result);
  matrix_t true_result = {0};
  s21_create_matrix(2, 3, &true_result);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = 2.13243422;
      true_result.matrix[i][j] = 2.13243422 * 3.3431413598;
    }
  s21_mult_number(&a, 3.3431413598, &result);
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&true_result);
}

int mul_num_2() {
  int res = 0;
  matrix_t b = {0};
  s21_create_matrix(2, 3, &b);
  matrix_t result = {0};
  s21_create_matrix(2, 3, &result);
  s21_mult_number(NULL, 2342, &result);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
}

int mul_num_3() {
  int res = 0;
  matrix_t a = {0};
  s21_create_matrix(9, 7, &a);
  matrix_t result = {0};
  s21_create_matrix(9, 7, &result);
  matrix_t true_result = {0};
  s21_create_matrix(9, 7, &true_result);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = i * 19.124981 * -1;
      true_result.matrix[i][j] = a.matrix[i][j] * 3.3431413598;
    }
  s21_mult_number(&a, 3.3431413598, &result);
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&true_result);
}

int mul_mat_1() {
  int res = 0;
  matrix_t a = {0};
  s21_create_matrix(2, 3, &a);
  matrix_t b = {0};
  s21_create_matrix(3, 2, &b);
  matrix_t result = {0};
  s21_create_matrix(2, 2, &result);
  matrix_t true_result = {0};
  s21_create_matrix(2, 2, &true_result);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = 2.13243;
      b.matrix[j][i] = 3.34314;
      if (j != 2) true_result.matrix[i][j] = 21.3870360906;
    }
  s21_mult_matrix(&a, &b, &result);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
  s21_remove_matrix(&true_result);
}

int mul_mat_2() {
  int res = 0;
  matrix_t a = {0};
  s21_create_matrix(2, 3, &a);
  matrix_t b = {0};
  s21_create_matrix(2, 3, &b);
  matrix_t result = {0};
  s21_create_matrix(2, 3, &result);
  s21_mult_matrix(&a, &b, &result);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
}

int mul_mat_3() {
  int res = 0;
  matrix_t a = {0};
  s21_create_matrix(2, 3, &a);
  matrix_t b = {0};
  s21_create_matrix(3, 2, &b);
  matrix_t result = {0};
  s21_create_matrix(2, 2, &result);
  matrix_t true_result = {0};
  s21_create_matrix(2, 2, &true_result);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = i + j;
      b.matrix[j][i] = j * 2 + i;
    }
  true_result.matrix[0][0] = 10;
  true_result.matrix[0][1] = 13;
  true_result.matrix[1][0] = 16;
  true_result.matrix[1][1] = 22;
  s21_mult_matrix(&a, &b, &result);
  s21_remove_matrix(&a);
  s21_remove_matrix(&b);
  s21_remove_matrix(&result);
  s21_remove_matrix(&true_result);
}

int mul_mat_4() {
  int res = 0;
  matrix_t result = {0};
  s21_create_matrix(2, 3, &result);
  s21_mult_matrix(NULL, NULL, &result);
  s21_remove_matrix(&result);
}

int transpose_1() {
  int res = 0;
  matrix_t a = {0};
  s21_create_matrix(2, 3, &a);
  matrix_t result = {0};
  s21_create_matrix(3, 2, &result);
  matrix_t true_result = {0};
  s21_create_matrix(3, 2, &true_result);
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = i + j;
      true_result.matrix[j][i] = i + j;
    }
  s21_transpose(&a, &result);
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&true_result);
}

int complements_1() {
  int res = 0;
  matrix_t a = {0};
  s21_create_matrix(3, 3, &a);
  matrix_t result = {0};
  s21_create_matrix(3, 3, &result);
  matrix_t true_result = {0};
  s21_create_matrix(3, 3, &true_result);
  a.matrix[0][0] = 0.73;
  a.matrix[0][1] = -0.07;
  a.matrix[0][2] = -0.12;
  a.matrix[1][0] = -0.19;
  a.matrix[1][1] = 0.72;
  a.matrix[1][2] = -0.15;
  a.matrix[2][0] = -0.12;
  a.matrix[2][1] = -0.17;
  a.matrix[2][2] = 0.92;
  true_result.matrix[0][0] = 0.6369;
  true_result.matrix[0][1] = 0.0848;
  true_result.matrix[0][2] = 0.0969;
  true_result.matrix[1][0] = 0.1928;
  true_result.matrix[1][1] = 0.6572;
  true_result.matrix[1][2] = 0.1323;
  true_result.matrix[2][0] = 0.1187;
  true_result.matrix[2][1] = 0.1325;
  true_result.matrix[2][2] = 0.5123;
  s21_calc_complements(&a, &result);
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&true_result);
}

int det_1() {
  int res = 0;
  matrix_t a = {0};
  s21_create_matrix(3, 3, &a);
  double result = 0.0;
  int c = 1;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = c++;
    }
  }
  s21_determinant(&a, &result);
  s21_remove_matrix(&a);
}

int det_2() {
  int res = 0;
  matrix_t a = {0};
  s21_create_matrix(4, 4, &a);
  double result = 0.0;
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      a.matrix[i][j] = i;
    }
  }
  a.matrix[0][0] = 3;
  a.matrix[2][2] = 14;
  a.matrix[3][3] = 2;
  s21_determinant(&a, &result);
  s21_remove_matrix(&a);
}

int det_3() {
  int res = 0;
  matrix_t a = {0};
  s21_create_matrix(7, 7, &a);
  double result = 0.0;
  int c = 1;
  for (int i = 0; i < 7; i++) {
    for (int j = 0; j < 7; j++) {
      a.matrix[i][j] = c++;
    }
  }
  s21_determinant(&a, &result);
  s21_remove_matrix(&a);
}

int det_4() {
  int res = 0;
  matrix_t a = {0};
  s21_create_matrix(2, 2, &a);
  double result = 0.0;
  int c = 1;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      a.matrix[i][j] = c++;
    }
  }
  s21_determinant(&a, &result);
  s21_remove_matrix(&a);
}

int inv_1() {
  int res = 0;
  matrix_t a = {0};
  s21_create_matrix(2, 3, &a);
  matrix_t result = {0};
  s21_create_matrix(3, 2, &result);
  s21_inverse_matrix(&a, &result);
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
}

int inv_2() {
  int res = 0;
  matrix_t a = {0};
  s21_create_matrix(3, 3, &a);
  matrix_t result = {0};
  s21_create_matrix(3, 3, &result);
  int c = 1;
  for (int i = 0; i < 3; i++)
    for (int j = 0; j < 3; j++) {
      a.matrix[i][j] = c++;
    }
  if (2 != s21_inverse_matrix(&a, &result)) res = 1;
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
}

int inv_3() {
  int res = 0;
  matrix_t a = {0};
  s21_create_matrix(2, 2, &a);
  matrix_t result = {0};
  s21_create_matrix(2, 2, &result);
  matrix_t true_result = {0};
  s21_create_matrix(2, 2, &true_result);
  int c = 1;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      a.matrix[i][j] = c++;
    }
  true_result.matrix[0][0] = -2;
  true_result.matrix[0][1] = 1;
  true_result.matrix[1][0] = 1.5;
  true_result.matrix[1][1] = -0.5;
  if (0 != s21_inverse_matrix(&a, &result)) res = 1;
  if (1 != s21_eq_matrix(&result, &true_result)) res = 1;
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&true_result);
  return res;
}

int inv_4() {
  int res = 0;
  matrix_t a = {0};
  s21_create_matrix(2, 2, &a);
  matrix_t result = {0};
  s21_create_matrix(2, 2, &result);
  matrix_t true_result = {0};
  s21_create_matrix(2, 2, &true_result);
  int c = 2;
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      a.matrix[i][j] = c--;
    }
  true_result.matrix[0][0] = 0.5;
  true_result.matrix[0][1] = 0.5;
  true_result.matrix[1][0] = 0;
  true_result.matrix[1][1] = -1;
  s21_inverse_matrix(&a, &result);
  s21_remove_matrix(&a);
  s21_remove_matrix(&result);
  s21_remove_matrix(&true_result);
}

int problem_1() {  // abort trap 6
  matrix_t A, B, R, R2;
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(1, 1, &B);
  s21_create_matrix(1, 1, &R2);

  A.matrix[0][0] = 1.25;
  B.matrix[0][0] = 2.25;

  R2.matrix[0][0] = 3.5;

  s21_sum_matrix(&A, &B, &R);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&R2);
}

int problem_2() {
  matrix_t A, B, R, R2;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &B);
  s21_create_matrix(3, 3, &R2);

  A.matrix[0][0] = 0.25;
  A.matrix[0][1] = 1.25;
  A.matrix[0][2] = 2.25;
  A.matrix[1][0] = 3.25;
  A.matrix[1][1] = 4.25;
  A.matrix[1][2] = 5.25;
  A.matrix[2][0] = 6.25;
  A.matrix[2][1] = 7.25;
  A.matrix[2][2] = 8.25;

  B.matrix[0][0] = 9.65;
  B.matrix[0][1] = 8.65;
  B.matrix[0][2] = 7.65;
  B.matrix[1][0] = 6.65;
  B.matrix[1][1] = 5.65;
  B.matrix[1][2] = 4.65;
  B.matrix[2][0] = 3.65;
  B.matrix[2][1] = 2.65;
  B.matrix[2][2] = 1.65;

  R2.matrix[0][0] = 9.9;
  R2.matrix[0][1] = 9.9;
  R2.matrix[0][2] = 9.9;
  R2.matrix[1][0] = 9.9;
  R2.matrix[1][1] = 9.9;
  R2.matrix[1][2] = 9.9;
  R2.matrix[2][0] = 9.9;
  R2.matrix[2][1] = 9.9;
  R2.matrix[2][2] = 9.9;

  s21_sum_matrix(&A, &B, &R);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&R2);
}

int problem_3() {
  matrix_t A, B, R, R2;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 3, &B);
  s21_create_matrix(3, 3, &R2);

  A.matrix[0][0] = 0;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  A.matrix[2][0] = 6;
  A.matrix[2][1] = 7;

  B.matrix[0][0] = 9;
  B.matrix[0][1] = 8;
  B.matrix[0][2] = 7;
  B.matrix[1][0] = 6;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 4;

  R2.matrix[0][0] = 6;
  R2.matrix[0][1] = 5;
  R2.matrix[0][2] = 4;
  R2.matrix[1][0] = 51;
  R2.matrix[1][1] = 44;
  R2.matrix[1][2] = 37;
  R2.matrix[2][0] = 96;
  R2.matrix[2][1] = 83;
  R2.matrix[2][2] = 70;

  s21_mult_matrix(&A, &B, &R);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&R2);
}

int problem_4() {
  matrix_t A, B, R, R2;
  s21_create_matrix(3, 2, &A);
  s21_create_matrix(2, 4, &B);
  s21_create_matrix(3, 4, &R2);

  A.matrix[0][0] = 0;
  A.matrix[0][1] = 1;
  A.matrix[1][0] = 3;
  A.matrix[1][1] = 4;
  A.matrix[2][0] = 6;
  A.matrix[2][1] = 7;

  B.matrix[0][0] = 9;
  B.matrix[0][1] = 8;
  B.matrix[0][2] = 7;
  B.matrix[0][3] = 7;
  B.matrix[1][0] = 6;
  B.matrix[1][1] = 5;
  B.matrix[1][2] = 4;
  B.matrix[1][3] = 7;

  R2.matrix[0][0] = 6;
  R2.matrix[0][1] = 5;
  R2.matrix[0][2] = 4;
  R2.matrix[0][3] = 7;
  R2.matrix[1][0] = 51;
  R2.matrix[1][1] = 44;
  R2.matrix[1][2] = 37;
  R2.matrix[1][3] = 49;
  R2.matrix[2][0] = 96;
  R2.matrix[2][1] = 83;
  R2.matrix[2][2] = 70;
  R2.matrix[2][3] = 91;

  int code = s21_mult_matrix(&A, &B, &R);
  printf("%d\n", code);

  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&R);
  s21_remove_matrix(&R2);
}

int main() {
  create();

  compare_1();
  compare_2();
  compare_3();

  sum_1();
  sum_2();
  sum_3();
  sum_4();

  sub_1();
  sub_2();
  sub_3();
  sub_4();

  mul_num_1();
  mul_num_2();
  mul_num_3();

  mul_mat_1();
  mul_mat_2();
  mul_mat_3();
  mul_mat_4();

  transpose_1();

  complements_1();

  det_1();
  det_2();
  det_3();
  det_4();

  inv_1();
  inv_2();
  inv_3();
  inv_4();

  problem_1();
  problem_2();
  problem_3();
  problem_4();
}
