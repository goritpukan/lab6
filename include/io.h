#ifndef IO_H
#define IO_H

double getNumberFromUser(const double min, const double max);

int getUserChoice(char *message);

void fillArrayManually(double **matrix, double *b, const int size);

void printMatrix(double **matrix, double *b, const int size);

void printSeparator();


#endif
