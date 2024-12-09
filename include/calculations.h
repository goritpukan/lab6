#ifndef CALCULATIONS_H
#define CALCULATIONS_H
void simpleIterationMethod(int size, double **matrix, double *b, double *x, double *xp, double epsilon);
void convertEpsilon(double *epsilon);
#endif