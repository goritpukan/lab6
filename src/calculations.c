#include "../include/calculations.h"

#include <math.h>

void simpleIterationMethod(int size, double **matrix, double *b, double *x, double *xp, double epsilon) {
  convertEpsilon(&epsilon);
  double delta = 0, maxDelta = 0;
  double sum = 0;
  do {
    maxDelta = 0.0;
    for (int i = 0; i < size; i++) {
      sum = 0;
      for (int j = 0; j < size; j++) {
        if (i != j) {
          sum += matrix[i][j] * xp[j];
        }
      }
      x[i] = (b[i] - sum) / matrix[i][i];
      delta = fabs(x[i] - xp[i]);
      if (delta > maxDelta) {
        maxDelta = delta;
      }
    }
    for (int i = 0; i < size; i++) {
      xp[i] = x[i];
    }
  } while (maxDelta > epsilon);
}

void convertEpsilon(double *epsilon) {
  *epsilon = pow(10, -*epsilon);
}
