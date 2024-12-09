#include <stdio.h>
#include <math.h>
#include "../include/colors.h"
#include "../include/matrix.h"

double getNumberFromUser(const double min, const double max) {
  char isValid = 0;
  double result = 0;
  do {
    isValid = scanf("%lf", &result);
    while (getchar() != '\n');
    if (result < min || result > max) {
      printf(RED"Enter value in range: [%lf, %lf]: \n"RESET, min, max);
      isValid = 0;
      continue;
    }
    if (!isValid) {
      printf(RED"Invalid input. Try again\n"RESET);
    }
  } while (!isValid);
  return result;
}

int getUserChoice(char *message) {
  int choice = 0;
  do {
    printf("%s", message);
    choice = getchar();
    while (getchar() != '\n');
    if (choice != '0' && choice != '1') {
      printf(RED"Enter 0 or 1"RESET);
    }
  } while (choice != '0' && choice != '1');
  return choice == '0' ? 0 : 1;
}

void fillArrayManually(double **matrix, double *b, const int size) {
  printf(RED"\n!!!|a_ii| MUST BE GREATER THAN THE SUM OF THE MODULES OF OTHER ELEMENTS!!!\n"RESET);
  for (int i = 0; i < size; i++) {
    double sum = 0;
    do {
      sum = 0;
      for (int j = 0; j < size + 1; j++) {
        if (j == size) {
          printf("Enter b_%d in range: [%d, %d]: ", i + 1, MIN, MAX);
          b[i] = getNumberFromUser(MIN, MAX);
          continue;
        }
        printf("Enter a_%d%d in range: [%d, %d]: ", i + 1, j + 1, MIN, MAX);
        double value = getNumberFromUser(MIN, MAX);
        matrix[i][j] = value;
        if (i != j) {
          sum += fabs(value);
        }
      }
      if (fabs(matrix[i][i]) < fabs(sum)) {
        printf(RED"\nThe sum of the modules of the elements must be less than the module of the diagonal element"RESET);
      }
    } while (fabs(matrix[i][i]) < fabs(sum));
  }
}

void printMatrix(double **matrix, double *b, const int size) {
  printf(GREEN"Your matrix:\n\n"RESET);
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size + 1; j++) {
      if (j == size) {
        printf(" = %lf\n\n", b[i]);
      } else {
        char sign = matrix[i][j] > 0 ? '+' : '-';
        printf(" %c %13lf x_%d", j == 0 ? ' ' : sign, fabs(matrix[i][j]), j + 1);
      }
    }
  }
}
void printSeparator() {
  printf(CYAN"\n#|");
  for (int i = 0; i < 150; i++) {
    printf("-");
  }
  printf("|#\n\n"RESET);
}
