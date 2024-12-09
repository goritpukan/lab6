#include "../include/matrix.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double getRandomNumber(const int min, const int max) {
  return min + ((double) rand() / RAND_MAX) * (max - min);
}

void generateRandomArray(double **matrix, double *b, const int size) {
  for (int i = 0; i < size; i++) {
    double sum = 0.0;
    for (int j = 0; j < size + 1; j++) {
      if (j == size) {
        b[i] = getRandomNumber(MIN, MAX);
      }
      if (j != i && j != size) {
        matrix[i][j] = getRandomNumber(MIN, MAX);
        sum += fabs(matrix[i][j]);
      }
    }
    double randomNumber = getRandomNumber(MIN, MAX);
    matrix[i][i] = randomNumber > 0 ? randomNumber + sum : randomNumber - sum;
  }
}

void testResults(int size, double **matrix, double *x, double *b, int epsilon) {
  for (int i = 0; i < size; i++) {
    double sum = 0;
    for (int j = 0; j < size; j++) {
      sum += matrix[i][j] * x[j];
    }
    double diffence = fabs(sum - b[i]);
    printf("The result after substituting the obtained results in row (%d) = %.*lf(+- %.*lf) or (%.15lf%)\n\n", i + 1, epsilon, sum, epsilon, diffence, fabs(diffence / b[i] * 100));
  }
}

int testMatrix(double **matrix, const int size) {
  for (int i = 0; i < size; i++) {
    double sum = 0;
    for (int j = 0; j < size; j++) {
      if (i != j) {
        sum += fabs(matrix[i][j]);
      }
    }
    if (fabs(matrix[i][i]) < fabs(sum)) {
      return 0;
    }
  }
  return 1;
}
