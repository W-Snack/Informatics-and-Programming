// Copyright 2021 Marina Usova

/*
���������� ������.

����������� ��������� ���������, ���������� � ���������� ����������.

����������� ����� �������� ��� ��� � �����, ��� � ��� ����� ������������ ����. 
�� ��������� ���� ��� � �� ������ ������� � ����� ����. ����� ���������
�������� ������������ �� ����� ������� ����� ���� � �������. 
�������� ��� � ����, � ����� �������� ����������, ������� �� �� �����.

*/

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

//#define N 4
//#define M 3
//#define K 2

/// <summary>
/// ��������� ���������� ����� �� ���������� ���������
/// </summary>
/// <param name="maximum">������������ ���������� �������� �������</param>
/// <param name="minimun">����������� ���������� �������� �������</param>
/// <returns>��������������� ��������� ��������</returns>
int generateRandNumber(int max, int min) {
  int value = (max - min)* ((float)rand() / RAND_MAX) + min;
  return value;
}

/// <summary>
/// ��������� ��������� ������� ������
/// </summary>
/// <param name="matrix">�������</param>
/// <param name="n">���������� �����</param>
/// <param name="m">���������� ��������</param>
int** setMemory(int** matrix, int n, int m) {
  matrix = (int**)malloc(n * sizeof(int*));
  for (int i = 0; i < n; i++)
    matrix[i] = (int*)malloc(m * sizeof(int));
  return matrix;
}

/// <summary>
/// ����� ������� �� �����
/// </summary>
/// <param name="matrix">�������</param>
/// <param name="n">���������� �����</param>
/// <param name="m">���������� ��������</param>
void printMatrix(int **matrix, int n, int m) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

/// <summary>
/// ��������� ������� �� �����
/// </summary>
/// <param name="matrix"></param>
/// <param name="n">����� �����</param>
/// <param name="m">����� ��������</param>
/// <param name="value">����� �� ������� ����� �������� �������</param>
/// <returns></returns>
int** multMatrixOnNumber(int** matrix, int n, int m, int* value) {
  int** res = NULL;                       // nullptr
  res = setMemory(res, n, m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      res[i][j] = matrix[i][j] * (*value);
    }
  }
  return res;
}

void fillArrayRandValues(int** matrix, int n, int m, int max, int min) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      matrix[i][j] = generateRandNumber(max, min);
    }
  }
}

void freeMemory(int** matrix, int n, int m) {
  for (int i = 0; i < n; i++) free(matrix[i]);
  free(matrix);
}

int** createMatrix(int** matrix, int n, int m, int max, int min, char name) {
  matrix = setMemory(matrix, n, m);
  fillArrayRandValues(matrix, n, m, max, min);
  printf("Matrix %c =\n", name);
  printMatrix(matrix, n, m);
  return matrix;
}

void inputData(int* n, int* m, int* k, int* max, int* min) {
    int is_vector;
    printf("�������� ��� ���������? (1-��, 0-���)\n");
    scanf_s("%d", &is_vector);
    if (is_vector) {
        *m = 1;
        printf("������� ����� �����\n");
        scanf_s("%d", n);
        *k = *n;
        printf("������� ������������ �������� �������� �������\n");
        scanf_s("%d", max);
        printf("������� ����������� �������� �������� �������\n");
        scanf_s("%d", min);
    }
    else {
        printf("������� ����� �����\n");
        scanf_s("%d", n);
        printf("������� ����� ��������\n");
        scanf_s("%d", m);
        printf("������� ����� �������� 2 �������\n");
        scanf_s("%d", k);
        printf("������� ������������ �������� �������� �������\n");
        scanf_s("%d", max);
        printf("������� ����������� �������� �������� �������\n");
        scanf_s("%d", min);
    }
}
/// <summary>
/// ���������������� �������
/// </summary>
/// <param name="matrix"></param>
/// <param name="n"></param>
/// <param name="m"></param>
/// <returns></returns>
int** transpMatrix(int** matrix, int n, int m) {
    int** res = NULL;
    res = setMemory(res, m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            res[i][j] = matrix[j][i];
        }
    }
    return res;
}
/// <summary>
/// ��������� ������� � �� ������� �
/// </summary>
/// <param name="matrix_a"></param>
/// <param name="n"></param>
/// <param name="m"></param>
/// <param name="matrix_b"></param>
/// <param name="k"></param>
/// <returns></returns>
int** multTwoMatrix(int** matrix_a, int n, int m, int** matrix_b, int k) {
    int** res = NULL;
    res = setMemory(res, n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            res[i][j] = 0;
            for (int k = 0; k < m; k++) {
                res[i][j] += matrix_a[i][k] * matrix_b[k][j];
            }
        }
    }
    return res;
}
/// <summary>
/// �������� ������
/// </summary>
/// <param name="matrix_a"></param>
/// <param name="n"></param>
/// <param name="m"></param>
/// <param name="matrix_b"></param>
/// <param name="k"></param>
/// <returns></returns>
int** matrixAddition(int** matrix_a, int n, int m, int** matrix_b, int k) {
    int** res = NULL;
    res = setMemory(res, n, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            res[i][j] = 0;
            res[i][j] += matrix_a[i][j] + matrix_b[i][j];
        }
    }
    return res;
}

int main() {
    setlocale(LC_ALL, "Rus");
  int **matrix_A = NULL, **matrix_B = NULL, **result = NULL;
  int max = 4, min = 0, value = 0, N = 0, M = 0, K = 0 ;

  //srand(time(0));

  inputData(&N, &M, &K, &max, &min);

  matrix_A = createMatrix(matrix_A, N, M, max, min, 'A');
  matrix_B = createMatrix(matrix_B, M, K, max, min, 'B');
  value = generateRandNumber(max, min);

  // ��������� ������� �� �����
  result = setMemory(result, N, M);
  result = multMatrixOnNumber(matrix_A, N, M, &value);
  printf("Matrix A x %d =\n", value);
  printMatrix(result, N, M);
  freeMemory(result, N, M);

  // ���������������� �������
  result = setMemory(result, M, N);
  result = transpMatrix(matrix_A, N, M);
  printf("Matrix AT =\n");
  printMatrix(result, M, N);
  // �������� ���������� ����� ������
  freeMemory(result, M, N);

  // ��������� ���� ������
  result = setMemory(result, N, K);
  result = multTwoMatrix(matrix_A, N, M, matrix_B, K);
  printf("Matrix AxB =\n");
  printMatrix(result, N, K);
  // �������� ���������� ����� ������
  freeMemory(result, N, K);

  // �������� ���� ������
  if ((N == M) && (M == K)) {  
      result = setMemory(result, N, M);
      result = matrixAddition(matrix_A, N, M, matrix_B, K);
      printf("Matrix A+B =\n");
      printMatrix(result, N, M);  
      freeMemory(result, N, M);
  }

 

  // �������� ���� ���������� ������
  freeMemory(matrix_A, N, M);
  freeMemory(matrix_B, M, K);

  return 0;
}
