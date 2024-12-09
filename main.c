#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "include/colors.h"
#include "include/io.h"
#include "include/calculations.h"
#include "include/matrix.h"

int main(void) {
  srand(time(NULL));
  printf(GREEN"This is program which solves linear systems of algebraic equations (SLAE) by the method of simple iteration with using dynamic arrays.\n"RESET);
  do {
    int size = 0;
    int epsilon = 0;
    printf("Enter size of matrix in range [2, 100]: ");
    size = (int) getNumberFromUser(2, 100);
    printSeparator();
    printf("Enter the precision 3 - 15: ");
    epsilon = (int) getNumberFromUser(3, 15);
    double **matrix = calloc(size, sizeof(double *));
    for (int i = 0; i < size; i++) {
      matrix[i] = (double *) calloc(size, sizeof(double));
    }
    double *b = calloc(size, sizeof(double));
    double *x = calloc(size, sizeof(double));
    double *xp = calloc(size, sizeof(double));
    if (matrix == NULL || b == NULL || x == NULL || xp == NULL) {
      printf(RED"Memory allocation error\n"RESET);
    }

    printSeparator();
    switch (getUserChoice("Choose filling method(0 - manually, 1 - generated): ")) {
      case 0:
        fillArrayManually(matrix, b, size);
        break;
      case 1:
        generateRandomArray(matrix, b, size);
        break;
      default:
        printf("Something impossible happened\n");
    }
    printSeparator();

    switch (getUserChoice("Do you want to print your matrix? (1 - yes, 0 - no): ")) {
      case 1:
        printMatrix(matrix, b, size);
        printSeparator();
        break;
      case 0:
        break;
      default:
        printf("Something impossible happened\n");
    }

    printf("Precision: %d\n", epsilon);
    printSeparator();
    simpleIterationMethod(size, matrix, b, x, xp, epsilon);

    for (int i = 0; i < size; i++) {
      printf("X(%d) = %.*lf\n\n", i + 1, epsilon, x[i]);
    }
    printSeparator();
    testResults(size, matrix, x, b, epsilon);
    printSeparator();
    for (int i = 0; i < size; i++) {
      free(matrix[i]);
    }
    free(matrix);
    free(b);
    free(x);
    free(xp);

    printf(GREEN"\nPress \'r\' to restart: "RESET);
  } while (getchar() == 'r');
  return 0;
}
