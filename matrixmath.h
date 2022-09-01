#ifndef MATRIXMATH_H    
#define MATRIXMATH_H

void switchRows(int m, int n, float matrix[m][n], int rowA, int rowB);
void logMatrix(int m, int n, float matrix[m][n]);
void addRows(int m, int n, float matrix[m][n], int rowA, int rowB, float factor);
void multiplyRow(int m, int n, float matrix[m][n], int row, float factor);
void reduce(int m, int n, float matrix[m][n]);

#endif