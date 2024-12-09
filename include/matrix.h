#ifndef MATRIX_H
#define MATRIX_H
#define MIN (-1000000)
#define MAX 1000000

double getRandomNumber(const int min, const int max);

void generateRandomArray(double **matrix, double *b, const int size);

void testResults(int size, double **matrix, double *x, double *b, int epsilon);

int testMatrix(double **matrix, const int size);
#endif
